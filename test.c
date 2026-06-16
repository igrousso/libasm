#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dst, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern int ft_read(int fd, char *buf, size_t count); 
extern int ft_write(int fd, char *buf, size_t count);
extern char *ft_strdup(char *str);

int main()
{
    char *test = ft_strdup("test\n");
    printf(test);
    free(test);
}
