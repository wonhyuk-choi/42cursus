/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:33:51 by wonchoi           #+#    #+#             */
/*   Updated: 2022/05/18 18:05:52 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{

		}
		else if (cmd == "SEARCH")
		{

		}
		else if (cmd == "EXIT")
		{
			return (0);
		}
		else
			std::cout << "TRY ADD / SEARCH / EXIT! DO NOT ANY CMD!" << std::endl;
	}
	return (0);
}