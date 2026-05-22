/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarakoto <rarakoto@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 07:10:56 by rarakoto          #+#    #+#             */
/*   Updated: 2026/05/04 20:21:42 by rarakoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <ft_printf.h>
#include <dirent.h>
#define STANDARD_BUFFER 1024
#define GNL_BUFFER_SIZE 4096
#define GNL_CLEAR_BUFFER -1
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif
#ifndef PROGRAM_NAME
#define PROGRAM_NAME "program"
#endif
#ifndef DEFAULT_ERROR_MESSAGE
#define DEFAULT_ERROR_MESSAGE "an error occured."
#endif
#ifndef DEFAULT_WARNING_MESSAGE
#define DEFAULT_WARNING_MESSAGE "you did something that can harm the program."
#endif

typedef struct s_list
{
	void *content;
	struct s_list *next;
	struct s_list *prev;
} t_list;

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;

typedef enum e_str_comp
{
	EQUAL,
	DIFFERENT,
	NULL_ARGS,
} t_str_comp;

typedef enum e_error
{
	FILE_ERR = -1,
	READ_ERR = -1,
	ERROR = -1,
	READ_END = 0,
	OK = 0,
	OUT_OF_RANGE
} t_error;

static const unsigned long long g_lookup_ten_power[] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,
	1000000000,
	10000000000,
	100000000000,
	10000000000000,
	100000000000000,
	1000000000000000,
	10000000000000000,
	100000000000000000,
	1000000000000000000};

/* Check if c is an alphabet. */
t_bool ft_isalpha(int c);

/* Check if c is a digit. */
t_bool ft_isdigit(int c);

/* Check if c is an alphabet or a digit. */
t_bool ft_isalnum(int c);

/* Check if c are part of the standard ASCII. */
t_bool ft_isascii(int c);

/* Check if c are printable. */
t_bool ft_isprint(int c);

/* Return the upper value of c if it an alphabet, return itself if not. */
int ft_toupper(int c);

/* Return the lower value of c if it an alphabet, return itself if not. */
int ft_tolower(int c);

/* Converts the initial portion of the string pointed to by nptr
 * to int.
 * NOTE: 0 is returned if nptr is NULL. */
int ft_atoi(const char *nptr);

/* Converts the initial portion of the string pointed to by nptr
 * to int. Set the parameter size to the size of the number returned.
 * NOTE: 0 is returned if nptr is NULL. */
int ft_atoi_nb_size(const char *nptr, ssize_t *size);

/* Create a new allocated string containing n in string format.
 * NOTE: Return NULL if the allocation fail. */
char *ft_itoa(int n);

/* Search for the first occurence of c in the string s. Both of the memory
 * area are interpreted as unsigned char.
 * NOTE: Return a pointer to the matching byte, NULL otherwise. */
void *ft_memchr(const void *s, int c, size_t n);

/* Compare the first n bytes of the memory areas of s1 and s2.
 * NOTE: Return an integer less than, equal to, or greater than zero
 * if the first n bytes of s1 is found, respectively, to be less than,
 * to match, or be greater than the first n bytes of s2. If one of the
 * arg is NULL, -123456789 is returned. */
int ft_memcmp(const void *s1, const void *s2, size_t n);

/* Copy n bytes from memory area src to memory area dest.
 * The memory area must not overlap.
 * NOTE: NULL is returned if d or s is NULL, otherwise a pointer to dest. */
void *ft_memcpy(void *dest, const void *src, size_t n);

/* Write the character c in the file descriptor.
 * NOTE: Do nothing if fd is -1. */
void ft_putchar_fd(char c, int fd);

/* Write the number n in the file descriptor.
 * NOTE: Do nothing if fd is -1. */
void ft_putnbr_fd(int n, int fd);

/* Duplicate the string passed in argument to a new allocation.
 * NOTE: NULL is returned if there is not enough memory or s
 * is NULL. */
char *ft_strdup(const char *s);

/* Apply the function (*f) to the entire string s.
 * NOTE: Do nothing if one of the parameter are NULL. */
void ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Return the len of the string passed in parameter.
 * NOTE: Return 0 if the string are NULL. */
size_t ft_strlen(const char *s);

/* Return an integer less than, equal to, or greater than zero if
 * s1 (or the first n bytes thereof) is found, respectively, to be less
 * than, to match, or be greater than s2.
 * This function is better used as a sorting comparison function.
 * NOTE: If the two string have to be exactly the
 * same(same len, same character), use compare() instead of this. */
int ft_strncmp(const char *s1, const char *s2, size_t n);

/* Return an integer less than, equal to, or greater than zero if
 * s1 (or the first n bytes thereof) is found, respectively, to be less
 * than, to match, or be greater than s2.
 * This function is better used as a sorting comparison function.
 * It doesn't take into account the case of the character.
 * NOTE: If the two string have to be exactly the
 * same(same len, same character), use compare() instead of this. */
int ft_strncmp_insensitive(const char *s1, const char *s2, size_t n);

/* Locates the first occurence of little inside big only checking the size
 * of len. The string little have to be null terminated.
 * NOTE: If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; other‐wise a pointer to the first
 * character of the first occurrence of little is returned.*/
char *ft_strnstr(const char *big, const char *little, size_t len);

/* Returns a pointer to the first occurence of the character c in the string s.
 * NOTE: NULL is returned if no occurence were found or if s is NULL. */
char *ft_strchr(const char *s, int c);

/* This function is a superset of ft_strchr, it gives you both a pointer and an index.
 * Returns a pointer to the first occurence of the character c in the string s.
 * The parameter index will be set to the actual index where c is in s.
 * NOTE: NULL is returned if no occurence were found or if s is NULL.
 * The index are set to the size of the string if no occurence were found. */
char *ft_strchr_index(const char *s, int c, ssize_t *index);

/* Returns a pointer to the last occurence of the character c in the string s.
 * NOTE: NULL is returned if no occurence were found or if s is NULL. */
char *ft_strrchr(const char *s, int c);

/* Subtract the len bytes of s starting from start into a new
 * allocated string.
 * NOTE: NULL is returned if there is not enough memory or s is NULL.
 * An empty string "" is returned if start >= ft_strlen(s). */
char *ft_substr(char const *s, unsigned int start, size_t len);

/* Fill the firt n bytes of the memory are pointed to by s with c. */
void *ft_memset(void *s, int c, size_t n);

/* NOTE: Erases the data in the n bytes of the memory. */
void ft_bzero(void *s, size_t n);

/* Copies n bytes from memory area src to memory area dest.
 * NOTE: Return a pointer to dest in case of SUCCES, NULL otherwise. */
void *ft_memmove(void *dest, const void *src, size_t n);

/* Copy and concatenate strings src to dst. It doesn't takes the nul-bytes
 * terminaison into account during the copy. Both of the string have to
 * be nul-bytes terminated.
 * NOTE: Return length of src if the copy was a SUCCESS. */
size_t ft_strlcpy(char *dst, const char *src, size_t size);

/* Copy and concatenate strings src to dst. It takes the nul-bytes
 * terminaison into account during the copy. Both of the string have to
 * be nul-bytes terminated.
 * NOTE: Return the number of bytes they successfully copied, 0 if one
 * of the dst or src is NULL, ft_strlen(src) if size == 0,
 * size + ft_strlen(src) if size <= ft_strlen(src). */
size_t ft_strlcat(char *dst, const char *src, size_t size);

/* Allocate a contiguous memory of nmemb elements of size and return a
 * pointer to the allocated memory. They are all initialized to 0.
 * NOTE: Return NULL if nmemb or size is 0.*/
void *ft_calloc(size_t nmemb, size_t size);

/* Join the two string s1 and s2 into a new allocation and return it.
 * NOTE: Need to be freed. NULL is returned if the arguments are NULL.
 * if s1 is NULL and not s2, ft_strdup(s2) will be returned, otherwise
 * if s2 is NULL and not s1, s1 will be returned. */
char *ft_strjoin(char const *s1, char const *s2);

/* Trim the current string by the delimiter.
 * NOTE: It only remove the right and left area used by the delimiter string.
 * Need to be freed. NULL is returned if one the argument is NULL. */
char *ft_strtrim(char const *s1, char const *set);

/* Set start and end to the index where "set" are trimmed.
 * NOTE: No allocation occur during the process.
 * This version are faster than ft_strtrim since we only compute index.
 * This may be used like this:
 * char path[] = "////////////,,,,,,,,,,,,,,,,,,,,+++";
 * size_t start = 0;
 * size_t end = 0;
 * ft_strtrim_fast(path, "/,-+", &start, &end);
 * path[end] = '\0';
 * ft_printf("[%s]\n", path + start);
 *  */
char *ft_strtrim_fast(char *s, const char *set, size_t *start, size_t *end);

/* Write the string s in the file descriptor.
 * NOTE: Do nothing in case of fd is -1 or s NULL. */
void ft_putstr_fd(char *s, int fd);

/* Write a newline after printing the string s in the fd.
 * NOTE: Do nothing in case of fd is -1 or s NULL. */
void ft_putendl_fd(char *s, int fd);

/* Apply the function (*f) passed in parameter to the entire string s into
 * a new copy of it.
 * NOTE: Return the result in success, NULL otherwise. */
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Allocate a new t_list and assign content to it. */
t_list *ft_lstnew(void *content);

/* Insert the new_list to the top of lst. */
void ft_lstadd_front(t_list **lst, t_list *new_list);

/* Get the size of lst.
 * NOTE: 0 is returned if lst is NULL. */
int ft_lstsize(t_list *lst);

/* Return the last node inside lst.
 * NOTE: Return NULL if the argument is NULL. */
t_list *ft_lstlast(t_list *lst);

/* Return the first node inside lst.
 * NOTE: Return NULL if the argument is NULL. */
t_list *ft_lstfirst(t_list *lst);

/* Append new_list to lst.
 * NOTE: Do nothing if lst is NULL. new_list is returned if lst is NULL. */
void ft_lstadd_back(t_list **lst, t_list *new_list);

/* Delete the node by the given function.
 * NOTE: if lst is NULL, it does nothing. If lst->content is NULL, (*del) will
 * not be called. */
void ft_lstdelone(t_list *lst, void (*del)(void *));

/* Free each node from the head to the tail using the (*del) function.
 * NOTE: It free lst->content only if it is not NULL. lst is set to NULL. */
void ft_lstclear(t_list **lst, void (*del)(void *));

/* Apply (*f) to all node inside lst
 * NOTE: It apply (*f) to lst->content only if it is not NULL.
 * Do nothing if lst is NULL. */
void ft_lstiter(t_list *lst, void (*f)(void *));

/* Apply (*f) to all node inside lst
 * NOTE: It apply (*f) to lst->content only if it is not NULL.
 * Do nothing if lst is NULL. */
void ft_lstiter_reverse(t_list *lst, void (*f)(void *));

/* Apply (*f) to all node inside lst into a new allocated list,
 * in case (*f) fail, (*del) will be called.
 * NOTE: NULL is returned if there lst is NULL. */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Copy the string from src to dest.
 * NOTE: This function doesn't check if dest is large enough to contain c.
 * It does nothing if one the argument is NULL. */
void ft_strcpy(char *src, char *dest);

/* Split the string s to token, delimited by the char c passed in argument,
 * into a char ** as a container.
 * NOTE: This have to be freed using the provided function free_splitted(). */
char **ft_split(char const *s, char c);

/* Return the number of token delimited by the char passed in argument.
 * NOTE: 0 is returned if s is NULL. */
size_t get_word_count(char *s, char c);

/* Free the splitted token resulted by ft_split.
 * NOTE: The argument passed in parameter are set to NULL. */
char **free_splitted(char ***splitted);

/* Return the number of character before the delim char.
 * NOTE: '\0' is assumed as part of the delim. */
size_t len_until_char(char *s, char c);

/* Check if the character passed in parameter are uppercase.
 * NOTE: Always return FALSE if the character is not an alphabet. */
t_bool are_uppercase(const char c);

/* Check if the character passed in parameter are lowercase.
 * NOTE: Always return FALSE if the character is not an alphabet. */
t_bool are_lowercase(const char c);

/* Compare two string without taking account of their case.
 * NOTE: Two strings have to be the same len to be EQUAL. */
t_str_comp compare(char *s1, char *s2);

/* Compare two string without taking account of their case if their
 * alphabet. EQUAL if the two strings is the same, DIFFERENT if not.
 * NULL_ARGS is returned in case of NULL passed as args.
 * NOTE: Two strings have to be the same len to be EQUAL. */
t_str_comp insensitive_compare(char *s1, char *s2);

/* This function free the address pointed by the pointer and set it to NULL. */
void ft_free(void **pointer);

/* Prompt an error in the STDERR_FILENO.
 * NOTE: if s is NULL, DEFAULT_ERROR_MESSAGE is printed.
 * HACK: The output have a sweet format:). */
int err(char const *s, int return_value);

/* Prompt multiple error in the STDERR_FILENO.
 * NOTE: if s is NULL, DEFAULT_ERROR_MESSAGE is printed.
 * HACK: The output have a sweet format:). */
int multerr(char *err[], unsigned int error_nb, int return_value);

/* Prompt a warning in the STDERR_FILENO.
 * NOTE: if s is NULL, DEFAULT_WARNING_MESSAGE is printed.
 * HACK: The output have a sweet format:). */
int warn(char const *s, int return_value);

/* NOTE: fd == FILE_ERR will return NULL.
 * Return each line of the file each time it is called.
 * It use a static char buffer[GNL_BUFFER_SIZE] as temporary buffer.
 * The maximum size of the line is determined by the size of
 * the GNL_BUFFER_SIZE macro. Attempting to read a line that
 * are bigger than that will result in truncated line that match the size
 * of GNL_BUFFER_SIZE. It will have a \n at the end and as always NULL
 * terminated.
 * If you read multiple line from fd X, without reaching the end, and
 * try to read another line from another fd, You will have to close fd X
 * and reopen it again to retrieve the line from the beginning. */
char *get_next_line(int fd);

/* Return the size of the file provided in path.
 * NOTE: 0 is returned if the path send got an error or path is NULL. */
long get_filesize(char *path);

/* Return the number of occurence of character inside the string s,
 * NOTE: 0 is returned if s is NULL. */
size_t n_time_in(char *s, char character);

/* Tell if one character inside the string character are found in str.
 * NOTE: Return FALSE if one of the argument is NULL. */
t_bool char_in_string(char *character, char *str);

/* Return the biggest value between a and b. */
long long ft_max(long long a, long long b);

/* Return the lowest value between a and b. */
long long ft_min(long long a, long long b);

/* Return the absolute value. */
long long ft_abs(long long val);

/* Return the number of digit of a number. */
unsigned long long digit_count(long long nb);

/* Output a number to a file descriptor.
 * This function use less syscall to output the number making it
 * slightly faster than ft_putnbr_fd.
 * TEST: need to test his limit, there is few scenario where it
 * output number that doesn't match the input. */
ssize_t fast_putnbr_fd(long long number, int fd);

/* Sort an array by using a given comparison function */
void qsort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *));

/* Get the number of file inside a directory, the function only count what
 * filter return TRUE. */
size_t filecount_dir(const char *path, t_bool (*filter)(const struct dirent *file));

#endif
