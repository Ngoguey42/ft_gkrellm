// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:31:05 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Window.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Vector2f const			Window::backgroundInsets = sf::Vector2f(20, 20);

// * CONSTRUCTORS *********************************************************** //
Window::Window(sf::Vector2f const &winSize) :
	sf::RenderWindow((sf::VideoMode(winSize.x, winSize.y),
					  "ft_gkrellm",
					  sf::Style::Default ^ sf::Style::Resize,
					  sf::ContextSettings(0, 0, 8));),
	ft::IMonitorDisplay(),
	_bg(winSize - Window::backgroundInsets),
	_modules()
{
	// std::cout << "[Window](sf::Vector2f const&) Ctor called" << std::endl;
	(void)winSize;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Window::~Window()
{
	// std::cout << "[Window]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //
}
