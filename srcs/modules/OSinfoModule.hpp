// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSinfoModule.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:38:49 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class OSinfoModule : public IMonitorModule
{
public:
	OSinfoModule(std::string const &moduleName);
	virtual ~OSinfoModule();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<float> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	
protected:
private:
	OSinfoModule();
	OSinfoModule(OSinfoModule const &src);
	OSinfoModule					&operator=(OSinfoModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;
	
};
}

#endif // ************************************************** OSINFOMODULE_HPP //
