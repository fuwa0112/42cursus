// main.c

#include <fcntl.h>      // open() 用
#include <unistd.h>     // close() 用
#include <stdio.h>      // printf() 用
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int  fd;
    char *line;

    if (argc < 2)
    {
        // 引数がなければ標準入力から読んでみる
        printf("Reading from standard input. Enter lines, then press Ctrl+D.\n");
        while ((line = get_next_line(0)) != NULL)
        {
            printf(">> %s", line);
            free(line);
        }
        return (0);
    }
    // 第1引数をファイル名とみなして open する
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Failed to open file: %s\n", argv[1]);
        return (1);
    }
    // ファイルから1行ずつ読み込み
    while ((line = get_next_line(fd)) != NULL)
    {
        printf(">> %s", line);
        free(line);
    }
    close(fd);
    return (0);
}
