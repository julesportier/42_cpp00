###########
# ALIASES #
###########
CXX := c++

#########
# FLAGS #
#########
STD_FLAGS :=	-std=c++98
ERROR_FLAGS :=	-Wall -Werror -Wextra
CXXFLAGS :=		$(STD_FLAGS) $(ERROR_FLAGS)
CXXFLAGS_DB :=	$(CXXFLAGS) -g3
CXXFLAGS_AS :=	$(CXXFLAGS) -g3 -fsanitize=address 
CXXFLAGS_NE :=	$(STD_FLAGS) -Wall -Wextra -g3
CXXFLAGS_REL :=	$(CXXFLAGS) -O2
DEP_FLAGS = 	-MMD

#########
# FILES #
#########
NAME := phonebook

SRC_DIR := src
vpath %.cpp $(SRC_DIR)
SRC :=	phonebook.cpp

BUILD_DIR := build
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP_FILES := $(OBJ:.o=.d)
-include $(DEP_FILES)

###########
# TARGETS #
###########
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

clean:
	rm -rf $(BUILD_DIR)

fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(NAME)

re: fclean all

#########
# RULES #
#########

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) $(DEP_FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

.PHONY: all clean fclean re noerr dbg asan rel
