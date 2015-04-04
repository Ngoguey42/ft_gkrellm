// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 08:53:03 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>

#include <ft_gkrellm.hpp>
#include <modules/IMonitorModule.hpp>
#include <modules/TimeModule.hpp>
#include <ft_sfml/Window.hpp>

namespace ftsf
{
sf::Font				Arial;
float                   getStrWidth(sf::Text const &ref)
{
	float		ret = static_cast<std::string const&>(ref.getString())
		.length();

	if (ref.getCharacterSize() <= 10)
		return ((ref.getCharacterSize() - 4)) * ret;
	if (ref.getCharacterSize() >= 20)
		return ((ref.getCharacterSize() - 8) * ret);
	return ((ref.getCharacterSize() - 5) * ret);
}
float                   getStrHeight(sf::Text const &ref)
{
	if (ref.getCharacterSize() <= 15)
		return (12.5);
	return (25);

}
}

#include <cstdlib>
#include <string>

void					parse_input(int ac, char **av, 
std::vector<ft::IMonitorModule*> &modules,
std::list<ft::IMonitorDisplay*> &displays)
{
	if (ac <= 1)
		return ;
	std::string					type = av[1];
	bool						n = false;
	bool						s = false;
	int							nb = atoi(&av[1][1]);
	std::vector<std::string> 	args(av + 2, av + ac);

	if (*av[1]++ != '-')
	{
		std::cout << "Bad graphical options" << std::endl;	
		return ;
	}
	while (*av[1] >= '0' && *av[1] <= '9')
		av[1]++;
	while (*av[1] == 's' || *av[1] == 'n')
	{
		if (*av[1] == 's')
			s = true;
		else if (*av[1] == 'n')
			n = true;
		av[1]++;
	}
	if (*av[1] != '\0')
	{
		std::cout << "Bad graphical options" << std::endl;	
		return ;
	}
	if (s)//debug
		std::cout << "s" << std::endl;
	if (n)
		std::cout << "n" << std::endl;//fin debug
	if (s || n)
	{
		while (--nb >= 0)
		{
			std::cout << "SFML: Loading ..." << std::endl;
			ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"); //verif
			if (s)
			{
				displays.push_back(new ftsf::Window(modules,
					ftsf::Window::calculateWindowSize(modules)));
			}
			if (n) 
			{
				;
			}
			std::cout << "SFML: Finished Loading ..." << std::endl;	
		}
		for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
		{
			std::transform(it->begin(), it->end(), it->begin(), ::tolower);
			if (*it == "hostname")
				modules.push_back(new ft::TimeModule("Time"));
			else if (*it == "osinfo")
				modules.push_back(new ft::TimeModule("Time"));
			else if (*it == "date")
				modules.push_back(new ft::TimeModule("Time"));
			else if (*it == "cpu")
				modules.push_back(new ft::TimeModule("Time"));
			else if (*it == "ram")
				modules.push_back(new ft::TimeModule("Time"));
			else if (*it == "network")
				modules.push_back(new ft::TimeModule("Time"));
		}
	}
}

#include <unistd.h>

int						main(int ac, char *av[])
{
	std::vector<ft::IMonitorModule*>	modules;
	std::list<ft::IMonitorDisplay*>		displays;
	//on peut foutre autant de sfml qu'on veut dans le liste et ca fonctionne
	//penser bonus
	
	try
	{
		parse_input(ac, av, modules, displays);
	}
	catch (...)
	{
		std::cout << "launching failed" << std::endl;
		return (1);
	
	}
	while (displays.size() > 0)
	{
		std::for_each(modules.begin(), modules.end(),
					  std::mem_fun(&ft::IMonitorModule::refresh_datas));
		displays.remove_if(std::mem_fun(&ft::IMonitorDisplay::updateDisplay));
		//fuites memoires ?
		usleep(1000000);
	}
    return (0);
}
