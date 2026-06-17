#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dst, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern int ft_read(int fd, char *buf, size_t count);
extern int ft_write(int fd, char *buf, size_t count);
extern char *ft_strdup(char *str);

extern int ft_atoi_base(char *str, char *base);

int main(int ac, char **av)
{
    printf("%d\n", ft_atoi_base("10", "012345678"));
}
