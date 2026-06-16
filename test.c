#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dst, char *src);

int main()
{
    char *test = strdup("test\n\0");
    char *dst = malloc(10);
    ft_strcpy(dst, test);
    printf(dst);
}