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

#include <limits>
#include <iostream>

static bool	is_max_int(int i)
{
	if (i == std::numeric_limits<int>::max())
		return (true);
	else
		return (false);
}

static void	print_str_default()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

static char	*to_upper_str(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (is_max_int(i))
			throw std::string("string too big");
		str[i] = toupper(str[i]);
		++i;
	}
	return (str);
}

static void	print_str_upper(char *str)
{
	std::cout << to_upper_str(str);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		print_str_default();
	else {
		for (int i = 1; argv[i]; ++i) {
			try {
				print_str_upper(argv[i]);
			}
			catch (std::string message) {
				std::cout << "error " + message;
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
