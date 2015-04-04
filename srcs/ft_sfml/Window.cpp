// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 11:58:34 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Window.hpp"

namespace ftsf
{
// * STATICS **************************************************************** //
sf::Vector2f const			Window::backgroundInsets = sf::Vector2f(20, 20);
sf::Vector2f				Window::calculateWindowSize(
	std::vector<ft::IMonitorModule*> const &modules)
{
	(void)modules;
	return (sf::Vector2f(220, 620));
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
	std::cout << "Updating display:  this=" <<
		((unsigned long long int)this) % 0x1000 <<
		"  isopen: " << this->isOpen()
			  << std::endl;
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

		// std::pointer_to_binary_function<Window*, sf::Drawable&, void> Test(draw);
		this->draw(this->_bg);
		y = 60.f;
		for (std::vector<Module*>::iterator it = this->_modulesFrames.begin();
			 it != this->_modulesFrames.end(); it++)
		{
			std::cout << "Window::updateDisplay, Calling draw for module" << std::endl;
			(*it)->refreshStrings();
			(*it)->setPosition(10., y);
			y += (*it)->getHeight();
			this->draw(**it);
			
		}
		// (void)Test;
		// for (std::vector<Module>::const_iterator it =
		// 		 this->_modulesFrames.begin();
		// 	 it != this->_modulesFrames.end(); it++)
		// 	target.draw(*it, states);
		
		// std::for_each(this->_modulesFrames.begin(), this->_modulesFrames.end(),
		// 			  bind1st(
		// 				  std::mem_fun_ref(&ftsf::Window::draw),
		// 				  this
		// 				  )
		// );
		// udpate Modules' DataFrames		
		// draw Modules	
		this->display();
		return (0);
	}	
	return (1);
}

// * NESTED_CLASSES ********************************************************* //
}
