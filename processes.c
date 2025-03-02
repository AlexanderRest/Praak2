#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = popen("ps aux --sort=pid", "r");
    if (fp == NULL) {
        perror("Ошибка при получении списка процессов");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line); // Вывод информации о процессе
    }

    pclose(fp);
}
