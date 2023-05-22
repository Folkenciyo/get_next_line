#Variables‹

NAME		= Get_new_line
NAME2		= Get_new_line_db
GNL			= get_next_line.a
OBJ_DIR		= obj/
TEST_DIR	= test/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs
NAME2		= Get_new_line_debug

# Colors

DEF_COLOR = \033[0;39m
BLACK = Black \033[0;30m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
YELLOW_ = \033[4;93m
BLUE = \033[0;94m
PINK_SUB = \033[0;4;45m
SORPRESA = \033[0;96m
MAGENTA = \033[0;95m
PURPLE = \033[0;35m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	get_next_line main get_next_line_utils

# Files
SRC 		= 	$($(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#####################
# Test files
TEST_01		=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test1))
TEST_02		=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test2))
TEST_03		=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test3))
TEST_03_01	=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test3_01))
TEST_04		=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test4))
TEST_05		=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test5))
TEST_06		=	$(addprefix $(TEST_DIR), $(addsuffix .txt, test6))

###

OBJF		=	.cache_exists

all:		$(NAME)

test:	$(NAME)
			@echo ""
			@echo "$(YELLOW_)Test1: normal line with tabs executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_01)
			@echo ""
			@echo "$(YELLOW_)Test2: long line executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_02)
			@echo ""
			@echo "$(YELLOW_)Test3: just nl executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_03)
			@echo ""
			@echo "$(YELLOW_)Test3_01: empy executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_03_01)
			@echo ""
			@echo "$(YELLOW_)Test4: new line executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_04)
			@echo ""
			@echo "$(YELLOW_)Test5: no new line executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_05)
			@echo ""
			@echo "$(YELLOW_)Test6: one char executed!$(DEF_COLOR)"
			@./$(NAME) $(TEST_06)
			@echo ""

debug:	$(NAME2)
			@echo "\n $(PINK_SUB)**¡¡¡You are in a debuging!!!**$(DEF_COLOR)"
			@echo "$(YELLOW)******¡¡¡ENJOY MODERFOKA!!!******$(DEF_COLOR)\n"
			@echo "$(PURPLE)Write: $(MAGENTA)b main $(PURPLE)(if you want to put a breakpoint in main) $(DEF_COLOR)\n"
			@echo "$(PURPLE)them if u want press $(MAGENTA)run$(DEF_COLOR)\n"
			@echo "$(PURPLE)and obviusly press $(MAGENTA)gui $(PURPLE)after that$(DEF_COLOR)\n"
			@lldb ./$(NAME2) $(TEST_03_01)

$(NAME2): $(GNL)
			@$(CC) -g  $(CFLAGS) -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o $(NAME2)
			@$(RM) -f $(GNL)
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(GREEN)Get_new_line executable compiled!$(DEF_COLOR)"

$(NAME): $(GNL)
			@$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(GNL) -o $(NAME)
			@$(RM) -f $(GNL)
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(GREEN)Get_new_line executable compiled!$(DEF_COLOR)"

$(GNL):	$(OBJ)
			@$(AR) $(GNL) $(OBJ)
			@echo "$(GREEN)Get_new_line compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: %.c | $(OBJF)
			@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)Get_new_line object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME2)
			@$(RM) -f $(GNL)
			@echo "$(CYAN)Get_new_line executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(YELLOW)Cleaned and rebuilt everything for Get_new_line!$(DEF_COLOR)"

.PHONY:		all clean fclean test re