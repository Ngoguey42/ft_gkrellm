// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 12:44:19 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Window.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Vector2f const			Window::backgroundInsets = sf::Vector2f(20, 20);
sf::Vector2f				Window::calculateWindowSize(
	std::vector<ft::IMonitorModule> const *modules)
{
	(void)modules;
	return (sf::Vector2f(220, 620));
}

// * CONSTRUCTORS *********************************************************** //
Window::Window(std::vector<ft::IMonitorModule> const *modules,
			   sf::Vector2f const &winSize) :
	sf::RenderWindow(sf::VideoMode(winSize.x, winSize.y),
					 "ft_gkrellm",
					 sf::Style::Default ^ sf::Style::Resize,
					 sf::ContextSettings(0, 0, 8)),
	ft::IMonitorDisplay(),
	_bg(winSize - Window::backgroundInsets),
	_modules(modules)
{
	// std::cout << "[Window](sf::Vector2f const&) Ctor called" << std::endl;
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
void						Window::updateDisplayLoop()
{
	while (this->isOpen())
	{
		sf::Event	event;

		while (this->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->close();
		}
		this->clear();
		this->draw(this->_bg);
		this->display();
	}	
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
