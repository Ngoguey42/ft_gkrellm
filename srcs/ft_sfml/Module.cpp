// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Module.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:09:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/18 15:22:47 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Module.hpp"
#include <algorithm>
#include <functional>

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Color const             Module::titleColor = sf::Color(0, 0, 0);
sf::Color const             Module::titleBorderColor = sf::Color(78, 73, 77);
sf::Color const             Module::titleTextColor = sf::Color(75, 125, 250);
sf::Color const             Module::mainColor = sf::Color(45, 45, 45);
sf::Color const             Module::mainBorderColor = sf::Color(100, 100, 100);
sf::Texture					Module::arrowTexture;

float const					Module::topBoxHeight = 25.f;
float const					Module::mainBoxContentInset = 10.f;
float const					Module::stringsBottomPadding = 2.f;
float const					Module::ModuleBottomPadding = 2.f;
float const					Module::ArrowSize = 15.f;
float const					Module::ArrowVertPadding = 5.f;
float const					Module::ArrowHorizPadding = 5.f;

float						Module::calcMainBoxHeight(
	ft::IMonitorModule const &module)
{
	float		tot = 0.f;

	for (std::vector<std::string>::const_iterator it =
			 module.getStrings().begin();
		 it != module.getStrings().end();
		 it++)
		tot += ftsf::getStrHeight(*it) + Module::stringsBottomPadding;
	
	return (tot + Module::mainBoxContentInset * 2.f);
}

float						Module::calcModuleFullHeight(
	ft::IMonitorModule const &module)
{
	return (Module::calcMainBoxHeight(module) + Module::topBoxHeight +
			Module::ModuleBottomPadding);
}

// * CONSTRUCTORS *********************************************************** //
Module::Module(const sf::Vector2f &mainBoxSize,
			   ft::IMonitorModule const *refModule) :
	sf::Drawable(),
	_topBox(sf::Vector2f(mainBoxSize.x, Module::topBoxHeight), 3.f),
	_mainBox(sf::Vector2f(mainBoxSize.x, Module::calcMainBoxHeight(*refModule)),
			 5.f),
	_refModule(refModule),
	_stringsFrames(refModule->getStrings().size()),
	_linesFrames(0),
	_height(Module::calcModuleFullHeight(*refModule))
{
	// stOxd::cout << "[Module](const sf::Vector2f&) Ctor called" << std::endl;
	this->_arrows[0].setTexture(ftsf::Module::arrowTexture);
	this->_arrows[0].setColor(sf::Color(255, 255, 255, 220));
	this->_arrows[0].setTextureRect(
		sf::IntRect(0, Module::ArrowSize,
					Module::ArrowSize, -Module::ArrowSize));
	this->_arrows[1].setTexture(ftsf::Module::arrowTexture);
	this->_arrows[1].setColor(sf::Color(255, 255, 255, 220));
	this->_arrows[1].setTextureRect(
		sf::IntRect(0, 0, Module::ArrowSize, Module::ArrowSize));

	this->_topBox.setFillColor(Module::titleColor);
	this->_topBox.setBorderColor(Module::titleBorderColor);
	this->_topBox.setBorderSize(3.);
	this->_topBox.setTextColor(Module::titleTextColor);
	this->_topBox.setCharacterSize(12.);
	this->_topBox.setText1(refModule->getModuleName());

	this->_mainBox.setFillColor(Module::mainColor);
	this->_mainBox.setBorderColor(Module::mainBorderColor);
	this->_mainBox.setBorderSize(5.);

	std::for_each(this->_stringsFrames.begin(), this->_stringsFrames.end(),
				  std::bind2nd(std::mem_fun_ref(&sf::Text::setFont),
							   ftsf::Arial));
	std::for_each(this->_stringsFrames.begin(), this->_stringsFrames.end(),
				  std::bind2nd(std::mem_fun_ref(&sf::Text::setCharacterSize),
							   11));
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
float                       Module::getHeight(void) const{return this->_height;}

// * SETTERS **************************************************************** //
void						Module::setPosition(const float x, const float y)
{
	float		frameY;

	this->_topBox.setPosition(x, y);
	this->_arrows[0].setPosition(x + this->_topBox.getSize().x -
								 Module::ArrowHorizPadding -
								 Module::ArrowSize,
								 y + Module::ArrowVertPadding);
	this->_arrows[1].setPosition(x + Module::ArrowHorizPadding,
								 y + Module::ArrowVertPadding);
	frameY = y + Module::topBoxHeight;
	this->_mainBox.setPosition(x, frameY);
	frameY += Module::mainBoxContentInset;
	for (std::vector<sf::Text>::iterator it = this->_stringsFrames.begin();
		 it != this->_stringsFrames.end(); it++)
	{
		(*it).setPosition(
			x + (this->_mainBox.getSize().x - ftsf::getStrWidth(*it)) / 2,
			frameY);
		// std::cout << "setting text center to " << frameY << std::endl;		
		frameY += ftsf::getStrHeight(*it) + Module::stringsBottomPadding;
	}
	return ;
}

// * MEMBER FUNCTIONS / METHODS ********************************************* //

void						Module::draw(sf::RenderTarget& target, 
										 sf::RenderStates states) const
{
	target.draw(this->_topBox, states);
	target.draw(this->_arrows[0], states);	
	target.draw(this->_arrows[1], states);
	target.draw(this->_mainBox, states);
	for (std::vector<sf::Text>::const_iterator it = this->_stringsFrames.begin();
		 it != this->_stringsFrames.end(); it++)
		target.draw(*it, states);
	return ;
}
void						Module::refreshStrings(void)
{
	std::vector<sf::Text>::iterator itf = this->_stringsFrames.begin();
	std::vector<std::string>::const_iterator its =
		this->_refModule->getStrings().begin();			
	for (;itf != this->_stringsFrames.end() &&
			 its != this->_refModule->getStrings().end();
		 itf++, its++)
		itf->setString(*its);
	return ;
}
int							Module::doesCollideArrow(float x, float y)
{
	const sf::Vector2f		&a0pos = this->_arrows[0].getPosition();

	if (y > a0pos.y && y < a0pos.y + Module::ArrowSize)
	{
		float				a1x = this->_arrows[1].getPosition().x;

		if (x > a1x)
		{
			if (x < a1x + Module::ArrowSize)
				return (1);
			else if (x > a0pos.x && x < a0pos.x + Module::ArrowSize)
				return (2);
		}
	}
	return (0);
}

// * NESTED_CLASSES ********************************************************* //
}
