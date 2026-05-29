NAME = RPN
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = RPN.cpp  main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f  $(OBJS)
fclean:
	rm -f $(OBJS) $(NAME)
re: fclean all