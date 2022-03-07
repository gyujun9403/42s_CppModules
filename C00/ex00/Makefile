TARGET = megaphone
CPP = c++
FLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET) : all

all : $(OBJS)
	$(CPP) $(FLAGS) -o $(TARGET) $<
%.o : %.cpp
	$(CPP) $(FLAGS) -c $<
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(TARGET)
re : fclean all
.PHONY : all clean fclean re