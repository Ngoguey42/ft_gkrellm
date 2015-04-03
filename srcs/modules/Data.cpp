// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Data.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:07:07 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 10:51:29 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Data.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
Data::Data(Data::Type t) :
	_type(t),
	_str("")
{
	// std::cout << "[Data](Style) Ctor called" << std::endl;
	return ;
}
Data::Data(Data const &src) :
	_type(src.getType()),
	_str(src.getStr())
{
	// std::cout << "[Data](Data const &src) Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Data::~Data()
{
	// std::cout << "[Data]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
Data::Type const			&Data::getType(void) const{return this->_type;}
std::string const			&Data::getStr(void) const{return this->_str;}

// * SETTERS **************************************************************** //
void						Data::setStr(std::string const &c){this->_str=c;}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //
}
