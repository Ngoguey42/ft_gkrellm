// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 07:06:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "TimeModule.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
TimeModule::TimeModule() :
	IMonitorModule(),
	_datas()
{
	// std::cout << "[TimeModule]() Ctor called" << std::endl;
	this->_datas.push_back(Data(Data::String));
	this->_datas.push_back(Data(Data::String));
	return ;
}

// * DESTRUCTORS ************************************************************ //
TimeModule::~TimeModule()
{
	// std::cout << "[TimeModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
std::vector<Data> const		&TimeModule::get_datas(void) const
{return this->_datas;}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						TimeModule::refresh_datas(void)
{
	std::cout << "Updating time datas:  this=" <<
		((unsigned long long int)this) % 0x1000
			  << std::endl;
	
	this->_datas[0].setStr("Mardi 42 Lol 2042");
	this->_datas[1].setStr("18:42:LOL");
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
