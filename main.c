#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dst, char *src);
extern int ft_read(int fd, char *buf, size_t count);
extern int ft_write(int fd, char *buf, size_t count);
extern char *ft_strdup(char *str);
extern int ft_strcmp(char *s1, char *s2);

extern int ft_atoi_base(char *str, char *base);

extern void ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin_list);
extern void ft_list_sort(t_list **begin_list, int (*cmp)());
extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void free_fct(void *data)
{
    free(data);
}

void test_atoi_base()
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

void test_list_push_front()
{
    t_list *l = malloc(sizeof(t_list));
    l->data = (void *)1;
    l->next = NULL;
    ft_list_push_front(&l, "test");
    ft_list_push_front(&l, (void *)2);
    ft_list_push_front(&l, (void *)3);
    ft_list_push_front(&l, (void *)4);
    ft_list_push_front(&l, (void *)5);
    
    while (l)
    {
        t_list *freelst = l;

        printf("%d\n", l->data);
        l = l->next;
        free(freelst);
    }
}

void test_list_size()
{
    t_list *l = malloc(sizeof(t_list));
    l->data = (void *)1;
    l->next = NULL;
    ft_list_push_front(&l, (void *)2);
    ft_list_push_front(&l, (void *)3);
    ft_list_push_front(&l, (void *)4);
    ft_list_push_front(&l, (void *)5);
    ft_list_push_front(&l, (void *)6);

    printf("%d\n", ft_list_size(l));
}

void test_list_sort()
{
    int *n1 = malloc(sizeof(int));
    *n1 = 3;
    int *n2 = malloc(sizeof(int));
    *n2 = 2;
    int *n3 = malloc(sizeof(int));
    *n3 = 1;
    t_list *l = malloc(sizeof(t_list));
    l->data = (void *)n1;
    t_list *l1 = malloc(sizeof(t_list));
    l->next = l1;
    l1->data = (void *)n2;
    t_list *l2 = malloc(sizeof(t_list));
    l1->next = l2;
    l2->data = (void *)n3;
    l2->next = NULL;

    ft_list_sort(&l, (int (*)())ft_strcmp);

    while (l)
    {
        printf("%s\n", l->data);
        l = l->next;
    }
}

void test_list_remove_if()
{
    char *n1 = ft_strdup("2");
    char *n2 = ft_strdup("2");
    char *n3 = ft_strdup("2");
    char *n4 = ft_strdup("2");
    char *n5 = ft_strdup("2");
    char *n6 = ft_strdup("2");
    char *n7 = ft_strdup("2");
    char *data_ref = ft_strdup("2");
    t_list *l = NULL;
    ft_list_push_front(&l, n1);
    ft_list_push_front(&l, n2);
    ft_list_push_front(&l, n3);
    ft_list_push_front(&l, n4);
    ft_list_push_front(&l, n5);
    ft_list_push_front(&l, n6);
    ft_list_push_front(&l, n7);
    t_list *tmp = l;
    while (tmp)
    {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
    ft_list_remove_if(&l, (void *)data_ref, (int (*)())ft_strcmp, free_fct);
    tmp = l;
    printf("\n\n");
    while (tmp)
    {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}



void test_strlen()
{
    char str1[] = "1";
    char str10[] = "10";
    char strlong[] = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    char strempty[] = "";
    printf("\033[34mstr\033[0m: %s\n\033[32mft_strlen\033[0m: %d\n\033[33mstrlen\033[0m: %d\n\n", str1, ft_strlen(str1), strlen(str1));
    printf("\033[34mstr\033[0m: %s\n\033[32mft_strlen\033[0m: %d\n\033[33mstrlen\033[0m: %d\n\n", str10, ft_strlen(str10), strlen(str10));
    printf("\033[34mstr\033[0m: %s\n\033[32mft_strlen\033[0m: %d\n\033[33mstrlen\033[0m: %d\n\n", strlong, ft_strlen(strlong), strlen(strlong));
    printf("\033[34mstr\033[0m: %s\n\033[32mft_strlen\033[0m: %d\n\033[33mstrlen\033[0m: %d\n\n", strempty, ft_strlen(strempty), strlen(strempty));
}

void test_strcpy()
{
    char src1[] = "Hello";
    char dst1[10];
    char dest1[10];
    printf("\033[34msrc\033[0m: %s\n\033[32mft_strcpy\033[0m: %s\n\033[33mstrcpy\033[0m: %s\n\n", src1, ft_strcpy(dst1, src1), strcpy(dest1, src1));
    
    char src2[] = "";
    char dst2[10];
    char dest2[10];
    printf("\033[34msrc\033[0m: %s\n\033[32mft_strcpy\033[0m: %s\n\033[33mstrcpy\033[0m: %s\n\n", src2, ft_strcpy(dst2, src2), strcpy(dest2, src2));
    
    char src3[] = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    char dst3[129];
    char dest3[129];
    printf("\033[34msrc\033[0m: %s\n\033[32mft_strcpy\033[0m: %s\n\033[33mstrcpy\033[0m: %s\n\n", src3, ft_strcpy(dst3, src3), strcpy(dest3, src3));
}

void test_strcmp()
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    char str4[] = "Hell";
    char strempty1[] = "";
    char strempty2[] = "";
    
    printf("\033[34mstr1\033[0m: %s, \033[34mstr2\033[0m: %s\n\033[32mft_strcmp\033[0m: %d\n\033[33mstrcmp\033[0m: %d\n\n", str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));
    printf("\033[34mstr1\033[0m: %s, \033[34mstr3\033[0m: %s\n\033[32mft_strcmp\033[0m: %d\n\033[33mstrcmp\033[0m: %d\n\n", str1, str3, ft_strcmp(str1, str3), strcmp(str1, str3));
    printf("\033[34mstr3\033[0m: %s, \033[34mstr1\033[0m: %s\n\033[32mft_strcmp\033[0m: %d\n\033[33mstrcmp\033[0m: %d\n\n", str3, str1, ft_strcmp(str3, str1), strcmp(str3, str1));
    printf("\033[34mstr1\033[0m: %s, \033[34mstr4\033[0m: %s\n\033[32mft_strcmp\033[0m: %d\n\033[33mstrcmp\033[0m: %d\n\n", str1, str4, ft_strcmp(str1, str4), strcmp(str1, str4));
    printf("\033[34mstr1\033[0m: %s, \033[34mstrempty1\033[0m: %s\n\033[32mft_strcmp\033[0m: %d\n\033[33mstrcmp\033[0m: %d\n\n", str1, strempty1, ft_strcmp(str1, strempty1), strcmp(str1, strempty1));
    printf("\033[34mstrempty1\033[0m: %s, \033[34mstrempty2\033[0m: %s\n\033[32mft_strcmp\033[0m: %d\n\033[33mstrcmp\033[0m: %d\n\n", strempty1, strempty2, ft_strcmp(strempty1, strempty2), strcmp(strempty1, strempty2));
}

void test_write()
{
    int ret_ft;
    int ret_sys;
    char str1[] = "Hello ft_write!\n";
    char str2[] = "";
    char str3[] = "Invalid fd test\n";

    printf("\033[34mstr\033[0m: %s", str1);
    errno = 0;
    ret_ft = ft_write(1, str1, strlen(str1));
    printf("\033[32mft_write ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_ft, errno);
    errno = 0;
    ret_sys = write(1, str1, strlen(str1));
    printf("\033[33mwrite ret\033[0m: %d \033[36merrno\033[0m: %d\n\n", ret_sys, errno);

    printf("\033[34mstr\033[0m: %s\n", str2);
    errno = 0;
    ret_ft = ft_write(1, str2, strlen(str2));
    printf("\033[32mft_write ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_ft, errno);
    errno = 0;
    ret_sys = write(1, str2, strlen(str2));
    printf("\033[33mwrite ret\033[0m: %d \033[36merrno\033[0m: %d\n\n", ret_sys, errno);

    errno = 0;
    ret_ft = ft_write(-1, str3, strlen(str3));
    printf("\033[34minvalid fd:\033[0m\n\033[32mft_write ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_ft, errno);
    errno = 0;
    ret_sys = write(-1, str3, strlen(str3));
    printf("\033[33mwrite ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_sys, errno);
}

void test_read()
{
    int ret_ft;
    int ret_sys;
    char buf_ft[256];
    char buf_sys[256];
    int fd = open("/etc/hosts", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }

    errno = 0;
    ret_ft = ft_read(fd, buf_ft, 100);
    printf("\033[32mft_read ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_ft, errno);
    if (ret_ft > 0)
    {
        write(1, buf_ft, ret_ft);
        write(1, "\n", 1);
    }

    lseek(fd, 0, SEEK_SET);
    errno = 0;
    ret_sys = read(fd, buf_sys, 100);
    printf("\033[33mread ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_sys, errno);
    if (ret_sys > 0)
    {
        write(1, buf_sys, ret_sys);
        write(1, "\n", 1);
    }

    errno = 0;
    ret_ft = ft_read(-1, buf_ft, 10);
    printf("\033[34minvalid fd:\033[0m\n\033[32mft_read ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_ft, errno);
    errno = 0;
    ret_sys = read(-1, buf_sys, 10);
    printf("\033[33mread ret\033[0m: %d \033[36merrno\033[0m: %d\n", ret_sys, errno);

    close(fd);
}

void test_strdup()
{
    char *s1 = "Hello ft_strdup!";
    char *d1;
    char *d2;

    d1 = ft_strdup(s1);
    d2 = strdup(s1);
    printf("\033[34mstr\033[0m: %s\n\033[32mft_strdup\033[0m: %s\n\033[33mstrdup\033[0m: %s\n\n", s1, d1, d2);
    free(d1);
    free(d2);

    d1 = ft_strdup("");
    d2 = strdup("");
    printf("\033[34mstr(empty)\033[0m: %s\n\033[32mft_strdup\033[0m: %s\n\033[33mstrdup\033[0m: %s\n\n", "", d1, d2);
    free(d1);
    free(d2);
}

int main(int ac, char **av)
{
    printf("\033[31mTEST FT_STRLEN:\033[0m\n\n");
    test_strlen();
    printf("\n\n\033[31mTEST FT_STRCPY:\033[0m\n\n");
    test_strcpy();
    printf("\n\n\033[31mTEST FT_STRCMP:\033[0m\n\n");
    test_strcmp();
    printf("\n\n\033[31mTEST FT_WRITE:\033[0m\n\n");
    test_write();
    printf("\n\n\033[31mTEST FT_READ:\033[0m\n\n");
    test_read();
    printf("\n\n\033[31mTEST FT_STRDUP:\033[0m\n\n");
    test_strdup();


}
