#Colors
GREEN				= \033[0;92m
RED					= \033[0;91m
DEF_COLOR			= \033[0;39m

# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
RM					= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate_both.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c \
						$(SRC_DIR)commands/topush.c 
						
PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/init_a_to_b.c \
						$(SRC_DIR)push_swap/init_b_to_a.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/init_stack.c \
						$(SRC_DIR)push_swap/main.c \
						$(SRC_DIR)push_swap/stack_utils.c

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) Makefile
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "$(GREEN)Objects compiled$(DEF_COLOR)"

$(LIBFT):
					@make -C ./libft

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@echo "$(RED)Objects deleted$(DEF_COLOR)"

fclean:
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "$(RED)Binaries deleted$(DEF_COLOR)"

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re