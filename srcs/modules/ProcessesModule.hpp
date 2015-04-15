// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ProcessesModule.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:01 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 15:00:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PROCESSESMODULE_HPP
# define PROCESSESMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class ProcessesModule : public IMonitorModule
{
public:
	ProcessesModule(std::string const &moduleName);
	virtual ~ProcessesModule();

	static std::string          datas[3];
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	ProcessesModule();
	ProcessesModule(ProcessesModule const &src);
	ProcessesModule					&operator=(ProcessesModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	
};
//std::ostream				&operator<<(std::ostream &o, ProcessesModule const &rhs);
}

#endif // *********************************************** PROCESSESMODULE_HPP //
