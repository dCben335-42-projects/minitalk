CLIENT_NAME = client
SERVER_NAME = server

CC          = cc
C_FLAGS     = -Wall -Wextra -Werror

BUILD_DIR   = ./.build
RM = rm -rf
MKDIR = mkdir -p

# includes
INCLUDES_DIR = ./includes
INCLUDES_FILES = minitalk_utils.h minitalk_server.h minitalk_client.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))
INCLUDES_FLAGS = -I $(INCLUDES_DIR)

# sources
SRC_DIR     = ./srcs
SRC_CLIENT_FILES = client.c 
SRC_SERVER_FILES = server.c
SRC_UTILS_FILES = ft_putendl_fd.c ft_strlen.c ft_atoi.c ft_putnbr_fd.c ft_error.c ft_memset.c

SRC_UTILS = $(addprefix $(SRC_DIR)/utils/, $(SRC_UTILS_FILES))
SRC_CLIENT = $(addprefix $(SRC_DIR)/, $(SRC_CLIENT_FILES)) $(SRC_UTILS)
SRC_SERVER = $(addprefix $(SRC_DIR)/, $(SRC_SERVER_FILES)) $(SRC_UTILS)

OBJ_CLIENT = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_CLIENT))
OBJ_SERVER = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_SERVER))

all: $(SERVER_NAME) $(CLIENT_NAME) 

$(CLIENT_NAME): $(OBJ_CLIENT)
	$(CC) $(C_FLAGS) -o $(CLIENT_NAME) $(OBJ_CLIENT)

$(SERVER_NAME): $(OBJ_SERVER)
	$(CC) $(C_FLAGS) -o $(SERVER_NAME) $(OBJ_SERVER)
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) Makefile
	@$(MKDIR) $(@D)
	$(CC) $(C_FLAGS) -o $@ -c $< $(INCLUDES_FLAGS)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)

re: fclean all

bonus: all

force:
	@true

.PHONY: all clean fclean re bonus force 
