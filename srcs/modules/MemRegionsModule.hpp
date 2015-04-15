// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MemRegionsModule.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:01 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 15:00:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MEMREGIONSMODULE_HPP
# define MEMREGIONSMODULE_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class MemRegionsModule : public IMonitorModule
{
public:
	MemRegionsModule(std::string const &moduleName);
	virtual ~MemRegionsModule();

	static std::string          datas[3];
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	MemRegionsModule();
	MemRegionsModule(MemRegionsModule const &src);
	MemRegionsModule					&operator=(MemRegionsModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	
};
}

#endif // ********************************************** MEMREGIONSMODULE_HPP //
