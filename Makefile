CC = gcc
CFLAGS = -Wall -Wextra -o2
LDFLAGS =
RM = rm -f

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SENDER_SRC = $(SRC_DIR)/sender.c $(SRC_DIR)/cipher.c $(SRC_DIR)/hash.c
RECEIVER_SRC = $(SRC_DIR)/receiver.c $(SRC_DIR)/cipher.c $(SRC_DIR)/hash.c

# Object files
SENDER_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SENDER_SRC))
RECEIVER_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(RECEIVER_SRC))

# Executables
SENDER_EXEC = $(BIN_DIR)/sender
RECEIVER_EXEC = $(BIN_DIR)/receiver

.PHONY: all clean

all: $(SENDER_EXEC) $(RECEIVER_EXEC)

$(SENDER_EXEC): $(SENDER_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(RECEIVER_EXEC): $(RECEIVER_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SENDER_OBJ) $(RECEIVER_OBJ)
	$(RM) $(SENDER_EXEC) $(RECEIVER_EXEC)
	@rmdir $(OBJ_DIR) $(BIN_DIR) 2>/dev/null || true