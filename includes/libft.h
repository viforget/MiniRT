/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:47:05 by viforget          #+#    #+#             */
/*   Updated: 2020/10/15 23:41:50 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif

/*
**	VOID
*/

void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar(char c);
void				ft_putendl(char *s);
void				ft_putnbr(int n);

/*
**	VOID *
*/

void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_freeutab(char **tab);
void				ft_freetab(char **tab, int h);

/*
**	CHAR * 
*/

char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size, char c);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_to_up(char *src);

/*
** CHAR **
*/

char				**ft_split(char const *s, char c);
char				**ft_settab(int x, int y);

/*
**	INT
*/

int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
**	SIZE_T
*/

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *restrict dst, const char *restrict src,
		size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_putstr(char *s);

/*
** BONUS
*/

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**	VOID
*/

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *elem));

/*
**	INT
*/

int					ft_lstsize(t_list *lst);

/*
** T_LIST *
*/

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void const *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));

#endif
