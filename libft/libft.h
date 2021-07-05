/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:13:12 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/05 19:35:11 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE	(1)

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_file_extension(char *file, char *ext);
int			get_next_line(int const fd, char **line);
char		*ft_program_name(char const *argv0);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcut(const char *str, char c);
char		*ft_strrchr(const char *s, int c);
char		*ft_remove_extension(char *filename);
char		**ft_strsplit(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *s, int c);
void		ft_putstr(char const *s);
void		ft_puterror(char *msg, int ret);
void		ft_putendl(char const *s);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif
