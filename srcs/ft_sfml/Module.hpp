// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Module.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:09:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 08:52:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MODULE_HPP
# define MODULE_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
# include <vector>
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
	Module(const sf::Vector2f &mainBoxSize,
		   ft::IMonitorModule const *refModule);
	virtual ~Module();

	// * MEMBER FUNCTIONS / METHODS * //
	virtual void                draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	virtual void                setPosition(const float x, const float y);
	
protected:
private:
	Module();
	Module(Module const &src);
	Module						&operator=(Module const &rhs);

	// * ATTRIBUTES ***************** //
	DefaultTextBox				_topBox;
	RoundedBox					_mainBox;
	ft::IMonitorModule const	*_refModule;
	std::vector<sf::Text*>		_stringsFrames;

};
//std::ostream					&operator<<(std::ostream &o, Module const &rhs);
}
#endif // ******************************************************** MODULE_HPP //
