#include "../../includes/render.h"

/*   서
 * 북  남
 *   동
 */

void	key_update(t_info *info);

void	draw(t_info *info)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	for(int y = 0; y < HEIGHT; y++)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = info->dir.x - info->plane.x;
		float rayDirY0 = info->dir.y - info->plane.y;
		float rayDirX1 = info->dir.x + info->plane.x;
		float rayDirY1 = info->dir.y + info->plane.y;

		// Current y position compared to the center of the screen (the horizon)
		int p = y - HEIGHT / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * HEIGHT;

		// Horizontal distance from the camera to the floor for the current row.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WIDTH;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WIDTH;

		// real world coordinates of the leftmost column
		float floorX = info->loc.y + rowDistance * rayDirX0;
		float floorY = info->loc.y + rowDistance * rayDirY0;

		for(int x = 0; x < WIDTH; ++x)
		{
			// 단순 색상으로 덮기 위해 텍스처 좌표 계산 부분 삭제

			// 바닥 색상 (여기서는 예시로 RGB 값을 사용)
			int floorColor = 0x00FF00; // 초록색

			// 천장 색상 (예시로 RGB 값 사용)
			int ceilingColor = 0x0000FF; // 파란색

			// 바닥 그리기
			info->buf[y][x] = floorColor;

			// 천장 그리기 (화면의 반대편)
			info->buf[HEIGHT - y - 1][x] = ceilingColor;

			// 바닥 좌표 업데이트
			floorX += floorStepX;
			floorY += floorStepY;
		}
	}

// WALL CASTING
for(int x = 0; x < WIDTH; x++)
{
	double cameraX = 2 * x / (double)WIDTH - 1;
	double rayDirX = info->dir.x + info->plane.x * cameraX;
	double rayDirY = info->dir.y + info->plane.y * cameraX;

	int mapX = (int)info->loc.x;
	int mapY = (int)info->loc.y;

	// length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;

	// length of ray from one x or y-side to next x or y-side
	double deltaDistX = fabs(1 / rayDirX);
	double deltaDistY = fabs(1 / rayDirY);
	double perpWallDist;

	// what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

	int hit = 0; // was there a wall hit?
	int side;    // was a NS or an EW wall hit?

	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (info->loc.x - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - info->loc.x) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (info->loc.y - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - info->loc.y) * deltaDistY;
	}

	// Perform DDA (Digital Differential Analysis)
	while (hit == 0)
	{
		// jump to next map square, OR in x-direction, OR in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0; // x-axis wall hit
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1; // y-axis wall hit
		}
		// Check if ray has hit a wall
		if (info->map_info[mapX][mapY] > 0) hit = 1;
	}

	// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect)
	if (side == 0)
		perpWallDist = (mapX - info->loc.x + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (mapY - info->loc.y + (1 - stepY) / 2) / rayDirY;

	// Calculate height of line to draw on screen
	int lineHeight = (int)(HEIGHT / perpWallDist);

	// Calculate lowest and highest pixel to fill in current stripe
	int drawStart = -lineHeight / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;

	// Determine textures based on wall direction (N/S/E/W)
	int texNum;
	if (side == 0) // x-axis wall hit (East-West)
	{
		if (rayDirX > 0) // West to East (East wall)
			texNum = 3;
		else // East to West (West wall)
			texNum = 2;
	}
	else // y-axis wall hit (North-South)
	{
		if (rayDirY > 0) // North to South (South wall)
			texNum = 1;
		else // South to North (North wall)
			texNum = 0;
	}

	// Calculate value of wallX
	double wallX;
	if (side == 0)
		wallX = info->loc.y + perpWallDist * rayDirY;
	else
		wallX = info->loc.x + perpWallDist * rayDirX;
	wallX -= floor(wallX);

	// x coordinate on the textures
	int texX = (int)(wallX * (double)TEX_WIDTH);
	if (side == 0 && rayDirX > 0)
		texX = TEX_WIDTH - texX - 1;
	if (side == 1 && rayDirY < 0)
		texX = TEX_WIDTH - texX - 1;

	// How much to increase the textures coordinate per screen pixel
	double step = 1.0 * TEX_HEIGHT / lineHeight;

	// Starting textures coordinate
	double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;

	// Draw the wall stripe
	for (int y = drawStart; y < drawEnd; y++)
	{
		// Cast the textures coordinate to integer, and mask with (TEX_HEIGHT - 1) in case of overflow
		int texY = (int)texPos & (TEX_HEIGHT - 1);
		texPos += step;

		// Get the color from the textures
		int color = info->textures[texNum][TEX_HEIGHT * texY + texX];

		// Make color darker for y-sides: R, G, and B byte each divided through two with a "shift" and "and"
		if (side == 1)
			color = (color >> 1) & 8355711;

		// Put the pixel on the buffer
		info->buf[y][x] = color;
	}
}

}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

void	key_update(t_info *info)
{
	if (info->key_w)
	{
		if (!info->map_info[(int)(info->loc.x + info->dir.x * info->moveSpeed)][(int)(info->loc.y)])
			info->loc.x += info->dir.x * info->moveSpeed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y + info->dir.y * info->moveSpeed)])
			info->loc.y += info->dir.y * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (info->key_s)
	{
		if (!info->map_info[(int)(info->loc.x - info->dir.x * info->moveSpeed)][(int)(info->loc.y)])
			info->loc.x -= info->dir.x * info->moveSpeed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y - info->dir.y * info->moveSpeed)])
			info->loc.y -= info->dir.y * info->moveSpeed;
	}
	if (info->key_d)
	{
		// move right by using the perpendicular direction
		double perpDirX = info->dir.y;
		double perpDirY = -info->dir.x;
		if (!info->map_info[(int)(info->loc.x + perpDirX * info->moveSpeed)][(int)(info->loc.y)])
			info->loc.x += perpDirX * info->moveSpeed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y + perpDirY * info->moveSpeed)])
			info->loc.y += perpDirY * info->moveSpeed;
	}
	// move left (A key)
	if (info->key_a)
	{
		// move left by using the perpendicular direction
		double perpDirX = info->dir.y;
		double perpDirY = -info->dir.x;
		if (!info->map_info[(int)(info->loc.x - perpDirX * info->moveSpeed)][(int)(info->loc.y)])
			info->loc.x -= perpDirX * info->moveSpeed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y - perpDirY * info->moveSpeed)])
			info->loc.y -= perpDirY * info->moveSpeed;
	}
	//rotate to the right
	if (info->key_right)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(-info->rotSpeed) - info->dir.y * sin(-info->rotSpeed);
		info->dir.y = oldDirX * sin(-info->rotSpeed) + info->dir.y * cos(-info->rotSpeed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(-info->rotSpeed) - info->plane.y * sin(-info->rotSpeed);
		info->plane.y = oldPlaneX * sin(-info->rotSpeed) + info->plane.y * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (info->key_left)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(info->rotSpeed) - info->dir.y * sin(info->rotSpeed);
		info->dir.y = oldDirX * sin(info->rotSpeed) + info->dir.y * cos(info->rotSpeed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(info->rotSpeed) - info->plane.y * sin(info->rotSpeed);
		info->plane.y = oldPlaneX * sin(info->rotSpeed) + info->plane.y * cos(info->rotSpeed);
	}
	if (info->key_esc)
		exit(0);
}

int		key_press(int key, t_info *info)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		info->key_w = 1;
	else if (key == A)
		info->key_a = 1;
	else if (key == S)
		info->key_s = 1;
	else if (key == D)
		info->key_d = 1;
	else if (key == L)
		info->key_left = 1;
	else if (key == R)
		info->key_right = 1;
	return (0);
}

int		key_release(int key, t_info *info)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		info->key_w = 0;
	else if (key == A)
		info->key_a = 0;
	else if (key == S)
		info->key_s = 0;
	else if (key == D)
		info->key_d = 0;
	else if (key == L)
		info->key_left = 0;
	else if (key == R)
		info->key_right = 0;

	return (0);
}

void	load_image(t_info *info, int *textures, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			textures[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->textures[0], info->texture.n_p, &img);
	load_image(info, info->textures[1], info->texture.s_p, &img);
	load_image(info, info->textures[2], info->texture.w_p, &img);
	load_image(info, info->textures[3], info->texture.e_p, &img);
}


int	render(t_info *info)
{
	info->mlx = mlx_init();
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_right = 0;
	info->key_left = 0;
	info->key_esc = 0;

	info->plane.x = 0.66;
	info->plane.y = 0;
	int tmp = info->loc.x;
	info->loc.x = info->loc.y;
	info->loc.y = tmp;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			info->buf[i][j] = 0;
		}
	}

	if (!(info->textures = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(info->textures[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEX_HEIGHT * TEX_WIDTH; j++)
		{
			info->textures[i][j] = 0;
		}
	}
	load_texture(info);
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;

	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");

	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, &key_release, info);
	mlx_loop(info->mlx);


	return (0);
}
