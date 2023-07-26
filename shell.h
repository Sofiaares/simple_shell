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

extern char **envi_mntal;

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

/* sim-s_printest */
void print_commands(char **cmd);

/* error handl */
void error_handl_i(char *vargs[], char *command[], int cmd_counter_i);

/* modes sh-c */
void batch(char *argv[], char *env[]);
void interactive(char *argv[], char *env[]);

/* parsh liner and execu s sh */
char *you_readline_i(void);
int ct_tken_i(char *rline, const char *dlmtoho);
char **prase_yline_i(char *inputin, const char *ydelimit);
int execute_args(char **vargs);
void execute_process_i(char **vargs, char *envy[]);

/* Constr_i */
void ourcod_i(char **vargs, char *i_line);
void ourext_i(char **vargs, char *i_line);
void ourenv_i(char **q, char *r);
void ourseten_v_i(char *vargs[], char *i_line);
void our_unseten_v_i(char *vargs[], char *i_line);
int is_built_in(char **vargs, char *i_line);
void (*check_built_ins(char *str))(char **, char *);

/*line-s-path functions*/
int find_path_index(char *env);
char *build_full_path(char *path, char *command);
char *search_full_path(char *command);
char **parse_path(int index, char *str);

/* simple s fuctions  */
void set_env(char *name, char *value);
char *_strd_up_i(char *src_v);
int _strcmps_i(char *sx, char *sv);
int _putchar(char c);
int _strlen_i(char *q);
void _puts_i(char *q);
void free_i(char *arr[]);
void print_num_i(int n);
char *_str_cat_i(char *vest, char *src_v);
char *_str_copy_i(char *vest, char *src_v);
int _atoi(char *s);
int _isdigit(int c);
int _isupper(int c);
#endif
