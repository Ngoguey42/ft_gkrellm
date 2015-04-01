
#include <iostream>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

class RoundedBox : public sf::Drawable
{
public:
    RoundedBox(const sf::Vector2f &size = sf::Vector2f(30, 30), float radius = 10.);
    void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                        setPosition(float x, float y);
    void                        setFillColor(const sf::Color &color);
    void                        setBorderColor(const sf::Color &color);
    void                        setSize(sf::Vector2f const &size);
    void                        setBorderSize(float size);

private:
    sf::Vector2f                _position;
    sf::Vector2f                _size;
    float                       _radius;
    sf::CircleShape             _corners[4];
    sf::ConvexShape             _box;
    sf::Color                   _color;

    bool                        _hasBorder;
    float                       _borderSize;
    RoundedBox                  *_internBox;
    sf::Color                   _borderColor;
};

void                        RoundedBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < 4; i++)
        target.draw(this->_corners[i], states);
    target.draw(this->_box, states);
    if (this->_hasBorder)
        this->_internBox->draw(target, states);
    return ;
}

RoundedBox::RoundedBox(const sf::Vector2f &size, float radius) :
    _position(0., 0.), _size(size), _radius(radius),
    _hasBorder(false), _borderSize(0), _internBox(NULL)
{
    for (int i = 0; i < 4; i++)
        this->_corners[i].setRadius(radius);
    this->_box.setPointCount(8);
    this->setFillColor(sf::Color::Black);
    this->setBorderColor(sf::Color::Black);
    return;
}

void                        RoundedBox::setFillColor(const sf::Color &color)
{
    this->_color = color;
    if (!this->_hasBorder)
    {
        for (int i = 0; i < 4; i++)
            this->_corners[i].setFillColor(color);
        this->_box.setFillColor(color);
    }
    else
        this->_internBox->setFillColor(color);
    return ;
}

void                        RoundedBox::setBorderColor(const sf::Color &color)
{
    this->_borderColor = color;
    if (this->_hasBorder)
    {
        for (int i = 0; i < 4; i++)
            this->_corners[i].setFillColor(color);
        this->_box.setFillColor(color);
    }
    return ;
}

void                        RoundedBox::setSize(sf::Vector2f const &size)
{
    this->_size = size;
    this->setPosition(this->_position.x, this->_position.y);
    if (this->_hasBorder)
          this->setBorderSize(this->_borderSize);
    return ;
}
void                        RoundedBox::setBorderSize(float size)
{
    this->_borderSize = size;
    if (size > 0)
    {
        if (this->_hasBorder == false)
        {
            this->_internBox = new RoundedBox(this->_size - sf::Vector2f(size * 2., size * 2.),
                                              this->_radius);
            this->_hasBorder = true;
            this->setBorderColor(this->_borderColor);
            this->setFillColor(this->_color);
        }
        else
            this->_internBox->setSize(this->_size - sf::Vector2f(size * 2., size * 2.));
        this->setPosition(this->_position.x, this->_position.y);
    }
    else if (this->_hasBorder == true)
    {
        delete this->_internBox;
        this->_hasBorder = false;
        this->setBorderColor(this->_borderColor);
        this->setFillColor(this->_color);
        this->setPosition(this->_position.x, this->_position.y);
    }
    return ;
}

void                        RoundedBox::setPosition(float x, float y)
{
    this->_position.x = x;
    this->_position.y = y;
    this->_corners[0].setPosition(x, y);
    this->_corners[1].setPosition(x + this->_size.x - this->_radius * 2, y);
    this->_corners[2].setPosition(x + this->_size.x - this->_radius * 2, y + this->_size.y - this->_radius * 2);
    this->_corners[3].setPosition(x, y + this->_size.y - this->_radius * 2);

    this->_box.setPoint(0, sf::Vector2f(x, y + this->_radius));
    this->_box.setPoint(1, sf::Vector2f(x + this->_radius, y));
    this->_box.setPoint(2, sf::Vector2f(x + this->_size.x - this->_radius, y));
    this->_box.setPoint(3, sf::Vector2f(x + this->_size.x, y + this->_radius));
    this->_box.setPoint(4, sf::Vector2f(x + this->_size.x, y + this->_size.y - this->_radius));
    this->_box.setPoint(5, sf::Vector2f(x + this->_size.x - this->_radius, y + this->_size.y));
    this->_box.setPoint(6, sf::Vector2f(x + this->_radius, y + this->_size.y));
    this->_box.setPoint(7, sf::Vector2f(x, y + this->_size.y - this->_radius));
    if (this->_hasBorder)
        this->_internBox->setPosition(x + this->_borderSize, y + this->_borderSize);
    return ;
}

int main(void)
{
    sf::RenderWindow    window(sf::VideoMode(400, 400), "SFML works!");
    RoundedBox          box(sf::Vector2f(200, 100), 30);

    box.setFillColor(sf::Color::Yellow);
    box.setPosition(50, 50);
    box.setBorderSize(10.);
    box.setBorderColor(sf::Color::Red);
//    box.setSize(sf::Vector2f(50, 50));
//    box.setPosition(0, 0);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        box.setBorderSize(-10. + static_cast<float>(std::time(NULL) % 10 * 3));
        window.clear();
        window.draw(box);
        window.display();
    }
    return (0);
}
