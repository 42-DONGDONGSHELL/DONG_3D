#include "../../includes/render.h"

void	calc(t_info *info)
{
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; ++x)
		{
			// 바닥 색상 (여기서는 예시로 RGB 값을 사용)
			int floorColor = info->texture.f_hash;

			// 천장 색상 (예시로 RGB 값 사용)
			int ceilingColor = info->texture.c_hash;

			// 바닥 그리기
			info->buf[y][x] = floorColor;

			// 천장 그리기 (화면의 반대편)
			info->buf[HEIGHT - y - 1][x] = ceilingColor;
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
		int color = info->tex[texNum][TEX_HEIGHT * texY + texX];

		// Make color darker for y-sides: R, G, and B byte each divided through two with a "shift" and "and"
		if (side == 1)
			color = (color >> 1) & 8355711;

		// Put the pixel on the buffer
		info->buf[y][x] = color;
	}
}
}
