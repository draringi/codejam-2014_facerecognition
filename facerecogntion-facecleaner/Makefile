.PHONY: all clean dist obj lib
CC:=gcc
AR:=ar

WARNINGS:=-Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-declarations -Wuninitialized \
            -Wredundant-decls -Winline -Wno-long-long -Wconversion             

CFLAGS:= -c -O2 -Iheaders -fpic $(WARNINGS)        
LIB:=lib/libfacerecogntion_cleaner.so  
STATIC_LIB:=lib/libfacerecogntion_cleaner.a
LDFLAGS:=-shared -O2 $(WARNINGS) -lopencv_imgproc -lopencv_objdetect -lopencv_contrib -lopencv_core

$(shell mkdir -p lib)
$(shell mkdir -p obj)

all: $(LIB) $(STATIC_LIB)

$(LIB): obj/face-cleaner.o
	@$(CC) $(LDFLAGS) obj/face-cleaner.o -o $(LIB)

$(STATIC_LIB): obj/face-cleaner.o
	@$(AR) cr $(STATIC_LIB) obj/face-cleaner.o

obj/face-cleaner.o: src/face-cleaner.cpp headers/facerecogntion/face-cleaner.h
	@$(CC) $(CFLAGS) src/face-cleaner.cpp -o obj/face-cleaner.o
	
clean:
	@rm obj/*
	@rm lib/*