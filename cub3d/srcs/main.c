/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:58 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:24:22 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;

	is_valid_arg(argc, argv);
	ft_memset(&info, 0, sizeof(info));
	read_cub_file(argv[1], &info);
	render(&info);
	free_all_resources(&info);
	return (0);
}
