#ifndef MAIN_H
#define MAIN_H

#define READ_SIZE 1024

/* 1 MB Memory Pool */
#define MEMORY_POOL_SIZE (1024 * 1024)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* Custom memory management functions */
void *_sbrk(ptrdiff_t increment);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, const void *src, size_t n);

/* Function prototypes */
void print_prompt(void);
char **env_to_array(void);
int execute(char *line, char **envp);
size_t _strlen(char *s);
int _getline(char **lineptr, size_t *n, FILE *stream);
int _fgetc(FILE *stream);
int _putchar(int c);
extern char **environ;

/* String helper functions */
char *_strchr(char *s, char c);
char *_strtok(char *str, const char *delim);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

#endif /* MAIN_H */

