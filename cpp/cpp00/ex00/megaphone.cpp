/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:20:33 by wonchoi           #+#    #+#             */
/*   Updated: 2022/05/06 15:02:24 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int     count;
	int		i;
    char    ch;

    count = 0;
    if (argc == 1)
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
    while (argv[++count])
    {
        i = 0;
        while (argv[count][i])
        {
            ch = (char)toupper(argv[count][i]);
            std::cout << ch;
			i++;
        }
        std::cout << " ";
    }
	std::cout << std::endl;
    return (0);
}