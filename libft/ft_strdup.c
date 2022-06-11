/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:39:23 by alyasar           #+#    #+#             */
/*   Updated: 2022/01/06 14:39:25 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
