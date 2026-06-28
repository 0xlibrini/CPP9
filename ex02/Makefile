NAME = PmergeMe
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =  main.cpp PmergeMe.cpp
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