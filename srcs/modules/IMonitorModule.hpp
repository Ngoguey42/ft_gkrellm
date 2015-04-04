// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 17:42:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 09:27:48 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

// # include <string>
# include <iostream>
//# include <stdexcept>
# include <Vector>

namespace ft
{
class IMonitorModule
{
public:
	IMonitorModule();
	virtual ~IMonitorModule();

	virtual void					refresh_datas(void) = 0;
	virtual std::string const			&getModuleName(void) const = 0;
	virtual std::vector<std::string>const	&getStrings(void) const = 0;
	
protected:
private:
	IMonitorModule(IMonitorModule const &src);
	IMonitorModule				&operator=(IMonitorModule const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, IMonitorModule const &rhs);
}

#endif // ************************************************ IMONITORMODULE_HPP //
