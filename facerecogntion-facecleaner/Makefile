CC:=gcc

WARNINGS:=-Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-declarations -Wuninitialized \
            -Wredundant-decls -Winline -Wno-long-long -Wconversion             

CFLAGS:= -c -Iheaders -fpic $(WARNINGS)        
LIB:=lib/libfacerecogntion_cleaner.so       
LDFLAGS:=-shared $(WARNINGS)

all: $(LIB)

$(LIB): obj/face-cleaner.o
	@$(CC) $(LDFLAGS) obj/face-cleaner.o -o $(LIB)


obj/face-cleaner.o: src/face-cleaner.cpp headers/face-cleaner.h
	@$(CC) $(CFLAGS) src/face-cleaner.cpp -o obj/face-cleaner.o
	
clean:
	rm obj/*