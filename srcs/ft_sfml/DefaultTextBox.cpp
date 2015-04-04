// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DefaultTextBox.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 12:21:57 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 10:30:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "DefaultTextBox.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
DefaultTextBox::DefaultTextBox(const sf::Vector2f &size, float radius) :
	RoundedBox(size, radius),
	_text1("empty", ftsf::Arial, 11)
{
	// std::cout << "[DefaultTextBox](const sf::Vector2f&) Ctor called" << std::end;
	return ;
}


// * DESTRUCTORS ************************************************************ //
DefaultTextBox::~DefaultTextBox()
{
	// std::cout << "[DefaultTextBox]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
void						DefaultTextBox::setText1(std::string const &c)
{
	this->_text1.setString(c);
	this->setPosition(this->getPosition().x, this->getPosition().y);
}
void						DefaultTextBox::draw(sf::RenderTarget& target,
	sf::RenderStates states) const
{
	RoundedBox::draw(target, states);
	target.draw(this->_text1, states);
	return ;
}
void                        DefaultTextBox::setPosition(const float x,
														const float y)
{
	RoundedBox::setPosition(x, y);

	// std::cout << this->_text1.getCharacterSize() << std::endl;
	this->_text1.setOrigin(ftsf::getStrWidth(this->_text1) / 2.f,
						   ftsf::getStrHeight(this->_text1) / 2.f);
	this->_text1.setPosition(x + this->getSize().x / 2.f,
							 y + this->getSize().y /2.f);
	return ;
}
void                        DefaultTextBox::setCharacterSize(size_t s)
{
	this->_text1.setCharacterSize(s);
	this->setPosition(this->getPosition().x, this->getPosition().y);
}
void                        DefaultTextBox::setTextColor(sf::Color const &color)
{this->_text1.setColor(color);}
void                        DefaultTextBox::setStyle(sf::Uint32 style)
{this->_text1.setStyle(style);}
// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //
}
