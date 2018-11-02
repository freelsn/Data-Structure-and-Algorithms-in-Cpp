INCS = -I src/ -I test/

CC = g++

CFLAGS = \
-std=c++14 \
-Wall \
-Werror=format-security \
-Werror=implicit-function-declaration

TARGET := run
SRCS := $(wildcard *.cpp) $(wildcard **/*.cpp)

OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

.PHONY: clean
clean:
	-rm -f $(TARGET) $(OBJS)
