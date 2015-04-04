// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:40:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class RAMModule : public IMonitorModule
{
public:
	RAMModule(std::string const &moduleName);
	virtual ~RAMModule();
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	RAMModule();
	RAMModule(RAMModule const &src);
	RAMModule					&operator=(RAMModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	
};
//std::ostream					&operator<<(std::ostream &o, RAMModule const &rhs);
}

#endif // ***************************************************** RAMMODULE_HPP //
