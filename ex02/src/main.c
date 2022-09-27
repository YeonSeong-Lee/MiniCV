/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhoki <seonhoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:58:15 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/27 20:04:05 by seonhoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/bitmap.h"

void	ft_swap_char(unsigned char *a, unsigned char *b)
{
	unsigned char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap(unsigned char *a, unsigned char *b)
{
	unsigned char	temp;
	unsigned char	temp2;
	unsigned char	temp3;

	temp = a[0];
	temp2 = a[1];
	temp3 = a[2];

	a[0] = b[0];
	a[1] = b[1];
	a[2] = b[2];
	b[0] = temp;
	b[1] = temp2;
	b[2] = temp3;
}

int	main(void)
{
	t_file_header	bh;
	t_info_header	bih;
	FILE			*fp;
	FILE			*wfp;
	unsigned char	*buf;
	size_t			buf_size;
	unsigned char	*new_buf;
	int				h;
	int				w;
	int				zh;
	int				zw;
	int				i;
	unsigned char	temp_pixel;


	h = 0;
	safe_open("./img/ex01_reversal.bmp", &fp);
	fread(&bh, sizeof(t_file_header), 1, fp);
	if (bh.bf_type != 0x4D42) // check bitmap file
	{
		fclose(fp);
		return (1);
	}
	fread(&bih, sizeof(t_info_header), 1, fp);
	buf_size = sizeof(unsigned char) * bih.bi_width * bih.bi_height * 3;
	printf("%zu\n", buf_size);
	buf = (unsigned char *)safe_malloc(buf_size);
	new_buf = (unsigned char *)safe_malloc(buf_size);
	while (h < bih.bi_height)
	{
		fread(buf + bih.bi_width * 3 * h, bih.bi_width, 3, fp);
		h++;
	}
	fclose(fp);
	wfp = fopen("test.bmp", "w");
	fwrite(&bh, sizeof(t_file_header), 1, wfp);
	fwrite(&bih, sizeof(t_info_header), 1, wfp);
	i = 84;
	memset(new_buf + 84, 255, buf_size);
	//zoom
	h = 0;
	zh = 0;
	while (h < bih.bi_height)
	{
		w = 0;
		zw = 0;
		while (w < bih.bi_width)
		{
			int j = 0;
			while (j < 3)
			{
				char temp = buf[i + (bih.bi_width * 3 * h) + w * 3 + j];
				new_buf[i + (bih.bi_width * 3 * zh) + zw * 3 + j] = temp;
				new_buf[i + (bih.bi_width * 3 * zh) + (zw + 1) * 3 + j] = temp;
				j++;
			}
			w += 1;
			zw += 2;
		}
		w = 0;
		zw = 0;
		zh += 1;
		while (w < bih.bi_width)
		{
			int j = 0;
			while (j < 3)
			{
				char temp = buf[i + (bih.bi_width * 3 * h) + w * 3 + j];
				new_buf[i + (bih.bi_width * 3 * zh) + zw * 3 + j] = temp;
				new_buf[i + (bih.bi_width * 3 * zh) + (zw + 1) * 3 + j] = temp;
				j++;
			}
			w += 1;
			zw += 2;
		}
		h++;
		zh += 1;
	}
	
	fwrite(new_buf, bih.bi_size_image, 3, wfp);
	fclose(wfp);
	return(0);
}
