// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 20:40:22 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CPUModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
CPUModule::CPUModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	char			buf[100];
	size_t			buflen = 100;
	size_t			pos;

	this->_strings.resize(2);
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	pos = buflen;
	this->_strings[0].assign(buf, pos);
	pos = this->_strings[0].find(" ", this->_strings[0].find(" ") + 1);
	this->_strings[1].assign(this->_strings[0], pos + 1, buflen - pos - 2);
	this->_strings[0].resize(pos);	
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
CPUModule::~CPUModule()
{
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&CPUModule::getStrings(void) const
{return (this->_strings);}

std::string const			&CPUModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						CPUModule::refresh_datas(void)
{
	std::stringstream   ssbuf;
	char                charbuf[100];
	FILE                *stream;

	if((stream = popen("top -l 1 | head -n 10 | grep CPU | cut -d' ' -f3", "r")))
	{
		while (fgets(charbuf, 100, stream))
			ssbuf << charbuf;
		pclose(stream);
		this->_strings[2] = "usage: " + ssbuf.str();
	}
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
