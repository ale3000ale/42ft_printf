# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 12:40:44 by amarcell          #+#    #+#              #
#    Updated: 2021/02/06 17:56:00 by amarcell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
COLOR_OFF	="\033[0m"       # Text Reset

# Regular Colors
BLACK		=		"\033[0;30m"        # Black
RED			=		"\033[0;31m"          # Red
GREEN		=		"\033[0;32m"        # Green
YELLOW		=		"\033[0;33m"       # Yellow
BLUE		=		"\033[0;34m"         # Blue
PURPLE		=		"\033[0;35m"       # Purple
CYAN		=		"\033[0;36m"         # Cyan
WHITE		=		"\033[0;37m"        # White

# Bold
BBLACK		=		"\033[1;30m       # Black
BRED		=		"\033[1;31m         # Red
BGREEN		=		"\033[1;32m"       # Green
BYELLOW		=		"\033[1;33m"      # Yellow
BBLUE		=		"\033[1;34m"        # Blue
BPURPLE	=		"\033[1;35m"      # Purple
BCYAN		=		"\033[1;36m"        # Cyan
BWHITE		=		"\033[1;37m"       # White

# Underline
UBLACK		=		"\033[4;30m"       # Black
URED		=		"\033[4;31m"         # Red
UGREEN		=		"\033[4;32m"       # Green
UYELLOW		=		"\033[4;33m"      # Yellow
UBLUE		=		"\033[4;34m"        # Blue
UPURPLE		=		"\033[4;35m"      # Purple
UCYAN		=		"\033[4;36m"        # Cyan
UWHITE		=		"\033[4;37m"       # White


LIB_DIR		=		libft

SRC_MAIN	=		main.c

SRC_PRINT	= 		bob_the_builder.c	state_zero.c	state_terminator.c	state_star.c	state_minus.c	\
					state_point.c		hex_to_string.c	ft_printf.c			number.c		result_zero.c

SRC_LIBFT	= 		$(LIB_DIR)/ft_isprint.c			$(LIB_DIR)/ft_memcmp.c		$(LIB_DIR)/ft_putchar_fd.c	$(LIB_DIR)/ft_unsigned_itoa.c\
					$(LIB_DIR)/ft_split.c			$(LIB_DIR)/ft_strlcat.c		$(LIB_DIR)/ft_strncmp.c		$(LIB_DIR)/ft_substr.c		\
					$(LIB_DIR)/ft_atoi.c			$(LIB_DIR)/ft_isalpha.c		$(LIB_DIR)/ft_itoa.c		$(LIB_DIR)/ft_memcpy.c		\
					$(LIB_DIR)/ft_putendl_fd.c		$(LIB_DIR)/ft_strchr.c		$(LIB_DIR)/ft_strlcpy.c		$(LIB_DIR)/ft_strnstr.c		\
					$(LIB_DIR)/ft_tolower.c			$(LIB_DIR)/ft_bzero.c   	$(LIB_DIR)/ft_isascii.c		$(LIB_DIR)/ft_memccpy.c		\
					$(LIB_DIR)/ft_memmove.c			$(LIB_DIR)/ft_putnbr_fd.c 	$(LIB_DIR)/ft_strdup.c 		$(LIB_DIR)/ft_strlen.c		\
					$(LIB_DIR)/ft_strrchr.c			$(LIB_DIR)/ft_toupper.c		$(LIB_DIR)/ft_calloc.c		$(LIB_DIR)/ft_isdigit.c		\
					$(LIB_DIR)/ft_memchr.c			$(LIB_DIR)/ft_memset.c		$(LIB_DIR)/ft_putstr_fd.c	$(LIB_DIR)/ft_strjoin.c		\
					$(LIB_DIR)/ft_strmapi.c			$(LIB_DIR)/ft_strtrim.c		$(LIB_DIR)/ft_strndup.c		$(LIB_DIR)/ft_lstnew.c		\
					$(LIB_DIR)/ft_lstadd_front.c	$(LIB_DIR)/ft_lstsize.c		$(LIB_DIR)/ft_lstlast.c		$(LIB_DIR)/ft_lstadd_back.c	\
					$(LIB_DIR)/ft_lstdelone.c 		$(LIB_DIR)/ft_lstclear.c	$(LIB_DIR)/ft_lstiter.c		$(LIB_DIR)/ft_lstmap.c		\
					$(LIB_DIR)/ft_atoi_zero.c		$(LIB_DIR)/ft_strshift.c
					


OBJS 		= 		$(SRC_LIBFT:.c=.o)	$(SRC_PRINT:.c=.o)		

OBJS_MAIN	=		$(SRC_MAIN:.c=.o)

CFLAGS		=		-Wall -Wextra -Werror 

CC 			= 		gcc

NAME = 		libftprintf.a

$(NAME) :	$(OBJS)
			@ ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			@ rm -f  $(OBJS) $(OBJS_MAIN)

fclean:		clean
			@ rm -f $(NAME)


re:			fclean all


run:		$(OBJS) $(OBJS_MAIN)
			clear
			clear
			@ $(CC) $(CFLAGS) $(SRC_LIBFT) $(SRC_MAIN) $(SRC_PRINT)
			./a.out



norme:		
			clear
			@ echo $(BPURPLE) "\n#------|norme libft|------#" $(COLOR_OFF) $(YELLOW)
			norminette ./$(LIB_DIR)/*.c
			norminette ./$(LIB_DIR)/*.h
			@ echo $(COLOR_OFF)
			@ echo $(BBLUE) "\n#------|norme printf|------#" $(COLOR_OFF) $(CYAN)
			norminette ./*.c
			norminette ./*.h
			@ echo $(COLOR_OFF)

.PHONY: 	all clean fclean re