// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 13:20:07 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include <ft_gkrellm.hpp>
#include <modules/IMonitorModule.hpp>
#include <modules/TimeModule.hpp>
#include <ft_sfml/Window.hpp>

namespace ftsf
{
sf::Font			Arial;
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

int						main(void)
{
	std::vector<ft::IMonitorModule>	modules;
	ft::IMonitorDisplay				*display[2];
	
	//lire les argv pour fill modules

	try
	{
		if (1) //si il faut lancer la sfml
		{
			std::cout << "SFML: Loading ..." << std::endl;
			ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"); //verif
			display[0] = new ftsf::Window(
				modules,
				ftsf::Window::calculateWindowSize(modules));
			display[0]->updateDisplay();
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
	while (1)
	{
		
		//refresh les datas avec un deltaT
	}

    return (0);
}
