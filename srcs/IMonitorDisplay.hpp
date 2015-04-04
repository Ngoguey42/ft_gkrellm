// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 11:05:12 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 06:23:28 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>

namespace ft
{
class IMonitorDisplay
{
public:
	IMonitorDisplay();
	virtual ~IMonitorDisplay();

	virtual int					updateDisplay(void) = 0;
	
protected:
private:
	IMonitorDisplay(IMonitorDisplay const &src);
	IMonitorDisplay				&operator=(IMonitorDisplay const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, IMonitorDisplay const &rhs);
}
#endif // *********************************************** IMONITORDISPLAY_HPP //
