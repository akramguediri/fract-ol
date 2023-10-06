/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:14:38 by aguediri          #+#    #+#             */
/*   Updated: 2023/07/29 19:56:24 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

double	ft_atodigit(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	ft_atofraction(const char **str)
{
	double	result;
	double	power;

	result = 0.0;
	power = 1.0;
	(*str)++;
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		power *= 10.0;
		(*str)++;
	}
	return (result / power);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		f;

	result = 0.0;
	sign = 1.0;
	f = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	result = ft_atodigit(&str);
	if (*str == '.')
	{
		f = 1;
		result += ft_atofraction(&str);
	}
	return (result * sign);
}
