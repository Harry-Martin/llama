# Usage:
# make			# compile to binary
# make clean	# clean up binaries and objects

# TODO(Harry): make a build directory with /debug and /release subdirectories.
#							 change `make all` to compile in release mode in the release dir.
#							 add `make debug` which compiles in release mode
#							 NOTE: make sure debug dependencies are seperate from release dependencies to prevent corrupt builds.

.PHONY := all clean install example

CC := gcc

DEPENDENCIES := -lm

STATIC_LIB := libllama.a
SHARED_LIB := libllama.so

SRC_ROOT := src

EXAMPLE_OBJ_ROOT := example/bin
STATIC_OBJ_ROOT := build/static
SHARED_OBJ_ROOT := build/shared

SRC_EXT := .c
OBJ_EXT := .o
DEPENDS_EXT := .d

SRCS := ${shell find ${SRC_ROOT} -name "*${SRC_EXT}"}
SRC := ${dir ${SRCS}}

STATIC_OBJS := ${patsubst ${SRC_ROOT}%${SRC_EXT}, ${STATIC_OBJ_ROOT}%${OBJ_EXT}, ${SRCS}}
STATIC_OBJ := ${sort ${dir ${STATIC_OBJS}}}

SHARED_OBJS := ${patsubst ${SRC_ROOT}%${SRC_EXT}, ${SHARED_OBJ_ROOT}%${OBJ_EXT}, ${SRCS}}
SHARED_OBJ := ${sort ${dir ${SHARED_OBJS}}}

STATIC_DEPENDS := ${shell find ${STATIC_OBJ_ROOT} -name "*${DEPENDS_EXT}"}
SHARED_DEPENDS := ${shell find ${SHARED_OBJ_ROOT} -name "*${DEPENDS_EXT}"}

all: static shared

static: ${STATIC_LIB}

shared: ${SHARED_LIB}

${STATIC_LIB}: ${STATIC_OBJS}
	ar rcs $@ ${STATIC_OBJS} 

${SHARED_LIB}: ${SHARED_OBJS}
	gcc -shared ${SHARED_OBJS} -o $@

-include ${SHARED_DEPENDS}
-include ${STATIC_DEPENDS}

${STATIC_OBJ_ROOT}/%${OBJ_EXT}: ${SRC_ROOT}/%${SRC_EXT} | ${STATIC_OBJ}
	${CC} -c $< -o $@ 

${SHARED_OBJ_ROOT}/%${OBJ_EXT}: ${SRC_ROOT}/%${SRC_EXT} | ${SHARED_OBJ}
	${CC} -c $< -o $@ -fPIC

${STATIC_OBJ}:
	mkdir -p ${STATIC_OBJ}

${SHARED_OBJ}:
	mkdir -p ${SHARED_OBJ}

install: ${SHARED_LIB}
	cp ${SHARED_LIB} /usr/lib
	mkdir /usr/include/llama
	cp include/*.h /usr/include/llama

clean: 
	rm -f ${STATIC_LIB} ${SHARED_LIB}
	rm -rf build/*
	rm -f example/*.o
	rm -f example/example

example: example/example.o ${SHARED_LIB}
	${CC}  $< -o example/example -L. -lllama -lm




