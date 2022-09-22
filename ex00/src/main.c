/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:58:15 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/22 18:00:02 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/bitmap.h"

int	main(void)
{
	t_file_header	bitmap_header;
	t_info_header	bitmap_info_header;
	FILE			*fp;
	FILE			*wfp;
	unsigned char	*buf;
	size_t			buf_size;
	int				height;
	size_t			i;
	unsigned char	tempColor;


	height = 0;
	safe_open("./img/ex00_color.bmp", &fp);
	fread(&bitmap_header, sizeof(t_file_header), 1, fp);
	if (bitmap_header.bf_type != 0x4D42) // check bitmap file
	{
		fclose(fp);
		return (1);
	}
	fread(&bitmap_info_header, sizeof(t_info_header), 1, fp);
	buf_size = sizeof(unsigned char) * bitmap_info_header.bi_width * bitmap_info_header.bi_height * 3;
	buf = (unsigned char *)safe_malloc(buf_size);
	while (height < bitmap_info_header.bi_height)
	{
		fread(buf + bitmap_info_header.bi_width * 3 * height, bitmap_info_header.bi_width, 3, fp);
		height++;
	}
	fclose(fp);
	i = 0;
	while (i < buf_size)
	{
		tempColor = buf[i];
		buf[i] = buf[i + 2];
		buf[i + 2] = tempColor;
		i += STEP;
	}
	wfp = fopen("test.bmp", "w");
	fwrite(&bitmap_header, sizeof(t_file_header), 1, wfp);
	fwrite(&bitmap_info_header, sizeof(t_info_header), 1, wfp);
	fwrite(buf, buf_size, 3, wfp);
	fclose(wfp);
	return(0);
}