/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_network_adress.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 13:03:57 by okruitho       #+#    #+#                */
/*   Updated: 2020/01/19 23:08:32 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "ft_netwhat.h"

int				ft_print_host_ranges()
{
	printf("10.0.0.0 – 10.255.255.255\n");
	printf("172.16.0.0 – 172.31.255.255\n");
	printf("192.168.0.0 – 192.168.255.255\n");
	return (0);
}

unsigned int	ft_parse_ip(char *ip)
{
	unsigned int rval;
	int count;

	rval = 0;
	count = 0;
	while (count != 4)
	{
		rval = rval * 256 + atoi(ip);
		while (isdigit(*ip))
			ip++;
		ip++;
		count++;
	}
	
	
	return (rval);
}

char	*ft_strchr(const char *s, int c)
{
	int x;

	x = 0;
	while (s[0] != 0)
	{
		if (s[0] == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

int			ft_get_nadress(unsigned int ip, int mask)
{
	mask = 32 - mask - 1;
	while (mask != 0)
	{
		ip &= ~(1UL << mask);
		mask--;
	}
	ip &= ~(1UL << mask);
	printf("%u.%u.%u.%u\n",(ip >> (8*3)) & 0xff, (ip >> (8*2)) & 0xff,(ip >> (8*1)) & 0xff,(ip >> (8*0)) & 0xff);
	return (0);
}

int			ft_get_hostc(int mask)
{
	int val;

	val = pow(2 , (32 - mask)) - 2;
	printf ("available masks: %d\n", val);
	return (0);
}

int			ft_get_cidr(unsigned int ip)
{
	int				n;
	unsigned int	to_compare;

	to_compare = 0;
	n = 32;
	while (n != 0)
	{
		to_compare |= 1UL << n;
		if (to_compare == ip)
		{
			printf("CIDR:%d",32 - n);
			return (0);
		}
		n--;
	}
	return (0);
}

int			ft_get_hostr(unsigned int ip, int mask)
{
	int rm = 32 - mask - 1;

	while (rm > 0)
	{
		ip &= ~(1UL << rm);
		rm--;
	}
	ip |= 1UL << rm;
	printf("%u.%u.%u.%u - ",(ip >> (8*3)) & 0xff, (ip >> (8*2)) & 0xff,(ip >> (8*1)) & 0xff,(ip >> (8*0)) & 0xff);
	rm = 32 - mask - 1;
	while (rm > 0)
	{
		ip |= 1UL << rm;
		rm--;
	}
	ip &= ~(1UL << rm);
	printf("%u.%u.%u.%u\n",(ip >> (8*3)) & 0xff, (ip >> (8*2)) & 0xff,(ip >> (8*1)) & 0xff,(ip >> (8*0)) & 0xff);
	
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 4)
		return (0);

	unsigned int 	ip = ft_parse_ip(argv[1]);

	if (ft_strchr(argv[3], 'n'))
		return (ft_get_nadress(ip, atoi(argv[2])));
	if (ft_strchr(argv[3], 'h'))
		return (ft_get_hostc(atoi(argv[2])));
	if (ft_strchr(argv[3], 'c'))
		return (ft_get_cidr(ip));
	if (ft_strchr(argv[3], 'r'))
		return (ft_get_hostr(ip, atoi(argv[2])));
	if (ft_strchr(argv[3], 'p'))
		return (ft_print_host_ranges());
	return (0);
}
