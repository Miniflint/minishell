
### TRISTAN
<<<<<<<<<<<IMPORTANT>>>>>>>>>>>
- [ ] ft_str_get_env envoie le faux env
- [x] LEAK ON SHLVL IN SHELL->ENV["SHLVL"];

- [ ] segfault && ||

- [ ] parse tokens unlist

- [ ] change for new 2 step parsing :
  - [x] change type_and_set for t_token
  - [x] retirer conditions pour split_cmd_sp
  - [x] Do not del the ' and " for the step 2
  - [ ] implement parenthesis
    - [x] check that there is at least one command between the brackets
    - [x] check if the parenthesis is closed
    - [x] check that all elements of a command line are never divided by parentheses example: (echo) hello
    - [ ] execution with parenthesis

- [ ] Step 2 of parsing (Tristan) :
  - [ ] Get home if ~ in first char and followed by nothing or /
  - [x] Set tokens in cmdli (with $, * and without ' and ")
  - [x] Error if var or match in redirection multiple file_names

- [x] match
  - [x] PRENDRE EN COMPTE LES QUOTES
    - [x] quote sur le path
    - [x] quote sur le first char '.'
  - [x] besoin de conditions pour:
    - [x] que des directory: (ends with /)
    - [x] Recursif
    - [x] fonctionne avec absolute and relative path
    - [x] recursif a travers les dossiers: (double * + /)


optional:
- [ ] parsing for bonuses
- [x] get parent folder git branch for prompt line
- [ ] take care of CDPATH variable -> should be added if updated
- [ ] Implement \


DONE: