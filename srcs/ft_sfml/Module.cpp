// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Module.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:09:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:10:26 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Module.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Color const             Module::titleColor = sf::Color(178, 173, 177);
sf::Color const             Module::titleBorderColor = sf::Color(78, 73,
																  77);
sf::Color const             Module::titleTextColor = sf::Color(100, 100, 1);
sf::Color const             Module::mainColor = sf::Color(138, 133, 177);
sf::Color const             Module::mainBorderColor = sf::Color(138, 133, 177);

// * CONSTRUCTORS *********************************************************** //
Module::Module(const sf::Vector2f &mainBoxSize) :
	sf::Drawable(),
	topBox(sf::Vector2f(mainBoxSize.x, 20.), 3.f),
	mainBox(mainBoxSize, 5.f)
{
	// std::cout << "[Module](const sf::Vector2f&) Ctor called" << std::endl;
	this->topBox.setFillColor(Module::titleColor);
	this->topBox.setBorderColor(Module::titleBorderColor);
	this->topBox.setBorderSize(3.);
	this->topBox.setTextColor(Module::titleTextColor);
	this->topBox.setCharacterSize(11.);

	this->mainBox.setFillColor(Module::mainColor);
	this->mainBox.setBorderColor(Module::mainBorderColor);
	this->mainBox.setBorderSize(5.);

	return ;
}

// * DESTRUCTORS ************************************************************ //
Module::~Module()
{
	// std::cout << "[Module]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
void						Module::setPosition(const float x, const float y)
{
	this->topBox.setPosition(x, y);
	this->mainBox.setPosition(x, y + this->topBox.getSize().y);
	return ;
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						Module::draw(sf::RenderTarget& target, 
	sf::RenderStates states) const
{
	target.draw(this->topBox, states);
	target.draw(this->mainBox, states);
	(void)target;
	(void)states;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
