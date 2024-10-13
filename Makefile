SRC_DIR:=src
OBJ_DIR:=build
SRCS:=$(wildcard $(SRC_DIR)/*.c) 
OBJS:=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

dcpc: $(OBJS) src/dcpc.h
	gcc $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	gcc -c $< -o $@

test: dcpc
	./$< tests/hello.c+
