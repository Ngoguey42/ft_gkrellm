// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_gkrellm.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:48:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 13:33:53 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <SFML/Graphics.hpp>
# include <IMonitorDisplay.hpp>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class IMonitorDisplay;
class IMonitorModule;
}

namespace ftsf
{
extern sf::Font			Arial;

float					getStrWidth(sf::Text const &ref);
float					getStrHeight(sf::Text const &ref);
float					getStrHeight(std::string const &ref);

class RoundedBox;
class DefaultTextBox;
class Background;
class Module;
}

#endif // **************************************************** FT_GKRELLM_HPP //
