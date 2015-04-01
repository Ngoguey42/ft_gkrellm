
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

class RoundedBox : public sf::Drawable
{
public:
    RoundedBox(const sf::Vector2f &size = sf::Vector2f(30, 30), float radius = 10.);
    void                        setBoxPosition(float x, float y);
    void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                        setFillColor(const sf::Color &color);


private:
    sf::Vector2f                _size;
    float                       _radius;
    sf::CircleShape             _corners[4];
    sf::ConvexShape             _box;
};

void                        RoundedBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < 4; i++)
        target.draw(this->_corners[i], states);
    target.draw(this->_box, states);
    (void)target;
    return ;
}

RoundedBox::RoundedBox(const sf::Vector2f &size, float radius) :
    _size(size), _radius(radius)
{
    for (int i = 0; i < 4; i++)
        this->_corners[i].setRadius(radius);
    this->_box.setPointCount(8);
    return;
}

void                        RoundedBox::setFillColor(const sf::Color &color)
{
    for (int i = 0; i < 4; i++)
        this->_corners[i].setFillColor(color);
    this->_box.setFillColor(color);
    return ;
}

void                        RoundedBox::setBoxPosition(float x, float y)
{
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
    return ;
}

int main(void)
{
    sf::RenderWindow    window(sf::VideoMode(400, 400), "SFML works!");
    RoundedBox          box(sf::Vector2f(200, 100), 40);

    box.setFillColor(sf::Color::Green);
    box.setBoxPosition(50, 50);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(box);
        window.display();
    }
    return (0);
}
