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
    printf("Invalid:\n%d\n", ft_atoi_base(NULL, NULL));
    printf("%d\n", ft_atoi_base(NULL, "01"));
    printf("%d\n", ft_atoi_base("01", ""));
    printf("%d\n", ft_atoi_base("01", "1"));
    printf("%d\n", ft_atoi_base("01", "1 "));
    printf("%d\n", ft_atoi_base("01", "1+"));
    printf("%d\n", ft_atoi_base("01", "1-"));
    printf("%d\n\n", ft_atoi_base("01", "11"));
    
    printf("Valid:\n%d\n", ft_atoi_base("01", "01"));
    printf("%d\n", ft_atoi_base("+", "0123456789"));
    printf("%d\n", ft_atoi_base("   ", "0123456789"));
    printf("%d\n", ft_atoi_base("", "0123456789"));
    printf("%d\n", ft_atoi_base("0123104", "012103"));
    printf("%d\n", ft_atoi_base("99999999999999999999", "0123456789"));
    printf("%d\n", ft_atoi_base("19", "01"));
    printf("%d\n", ft_atoi_base("    01", "0123"));
    printf("%d\n", ft_atoi_base("     -01", "01"));
    printf("%d\n", ft_atoi_base("     +01", "01"));
    printf("%d\n", ft_atoi_base("     01   ", "01"));
    printf("%d\n", ft_atoi_base("     011101   ", "01"));
    printf("%d\n", ft_atoi_base("++10", "01"));
    printf("%d\n", ft_atoi_base("--10", "01"));
    printf("%d\n", ft_atoi_base("+102", "01"));
    printf("%d\n", ft_atoi_base("1021010", "01"));
    printf("%d\n", ft_atoi_base("10+10100", "01"));
    printf("%d\n", ft_atoi_base("10-1010110", "01"));
    
}
