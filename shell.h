#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>

#define DLMT " \t\n"

extern char **environ;

/**
 * struct built_in - Defines the built_in funcs.
 * @built: The name of the build in command.
 * @func: A pointer to the right built_in funcs.
 */
typedef struct built_in
{
	char *built;
	void (*func)(char **, char *);
} built_in_t;

/* test func */
void print_commands(char **cmd);

/* handle errors */
void handle_exe_err(char *argvs[], char *comands[], int cmdcounter);

/* modes */
void batch(char *argw[], char *envy[]);
void interactive(char *argw[], char *envy[]);

/* parse and execute functions */
char *read_line(void);
int count_token(char *rline, const char *ydlmt);
char **parse_line(char *rline, const char *delimi);
int execute_args(char **args);
void creates_process(char **comands, char *envy[]);

/* Builtin functions */
void our_cod(char **argss, char *eline);
void our_exit(char **argss, char *eline);
void our_env(char **m, char *t);
void our_setenv(char *argss[], char *eline);
void our_unsetenv(char *argss[], char *eline);
int is_built_in(char **args, char *line);
void (*check_built_ins(char *str))(char **, char *);

/*path functions*/
int find_path_index(char *envy);
char *build_full_path(char *paths, char *commande);
char *search_full_path(char *command);
char **parse_path(int index, char *rts);


/* alx functions */
void set_env(char *na, char *valu);
char *_strdup_(char *src1);
int _strcmp_(char *b1, char *b2);
int _putchar(char ch);
int _strlen(char *y);
void _puts(char *y);
void free_arr(char *arr1[]);
void print_number(int v);
char *_strcat_(char *det, char *src1);
char *_strcpy_(char *det, char *src1);
int _atoi(char *v);
int _isdigit_(int y);
int _isupper(int ch);

#endif
