/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:20:42 by juportie          #+#    #+#             */
/*   Updated: 2025/07/06 12:33:14 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_str_default()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}

static std::string	to_upper_str(std::string str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); ++i) {
		*i = toupper(*i);
	}
	return (str);
}

static void	print_str_upper(std::string str)
{
	std::cout << to_upper_str(str);
}

int	main(int argc, char** argv)
{
	if (argc == 1) {
		print_str_default();
	}
	else {
		for (int i = 1; argv[i]; ++i) {
			print_str_upper(std::string(argv[i]));
		}
		std::cout << '\n';
	}
	return (0);
}
