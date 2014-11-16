.PHONY: all clean dist
CC:=g++

WARNINGS:=-Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-declarations -Wuninitialized \
            -Wredundant-decls -Winline -Wno-long-long -Wconversion             
OPENCV_CFLAGS:=$(shell pkg-config opencv --cflags)
CFLAGS:= -c -O2 -Iheaders $(WARNINGS) $(OPENCV_CFLAGS)        
APP:=bin/facerecog_cleaner  
OPENCV_LDFLAGS:=$(shell pkg-config opencv --libs)
LDFLAGS:= -O2 $(WARNINGS) $(OPENCV_LDFLAGS) -lfreeimage -lcrypt
OBJ_LIST:= obj/face-cleaner.o obj/core.o obj/file_type.o obj/load_gif.o obj/load_file.o

$(shell mkdir -p bin)
$(shell mkdir -p obj)

all: $(APP)

$(APP): $(OBJ_LIST)
	@$(CC) $(LDFLAGS) $(OBJ_LIST) -o $(APP)


obj/face-cleaner.o: src/face-cleaner.cpp headers/face-cleaner.h headers/load_file.h
	@$(CC) $(CFLAGS) $< -o $@
	
obj/core.o: src/core.c headers/face-cleaner.h
	@$(CC) $(CFLAGS) $< -o $@
	
obj/file_type.o: src/file_type.cpp headers/file_type.h
	@$(CC) $(CFLAGS) $< -o $@

obj/load_gif.o: src/load_gif.cpp headers/load_gif.h
	@$(CC) $(CFLAGS) $< -o $@

obj/load_file.o: src/load_file.cpp headers/load_file.h headers/load_gif.h headers/file_type.h
	@$(CC) $(CFLAGS) $< -o $@

clean:
	-@rm obj/*
	-@rm bin/*