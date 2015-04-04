// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Background.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:59:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 13:57:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Background.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
float const					Background::posX = 10.f;
float const					Background::posY = 10.f;
std::string const			Background::header = "ft_gkrellm";
std::string const			Background::footer = "ngoguey/wide-aze";
sf::Color const				Background::color = sf::Color(178, 173, 177);
float const					Background::titlePad = 0.0f;
// float const					Background::titlePad = 3.5f;
float const					Background::titleHeight = 45.f;
float const					Background::footerPad = 0.f;
float const					Background::footerHeight = 15.f;


// * CONSTRUCTORS *********************************************************** //
Background::Background(const sf::Vector2f &size) :
	_size(size),
	_titleBox(sf::Vector2f(size.x - Background::titlePad * 2.,
						   Background::titleHeight), 9.),
	_box(size, 5.),
	_footerBox(sf::Vector2f(size.x - Background::footerPad * 2.,
							Background::footerHeight), 3.)
{
	std::cout << "[Background](const sf::Vector2f&) Ctor called" << std::endl;
	this->_box.setFillColor(Background::color);
	this->_box.setPosition(Background::posX, Background::posY);
	this->_titleBox.setFillColor(sf::Color(130, 130, 130));
	this->_titleBox.setPosition(Background::posX + Background::titlePad,
								Background::posY + Background::titlePad);
	this->_titleBox.setBorderColor(sf::Color(70, 70, 70));
	this->_titleBox.setBorderSize(3.);
	this->_titleBox.setText1("ft_gkrellm");
	this->_titleBox.setTextColor(sf::Color::Blue);
	this->_titleBox.setCharacterSize(20);

	this->_footerBox.setFillColor(sf::Color(100, 100, 100));
	this->_footerBox.setPosition(Background::posX + Background::footerPad,
								 size.y + Background::posY - 15. -
								 Background::footerPad);
	this->_footerBox.setBorderColor(sf::Color(70, 70, 70));
	this->_footerBox.setBorderSize(2.);
	this->_footerBox.setText1("wide-aze / ngoguey");
	this->_footerBox.setTextColor(sf::Color::Black);
	this->_footerBox.setCharacterSize(10);
	this->_footerBox.setStyle(sf::Text::Italic);
	(void)size;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Background::~Background()
{
	std::cout << "[Background]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						Background::draw(sf::RenderTarget& target, 
	sf::RenderStates states) const
{
	target.draw(this->_box, states);
	target.draw(this->_titleBox, states);
	target.draw(this->_footerBox, states);
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
