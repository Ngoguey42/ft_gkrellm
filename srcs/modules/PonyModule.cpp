// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PonyModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 18:10:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include "PonyModule.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
PonyModule::PonyModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[PonyModule]() Ctor called" << std::endl;
	this->_strings.resize(28);
	this->_strings[0]  = "                __..___ ";
	this->_strings[1]  = "          _.-'____<'``  ";
	this->_strings[2]  = "    ___.-`.-'`     ```_'";
	this->_strings[3]  = "   /  \\.'` __.----'','/.";
	this->_strings[4]  = "  ( /  \\_/` ,---''.' /  ";
	this->_strings[5]  = "  | |    `,._\\  ,'  /``'";
	this->_strings[6]  = " /( '.  .'``'-`   .-.   ";
	this->_strings[7]  = "( /\\    | |``'.`._|.-:  ";
	this->_strings[8]  = "|| (\\_  ( (    \\ _ | |  ";
	this->_strings[9]  = "|| : \\   \\ \\    ))\\ \\j  ";
	this->_strings[10]  = "|( (, \\   '.`--'/  ``-. ";
	this->_strings[11]  = "' . \\`.`.   ````  \\__/  ";
	this->_strings[12]  = " V(  \\ `-\\-,______.-'   ";
	this->_strings[13]  = "__/\\ .`.     /.^. /     ";
	this->_strings[14]  = "    \\|`.:   (/   V      ";
	this->_strings[15]  = "         `   \\          ";
	this->_strings[16]  = "              |         ";
	this->_strings[17]  = "              |         ";
	this->_strings[18]  = "              |         ";
	this->_strings[19]  = "          \\__/          ";
	this->_strings[20]  = "_____\\       \\          ";
	this->_strings[21]  = "|    |\\       \\         ";
	this->_strings[22]  = "     | `--,    \\        ";
	this->_strings[23]  = "     |   /      l       ";
	this->_strings[24]  = "      | (       |       ";
	this->_strings[25]  = "      |  \\      |       ";
	this->_strings[26]  = "       \\  `.___/        ";
	this->_strings[27]  = "\\_______)               ";
	return ;
}

// * DESTRUCTORS ************************************************************ //
PonyModule::~PonyModule()
{
	// std::cout << "[PonyModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&PonyModule::getStrings(void) const
{return (this->_strings);}

std::string const			&PonyModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						PonyModule::refresh_datas(void)
{
	if (time(NULL) % 2 == 0)
	{
		this->_strings[7]  = "( /\\    | |``'.`._|.-:  ";
		this->_strings[8]  = "|| (\\_  ( (    \\ _ | |  ";
		this->_strings[9]  = "|| : \\   \\ \\    ))\\ \\j  ";
	}
	else
	{
		this->_strings[7]  = "( /\\    | |`*'.`._|.*:  ";
		this->_strings[8]  = "|| (\\_  ( ( *W*\\ _ |W|  ";
		this->_strings[9]  = "|| : \\   \\ \\ ** ))\\ \\j  ";
	}
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
