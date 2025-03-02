#include <stdio.h>

// Глобальная переменная для файла ошибок
static FILE *error_file = NULL;

// Функция для установки пути к файлу ошибок
void set_error_path(const char *path) {
    if (error_file != NULL) {
        fclose(error_file);
    }
    error_file = fopen(path, "w");
    if (error_file == NULL) {
        perror("Не удалось открыть файл для логирования ошибок");
    }
}

// Функция для логирования ошибок
void log_error(const char *error_message) {
    if (error_file != NULL) {
        fprintf(error_file, "Ошибка: %s\n", error_message);
        fflush(error_file); // Сбрасываем буфер, чтобы моментально записать данные в файл
    } else {
        fprintf(stderr, "Файл логов ошибок не открыт. Сообщение не записано.\n");
    }
}

// Функция для завершения работы с файлом ошибок
void close_error_log() {
    if (error_file != NULL) {
        fclose(error_file);
        error_file = NULL;
    }
}

int main() {
    // Устанавливаем путь к файлу логов ошибок
    set_error_path("error.log");
    
    // Примеры логирования ошибок
    log_error("Не удалось открыть файл данных.");
    log_error("Недостаточно памяти для выполнения операции.");
    
    // Завершение работы с файлом логов ошибок
    close_error_log();
    
    return 0;
}
