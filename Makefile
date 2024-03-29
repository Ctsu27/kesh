# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 10:24:15 by kehuang           #+#    #+#              #
#    Updated: 2019/04/07 13:12:02 by kehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL			:=			all
NAME					:=			kesh

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 COLOR                                        #

C_X						:=			\033[0m
C_R						:=			\033[31m
C_Y						:=			\033[33m
C_C						:=			\033[36m

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

ROOT_PROJECT			:=			$(shell pwd)
INC_DIR					:=			./includes
LIB_DIR					:=			./libft
TEST_DIR				:=			./tests

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC						:=			gcc
CFLAGS					:=			-Wall -Wextra -Werror
LIBFLAGS				:=			-L$(LIB_DIR) -lft -ltermcap

ifneq ($(DEBUG),)
OBJ_DIR					:=			./debug
CFLAGS					+=			-g3
else
  ifneq ($(DEV),)
  OBJ_DIR				:=			./dev
  CFLAGS				+=			-g3
  CFLAGS				+=			-O0 -std=c99 \
  									-Wchar-subscripts -Wparentheses \
									-Wsequence-point -Winline \
									-Wdisabled-optimization
  else
  OBJ_DIR				:=			./objs
  endif
endif

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

#-----------#
#    ROOT   #

SRC_DIR					:=			./src

ifndef OBJ_DIR
OBJ_DIR := ./objs
endif

INC_NAME				:=			kesh.h					\

SRC_NAME				:=			kesh.c					\

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix $(SRC_DIR)/,$(INC_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

OBJS					:=			$(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))

#-----------#
#  BUILTIN  #

SRC_BUILTIN_DIR			:=			builtin

INC_BUILTIN_NAME		:=			builtin.h				\

SRC_BUILTIN_NAME		:=			cd.c					\
									echo.c					\
									env.c					\
									exit.c					\
									setenv.c				\
									unsetenv.c				\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_BUILTIN_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_BUILTIN_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_BUILTIN_DIR)/,$(INC_BUILTIN_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#-----------#
#   LEXER   #

SRC_LEXER_DIR			:=			lexer

INC_LEXER_NAME			:=			lexer.h					\

SRC_LEXER_NAME			:=			lexer.c					\
									lexer_config.c			\
									show_token.c			\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_LEXER_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_LEXER_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_LEXER_DIR)/,$(INC_LEXER_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#   handler

SRC_HANDLER_DIR			:=			handler

INC_HANDLER_NAME		:=			handler.h				\

SRC_HANDLER_NAME		:=			handler_back_quote.c	\
									handler_double_quote.c	\
									handler_sh.c			\
									handler_simple_quote.c	\
									handler_white_space.c	\
									handler_word.c			\
									handler_undefined.c		\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_HANDLER_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_LEXER_DIR)/$(SRC_HANDLER_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_LEXER_DIR)/$(SRC_HANDLER_DIR)/,$(INC_HANDLER_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#-----------#
#   PARSER  #

SRC_PARSER_DIR			:=			parser

INC_PARSER_NAME			:=			parser.h				\
									parser_int.h			\

SRC_PARSER_NAME			:=			token_adjust.c			\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_PARSER_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_PARSER_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_PARSER_DIR)/,$(INC_PARSER_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#   EXPANSION

SRC_EXPANSION_DIR		:=			expansion

INC_EXPANSION_NAME		:=			expansion.h					\

SRC_EXPANSION_NAME		:=			none_expansion.c			\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_EXPANSION_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_PARSER_DIR)/$(SRC_EXPANSION_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_PARSER_DIR)/$(SRC_EXPANSION_DIR)/,$(INC_EXPANSION_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#-----------#
#   SHELL   #

SRC_SHELL_DIR			:=			shell

SRC_SHELL_NAME			:=			init_shell.c			\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_SHELL_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_SHELL_DIR)/%.c $(addprefix $(SRC_DIR)/,$(INC_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#-----------#
#   UTILS   #

SRC_UTILS_DIR			:=			utils

INC_UTILS_NAME			:=			utils.h					\

SRC_UTILS_NAME			:=			env_utils.c				\
									ft_err.c				\
									ft_getopt.c				\
									ft_mem2del.c			\
									ft_str2dup.c			\
									ft_putendl2.c			\
									is_pow_of2.c			\
									round_up_pow.c			\
									free_env.c				\
									free_token.c			\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_UTILS_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_UTILS_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_UTILS_DIR)/,$(INC_UTILS_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#   ARRAY

SRC_ARRAY_DIR			:=			array

INC_ARRAY_NAME			:=			array.h					\

SRC_ARRAY_NAME			:=			array_delete.c			\
									array_find.c			\
									array_find_index.c		\
									array_foreach.c			\
									array_map.c				\
									array_new.c				\
									array_push.c			\
									array_push_at.c			\
									array_realloc.c			\
									array_show.c			\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_ARRAY_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_UTILS_DIR)/$(SRC_ARRAY_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_UTILS_DIR)/$(SRC_ARRAY_DIR)/,$(INC_ARRAY_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@

#   FT_PRINTF

SRC_FT_PRINTF_DIR		:=			ft_printf

INC_FT_PRINTF_NAME		:=			ft_printf.h				\
									ft_printf_int.h			\

SRC_FT_PRINTF_NAME		:=			ft_pf.c					\
									ft_pf_buf.c				\
									c_conv.c				\
									id_conv.c				\
									p_conv.c				\
									s_conv.c				\
									u_conv.c				\
									x__conv.c				\
									x_conv.c				\

OBJS					+=			$(addprefix $(OBJ_DIR)/,$(SRC_FT_PRINTF_NAME:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SRC_UTILS_DIR)/$(SRC_FT_PRINTF_DIR)/%.c $(addprefix $(SRC_DIR)/$(SRC_UTILS_DIR)/$(SRC_FT_PRINTF_DIR)/,$(INC_FT_PRINTF_NAME))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "${C_C}%s${C_X} :: ${C_R}%s${C_X}\n"  $(NAME) $@


#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAME)
.PHONY: all

$(NAME):				$(OBJ_DIR) $(OBJS)
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS) -I$(INC_DIR)
	@printf '${C_Y}[ READY ] ${C_C}$(NAME)${C_Y} ---\n${C_X}'

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@printf '${C_Y}[ KILL ] ${C_C}$(NAME)${C_Y} Clean ${C_R}$(OBJ_DIR)${C_Y} ---\n${C_X}'
.PHONY: clean

fclean:
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) clean
	@rm -f $(NAME)
	@printf '${C_Y}[ KILL ] ${C_C}$(NAME)${C_Y} Flean ---\n${C_X}'
.PHONY: fclean

re:
	@$(MAKE) fclean
	@$(MAKE)
.PHONY: re

delete:
	@$(MAKE) fclean
	@$(MAKE) DEV="1" fclean
	@$(MAKE) DEBUG="1" fclean
.PHONY: delete

pclean:
	@rm -rf $(OBJ_DIR)
	@printf '${C_Y}[ KILL ] ${C_C}$(NAME)${C_Y} Clean ${C_R}$(OBJ_DIR)${C_Y} ---\n${C_X}'
	@rm -f $(NAME)
	@printf '${C_Y}[ KILL ] ${C_C}$(NAME)${C_Y} Flean ---\n${C_X}'

ra:
	@$(MAKE) pclean
	@$(MAKE)
.PHONY: ra

run:
	@$(MAKE)
	./$(NAME)
.PHONY: run

t test unit:
	@$(MAKE)
	@find $(ROOT_PROJECT)/$(TEST_DIR) -name "*.c" -exec \
		$(CC) {} -o {}.unit.out $(LIBFLAGS) $(filter-out $(OBJ_DIR)/kesh.o,$(OBJS)) -I$(INC_DIR) \;
	@find -s $(ROOT_PROJECT)/$(TEST_DIR) -name "*.unit.out" -exec \
		{} \;
	@find -s $(ROOT_PROJECT)/$(TEST_DIR) -name "*.unit.out" -exec \
		rm -f {} \;
.PHONY: t test unit

val vg valg:
	@$(MAKE)
ifeq (,$(findstring fsanitize,$(CFLAGS)))
	@valgrind --leak-check=full ./$(NAME)
else
	@echo "Can not run valgrind ${C_C}./$(NAME)${C_X} because fsanitize is in flags"
endif
.PHONY: val vg valg

main:
	@$(MAKE)
	@gcc -g3 -o test.out main.c $(LIBFLAGS) $(filter-out $(OBJ_DIR)/kesh.o,$(OBJS)) -I$(INC_DIR)
	./test.out
.PHONY: main
