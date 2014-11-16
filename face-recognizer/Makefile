.PHONY: all clean dist
CC:=g++

WARNINGS:=-Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-declarations -Wuninitialized \
            -Wredundant-decls -Winline -Wno-long-long -Wconversion        

PROJECT_DIRS := headers src
PROJECT_SRC_C := $(shell find $(PROJECT_DIRS) -type f -name \*.c)
PROJECT_SRC_CPP := $(shell find $(PROJECT_DIRS) -type f -name \*.cpp)
PROJECT_HEADERS_C := $(shell find $(PROJECT_DIRS) -type f -name \*.h)
PROJECT_HEADERS_CPP := $(shell find $(PROJECT_DIRS) -type f -name \*.hpp)
PROJECT_OBJ := $(patsubst src/%, obj/%, $(patsubst %.c,%.o,$(PROJECT_SRC_C)))
PROJECT_OBJ := $(PROJECT_OBJ) $(patsubst src/%, obj/%, $(patsubst %.cpp,%.o,$(PROJECT_SRC_CPP)))
PROJECT_DEPS := $(patsubst %.o,%.d,$(PROJECT_OBJ)) 
APP:=bin/facerecog
OPENCV_LIBS:=$(shell pkg-config opencv --libs)
LINKED_LIBRARIES:= $(OPENCV_LIBS)

$(shell mkdir -p obj)
$(shell mkdir -p bin)

CFLAGS:= -c -O2 -Iheaders $(WARNINGS)
LDFLAGS:= -O2 $(LINKED_LIBRARIES)

all: $(APP)

debug:
	@echo Project dirs:
	@echo $(PROJECT_DIRS)
	@echo Project C files:
	@echo $(PROJECT_SRC_C)
	@echo Project C++ files:
	@echo $(PROJECT_SRC_CPP)
	@echo Project Objects:
	@echo $(PROJECT_OBJ)
	@echo Project Deps:
	@echo $(PROJECT_DEPS)

obj/%.o: src/%.cpp Makefile
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	
$(APP): $(PROJECT_OBJ)
	@$(CC) $(LDFLAGS) $(PROJECT_OBJ) $(FACECLEANER_STATIC) -o $(APP)
	
clean:
	-@rm obj/*
	-@rm bin/*
