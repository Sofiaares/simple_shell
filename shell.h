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

void (*check_built_ins(char *str))(char **, char *);
int is_built_in(char **args, char *line);
char *search_full_path(char *command);
char **parse_path(int index, char *str);
char *build_full_path(char *path, char *command);
int find_path_index(char *env);
void print_commands(char **cmd);
int _isdigit(int c);
void set_env(char *name, char *value);
int _atoi(char *s);
int _isupper(int c);

#endif
