#include "../includes/cub3d.h"

void	print_identifier_info(t_info *info)
{
	printf("================[IDENTIFIER INFO]================\n");
	printf("e_p = %s\n", info->texture.e_p);
	printf("w_p = %s\n", info->texture.w_p);
	printf("s_p = %s\n", info->texture.s_p);
	printf("n_p = %s\n", info->texture.n_p);
	printf("c_rgb = %d, %d, %d\n", info->texture.c_rgb[0], info->texture.c_rgb[1], info->texture.c_rgb[2]);
	printf("f_rgb = %d, %d, %d\n", info->texture.f_rgb[0], info->texture.f_rgb[1], info->texture.f_rgb[2]);
	printf("==============[IDENTIFIER INFO DONE]==============\n");
}

void print_map(t_info *info)
{
	printf("====================[MAP INFO]====================\n");
	printf("map_height = %d\n", info->map_height);
	printf("map_width = %d\n", info->map_width);
	for (int i = 0; i < info->map_height; i++) {
		for (int j = 0; j < info->map_width; j++) {
			printf("%d", info->map_info[i][j]);
		}
		printf("\n");
	}
	printf("==================[MAP INFO DONE]==================\n");
}

void print_xy(t_info *info)
{
	printf("====================[XYs INFO]====================\n");
	printf("My loc :: x = %f, y = %f\n", info->loc.x, info->loc.y);
	printf("My dir :: x = %f, y = %f\n", info->dir.x, info->dir.y);
	printf("Plane :: x = %f, y = %f\n", info->plane.x, info->plane.y);
	printf("==================[XYs INFO DONE]==================\n");
}

int	main(int argc, char **argv)
{
	t_info	info;

	is_valid_arg(argc, argv);
	ft_memset(&info, 0, sizeof(info));
	read_cub_file(argv[1], &info);
	print_identifier_info(&info);
	print_map(&info);
	print_xy(&info);
	/**
	 * 1. argument가 valid한지 확인. -> is_valid_arg();
	 * 2. 구조체 초기화. -> ft_memset();
	 * 3. argument로 들어온 파일 읽어 구조체 완성시키기. -> read_cub_file(); -> get_next_line을 이용하여 체우기
	 * 4. Map이 valid한지 확인하기. -> is_valid_map();
	 */
	return (0);
}
