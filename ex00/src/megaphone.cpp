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
#include <string>

static void	print_str_default()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}

static std::string	to_upper_str(std::string str)
{
	std::string::size_type str_size = str.size();
	for (std::string::size_type i = 0; i < str_size; ++i) {
		str[i] = toupper(str[i]);
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
