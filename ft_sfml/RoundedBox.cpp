// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RoundedBox.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:00:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 17:18:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "RoundedBox.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
RoundedBox::RoundedBox(const sf::Vector2f &size, float radius) :
	_position(0., 0.), _size(size), _radius(radius),
	_hasBorder(false), _borderSize(0), _internBox(NULL)
{
	for (int i = 0; i < 4; i++)
	{
		this->_corners[i].setRadius(radius);
		this->_corners[i].setPointCount(30);
	}
	this->_box.setPointCount(8);
	this->setFillColor(sf::Color::Black);
	this->setBorderColor(sf::Color::Black);
	return;
}

// * DESTRUCTORS ************************************************************ //
RoundedBox::~RoundedBox()
{
	// std::cout << "[RoundedBox]() Dtor called" << std::endl;
	if (this->_hasBorder)
		delete this->_internBox;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
sf::Vector2f const          &RoundedBox::getSize(void) const
{return this->_size;}
sf::Vector2f const          &RoundedBox::getPosition(void) const
{return this->_position;}

// * SETTERS **************************************************************** //
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
			this->_internBox = new RoundedBox(this->_size -
											  sf::Vector2f(size * 2., size * 2.),
											  this->_radius - this->_borderSize);
			this->_hasBorder = true;
			this->setBorderColor(this->_borderColor);
			this->setFillColor(this->_color);
		}
		else
			this->_internBox->setSize(this->_size -
									  sf::Vector2f(size * 2., size * 2.));
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
void                        RoundedBox::setPosition(const float x, const float y)
{
	const float		xNorm = x + this->_radius;
	const float		yNorm = y + this->_radius;
	const float		xRight = x + this->_size.x;
	const float		yBottom = y + this->_size.y;
	const float		xRightNorm = xRight - this->_radius;
	const float		yBottomNorm = yBottom - this->_radius;
	const float		corner_rightX = xRightNorm - this->_radius;
	const float		corner_bottomY = yBottomNorm - this->_radius;

	this->_position.x = x;
	this->_position.y = y;
	this->_corners[0].setPosition(x, y);
	this->_corners[1].setPosition(corner_rightX, y);
	this->_corners[2].setPosition(corner_rightX, corner_bottomY);
	this->_corners[3].setPosition(x, corner_bottomY);

	this->_box.setPoint(0, sf::Vector2f(x, yNorm));
	this->_box.setPoint(1, sf::Vector2f(xNorm, y));
	this->_box.setPoint(2, sf::Vector2f(xRightNorm, y));
	this->_box.setPoint(3, sf::Vector2f(xRight, yNorm));
	this->_box.setPoint(4, sf::Vector2f(xRight, yBottomNorm));
	this->_box.setPoint(5, sf::Vector2f(xRightNorm, yBottom));
	this->_box.setPoint(6, sf::Vector2f(xNorm, yBottom));
	this->_box.setPoint(7, sf::Vector2f(x, yBottomNorm));
	if (this->_hasBorder)
		this->_internBox->setPosition(x + this->_borderSize,
									  y + this->_borderSize);
	return ;
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
void                        RoundedBox::draw(sf::RenderTarget& target,
											 sf::RenderStates states) const
{
	for (int i = 0; i < 4; i++)
		target.draw(this->_corners[i], states);
	target.draw(this->_box, states);
	if (this->_hasBorder)
		this->_internBox->draw(target, states);
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
