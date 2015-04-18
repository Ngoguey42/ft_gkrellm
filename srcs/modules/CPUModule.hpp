// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:01 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/18 15:31:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <deque>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class CPUModule : public IMonitorModule
{
public:
	CPUModule(std::string const &moduleName);
	virtual ~CPUModule();

	static std::string          datas[3];
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	CPUModule();
	CPUModule(CPUModule const &src);
	CPUModule					&operator=(CPUModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;
	
};
//std::ostream					&operator<<(std::ostream &o, CPUModule const &rhs);
}

#endif // ***************************************************** CPUMODULE_HPP //
