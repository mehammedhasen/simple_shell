#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PATH_MAx 4096
#define HISTORY_FILE    "hsh shell history"
#define HIST_SIZE 4096

extern char **environ;

/**
 * struct list_node - single link list for env
 * @line: count number of history
 * @strg: string of link list
 * @next: next node address
 */

typedef struct list_node
{
	int line;
	char *strg;
	struct list_node *next;
} list_s;

/**
 *struct al_info - contain all argument information to function
 * @str_ptr: a string generated from getline containing arguements
 * @argv: array ofstring or pp
 * @file_path: pointer of fullpath of file
 * @filname: file name of readable
 * @argc: argument count
 * @rdfld: readeble file
 * @historycount: count history line
 * @history: history link-list pointer
 * @env: env link-list pointer
 * @environ: array of enviromental var
 * @env_flag: flag  for manipu env
 * @status: prv func return value
 */

typedef struct al_info
{
	char *str_ptr;
	char **argv;
	char *file_path;
	char *filname;
	int argc;
	int count_hist;
	list_s *env;
	list_s *history;
	char **environ;
	int env_flag;
	int status;
} in_arg;	/* get is pointer to struct */


/**
 *struct buil_call - contains a builtin string and related function
 *@type: the builtin command flag
 *@funcptr: the function
 */
typedef struct buil_call
{
	char *type;
	int (*funcptr)(in_arg *);
} buil_fun_tab;

#define ALL_ARGUMENT {NULL, NULL, NULL, NULL, 0, 0, NULL, NULL, NULL, 0, 0}

/* input string */
int input_str(in_arg *get);
void print_prompt(void);
void delet_comment(char *bufin);

/* atoi func list*/

int is_delim(char c, char *delimeter);
int ch_interactive(void);
int _isalpha(char c);
int _atoi(char *strg);
char *_memset(char *s, char b, size_t n);

/* string manipulation func list(string_mn2)*/

char *_strcpy(char *destr, char *srstr);
char *_strdup(const char *str);
void *_puts(char *strg);
int _putchar(char c);
/* string manipulation func list(string_mn1)*/

int _strlen(char *strg);
int _strcmp(char *strg1, char *strg2);
char *ch_st_vrname(const char *vstr, const char *nstr);
char *_strcat(char *dest, char *src);

/*link list_mn1*/

list_s *ad_node(list_s **head, const char *strg);
list_s *ad_node_at_end(list_s **head, const char *strg, int line);
size_t list_s_len(const list_s *head);
size_t print_strg_in_alnode(const list_s *head);
int delete_node_at_index(list_s **head, unsigned int index);
void free_all_node(list_s **head);

/*link list_mn2*/

int find_node_index(list_s **head, list_s *node);
char **pp_to_string(list_s *head);
list_s *node_st_wtpref(list_s *head, char *prefix, char c);

/*al_env__func_list*/

char **alloc_environ(in_arg *get);
int listdown_all_env(in_arg *get);
char *_getenv(const char *vrname);
int myenv(in_arg *get);
int _unsetenv(in_arg *get, char *name);
int _setenv(in_arg *get, char *name, char *value);
char *mk_env_str(char *vrname, char *vrvalue);
int myunsetenv(in_arg *get);
int mysetenv(in_arg *get);




/*builtin*/

int mycd(in_arg *get);
int myexit(in_arg *get);
int myhelp(in_arg *get);

/*var_info*/
void clear_arg(in_arg *get);


/*error_string*/
int _putchar2fld(char c, int fld);
int _putstr2fld(char *strg, int fld);
void _put_str_er(char *strg);
int _put_char_er(char c);

/*errot_signal*/
void error_print(char *strg);
int _putchar (char c);
void signal_handler(void);

/*file_path*/

char *get_envpath(in_arg *get);
char *find_file_path(char *comd);

/*token-parse*/
char **str_token(char *str, char dl);
char *_trspace(char *st, char dl);
int _wordcount(char *sw, char dl);

/*token 2*/
char **tok_str(char *strg, char *dlmte);
/*ex call 1&2*/
void excu_semicol(in_arg *get,char *buf, char **envp);
void excu_space(in_arg *get, char *buf, char **envp);
void handle_echo_variable(char *buf);
char *check_comment(char *buf);
void print_prompt(void);
void excu_and(in_arg *get,char *buf, char **envp);
void excu_or(in_arg *get,char *buf, char **envp);
/*excute_fle*/
void excute_com(in_arg *get, char *buffer, char **envp);
/*check buff chain*/
int  check_bufchain(char *buf);
/*_getline*/
size_t _getline(char **buptr, size_t *rd);



#endif
