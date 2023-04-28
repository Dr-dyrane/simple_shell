#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create second process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct list_s - the linked list of variables
 * @value:the  value
 * @next: pointer to next node
 *
 * Description: the generic linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *_get_line(FILE *fp);
char **tok_enizer(char *str);
char *_directpath(char *order, char *wholepath, char *path);
int second(char *wholepath, char **to_kens);
void report_errors(int error);

/* the utility functions */
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

/* the prototypes for builtins */
int my_shell_env(void);
int my_shell_exit(void);
int execute_built_ins(char **to_kens);
int shell_num_builtins(built_s builtin[]);

/* prototypes for the helper functions for path linked list */
char *get_env(const char *name);
char **dup_env(char **environ_dup, unsigned int env_le_ngth);
list_s *pathlist(char *variable, list_s *head);

/* the prototypes for free functions */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);
#endif /* MAIN_H */
