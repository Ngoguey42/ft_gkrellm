// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RoundedBox.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 10:04:22 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROUNDEDBOX_HPP
# define ROUNDEDBOX_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
#include <SFML/Graphics.hpp>

class RoundedBox : public sf::Drawable
{
public:
	// * CTORS / DTORS ************** //
	virtual ~RoundedBox();
	RoundedBox(const sf::Vector2f &size = sf::Vector2f(30, 30),
			   float radius = 10.);

	// * GETTERS / SETTERS ********** //
	void                        setPosition(float x, float y);
	void                        setFillColor(const sf::Color &color);
	void                        setBorderColor(const sf::Color &color);
	void                        setSize(sf::Vector2f const &size);
	void                        setBorderSize(float size);

	// * MEMBER FUNCTIONS / METHODS * //
	void                        draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	
protected:
private:
	RoundedBox();
	RoundedBox(RoundedBox const &src);
	RoundedBox					&operator=(RoundedBox const &rhs);

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
};
//std::ostream					&operator<<(std::ostream &o, RoundedBox const &rhs);

#endif // **************************************************** ROUNDEDBOX_HPP //
