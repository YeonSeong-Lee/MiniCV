/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:58:15 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/22 20:50:59 by seongyle         ###   ########seoul.kr  */
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
	t_file_header	bitmap_header;
	t_info_header	bitmap_info_header;
	FILE			*fp;
	FILE			*wfp;
	unsigned char	*buf;
	size_t			buf_size;
	unsigned char	*new_buf;
	int				height;
	int				width;
	int				i;
	unsigned char	temp_pixel;


	height = 0;
	safe_open("./img/ex01_reversal.bmp", &fp);
	fread(&bitmap_header, sizeof(t_file_header), 1, fp);
	if (bitmap_header.bf_type != 0x4D42) // check bitmap file
	{
		fclose(fp);
		return (1);
	}
	fread(&bitmap_info_header, sizeof(t_info_header), 1, fp);
	buf_size = sizeof(unsigned char) * bitmap_info_header.bi_width * bitmap_info_header.bi_height * 3;
	buf = (unsigned char *)safe_malloc(buf_size);
	new_buf = (unsigned char *)safe_malloc(buf_size);
	while (height < bitmap_info_header.bi_height)
	{
		fread(buf + bitmap_info_header.bi_width * 3 * height, bitmap_info_header.bi_width, 3, fp);
		height++;
	}
	fclose(fp);
	i = 0;
	while (i < buf_size)
	{
		new_buf[i] = buf[i];
		i++;
	}

	wfp = fopen("test.bmp", "w");
	fwrite(&bitmap_header, sizeof(t_file_header), 1, wfp);
	fwrite(&bitmap_info_header, sizeof(t_info_header), 1, wfp);
	fwrite(buf, buf_size, 3, wfp);
	fclose(wfp);
	return(0);
}
