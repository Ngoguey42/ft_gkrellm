// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AModule.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 17:43:39 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 19:18:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMODULE_HPP
# define AMODULE_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
# include <ft_gkrellm.hpp>
# include <RoundedBox.hpp>
# include <DefaultTextBox.hpp>
# include <IMonitorModule.hpp>
# include <SFML/Graphics.hpp>

namespace ftsf
{
class AModule : public IMonitorModule, public sf::Drawable
{
public:
	// * STATICS ******************** //
	static sf::Color const		titleColor;
	static sf::Color const		titleBorderColor;
	static sf::Color const		titleTextColor;
	static sf::Color const		mainColor;
	static sf::Color const		mainBorderColor;
	
	// * CTORS / DTORS ************** //
	virtual ~AModule();

	// * MEMBER FUNCTIONS / METHODS * //
	virtual void                draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	virtual void                setPosition(const float x, const float y);
	virtual void                refresh_datas(void) = 0;
	
protected:
	AModule(const sf::Vector2f &mainBoxSize);

	// * ATTRIBUTES ***************** //
	DefaultTextBox				topBox;
	RoundedBox					mainBox;

private:
	AModule();
	AModule(AModule const &src);
	AModule						&operator=(AModule const &rhs);

};
//std::ostream					&operator<<(std::ostream &o, AModule const &rhs);
}
#endif // ******************************************************* AMODULE_HPP //
