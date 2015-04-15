// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/15 18:41:33 by ngoguey          ###   ########.fr       //
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
	if (winSize.y > 15000)
	{
		std::cout << "Window too large" << std::endl;
		exit(1);
	}
	
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
	if (this->isOpen())
	{
		sf::Event	event;
		float		y;

		while (this->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->close();
			else if (event.type == sf::Event::MouseButtonPressed &&
					 event.mouseButton.button == sf::Mouse::Left)
				this->checkArrowClick(event.mouseButton.x, event.mouseButton.y);
		}
		this->clear();
		this->draw(this->_bg);
		y = Window::firstModulePadding + Window::backgroundInsets.y / 2.f+
			Background::titleHeight;
		for (std::vector<Module*>::iterator it = this->_modulesFrames.begin();
			 it != this->_modulesFrames.end(); it++)
		{
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
void						Window::checkArrowClick(float x, float y)
{
	int		val;

	for (std::vector<Module*>::iterator it =
			 this->_modulesFrames.begin();
		 it != this->_modulesFrames.end(); it++)
	{
		if ((val = (*it)->doesCollideArrow(x, y)) != 0)
		{
			if (val == 2 && it != this->_modulesFrames.begin())
				iter_swap(it, it - 1);
			else if (val == 1 && (it + 1) != this->_modulesFrames.end())
				iter_swap(it + 1, it);
			return ;
		}
	}
	return ;
}		

		
// * NESTED_CLASSES ********************************************************* //
}
