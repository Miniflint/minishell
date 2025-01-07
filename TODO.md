<<<<<<<<<IMPORTANT>>>>>>>>>>>
- [x] LEAK ON SHLVL IN SHELL->ENV["SHLVL"];

- [ ] take care of CDPATH variable -> should be added if updated

- [ ] parse tokens unlist

- [ ] change for new 2 step parsing :
  - [x] change type_and_set for t_token
  - [x] retirer conditions pour split_cmd_sp
  - [x] Do not del the ' and " for the step 2
  - [ ] implement parenthesis
    - [ ] check that there is at least one command between the brackets
    - [ ] check if the parenthesis is closed

- [ ] Step 2 of parsing (Tristan) :
  - [ ] Get home if ~ in first char and followed by nothing or /
  - [ ] Implement \
  - [ ] Set tokens in cmdli (with $, * and without ' and ")
  - [ ] Error if var or match in redirection multiple file_names

- [ ] match
  - [ ] besoin de conditions pour:
    - [ ] que des directory: (ends with /)
    - [ ] recursif a travers les dossiers: (double * + /)

optional:
- [ ] parsing for bonuses

- [x] get parent folder git branch for prompt line

Note :
Comtpeur de commande reviens à 0 à chaque parenthese fermante comme ouvrante et s'incrémente à chaque commande, si !compteur et parenthèse fermante alors erreur de synthax.
Compteur de parenthese s'incrémente avec ouvrante décrémente si fermante, si valeur négative erreur, si valeur vrai à la fin du prompt erreur.
