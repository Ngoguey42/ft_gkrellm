// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Module.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:09:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 08:54:36 by ngoguey          ###   ########.fr       //
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
Module::Module(const sf::Vector2f &mainBoxSize,
			   ft::IMonitorModule const *refModule) :
	sf::Drawable(),
	_topBox(sf::Vector2f(mainBoxSize.x, 20.), 3.f),
	_mainBox(mainBoxSize, 5.f),
	_refModule(refModule),
	_stringsFrames()
{
	// stOxd::cout << "[Module](const sf::Vector2f&) Ctor called" << std::endl;
	this->_topBox.setFillColor(Module::titleColor);
	this->_topBox.setBorderColor(Module::titleBorderColor);
	this->_topBox.setBorderSize(3.);
	this->_topBox.setTextColor(Module::titleTextColor);
	this->_topBox.setCharacterSize(11.);
	this->_topBox.setText1(refModule->getModuleName());

	this->_mainBox.setFillColor(Module::mainColor);
	this->_mainBox.setBorderColor(Module::mainBorderColor);
	this->_mainBox.setBorderSize(5.);

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
	this->_topBox.setPosition(x, y);
	this->_mainBox.setPosition(x, y + this->_topBox.getSize().y);
	return ;
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //

void						Module::draw(sf::RenderTarget& target, 
	sf::RenderStates states) const
{
	target.draw(this->_topBox, states);
	target.draw(this->_mainBox, states);

//refresh toutes nos 'stringsFrames' face aux 'strings' du refModule
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
