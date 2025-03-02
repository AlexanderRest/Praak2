#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_users() {
    FILE *fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("Ошибка при получении списка пользователей");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ":");
        char *homedir = strtok(NULL, ":");
        homedir = strtok(NULL, ":"); // Пропускаем поле идентификатора группы
        homedir = strtok(NULL, ":"); // Берём домашний каталог после группы
        printf("Пользователь: %s, Домашняя директория: %s\n", username, homedir);
    }

    pclose(fp);
}
