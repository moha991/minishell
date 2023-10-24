/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:14:13 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/24 02:04:18 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minshell.h"


int main(int argc, char **argv) {
    
    
	if (!argv || argc != 1)
		return (EXIT_FAILURE);

    rl_initialize();
    run_shell();
    return (0);
}