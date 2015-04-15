// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 16:56:24 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 13:52:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTNC_WINDOW_HPP
# define FTNC_WINDOW_HPP

# include <iostream>
# include <stdexcept>
# include <vector>
# include <ft_gkrellm.hpp>
# include <IMonitorDisplay.hpp>
# include <sys/ioctl.h>
# include <ncurses.h>
# include <unistd.h>
# include "Line.hpp"

namespace ftnc
{
class Window : public ft::IMonitorDisplay
{

public:

	// * NESTED OBJECTS ************* //
	// pour willy wonka
	
	// * CTORS / DTORS ************** //
	Window(std::vector<ft::IMonitorModule*> const &modules);
	virtual ~Window();

	// * MEMBER FUNCTIONS / METHODS * //
	int							updateDisplay();


	
private:
	void                        _pushLine(char bg,
										  const std::string &refstr,
										  bool isDynamic);
	Window();
	Window(Window const &src);
	Window						&operator=(Window const &rhs);

	// * ATTRIBUTES ***************** //
	const std::vector<ft::IMonitorModule*>	&_modules;
	struct winsize				w;
	std::vector<ftnc::Line>		_lines;
	size_t						_pushedLines;

};

}

#endif // *************************************************** FTNC_WINDOW_HPP //
