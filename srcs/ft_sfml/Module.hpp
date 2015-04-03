// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Module.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:09:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:52:44 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MODULE_HPP
# define MODULE_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
# include <SFML/Graphics.hpp>

# include <ft_gkrellm.hpp>
# include <modules/IMonitorModule.hpp>

# include <ft_sfml/RoundedBox.hpp>
# include <ft_sfml/DefaultTextBox.hpp>

namespace ftsf
{
class Module : public sf::Drawable
{
public:
	// * STATICS ******************** //
	static sf::Color const		titleColor;
	static sf::Color const		titleBorderColor;
	static sf::Color const		titleTextColor;
	static sf::Color const		mainColor;
	static sf::Color const		mainBorderColor;
	
	// * CTORS / DTORS ************** //
	virtual ~Module();

	// * MEMBER FUNCTIONS / METHODS * //
	virtual void                draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	virtual void                setPosition(const float x, const float y);
	virtual void                refresh_datas(void) = 0;
	
protected:
	Module(const sf::Vector2f &mainBoxSize);

	// * ATTRIBUTES ***************** //
	DefaultTextBox				topBox;
	RoundedBox					mainBox;

private:
	Module();
	Module(Module const &src);
	Module						&operator=(Module const &rhs);

};
//std::ostream					&operator<<(std::ostream &o, Module const &rhs);
}
#endif // ******************************************************** MODULE_HPP //
