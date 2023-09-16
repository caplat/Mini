/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:19:17 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/16 12:17:14 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_b_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		print_tab(tab[i++]);
}

void free_big_tab(char ***tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free_arr(tab[i]);
		i++;
	}
	free(tab);
}

void remove_str_from_tab(char ***tab, int position)
{
    int length = find_length(*tab);
    char **newtab = malloc(sizeof(char *) * length);
    if (!newtab)
        return;

    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (i != position)
        {
            newtab[j] = strdup((*tab)[i]); // Utilisez strdup pour copier la chaîne
            j++;
        }
        else
        {
            free((*tab)[i]); // Libérez la mémoire de l'élément supprimé
        }
    }
    newtab[j] = NULL;

    free(*tab);  // Libérez le tableau original
    *tab = newtab;
}

// int find_position(char ***tab, char *element_to_find) 
// {
//     int i;
// 	int length; // Supposons que vous avez une fonction pour obtenir la longueur du tableau.

//     i = -1;
// 	length = find_length(*tab);
// 	while(++i < length) 
// 	{
//         if (ft_strncmp((*tab)[i], element_to_find,ft_strlen(element_to_find)) == 0) 
//             return i; // Retourne l'indice si l'élément est trouvé.
//     }
//     return -1; // Retourne -1 si l'élément n'est pas trouvé.
// }





