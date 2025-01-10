#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>


char    *get_next_line(int fd);
char    *read_add(int fd, char *buffer);
char    *find_new_line(char *str);
char    *create_line(char *buffer, char *new_line);

char    *ft_strncpy(char *dest, const char *src, unsigned int n);
char    *ft_strjoin (const char *s1, const char *s2);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_strdup(const char *s);
#endif