#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return


if [ -f ~/.bash_aliases ]; then
        . ~/.bash_aliases   # --> Read bash_aliases, if present.
fi

export PS1=' \[\e[0;37m\]\w\[\e[m\] \[\e[1;37m\]\$ \[\e[0m\]'
export EDITOR='vim'

PATH=$PATH:$(ruby -rubygems -e "puts Gem.user_dir")/bin
PATH=$PATH:/home/william/bin
export PATH
