/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:09:23 by amhernandez       #+#    #+#             */
/*   Updated: 2025/03/16 20:09:26 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_env(const char **env)
{
	char	**env_array;

	if (!env)
		return (NULL);
	env_array = NULL;
	while (*env)
	{
		ft_append_array((void ***)&env_array, ft_strdup(*env++));
		if (!env_array)
			break ;
	}
	return (env_array);
}

char	*ft_getenv(const char *name, char **env)
{
	size_t	len;

	if (!name || !env)
		return (NULL);
	len = ft_strlen(name);
	while (*env)
	{
		if (ft_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
		env++;
	}
	return (NULL);
}

int	ft_unsetenv(const char *name, char ***env)
{
	char	**current;
	size_t	len;
	char	**end;
	size_t	remaining;

	if (!name || !env || !*env)
		return (0);
	len = ft_strlen(name);
	current = *env;
	while (*current)
	{
		if (ft_strncmp(*current, name, len) == 0 && (*current)[len] == '=')
		{
			free(*current);
			end = current;
			while (*end)
				end++;
			remaining = end - current;
			ft_memmove(current, current + 1, sizeof(char *) * remaining);
			return (1);
		}
		current++;
	}
	return (0);
}

int	ft_setenv(const char *name, const char *value, char ***env)
{
	char	*new_var;

	if (!name || !value || !env)
		return (0);
	new_var = ft_strjoin(name, "=");
	if (!new_var)
		return (0);
	new_var = ft_strappend(new_var, value);
	if (!new_var)
		return (0);
	ft_unsetenv(name, env);
	ft_append_array((void ***)env, ft_strdup(new_var));
	free(new_var);
	if (!ft_getenv(name, *env))
		return (0);
	return (1);
}
