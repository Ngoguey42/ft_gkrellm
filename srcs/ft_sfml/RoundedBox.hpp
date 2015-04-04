// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RoundedBox.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 11:51:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROUNDEDBOX_HPP
# define ROUNDEDBOX_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
#include <ft_gkrellm.hpp>
#include <SFML/Graphics.hpp>

namespace ftsf
{
class RoundedBox : public sf::Drawable
{
public:
	// * CTORS / DTORS ************** //
	virtual ~RoundedBox();
	RoundedBox(const sf::Vector2f &size = sf::Vector2f(30, 30),
			   float radius = 10.);

	// * GETTERS / SETTERS ********** //
	sf::Vector2f const			&getSize(void) const;
	sf::Vector2f const			&getPosition(void) const;

	virtual void                setPosition(const float x, const float y);
	void                        setFillColor(const sf::Color &color);
	void                        setBorderColor(const sf::Color &color);
	void                        setBorderSize(float size);
	void                        setSize(sf::Vector2f const &size);
	
	// * MEMBER FUNCTIONS / METHODS * //
	void                        draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	
protected:
	// * ATTRIBUTES ***************** //
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

private:
	RoundedBox();
	RoundedBox(RoundedBox const &src);
	RoundedBox					&operator=(RoundedBox const &rhs);


};
//std::ostream					&operator<<(std::ostream &o, RoundedBox const &rhs);
}

#endif // **************************************************** ROUNDEDBOX_HPP //
