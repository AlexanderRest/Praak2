#include <stdio.h>

void print_help() {
    printf("Использование: my_utility [опции]\n");
    printf("Опции:\n");
    printf("-u, --users             Вывести список пользователей и их домашние директории\n");
    printf("-p, --processes         Вывести список запущенных процессов\n");
    printf("-h, --help              Показать справку\n");
    printf("-l PATH, --log PATH     Логировать вывод в указанный файл\n");
    printf("-e PATH, --errors PATH  Логировать ошибки в указанный файл\n");
}
