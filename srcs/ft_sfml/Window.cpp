// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 15:23:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Window.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Vector2f const			Window::backgroundInsets = sf::Vector2f(20, 20);
float const					Window::firstModulePadding = 5.f;

sf::Vector2f				Window::calculateWindowSize(
	std::vector<ft::IMonitorModule*> const &modules)
{
	float	y = 0.f;

	for (std::vector<ft::IMonitorModule const*>::const_iterator it =
			 modules.begin();
		 it != modules.end(); it++)
		y += Module::calcModuleFullHeight(**it);
	y += Background::titleHeight +
		Background::footerHeight +
		Window::firstModulePadding +
		Window::backgroundInsets.y;
	return (sf::Vector2f(220, y));
}

// * CONSTRUCTORS *********************************************************** //
Window::Window(std::vector<ft::IMonitorModule*> const &modules,
			   sf::Vector2f const &winSize) :
	sf::RenderWindow(sf::VideoMode(winSize.x, winSize.y),
					 "ft_gkrellm",
					 sf::Style::Default ^ sf::Style::Resize,
					 sf::ContextSettings(0, 0, 8)),
	ft::IMonitorDisplay(),
	_bg(winSize - Window::backgroundInsets),
	_modules(modules),
	_modulesFrames()
{
	for (std::vector<ft::IMonitorModule*>::const_iterator it =
			 this->_modules.begin();
		 it != this->_modules.end(); it++)
	{
		this->_modulesFrames.push_back(
			new ftsf::Module(winSize - Window::backgroundInsets, *it));
		
	}
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
int							Window::updateDisplay()
{
	// std::cout << "Updating display:  this=" <<
		// ((unsigned long long int)this) % 0x1000 <<
		// "  isopen: " << this->isOpen()
		// 	  << std::endl;
	if (this->isOpen())
	{
		sf::Event	event;
		float		y;

		while (this->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->close();
		}
		this->clear();
		this->draw(this->_bg);
		y = Window::firstModulePadding + Window::backgroundInsets.y / 2.f+
			Background::titleHeight;
		for (std::vector<Module*>::iterator it = this->_modulesFrames.begin();
			 it != this->_modulesFrames.end(); it++)
		{
			// std::cout << "Window::updateDisplay, Calling draw for module" << std::endl;
			(*it)->refreshStrings();
			(*it)->setPosition(10., y);
			y += (*it)->getHeight();
			this->draw(**it);
		}
		this->display();
		return (0);
	}	
	return (1);
}

// * NESTED_CLASSES ********************************************************* //
}
