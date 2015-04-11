// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 16:57:43 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 16:58:31 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Window.hpp"
#include <sys/ioctl.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>

namespace ftnc
{

// * CONSTRUCTORS *********************************************************** //
Window::Window(std::vector<ft::IMonitorModule*> const &modules) :
// 	sf::RenderWindow(sf::VideoMode(winSize.x, winSize.y),
// 					 "ft_gkrellm",
// 					 sf::Style::Default ^ sf::Style::Resize,
// 					 sf::ContextSettings(0, 0, 8)),
	ft::IMonitorDisplay(),
// 	_bg(winSize - Window::backgroundInsets),
	_modules(modules)
	// _modulesFrames()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, this->w);

	// this->_lines.resize(w.ws_row);
	// for (std::vector<ft::IMonitorModule*>::const_iterator it =
	// 		 this->_modules.begin();
	// 	 it != this->_modules.end(); it++)
	// {
	// 	this->_modulesFrames.push_back(
	// 		new ftnc::Module(winSize - Window::backgroundInsets, *it));
	// }
	return ;
}

// * DESTRUCTORS ************************************************************ //
Window::~Window()
{
	clear();
	refresh();
	endwin();
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
int							Window::updateDisplay()
{
	int		key;
	//int		nlines = 0;

	key =getch();
	if (key == 'q' || key == 'Q')
		return (1);
	clear();

	printw("*****J'AIME LES EXIT******");

	refresh();	
// 	if (this->isOpen())
// 	{
// 		sf::Event	event;
// 		float		y;

// 		while (this->pollEvent(event))
// 		{
// 			if (event.type == sf::Event::Closed)
// 				this->close();
// 			else if (event.type == sf::Event::MouseButtonPressed &&
// 					 event.mouseButton.button == sf::Mouse::Left)
// 				this->checkArrowClick(event.mouseButton.x, event.mouseButton.y);
// 		}
// 		this->clear();
// 		this->draw(this->_bg);
// 		y = Window::firstModulePadding + Window::backgroundInsets.y / 2.f+
// 			Background::titleHeight;
// 		for (std::vector<Module*>::iterator it = this->_modulesFrames.begin();
// 			 it != this->_modulesFrames.end(); it++)
// 		{
// 			(*it)->refreshStrings();
// 			(*it)->setPosition(10., y);
// 			y += (*it)->getHeight();
// 			this->draw(**it);
// 		}
// 		this->display();
		return (0);
// 	}	
	// return (1);
}

}
