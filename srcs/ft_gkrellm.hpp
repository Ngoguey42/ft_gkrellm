// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_gkrellm.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:48:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 11:40:56 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <pthread.h>
# include <SFML/Graphics.hpp>

namespace ft
{
class IMonitorDisplay;

class IMonitorModule;
class Data;

struct							threadDatas
{
	pthread_mutexattr_t			mutex_attr;
	pthread_mutex_t				mutex;
	pthread_t					tid;
	std::vector<IMonitorModule>	*modules;
};
}

namespace ftsf
{
extern sf::Font			Arial;

float					getStrWidth(sf::Text const &ref);
float					getStrHeight(sf::Text const &ref);

class RoundedBox;
class DefaultTextBox;
class Background;
class Module;
}

#endif // **************************************************** FT_GKRELLM_HPP //
