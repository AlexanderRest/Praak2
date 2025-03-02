#include <stdio.h>
#include <stdlib.h>

// Глобальная переменная для файла логов
static FILE *log_file = NULL;

// Функция для установки пути к файлу логов
void set_log_path(const char *path) {
    if (log_file != NULL) {
        fclose(log_file);
    }
    log_file = fopen(path, "w");
    if (log_file == NULL) {
        perror("Не удалось открыть файл для логирования");
    } else {
        fprintf(log_file, "Логирование начато\n");
    }
}

// Функция для логирования сообщений
void log_event(const char *message) {
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fflush(log_file);  // Сбрасываем буфер, чтобы моментально записать данные в файл
    } else {
        fprintf(stderr, "Файл логов не открыт. Сообщение не записано.\n");
    }
}

// Функция для завершения работы с файлом логов
void close_log() {
    if (log_file != NULL) {
        fprintf(log_file, "Логирование завершено\n");
        fclose(log_file);
        log_file = NULL;
    }
}

int main() {
    // Устанавливаем путь к файлу логов
    set_log_path("app.log");
    
    // Примеры логирования событий
    log_event("Система инициализирована.");
    log_event("Произошла ошибка: Неверный ввод.");
    log_event("Завершение работы приложения.");

    // Закрываем файл логов
    close_log();

    return 0;
}
