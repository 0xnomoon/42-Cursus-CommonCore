/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 07:33:37 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/09 19:29:55 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H

# define CUBE3D_H

# define BUFFER_SIZE 32

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			*pos;
	char			*pos2;
	int				ret;
	int				fd_tp;
}					t_list;

typedef struct		s_sprite
{
	int				nbsp;
	double			**sp;
	double			spx;
	double			spy;
	double			indev;
	double			transformx;
	double			transformy;
	int				spsx;
	int				sph;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	int				spwidth;
	int				stripe;
	double			*zbuffer;
	int				i;
}					t_sprite;

typedef struct		s_fov
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			olddirx;
	char			orientation;
}					t_fov;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				*pix;
	void			*img;
}					t_mlx;

typedef struct		s_texture
{
	int				width;
	int				height;
	void			*img;
	int				*pix;
	int				bpp;
	int				size;
	int				endian;
	int				smallval;
}					t_texture;

typedef struct		s_key
{
	double			speed;
	int				front;
	int				back;
	int				rotl;
	int				rotr;
	int				mover;
	int				movel;
	int				sprint;
}					t_key;

typedef struct		s_stuff
{
	int				x;
	double			camerax;
	double			raydir_x;
	double			raydir_y;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			walldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				start;
	int				end;
	double			speed;
	double			rotspeed;
	double			oldplanex;
	int				texture_xn;
	int				texture_xs;
	int				texture_xw;
	int				texture_xe;
	int				texture_xsp;
	int				textx;
	double			wallx;
	double			texty;
}					t_stuff;

typedef struct		s_rgb
{
	int				g_r;
	int				g_g;
	int				g_b;
	int				s_r;
	int				s_g;
	int				s_b;
	int				skyhex;
	int				groundhex;
}					t_rgb;

typedef struct		s_map
{
	int				width;
	int				height;
	char			*pathno;
	char			*pathso;
	char			*pathwe;
	char			*pathea;
	char			*pathsprite;
	char			*ground;
	char			*skybox;
	char			**map;
	char			*mapcpy;
	char			*mapcpywithoutspace;
	int				firstaff;
	int				hud;
	char			*hudpath;
	int				screenshot;
	char			*rs;
	int				rscheck;
	t_key			key;
	t_mlx			data;
	t_fov			fov;
	t_stuff			stuff;
	t_rgb			rgb;
	t_sprite		sp;
	t_texture		texture;
	t_texture		dst_n;
	t_texture		dst_s;
	t_texture		dst_sp;
	t_texture		dst_w;
	t_texture		dst_e;
	t_texture		dst_hud;
}					t_map;

int					get_next_line(int fd, char **line);
int					rdline(char **line, char **str, t_list spl, char *buff);
int					checkerror_gnl(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*sdupfr(char *s1, size_t n);
char				*ft_sjoin_free(char const *dst, char const *src, size_t n);
size_t				ft_strlen(const char *str);
int					endofline(char **str, char *pos, char *pos2, char **line);
int					posnonull(char **line, char **str, char *buff, t_list spl);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char *str, char *charset);
int					ft_initvar(t_map *tab);
int					key_press(int keycode, t_map *tab);
int					key_release(int keycode, t_map *tab);
void				ft_window(t_map *tab);
int					parseletters(char *str, t_map *tab);
int					ft_parse(t_map *tab, int fd);
int					is_loopneeded(t_map *tab);
void				ft_calcray(t_map *tab);
void				ft_calcstepside(t_map *tab);
void				ft_hit(t_map *tab);
int					ft_loopgame(t_map *tab);
void				ft_draw(t_map *tab);
void				ft_move(t_map *tab);
void				ft_rotate(t_map *tab);
void				ft_hit(t_map *tab);
void				ft_distance(t_map *tab);
void				ft_rgbtohex(t_map *tab);
void				get_texture(t_map *tab);
void				get_texture_x(t_map *tab);
int					countsprite(t_map *tab);
void				ft_sortsprite(t_map *tab);
void				ft_rgbground(t_map *tab);
void				count_sprite(t_map *tab);
int					sp_malloc(t_map *tab);
void				ft_sortsp(t_map *tab);
void				sprite_draw_calc(t_map *tab);
void				exact_hit_pos(t_map *tab);
void				display_ray_gun(t_map *tab);
int					map_error(t_map *tab);
int					create_screenshot(t_map *tab);
int					create_bmp(t_map *tab);
unsigned char		*create_bitmap_header(int res_y, int res_x);
unsigned char		*create_file_header(int res_y, int res_x);
void				get_pixels(t_map *tab, int fd);
int					check_screenshot(char *str, t_map *tab);
int					ft_check_path(t_map *tab);
int					check_map(t_map *tab);
int					check_rgb(t_map *tab);
int					ft_error(t_map *tab);
int					check_mainmapfile(char *str);
int					ft_fix_text(t_map *tab);
int					whilespace(char *str);
int					whilenb(char *str);
int					checkfc(t_map *tab);
void				parseres(char *str, t_map *tab);
int					ft_exit(t_map *tab);
void				parse_path_error(char *str, t_map *tab);
int					checkspawn(t_map *tab);
int					uselessp1(t_map *tab, int x, int y);

#endif
