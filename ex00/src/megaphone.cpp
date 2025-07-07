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

static void	print_error(std::string message)
{
	std::cerr << "Error " + message + '\n';
}

static void	print_str_default()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}

static bool	is_max_int(int i)
{
	if (i == std::numeric_limits<int>::max())
		return (true);
	else
		return (false);
}

static char	*to_upper_str(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (is_max_int(i))
		{
			print_error("string is too big");
			return (NULL);
		}
		str[i] = toupper(str[i]);
		++i;
	}
	return (str);
}

static int	print_str_upper(char *str)
{
	str = to_upper_str(str);
	if (!str)
		return (-1);
	std::cout << str;
	return (0);
}

int	main(int argc, char *argv[])
{
	if (is_max_int(argc))
	{
		print_error("too much arguments");
		return (-1);
	}
	else if (argc == 1)
	{
		print_str_default();
	}
	else
	{
		for (int i = 1; argv[i]; ++i)
		{
			if (print_str_upper(argv[i]) == -1)
				return (-1);
		}
		std::cout << '\n';
	}
	return (0);
}
