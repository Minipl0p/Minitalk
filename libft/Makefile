# =========================
# Makefile pour libft (42-friendly)
# =========================

# Couleurs ANSI
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
NC     = \033[0m # No Color

# Nom de la bibliothèque
NAME = libft.a
AR = ar -rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Sources (liste existante)
SRCS =	ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_countwordsep.c \
		ft_freenarr.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_join_wish.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putchar_printf.c \
		ft_putendl_fd.c \
		ft_puterror.c \
		ft_putnbr_base_printf.c \
		ft_putnbr_fd.c \
		ft_putnbr_printf.c \
		ft_putstr_fd.c \
		ft_putstr_printf.c \
		ft_split.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strndup.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_toupper.c \
		ft_tolower.c

# Génération des objets
OBJS = $(SRCS:%.c=%.o)

# Règle par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJS)
	@echo "${BLUE}📦 Building $(NAME)...${NC}"
	@$(AR) $(NAME) $(OBJS) > /dev/null 2>&1
	@echo "${GREEN}✅ $(NAME) built successfully!${NC}"

# Compilation des fichiers .c en .o (sans afficher les commandes)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

# Nettoyage des objets
clean:
	@echo "${RED}🧹 Cleaning object files...${NC}"
	@rm -f $(OBJS) 2> /dev/null

# Nettoyage complet (objets + bibliothèque)
fclean: clean
	@echo "${RED}🗑️ Removing $(NAME)...${NC}"
	@rm -f $(NAME) 2> /dev/null

# Rebuild
re: fclean all

# Cibles phony
.PHONY: all clean fclean re

