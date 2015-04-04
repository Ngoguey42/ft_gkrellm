// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 07:22:11 by ngoguey          ###   ########.fr       //
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

#include <unistd.h>

int						main(int ac, char *av[])
{
	std::vector<ft::IMonitorModule*>	modules;
	std::list<ft::IMonitorDisplay*>		displays;
	//on peut foutre autant de sfml qu'on veut dans le liste et ca fonctionne
	//penser bonus
	
	try
	{
		//lire les argv pour fill modules
		(void)ac;
		(void)av;

		modules.push_back(new ft::TimeModule());
		modules.push_back(new ft::TimeModule);
		
		if (1) //si il faut lancer la sfml
		{
			std::cout << "SFML: Loading ..." << std::endl;
			ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"); //verif
			displays.push_back(new ftsf::Window(
								   modules,
								   ftsf::Window::calculateWindowSize(modules)));
			displays.push_back(new ftsf::Window(
								   modules,
								   ftsf::Window::calculateWindowSize(modules)));
			std::cout << "SFML: Finished Loading ..." << std::endl;	
		}
		if (0)
		{
			//si il faut lancer la ncurse
		}
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
		usleep(1000000);
	}
    return (0);
}
