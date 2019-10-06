/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:46:40 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/24 13:43:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include <string.h>
# include "libft.h"

/*
** Defining speces
*/

# define S_CHAR 'c'
# define S_STRING 's'
# define S_POINTER 'p'
# define S_PERCENT '%'
# define S_DECIMAL 'd'
# define S_INTEGER 'i'
# define S_OCTAL 'o'
# define S_HEX 'x'
# define S_BHEX 'X'
# define S_UNSIGNED 'u'
# define S_UNSIGNEDL 'U'
# define S_FLOAT 'f'

/*
** defining format flags
*/

# define F_MINUS (1 << 0)
# define F_ZERO (1 << 1)
# define F_PLUS (1 << 2)
# define F_SHARP (1 << 3)
# define F_SPACE (1 << 4)

/*
** defining length flags
*/

# define F_HH (1 << 5)
# define F_H (1 << 6)
# define F_L (1 << 7)
# define F_LL (1 << 8)
# define F_J (1 << 9)
# define F_Z (1 << 10)
# define F_BL (1 << 11)

typedef struct			s_token
{
	char				spec;
	char				width;
	char				precision;
	int					flags;
}						t_token;

typedef struct			s_string
{
	char				*data;
	int					size;
	int					capacity;
}						t_string;

typedef struct			s_bignum
{
	char				sign;
	t_string			*int_part;
	t_string			*frac_part;
}						t_bignum;

union
{
	long double			d_num;
	struct				s_double
	{
		__uint128_t		mantissa:64;
		__uint128_t		exponent:15;
		__uint128_t		sign:1;
	}					t_double;
}						t;

typedef struct			s_doubled
{
	char				sign;
	int					exponent;
	char				*mantissa;
}						t_doubled;

int						do_tok(const char *form, va_list vargs, int *i);
int						print_num(char *str, t_token *token, int sign);

/*
**	PRINT
*/

int						print_dec(long long int n, t_token *token);
int						print_pointer(unsigned long long int p, t_token *token);
int						print_char(char c, t_token *token);
int						print_string(char *ap, t_token *token);
int						print_octal(size_t n, t_token *token);
int						print_hex(size_t n, t_token *token);
int						print_unsigned(unsigned long long u, t_token *token);
int						default_float(t_token *list, double arg);
t_bignum				*get_the_bits(long double arg);
t_bignum				*big_num_create(void);
t_string				*str_create_size(int size);
void					str_pushchar(t_string *s, char c);
void					str_resize(t_string *s, int new_size);
void					pos_pow(t_bignum **n, int power,
							t_bignum *(*f)(t_bignum *));
void					big_num_destroy(t_bignum **num);
void					str_destroy(t_string **s);
void					str_clean(t_string **s);
t_bignum				*bin_div(t_bignum *l);
t_bignum				*bin_mult(t_bignum *l);
t_string				*str_cut(t_string *str, int start, int end);
void					str_push_cs(t_string *l, t_string *r);
char					str_at(t_string *s, int idx);
void					bin_to_dec(t_bignum *num);
void					do_int_part(t_bignum *num);
t_bignum				*big_num_create_by_str(char sign, char *int_part,
						char *frac_part);
t_string				*str_create_str(char *s);
t_bignum				*dec_sum(t_bignum *l, t_bignum *r, int n);
t_bignum				*dec_mult(t_bignum *n);
char					frac_sum(t_string *l, t_string *r,
							t_string *res);
void					int_sum(t_string *l, t_string *r,
							t_string *res, char rem);
char					frac_dec_mult(t_string *n, t_string *res);
void					swap_comp_str(t_string *s1, t_string *s2);
void					str_rev(t_string *s);
void					do_frac_part(t_bignum *num);
t_bignum				*dec_div(t_bignum *n);
int						find_digit(t_string *s, int start);
void					put_zeros(int precision, t_string *str);
char					*put_bignum_strings_into_one(t_bignum *num,
							t_token *lst);
char					*cust_strjoin_left(t_string *s1, char *s2);
char					*cust_strdup(t_string *src);
char					*ft_strjoin_free(char *s1, char *s2, int n);
void					add_sign_float(char sign, char **str, t_token *lst);
void					add_sign(char **str, char sign);
void					width_insert(t_token *list, char **substr);
void					width_insert_left(char **new_str, char *substr,\
							int width, char c);
void					width_insert_right(char **new_str, char *substr,\
							int width, char c);
char					del_minus(char **str);
int						str_len(t_string *s);
void					int_dec_mult(t_string *n, t_string *res, char rem);
int						long_float(t_token *list, long double arg);
int						parce_tok_float(t_token token, va_list vargs);
void					rround(t_bignum **num, int precision);
char					*round_dbl(char **s, int p);
int						print_double(double n, t_token *tok);
char					*dbl_to_str(double d);
char					*get_frac_from_bin(char *s);
char					*get_int_from_bin(char *s);
char					*str_add_fraction(char **s1, char *s2);
char					*str_add_int(char **s1, char *s2, int flag);
char					*str_div2(char **str);

/*
**	Helper funcs
*/

int						print_without_flag(char *str, int w, int p, char c);
int						print_with_flag(char *str, int w, int p, char c);
char					*ft_strjoinnch(char *str, char c, int n);
size_t					cast_to_flag(size_t n, t_token *tok);
int						check_for_kostyl(long double n);
int						kostyl(long double n, t_token *tok);

#endif
