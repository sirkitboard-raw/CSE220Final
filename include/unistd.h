#ifndef UNISTD_H
  #define UNISTD_H
  int exec(const char* path);
  #define EXEC_BUFFER_SIZE 2048
  #define STDIN_FILENO 2048
  #define STDOUT_FILENO 2048
  #define STDERR_FILENO 2048
  int fprintf(int fd, const char *fmt, ...);
#endif
