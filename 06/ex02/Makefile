NAME = dynamic
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Base.cpp
OBJS_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32mCompilation terminée avec succès ✅\033[0m"

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Nettoyage des fichiers objets effectué."

fclean: clean
	@rm -rf $(NAME)
	@echo "Nettoyage complet effectué."

re: fclean all

.PHONY: all clean fclean re
