
NAME=		threads_bash
CC=			g++
RM=			rm -rvf

SRCS=		main.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS=	-W -Wall -Wextra -Wshadow
LDFLAGS=

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM)	$(NAME)

re:			fclean all

.PHONY:		all clean fclean re

