TARGET = tests
CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
DIR = ./
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR), $(OBJS))
	$(CPP) $(FLAGS) -o $(TARGET) $^ -I $(DIR)
%.o : %.cpp
	$(CPP) $(FLAGS) -o $@ -c $< -I $(DIR)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(TARGET)
re : fclean all
.PHONY : all clean fclean re re