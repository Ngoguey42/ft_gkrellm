// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CatModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/17 09:01:30 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include "CatModule.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
CatModule::CatModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[CatModule]() Ctor called" << std::endl;
	this->_strings.resize(7);
	this->_strings[0]  = "  |\\_._/|  ";
	this->_strings[1]  = "  | o o |  ";
	this->_strings[2]  = "  (  T  )  ";
	this->_strings[3]  = " .^`-^-'^. ";
	this->_strings[4]  = " `.  ;  .' ";
	this->_strings[5]  = " | | | | | ";
	this->_strings[6]  = "((_((|))_))";
	return ;
}

// * DESTRUCTORS ************************************************************ //
CatModule::~CatModule()
{
	// std::cout << "[CatModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&CatModule::getStrings(void) const
{return (this->_strings);}

std::string const			&CatModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						CatModule::refresh_datas(void)
{
	int		random = time(NULL) % 4;
	if (random == 0 || random == 2)
	{
		this->_strings[0]  = "  |\\_._/|  ";
		this->_strings[1]  = "  | o o |  ";
		this->_strings[2]  = "  (  T  )  ";
	}
	else if (random == 1)
	{
		this->_strings[0]  = "  |,\\__/|  ";
		this->_strings[1]  = "  |  o o|  ";
		this->_strings[2]  = "  (   T )  ";
	}
	else
	{
		this->_strings[0]  = "  |\\__/,|  ";
		this->_strings[1]  = "  |o o  |  ";
		this->_strings[2]  = "  ( T   )  ";
	}
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
