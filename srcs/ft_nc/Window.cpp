// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 16:57:43 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 14:26:45 by ngoguey          ###   ########.fr       //
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
	_modules(modules),
	_pushedLines(0)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &this->w);
	this->_lines.resize(w.ws_row);

	std::cerr << w.ws_col << "cols" << std::endl;
	std::cerr << w.ws_row << "rows" << std::endl;	
	try
	{
		_pushLine('*', "", false);
		_pushLine('*', "FT_GKRELLM", false);
		_pushLine('*', "", false);
		_pushLine(' ', "", false);
		for (std::vector<ft::IMonitorModule*>::const_iterator it =
				 this->_modules.begin();
			 it != this->_modules.end(); it++)
		{
			std::vector<std::string>const	&strings =
				(*it)->getStrings();

			_pushLine('_', "", false);
			_pushLine('.', (*it)->getModuleName(), false);
			_pushLine('.', "", false);
			for (std::vector<std::string>::const_iterator it = strings.begin();
				 it != strings.end();
				 it++)
				_pushLine('.', *it, true);
		}
		_pushLine('_', "", false);		
	}
	catch (std::length_error &)
	{}
// 	it sur chaque module qui it sur chaque ligne pour appeler Line::initialize pour chaque ligne

//	std::vector<std::string> const	&getStrings(void) const;
//	std::string const			&getModuleName(void) const;
	
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

	key = getch();
	if (key == 'q' || key == 'Q')
		return (1);
	clear();
	for (std::vector<ftnc::Line>::iterator it = this->_lines.begin();
		 it != this->_lines.end(); it++)
	{
		(*it).update();
		printw("%s", (*it).c_str());
	}
	refresh();
	return (0);
}
void						Window::_pushLine(char bg,
											  const std::string &refstr, bool isDynamic)
{
	if (_pushedLines >= w.ws_row)
		throw std::length_error("");	
	
	_lines[_pushedLines++].initialize(
		bg, static_cast<size_t>(w.ws_col), refstr, isDynamic);
	return ;
}
}
