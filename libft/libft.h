/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:57:01 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/18 15:40:22 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "printf.h"

//structs
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//linked lists
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);

//ints
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
int	long	ft_atol(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_arrlen(char **arr);
int		ft_lstsize(t_list *lst);
int		ft_printarr(char **arr);
int		ft_addprintarr(char *print, char **arr);
int		ft_arr_srch(char *str, char **arr);
//chars
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_locate_str(char *str, char **arr);
char	*rev_strchr(char *str, int c);
char	**ft_split(char *s, char c);
char	**ft_cpyarr(char **arr);
char	*ft_joinstrjoin(char *left, char *middle, char *right);
char	**ft_addarr(char *str, char **arr);
char	**ft_subarr(char *str, char **old_arr);
char	**ft_srchrarr(char *fnd, char **old_arr, char *rplc);
//voids
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_realloc(void *ptr, size_t size);
void	ft_farray(char	**arr);
void	ft_lstadd_front(t_list **lst, t_list *newnode);
// void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif
