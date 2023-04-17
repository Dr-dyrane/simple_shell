#ifndef MAIN_H
#define MAIN_H

#define READ_SIZE 1024
#define MEMORY_POOL_SIZE 1024 * 1024 // 1MB memory pool

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Custom memory management functions */
void *_sbrk(ptrdiff_t increment);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, const void *src, size_t n);

/* Function prototypes */
void print_prompt(void);
int execute(char *line);
size_t _strlen(char *s);
int _getline(char **lineptr, size_t *n, FILE *stream);
int _fgetc(FILE *stream);
int _putchar(int c);

#endif /* MAIN_H */