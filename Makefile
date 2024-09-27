SRC_DIR:=src
OBJ_DIR:=build
SRCS:=$(wildcard $(SRC_DIR)/*.c) 
OBJS:=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

dcpc: $(OBJS)
	gcc $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	gcc -c $< -o $@
