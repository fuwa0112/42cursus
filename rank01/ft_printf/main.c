// test.c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1 = printf("Hello %s, number: %d\n", "world", 42);
    int ret2 = ft_printf("Hello %s, number: %d\n", "world", 42);

    printf("Return printf:    %d\n", ret1);
    printf("Return ft_printf: %d\n", ret2);

    return 0;
}
