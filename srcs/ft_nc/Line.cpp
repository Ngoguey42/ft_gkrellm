// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Line.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 17:46:27 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 14:22:05 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Line.hpp"
#include <algorithm>

namespace ftnc
{
Line::Line() :
	std::string(""),
	_bg(' '),
	_width(10),
	_refstr(NULL),
	_isDynamic(false)
{
	// std::cout << "[Line]() Ctor called" << std::endl;
	return ;
}
Line::Line(Line const &src) :
	std::string(src),
	_bg(src._bg),
	_width(src._width),
	_refstr(src._refstr),
	_isDynamic(src._isDynamic)
{
	// std::cout << "[Line](Line const&) Ctor called" << std::endl;
	return ;
}

Line::~Line()
{}

void			Line::initialize(char bg, size_t width,
								 const std::string &refstr, bool isDynamic)
{
	this->_bg = bg;
	this->_width = width;
	this->_refstr = &refstr;
	if (!(this->_isDynamic = isDynamic))
		this->_update();
	return ;
}

void			Line::update(void)
{
	if (this->_isDynamic == true)
		this->_update();
	return ;
}

void			Line::_update(void)
{
	size_t		pool = 0;
	size_t		curPool;

	this->clear();
	curPool = (_width - this->_refstr->size()) / 2;
	if (curPool > 0 && _width > this->_refstr->size())
	{
		this->resize(curPool, _bg);
		pool += curPool;
	}
	curPool = std::min(this->_refstr->size(), _width);	
	if (curPool > 0)
	{
		this->append(*this->_refstr, 0, curPool);
		pool += curPool;
	}	
	this->resize(_width, _bg);
	return ;
}

}
