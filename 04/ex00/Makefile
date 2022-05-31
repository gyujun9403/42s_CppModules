TARGET = ex00
CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
DIR = ./
SRCS = Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
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
re : #fclean all
# make fclean
# make all

.PHONY : all clean fclean re