/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:10:21 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 02:38:30 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 1

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void	lst_add_back(t_list **lst, t_list *new);
void	lst_add_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **head);
void	put_index(t_list *list);
void	push_four(t_list **head, t_list **b);
void	push_five(t_list **head, t_list **b);
void	ft_push(t_list **head1, t_list **head2, char c);
void	ft_rev_rotate(t_list **head, char c);
void	rev_rotate_x(t_list **head1, t_list **head2, char c);
void	ft_rotate(t_list **head1, char c);
void	rotate_x(t_list **head1, t_list **head2, char c);
void	ft_swap(t_list **head, char c);
void	ft_swap_x(t_list **head1, t_list **head2);
void	ft_push_swap(t_list **a, t_list **b, int size);
void	push_to_a(t_list **a, t_list **b);
void	ft_cut(t_list **a, t_list **b);
void	re_push(t_list **a, t_list **b, int index);
void	push_tree(t_list **head);
void	stock_a(t_list **a, int ac, char **av);
int		check_args(char **av);

t_list	*ft_lstnew(int content);
t_list	*lst_last(t_list *lst);

int		p_min(t_list **a);
int		ft_atoi(char *str);
int		check_do(t_list *list);
int		ft_lstsize(t_list *lst);
int		sort_max(t_list *list);
int		pos_nb(t_list **b, int index);
int		ft_nb_inst(int len, int pos);
int		susb(char **av);

char	**ft_split(char const *s, char sep);
char	**ft_free_tab(char **str);
// BONUS
size_t	ft_strlen(char const *s);

int		ft_strcmp(char *s1, char *s2);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);

void	*ft_calloc(size_t count, size_t n);
void	ft_read_it(t_list **a, t_list **b);
void	ft_verify(t_list **a, t_list **b, char *str);

#endif