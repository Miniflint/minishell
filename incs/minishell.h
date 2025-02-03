#ifndef MINISHELL_H
# define MINISHELL_H
//# define PATH_MAX 2048

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/termios.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <linux/limits.h>
# include <dirent.h>
# include <sys/wait.h>
# include "../libft/libft.h"
#include "../printfd/HEADER/ft_printfd.h"

# ifndef DT_DIR
# define DT_DIR 4
# endif

// Readline
# include <readline/readline.h>
# include <readline/history.h>

//globale pour recuperer la valeur du statut de exit
extern int	g_errno;

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*previous;
	struct s_token	*next;
}	t_token;

typedef struct s_slist
{
	char			*str;
	struct s_slist	*next;
}	t_slist;

typedef struct s_variable
{
	char				*name;
	char				*value;
	struct s_variable	*next;
}	t_variable;

typedef struct s_shell
{
	t_variable			*env;
	t_variable			*export;
	char				**str_env;
	char				*read;
	int					if_sig;
	int					say;
	int					parenthesis;
	int					cmd_cmpt;
}	t_shell;

typedef enum e_type
{
	EMPTY,
	CMD,
	ARG,
	PIPE,
	RFILE,
	RDI,
	RDO,
	RDIH,
	RDOA,
	ANDOR,
	OPEN_P,
	CLOSE_P
}			t_type;

typedef struct s_unlist
{
	t_type			type;
	char			*token;
	struct s_unlist	*next;
}					t_unlist;

typedef struct s_file
{
	t_type	type;
	char	*name;
}			t_file;

typedef struct s_cmdli
{
	t_unlist		*tokens;
	t_unlist		*tok_cursor;
	char			*cmd;
	char			**cmd_args;
	int				*pipe_in;
	int				*pipe_out;
	int				create_fork;
	int				exit_fork;
	int				here_doc;
	int				fd_in;
	int				fd_out;
	char			**file_in;
	t_file			**file_out;
	int				and_or;
	pid_t			pid;
	int				cmd_error;
	struct s_cmdli	*previous;
	struct s_cmdli	*next;
}					t_cmdli;

typedef struct dirent t_dir;

typedef struct s_param_match
{
	int	depth;
	int	*is_first;
}	t_p_match;

typedef struct s_match_info
{
	DIR		*dir_ptr;
	char	**sep;
	char	**sep_base_ptr;
	char	*base_path;
	char	*d_name;
	char	full_path[PATH_MAX];
	int		infinite;
	int		max_depth_file;
	int		max_depth_dir;
	int		dir_or_file;
	int		absolute_path;
}	t_match;


char	*remove_quote(char *str);

// Match
int		match(char *s1, char *s2, char quote);
void	rec_dir(t_match info, int depth, t_cmdli *cmdli, int *is_first);
void	if_rec_dir(t_cmdli *cmdli, t_p_match *p, t_match info, char **get_name);
void	check_open_dir(char *separators, t_cmdli *cmdli);
char	*get_path_sep(t_match *info, char *separators);


// match utils.c
void	assign_info_base_path(t_match *info, char *separators);
int		get_depth(int depth, int max_depth);
int		skip_add_path(char f_p[PATH_MAX], char *d_name, char *base_path, int depth);
char	*dup_file_name(char *name, int dir_or_file);
void	add_tok_unl(t_cmdli *cmdli, char *name, int *is_first, int dir_or_file);
void	parse_param_recdir(char *s, t_match *info, int *is_first);
char	*join_path_free(t_match *info, char *path, int i);


// Parsing
void		free_tab(char **ss);
int			new_unlist(t_cmdli *cmdli, char *s, t_type type);
t_cmdli		*cmdli_first(t_cmdli *cmds_list);
void		free_content(t_cmdli *cmdli);
void		free_cmdli(t_cmdli **cmdli);
void		free_unlist(t_cmdli *cmdli);
void		free_file(t_file **files);
t_cmdli		*error_cmdli_nl(t_cmdli **cmds_list);
void		error_cmdli(t_cmdli **cmds_list, char *s);
void		error_cmdli_interpret(t_cmdli **cmds_list, char *s);
void		error_cmdli_interpret_s(t_cmdli **cmds_list, char *s);
int			ft_strcmp_int(char *s1, char *s2);
int			ft_strslen(char **s);
int			files_len(t_file **files);
char		*split_cmd(char **cmdline, unsigned int *i, char c);
char		**ft_strsjoin(char *s, char **ss);
t_file		**file_join(char *file, t_file **files, t_type type);
char		*add_var(char **cmdline, char *str, unsigned int *i);
char		*add_home(unsigned int *i);
char		*add_quote(char **cmdline, char *str, unsigned int *i);
char		*add_dquote(char **cmdline, char *str, unsigned int *i);
char		*split_cmd_sp(char **cmdline, unsigned int *i);
t_cmdli		*create_cmdli(void);
void		add_pipe(t_cmdli **cmds_list, t_type *type);
void		add_andor(t_cmdli **cmds_list, t_type *type, int and_or);
int			add_arg(t_cmdli *cmdli, char *arg);
int			add_cmd(t_cmdli *cmdli, char *cmd);
int			file_rdi(t_cmdli *cmdli, char *file);
int			file_rdo(t_cmdli *cmdli, char *file, t_type type);
//void		file_heredoc(t_cmdli **cmds_list, char *file);
int			add_file(t_cmdli *cmdli, char *file, t_type type);
void		type_and_set(char *s, t_cmdli **cmds_list,
				t_type *type, int interpret);
t_cmdli		*get_cmds(char **cmdline);

// Parsing step 2
int			store_tokens(t_cmdli *cmdli);

// List utils
void		free_nodes(t_variable **list);
void		free_nodes_contents(t_variable **list);
void		insert_new_node(t_variable **export, t_variable *env);
t_variable	*create_node_name_value(char *name, char *value);
t_variable	*get_last_node(t_variable *list);
void		add_node_back(t_variable **list, t_variable *new);

// Init
void		init_shell(t_shell *shell, char **env);
t_shell		*ft_get_shell(t_shell *new_shell);
t_variable	*ft_get_env(void);
char		**ft_get_str_env(void);
t_variable	*ft_get_export(void);
char		*ft_get_var(char *substr);

char		*ft_prompt(void);
void		ft_print_prompt(void);
char		*get_git_path(char *cwd, char *file);
void		none_git_prompt(char *prompt, const char **prompt_elem, char *cwd);
void		git_prompt(char *prompt, const char **prompt_elem,
				char *git_path, char *cwd);
char		*get_git_branch(char *git_path);
void		prompt_cat(char *prompt, const char *element, unsigned int *i);

void		__update_env(void);
t_variable	*init_env(char **m_env);
char		*ft_strldup(char *s, unsigned int len);
void		split_variable(t_variable *node, char *s);
t_variable	*create_var_node(char *s);

t_variable	*init_export(void);

// Signals
void		handle_interrupt(int sig);
void		sig_mode(int mode);
void		term_handler(void);

// Builtins
void		ft_env(t_cmdli **cmdli);
int			put_node(t_variable **export, t_variable *current,
				t_variable *prev, t_variable *new);
void		ft_export(t_cmdli **cmdli);
void		ft_unset(t_cmdli **cmdli);
void		ft_pwd(t_cmdli **cmdli);
void		ft_exit(t_cmdli **cmdli);
void		free_shell_variables(void);
void		ft_sig_exit(void);
void		ft_cd(t_cmdli **cmdli);
void		ft_echo(t_cmdli **cmdli);

// ft_export_utils.c
void		print_export(t_cmdli **cmdli);
void		free_content_node_and_print(t_cmdli *cmdli, t_variable *new, int i);
int			check_non_authorized_names(char *str, int *i);
int			ft_is_alphanum_(char c);

// Builtins utils
void		replace_node(t_variable **export, t_variable *new);
void		replace_node_env(t_variable **env, t_variable *new);

// Binaries
int			exec_cmd(t_cmdli *cmdli);
int			no_cmd(t_cmdli **cmdli);

// Execution
int			andor_check(t_cmdli **cmdli);
void		is_builtin(t_cmdli **cmdli, int mode);
void		exec_builtin(void (*f)(t_cmdli **), t_cmdli **cmdli, int mode);
int			builtin_fork(void (*f)(t_cmdli **), t_cmdli **cmdli);

void		is_absolute_path(char **args, t_list *env);
char		*no_path(char *cmd, char *path);
char		*path_join(char *path, char *cmd, unsigned int path_len,
				unsigned int cmd_len);
char		**free_path(char **tab, char *path);

void		set_redirection(t_cmdli *cmdli);
char		*get_absolute_path(char *cmd, char *path);
int			ft_strchr_path(char *s, char *path, int c);
int			close_pipe(int	*pipe);
int			close_and_free(t_cmdli *cmdli);
void		write_heredoc(t_cmdli **cmdli, char *limit);
int			set_file_out(t_cmdli *cmdli);
int			set_file_in(t_cmdli *cmdli);
int			builtin_set_file(t_cmdli *cmdli);

// Readline
void		rl_replace_line(const char *text, int clear_undo);

// Heredoc
int			heredoc(t_cmdli **cmdli, char *limit);

//Secure
char		**free_tab_null(char **ss);
int			return_error(int error, char *custom);
int			exit_error(int error, char *custom);
char		**ss_error(int error, char *custom);
char		*s_error(int error, char *custom);
void		void_error(int error, char *custom);
void		malloc_error(t_cmdli **cmdli);

//Fun
void		ft_say(char *str);
void		print_and_say(char *print, char *say);
void		print_minishell(void);
void		back_to_the_future(void);
void		image_1(int back);
void		image_2(int back);
void		image_3(int back);
void		image_4(int back);
void		image_5(int back);
void		image_6(int back);
void		image_7(int back);
void		image_8(int back);
void		image_9(int back);
void		image_10(int back);
void		image_11(int back);
void		image_12(int back);
void		image_13(int back);
void		image_14(int back);
void		image_15(int back);
void		image_16(int back);
void		image_17(int back);
void		image_18(int back);
void		image_19(int back);
void		image_20(int back);

#endif
