NAME			=	libftprintf.a

SRCS			=	ft_printf.c other_functions_1.c other_functions_2.c

OBJS			=	$(SRCS:c=o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

all:		$(OBJS) $(NAME)

%.o:		%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c -I. $< -o $(<:c=o)
				@echo "Compiling OK!"

$(NAME):
				@echo "Creating library..." 
				@ar -rcs $@ $(OBJS)
				@echo "Job's done!"

clean:
				@echo "Cleaning objects..."
				@rm -f $(OBJS) $(BONUS_OBJS)
				@echo "Cleaned up!"

fclean:		clean
				@echo "Cleaning library..."
				@rm -f $(NAME)
				@echo "Cleaned up!"

re:			fclean all

.PHONY:		all clean fclean re bonus