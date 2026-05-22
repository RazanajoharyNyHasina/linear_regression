/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarakoto <rarakoto@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 08:15:11 by rarakoto          #+#    #+#             */
/*   Updated: 2026/04/29 15:18:12 by rarakoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <libft.h>
#include <stdarg.h>
#ifndef FT_PRINTF_MAX_PRECISION_INTEGER
#define FT_PRINTF_MAX_TMP_BUFFER_SIZE 4096
#endif

typedef enum e_length_format
{
	UNDEFINED,
	H,
	HH,
	L,
	LL,
	Q,
	BIG_L,
	J,
	Z,
	T
} t_length_format;

typedef struct s_format_data
{
	char has_width;
	char has_precision;
	char has_variadic_width;
	char has_variadic_precision;
	char specifier;
	int hashtag;
	int zero;
	int minus;
	int space;
	int plus;
	int width;
	int precision;
	t_length_format length;
} t_format_data;

/* Print on the STDOUT_FILENO a formatted string.
 *
 * '%c' Prints a single character.
 * '%s' Prints a string (as defined by the common C convention).
 * '%p' The void * pointer argument has to be printed in hexadecimal format.
 * '%d' Prints a decimal (base 10) number.
 * '%i' Prints an integer in base 10.
 * '%u' Prints an unsigned decimal (base 10) number.
 * '%x' Prints a number in hexadecimal (base 16) lowercase format.
 * '%X' Prints a number in hexadecimal (base 16) uppercase format.
 * '%%' Prints a percent sign.
 *
 * #### Flags
 * \#  - The value should be converted to an "alternate form".  For o conversions, the first character of  the
 *       output string is made zero (by prefixing a 0 if it was not zero already).  For x and X conversions, a
 *       nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.  For a, A, e,  E,  f,
 *       F,  g, and G conversions, the result will always contain a decimal point, even if no digits follow it
 *       (normally, a decimal point appears in the results of those conversions only if a digit follows).  For
 *       g  and G conversions, trailing zeros are not removed from the result as they would otherwise be.  For
 *       other conversions, the result is undefined.
 * 0   - The value should be zero padded.  For d, i, o, u, x, X, a, A, e, E, f, F, g, and G  conversions,  the
 *       converted  value  is padded on the left with zeros rather than blanks.  If the 0 and - flags both ap‐
 *       pear, the 0 flag is ignored.  If a precision is given with a numeric conversion (d, i, o, u,  x,  and
 *       X), the 0 flag is ignored.  For other conversions, the behavior is undefined.
 * '-' - The  converted  value is to be left adjusted on the field boundary.  (The default is right
 *       justification.)  The converted value is padded on the right with blanks, rather than on the left
 *       with  blanks or zeros.  A - overrides a 0 if both are given.
 * ' ' - (a space) A blank should be left before a positive number (or empty string) produced by a signed
 *       conversion.
 * \+  - A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default,
 *       a sign is used only for negative numbers.  A + overrides a space if both are used.
 *
 * #### Field Width
 * An  optional  decimal digit string (with nonzero first digit) specifying a minimum field width.  If the con‐
 * verted value has fewer characters than the field width, it will be padded with spaces on the left (or right,
 * if  the  left-adjustment flag has been given).  Instead of a decimal digit string one may write "*" or "*m$"
 * (for some decimal integer m) to specify that the field width is given in the next argument, or in  the  m-th
 * argument,  respectively,  which must be of type int.  A negative field width is taken as a '-' flag followed
 * by a positive field width.  In no case does a nonexistent or small field width cause truncation of a  field;
 * if the result of a conversion is wider than the field width, the field is expanded to contain the conversion
 * result.
 *
 * #### Precision
 * An optional precision, in the form of a period ('.')  followed by an optional decimal digit string.  Instead
 * of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the preci‐
 * sion is given in the next argument, or in the m-th argument, respectively, which must be of  type  int.   If
 * the  precision is given as just '.', the precision is taken to be zero.  A negative precision is taken as if
 * the precision were omitted.  This gives the minimum number of digits to appear for d, i, o, u, x, and X con‐
 * versions, the number of digits to appear after the radix character for a, A, e, E, f, and F conversions, the
 * maximum number of significant digits for g and G conversions, or the maximum  number  of  characters  to  be
 * printed from a string for s and S conversions.
 *
 * Return the number of character printed. */
int ft_printf(const char *format, ...);

#endif