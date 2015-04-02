// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AModule.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 17:45:48 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 19:11:55 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "AModule.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Color const             AModule::titleColor = sf::Color(178, 173, 177);
sf::Color const             AModule::titleBorderColor = sf::Color(78, 73,
																  77);
sf::Color const             AModule::titleTextColor = sf::Color(100, 100, 1);
sf::Color const             AModule::mainColor = sf::Color(138, 133, 177);
sf::Color const             AModule::mainBorderColor = sf::Color(138, 133, 177);

// * CONSTRUCTORS *********************************************************** //
AModule::AModule(const sf::Vector2f &mainBoxSize) :
	IMonitorModule(),
	sf::Drawable(),
	topBox(sf::Vector2f(mainBoxSize.x, 20.), 3.f),
	mainBox(mainBoxSize, 5.f)
{
	// std::cout << "[AModule](const sf::Vector2f&) Ctor called" << std::endl;
	this->topBox.setFillColor(AModule::titleColor);
	this->topBox.setBorderColor(AModule::titleBorderColor);
	this->topBox.setBorderSize(3.);
	this->topBox.setTextColor(AModule::titleTextColor);
	this->topBox.setCharacterSize(11.);

	this->mainBox.setFillColor(AModule::mainColor);
	this->mainBox.setBorderColor(AModule::mainBorderColor);
	this->mainBox.setBorderSize(5.);

	return ;
}

// * DESTRUCTORS ************************************************************ //
AModule::~AModule()
{
	// std::cout << "[AModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
void						AModule::setPosition(const float x, const float y)
{
	this->topBox.setPosition(x, y);
	this->mainBox.setPosition(x, y + this->topBox.getSize().y);
	return ;
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						AModule::draw(sf::RenderTarget& target, 
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
