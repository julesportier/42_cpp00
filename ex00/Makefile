CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra
CXXFLAGS_DB := -std=c++98 -Wall -Werror -Wextra -g3
CXXFLAGS_AS := -std=c++98 -Wall -Werror -Wextra -g3 -fsanitize=address 
CXXFLAGS_NE := -std=c++98 -g3
CXXFLAGS_REL := -std=c++98 -Wall -Werror -Wextra -O2

NAME := megaphone

SRC_DIR := src
vpath %.cpp $(SRC_DIR)
SRC := megaphone.cpp

BUILD_DIR := build
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP_FLAGS = -MMD
DEP_FILES := $(OBJ:.o=.d)

all: $(BUILD_DIR) $(NAME)

noerr: CXXFLAGS = $(CXXFLAGS_NE)
noerr: all
dbg: CXXFLAGS = $(CXXFLAGS_DB)
dbg: all
asan: CXXFLAGS = $(CXXFLAGS_AS)
asan: cc = clang
asan: all
rel: CXXFLAGS = $(CXXFLAGS_REL)
rel: all

-include $(DEP_FILES)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) $(DEP_FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re noerr dbg asan rel
