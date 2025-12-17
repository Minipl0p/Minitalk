# ============================================================================#
# 									Makefile								  #
# ============================================================================#

# Colors
RED   := \033[0;31m
GREEN := \033[0;32m
BLUE  := \033[0;34m
NC    := \033[0m

# Names
NAME_SERVER := server
NAME_CLIENT := client
CC := cc
CFLAGS := -Wall -Wextra -Werror -g -Iheader
LIBDIR := libft
LIBNAME := libft.a
LIB := $(LIBDIR)/$(LIBNAME)

# Commands
LIBMAKE := $(MAKE) --no-print-directory -C $(LIBDIR)
RM := rm -rf

.PHONY: all clean fclean re libs libclean help

all: libs $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):
	@echo "$(BLUE)🔗 Building $@...$(NC)"
	@$(CC) $(CFLAGS) src/server.c -L$(LIBDIR) -l:$(LIBNAME) -o $(NAME_SERVER)
	@echo "$(GREEN)✅ Built $@$(NC)"

$(NAME_CLIENT):
	@echo "$(BLUE)🔗 Building $@...$(NC)"
	@$(CC) $(CFLAGS) src/client.c -L$(LIBDIR) -l:$(LIBNAME) -o $(NAME_CLIENT)
	@echo "$(GREEN)✅ Built $@$(NC)"

libs:
	@echo "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)"
	@$(LIBMAKE)

clean:
	@echo "$(RED)🧹 Cleaning objects...$(NC)"
	@$(RM) obj

libclean:
	@echo "$(RED)🧹 Cleaning lib in $(LIBDIR)...$(NC)"
	@$(LIBMAKE) clean

fclean: clean libclean
	@echo "$(RED)🗑️ Removing binaries and library $(LIBNAME)...$(NC)"
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(LIB)

re: fclean all
