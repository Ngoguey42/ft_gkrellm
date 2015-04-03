// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 12:14:35 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cmath>
#include <pthread.h>
#include <unistd.h>
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



static void				*threadsplit_sfml(void *ptr)
{
	ft::threadDatas		*datas = static_cast<ft::threadDatas*>(ptr);

	std::cout << "SFML: Loading ..." << std::endl;
	// ftsf::Window		sfwin(sf::Vector2f(220, 320));
	ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"); //verif
	// sleep(2);
	std::cout << "SFML: Finished Loading ..." << std::endl;	
	pthread_mutex_unlock(&datas->mutex);

	
	return (NULL);
}

static int				launch_sfml(ft::threadDatas *datas)
{
	//faire full verif sur ces appels systeme, return une error
	pthread_mutexattr_init(&datas->mutex_attr);
	pthread_mutexattr_setprotocol(&datas->mutex_attr, PTHREAD_PRIO_INHERIT);
	pthread_mutexattr_setpshared(&datas->mutex_attr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&datas->mutex, &datas->mutex_attr);
	std::cout << "MAIN: locking sfml's mutex (1)" << std::endl;
	pthread_mutex_lock(&datas->mutex);
	std::cout << "MAIN: lockED sfml's mutex (1)" << std::endl;
	pthread_create(&datas->tid, NULL, &threadsplit_sfml, datas);
	
	std::cout << "MAIN: locking sfml's mutex (2)" << std::endl;	
	pthread_mutex_lock(&datas->mutex);
	std::cout << "MAIN: lockED sfml's mutex (2)" << std::endl;
	pthread_mutex_unlock(&datas->mutex);
	pthread_mutex_destroy(&datas->mutex);
	pthread_mutexattr_destroy(&datas->mutex_attr);
	return (0);
}

int						main(void)
{
	std::vector<ft::IMonitorModule>	modules;
	ft::threadDatas				datas[2]; //sfml 0, ncurses 1
	//lire les argv pour fill modules

	if (1) //si il faut lancer la sfml
	{
		datas[0].modules = &modules;
		std::cout << "MAIN: launching sfml" << std::endl;
		if (launch_sfml(reinterpret_cast<ft::threadDatas*>(datas)))
		{
			std::cout << "MAIN: sfml launch failed" << std::endl;
			return (1);
		}
		std::cout << "MAIN: sfml launched successfully" << std::endl;
	}
	//si il faut lancer la ncurse

	while (1)
	{
		//refresh les datas avec un deltaT
	}

    return (0);
}
