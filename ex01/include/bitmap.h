/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:23:34 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/22 17:58:02 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

#ifndef STEP 
# define STEP 3
#endif
typedef struct s_file_header
{
	unsigned short		bf_type;
	unsigned int		bf_size;
	unsigned short		bf_reserved1;
	unsigned short		bf_reserved2;
	unsigned int		bf_off_bits;
}				t_file_header;

typedef struct s_info_header
{
	unsigned int		bi_size;
	int					bi_width;
	int					bi_height;
	unsigned short		bi_planes;
	unsigned short		bi_bit_count;
	unsigned int		bi_compression;
	unsigned int		bi_size_image;
	int					bi_x_pels_per_meter;
	int					bi_y_pels_per_meter;
	unsigned int		bi_clr_used;
	unsigned int		bi_clr_important;
}				t_info_header;

void	safe_open(char *path, FILE **fp);
void	*safe_malloc(size_t size);

#endif