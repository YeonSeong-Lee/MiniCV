/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:58:15 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/22 15:52:36 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/bitmap.h"

int	main(void)
{
	FILE	*fp;
	// char	ptr[1];
	// size_t	read_size;

	fp = fopen("../img/ex00_color.bmp", "r");
	if (!fp)
	{
		printf("Error!\n");
		return (1);
	}
	// printf("fp: %p\n", fp);
	// printf("ptr: %p\n", ptr);
	// read_size = fread(ptr, 1, 1, fp);
	// printf("rs=%lu\n", read_size);
	// printf("fp: %p\n", fp);
	// printf("ptr: %p\n", ptr);
	fclose(fp);
	return(0);
}