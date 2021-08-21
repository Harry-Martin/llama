# Usage:
# make			# compile to binary
# make clean	# clean up binaries and objects

# TODO(Harry): make a build directory with /debug and /release subdirectories.
#							 change `make all` to compile in release mode in the release dir.
#							 add `make debug` which compiles in release mode
#							 NOTE: make sure debug dependencies are seperate from release dependencies to prevent corrupt builds.

.PHONY := all clean

CC := gcc

COMPILER_FLAGS := -Wall -g -MMD -MP
#COMPILER_FLAGS := -O3

LINKER_FLAGS := -lm

TARGET := llama

SRC_ROOT := ./src
OBJ_ROOT := ./obj

SRC_EXT := .c
OBJ_EXT := .o
DEPENDS_EXT := .d

SRCS := ${shell find ${SRC_ROOT} -name "*${SRC_EXT}"}
SRC := ${dir ${SRCS}}

OBJS := ${patsubst ${SRC_ROOT}%${SRC_EXT}, ${OBJ_ROOT}%${OBJ_EXT}, ${SRCS}}
OBJ := ${sort ${dir ${OBJS}}}

DEPENDS := ${shell find ${OBJ_ROOT} -name "*${DEPENDS_EXT}"}

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${OBJS} -o $@ ${LINKER_FLAGS}

-include ${DEPENDS}

${OBJ_ROOT}/%${OBJ_EXT}: ${SRC_ROOT}/%${SRC_EXT} | ${OBJ}
	${CC} -c $< -o $@ ${COMPILER_FLAGS}

${OBJ}:
	mkdir -p ${OBJ}

clean:
	cd ${OBJ_ROOT} && rm -rf *
