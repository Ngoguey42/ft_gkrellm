// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_gkrellm.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:48:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 16:13:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <SFML/Graphics.hpp>

namespace ftsf
{
float					getStrWidth(sf::Text const &ref);
float					getStrHeight(sf::Text const &ref);

class RoundedBox;
class DefaultTextBox;
class Background;
extern sf::Font			Arial;
}

#endif // **************************************************** FT_GKRELLM_HPP //
