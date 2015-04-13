// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Line.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 17:46:27 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 17:46:28 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Line.hpp"

namespace ftnc
{

Line::Line(){}

Line::~Line(){}

void			Line::initialize(char bg, int width, const std::string &refstr,
	bool isDynamic)
{
	this->_bg = bg;
	this->_width = width;
	this->_refstr = &refstr;
	this->_isDynamic = isDynamic;
	this->_update();
}

void			Line::update(void)
{
	if (this->_isDynamic == true)
		this->_update();
}

void			Line::_update(void)
{
	
}

}
