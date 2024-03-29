# source: http://www.puxan.com/web/howto-write-generic-makefiles/
# Declaration of variables
CC = gcc
CC_FLAGS = -std=gnu11 -Wall -Wextra -Werror
LINKER_FLAGS = 
VALGRIND = valgrind

# File names
EXEC = main
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKER_FLAGS) -o $(EXEC)

# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@

analyze: $(EXEC)
	$(VALGRIND) ./$(EXEC)

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
