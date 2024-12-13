FROM archlinux

RUN pacman -Sy --noconfirm git vim make gcc curl zsh neofetch valgrind

RUN sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

ENV DEBUGINFOD_URLS="https://debuginfod.archlinux.org/"

RUN echo 'alias  val_com="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=val_out.log"' >> ~/.zshrc

COPY . checking_files

ENTRYPOINT [ "zsh" ]
