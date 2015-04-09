// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetworkModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 20:42:28 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NetworkModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
NetworkModule::NetworkModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[NetworkModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
NetworkModule::~NetworkModule()
{
	// std::cout << "[NetworkModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&NetworkModule::getStrings(void) const
{return (this->_strings);}

std::string const			&NetworkModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						NetworkModule::refresh_datas(void)
{
	// std::cout << "Updating network datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	std::stringstream   ssbuf;
	char                charbuf[100];
	FILE                *stream;
	std::string			tmp;

	if((stream = popen("top -l 1 | head -n 10 | grep Networks | cut -d' ' -f3,5", "r")))
	{
		while (fgets(charbuf, 100, stream))
			ssbuf << charbuf;
		pclose(stream);
		tmp = ssbuf.str();
		this->_strings[0] = "PACKETS";
		this->_strings[1] = "in: " + tmp.substr(0, tmp.find('/'));
		this->_strings[2] = "out: " + tmp.substr(tmp.find(' ') + 1,
			tmp.find_last_of('/') - tmp.find(' ') - 1);
	}
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
