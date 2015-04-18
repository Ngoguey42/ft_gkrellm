// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostnameModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:35:23 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class HostnameModule : public IMonitorModule
{
public:
	HostnameModule(std::string const &moduleName);
	virtual ~HostnameModule();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<float> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	
protected:
private:
	HostnameModule();
	HostnameModule(HostnameModule const &src);
	HostnameModule					&operator=(HostnameModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;
	
};
}

#endif // ****************************************************** HOSTNAME_HPP //
