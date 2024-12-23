<<<<<<<<<IMPORTANT>>>>>>>>>>>
- [x] LEAK ON SHLVL IN SHELL->ENV["SHLVL"];

- [ ] take care of CDPATH variable -> should be added if updated

- [ ] parse tokens unlist

- [ ] change for new 2 step parsing :
  - [ ] change type_and_set for t_token
  - [ ] retirer conditions pour split_cmd_sp
  - [ ] Do not del the ' and " for the step 2
  - [ ] Error if var or match in redirection file_name
  - [ ] implement parenthesis

- [ ] Step 2 of parsing (Tristan) :
  - [ ] Get home if ~ in first char and followed by nothing or /
  - [ ] Implement \
  - [ ] Set tokens in cmdli (with $, * and without ' and ")

- [ ] match
  - [ ] besoin de conditions pour:
    - [ ] que des directory: (ends with /)
    - [ ] recursif a travers les dossiers: (double * + /)

optional:
- [ ] parsing for bonuses

- [ ] get parent folder git branch for prompt line
