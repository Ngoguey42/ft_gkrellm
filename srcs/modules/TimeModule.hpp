// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 09:00:52 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class TimeModule : public IMonitorModule
{
public:
	TimeModule(std::string const &moduleName);
	virtual ~TimeModule();
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	TimeModule();
	TimeModule(TimeModule const &src);
	TimeModule					&operator=(TimeModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	
};
//std::ostream					&operator<<(std::ostream &o, TimeModule const &rhs);
}

#endif // **************************************************** TIMEMODULE_HPP //
