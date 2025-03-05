#ifndef logger_h
#define logger_h

void set_log_path(const char *path);
void log_event(const char *message);
void close_log();

#endif
