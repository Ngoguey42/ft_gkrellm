// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_gkrellm.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:48:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:10:49 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <SFML/Graphics.hpp>

namespace ft
{
class IMonitorModule;
class IMonitorDisplay;

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
