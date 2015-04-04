// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetworkModule.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:37:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class NetworkModule : public IMonitorModule
{
public:
	NetworkModule(std::string const &moduleName);
	virtual ~NetworkModule();
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	NetworkModule();
	NetworkModule(NetworkModule const &src);
	NetworkModule					&operator=(NetworkModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	
};
//std::ostream					&operator<<(std::ostream &o, NetworkModule const &rhs);
}

#endif // ************************************************* NETWORKMODULE_HPP //
