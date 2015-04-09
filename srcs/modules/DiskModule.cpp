// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DiskModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 20:42:28 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DiskModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
DiskModule::DiskModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[DiskModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
DiskModule::~DiskModule()
{
	// std::cout << "[DiskModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&DiskModule::getStrings(void) const
{return (this->_strings);}

std::string const			&DiskModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						DiskModule::refresh_datas(void)
{
	// std::cout << "Updating disk datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	std::stringstream   ssbuf;
	char                charbuf[100];
	FILE                *stream;
	std::string			tmp;

	if((stream = popen("top -l 1 | head -n 10 | grep Disk | cut -d' ' -f2,4", "r")))
	{
		while (fgets(charbuf, 100, stream))
			ssbuf << charbuf;
		pclose(stream);
		tmp = ssbuf.str();
		this->_strings[0] = "DATA";
		this->_strings[1] = "read: " + tmp.substr(0, tmp.find('/'));
		this->_strings[2] = "write: " + tmp.substr(tmp.find(' ') + 1,
			tmp.find_last_of('/') - tmp.find(' ') - 1);
	}
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
