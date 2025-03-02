#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "logger.h"
#include "error_handler.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *error_path = NULL;

    // Определение длинных опций
    struct option long_options[] = {
        {"users", no_argument, NULL, 'u'},
        {"processes", no_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {"log", required_argument, NULL, 'l'},
        {"error", required_argument, NULL, 'e'},
        {NULL, 0, NULL, 0} // Конец массива
    };

    // Обработка опций
    while (1) {
        int option_index = 0;
        opt = getopt_long(argc, argv, "u:p:h:l:e:", long_options, &option_index);
        
        // Если все опции обработаны
        if (opt == -1) {
            break;
        }

        switch (opt) {
            case 'u':
                list_users(); // Функция для вывода пользователей
                break;
            case 'p':
                list_processes(); // Функция для вывода процессов
                break;
            case 'h':
                print_help(); // Функция для вывода справки
                return 0;
            case 'l':
                log_path = optarg; // Сохраняем путь для логирования
                set_log_path(log_path); // Функция для настройки логирования
                break;
            case 'e':
                error_path = optarg; // Сохраняем путь для ошибок
                set_error_path(error_path); // Функция для настройки вывода ошибок
                break;
            default:
                print_help(); // Если введены неправильные аргументы
                return 1;
        }
    }

    return 0;
}
