TARGET = ex01
CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
DIR = ./
SRCS = main.cpp Serializer.cpp
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
re : 
	make fclean
	make all
.PHONY : all clean fclean re