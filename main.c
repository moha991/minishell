/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:04:21 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/16 12:35:59 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minshell.h"


int main() {
    rl_initialize();

    run_shell();

    return 0;
}