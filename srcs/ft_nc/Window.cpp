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
	ft::IMonitorDisplay(),
	_modules(modules)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, this->w);

// 	it sur chaque module qui it sur chaque ligne pour appeler Line::initialize pour chaque ligne

//	std::vector<std::string> const	&getStrings(void) const;
//	std::string const			&getModuleName(void) const;
	this->_lines.resize(w.ws_row);
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
	// int		nlines = 0;

	key = getch();
	if (key == 'q' || key == 'Q')
		return (1);
	clear();

	for (std::vector<ftnc::Line*>::iterator it = this->_lines.begin();
		it != this->_lines.end(); it++)
	{
		(*it)->update();
	}
	printw("toto");

	refresh();
	return (0);
}

}
