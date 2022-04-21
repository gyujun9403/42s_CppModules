TARGET = ex00
CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
DIR = ./
SRCS = newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp \
	main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR), $(OBJS))
	$(CPP) $(FLAGS) -o $(TARGET) $^
%.o : %.cpp
	$(CPP) $(FLAGS) -o $@ -c $<
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(TARGET)
re : fclean all
.PHONY : all clean fclean re