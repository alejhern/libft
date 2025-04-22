# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:12:48 by alejhern          #+#    #+#              #
#    Updated: 2024/09/16 22:04:04 by alejhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

OBJS_DIR  = objs
DEPS_DIR  = deps

SRCS      = ft_array_mods.c \
            ft_atoi.c \
            ft_atol.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_env.c \
            ft_error_exit.c \
            ft_exec_catch.c \
            ft_execute.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isnum.c \
            ft_isprint.c \
            ft_itoa.c \
            ft_itoa_base.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memlen.c \
            ft_memmove.c \
            ft_memset.c \
            ft_nblen.c \
            ft_pipex.c \
            ft_pos.c \
            ft_printf.c \
            ft_printf_float.c \
            ft_printf_parse_flags.c \
            ft_printf_printers.c \
            ft_putchar_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
            ft_putstr_fd.c \
            ft_realloc.c \
            ft_split.c \
            ft_strappend.c \
            ft_strchr.c \
            ft_strdup.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmapi.c \
            ft_strncmp.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strtrim.c \
            ft_substr.c \
            ft_tolower.c \
            ft_toupper.c \
            get_next_line.c \
            pipex_utils.c

SRCS_B    = ft_lstadd_back_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstclear_bonus.c \
            ft_lstdelone_bonus.c \
            ft_lstiter_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstmap_bonus.c \
            ft_lstnew_bonus.c \
            ft_lstsize_bonus.c

OBJS      = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_B    = $(SRCS_B:%.c=$(OBJS_DIR)/%.o)
DEPS      = $(SRCS:%.c=$(DEPS_DIR)/%.d) $(SRCS_B:%.c=$(DEPS_DIR)/%.d)

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME      = libft.a
FLAGS     = -g -Wall -Werror -Wextra -I.
DEPFLAGS  = -MMD -MP
BUFFER_SIZE ?= 42
CFLAGS    += -DBUFFER_SIZE=$(BUFFER_SIZE)

# Calculamos el total de archivos a compilar
TOTAL_SRCS = $(words $(SRCS) $(SRCS_B))
COMPILED = 0

# **************************************************************************** #
#                                 FUNCIONES                                    #
# **************************************************************************** #

define print_progress
	@printf "\033[2K\r"  # Limpia la línea actual
	@printf "$(CYAN)["
	@for i in $$(seq 1 $(1)); do printf "#"; done
	@for i in $$(seq $$(($(1) + 1)) 20); do printf " "; done
	@printf "] $(2)%% $(GREEN)(%d/%d)%-3s$(RESET)" $(3) $(4)
	@printf "\033[1B"  # Mueve el cursor abajo para la siguiente línea
endef

define reset_cursor
	@printf "\033[$(1)A"  # Mueve el cursor arriba N líneas
endef

# **************************************************************************** #
#                                 COLORES                                      #
# **************************************************************************** #

RESET   = \033[0m
RED     = \033[38;5;196m
YELLOW  = \033[38;5;220m
GREEN   = \033[38;5;46m
CYAN    = \033[38;5;51m
MAGENTA = \033[38;5;198m
WHITE   = \033[97m
PURPLE  = \033[38;5;129m
ORANGE  = \033[38;5;214m
BLUE    = \033[38;5;33m
NEON    = \033[38;5;201m

# **************************************************************************** #
#                                 REGLAS                                       #
# **************************************************************************** #

all: banner dirs $(NAME) bonus

banner:
	@echo "$(NEON)"
	@echo "╔══════════════════════════════════════════════════╗"
	@echo "║ $(YELLOW)██╗     ██╗██████╗ ███████╗████████╗  $(BLUE)🚀  MAKE   $(NEON)║"
	@echo "║ $(YELLOW)██║     ██║██╔══██╗██╔════╝╚══██╔══╝  $(BLUE)✨  READY  $(NEON)║"
	@echo "║ $(YELLOW)██║     ██║██████╔╝█████╗     ██║     $(BLUE)🎯  TO     $(NEON)║"
	@echo "║ $(YELLOW)██║     ██║██╔══██╗██╔══╝     ██║     $(BLUE)🏆  ROC    $(NEON)║"
	@echo "║ $(YELLOW)███████╗██║██████╔╝██║        ██║                $(NEON)║"
	@echo "║ $(YELLOW)╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝                $(NEON)║"
	@echo "╚══════════════════════════════════════════════════╝"
	@echo "$(RESET)"

dirs:
	@mkdir -p $(OBJS_DIR) $(DEPS_DIR)
	@echo "📂 Directorios creados: $(YELLOW)$(OBJS_DIR) $(DEPS_DIR)$(RESET)"

update:
	@echo "🔄 Actualizando Libft..." 
	@if git pull 2>&1 | grep -q "fatal"; then \
		echo "⚠️  $(RED)Error: No se pudo actualizar la Libft.$(RESET)"; \
	else \
		echo "✅ $(GREEN)Libft actualizada!$(RESET)"; \
	fi

$(OBJS_DIR)/%.o: %.c | dirs
	@$(eval COMPILED=$(shell expr $(COMPILED) + 1))
	@$(eval PERCENT=$(shell expr $(COMPILED) \* 100 / $(TOTAL_SRCS)))
	@$(eval PROGRESS=$(shell expr $(PERCENT) \* 20 / 100))
	@$(call print_progress,$(PROGRESS),$(PERCENT),$(COMPILED),$(TOTAL_SRCS))
	@printf "$(CYAN)🔧 Compilando: $(YELLOW)%-30s$(RESET)" "$<"
	@cc $(FLAGS) $(DEPFLAGS) -c -o $@ $< -MF $(DEPS_DIR)/$*.d
	@printf "✅ Objeto generado: $(GREEN)%s $(MAGENTA)🌟$(RESET)\n" "$@"

-include $(DEPS)

$(NAME): update $(OBJS)
	@echo "$(MAGENTA)🔗 Creando librería: $(YELLOW)$(NAME)$(RESET)"
	@ar -rcs $(NAME) $(OBJS)
	@echo "🎉 $(GREEN)Librería completada: $(YELLOW)$(NAME)$(RESET) 🎉"

bonus: update $(OBJS_B)
	@echo "$(MAGENTA)✨ Compilando versión BONUS$(RESET)"
	@ar -rcs $(NAME) $(OBJS_B)
	@echo "🏆 $(ORANGE)¡Versión BONUS completada!$(RESET) 🎊"

clean:
	@rm -rf $(OBJS_DIR) $(DEPS_DIR)
	@echo "🧹 $(RED)Objetos eliminados: $(YELLOW)$(OBJS_DIR) $(DEPS_DIR)$(RESET) 🗑️"

fclean: clean
	@rm -f $(NAME)
	@echo "💥 $(RED)Librería eliminada: $(YELLOW)$(NAME)$(RESET) 💣"

re: fclean all
	@echo "$(CYAN)♻️  Reconstrucción completada!$(RESET) 🔄"

merge_in_master:
	@echo "Current branch: $(shell git rev-parse --abbrev-ref HEAD)"
	@if [ "$(shell git rev-parse --abbrev-ref HEAD)" = "developing" ]; then \
        echo "🔄 Cambiando a la rama 'master' y haciendo merge..."; \
		git checkout master && \
		git merge developing && \
		echo "✅ Merge completado!"; \
        echo "🔄 Subiendo cambios a la rama 'master'..."; \
		git push origin master && \
        echo "✅ Cambios subidos!"; \
        echo "$(CYAN)🔄 Cambiando a la rama 'developing'$(RESET) 🔄"; \
		git checkout developing; \
	else \
		echo "🚫 No estás en la rama 'developing'"; \
	fi

.PHONY: all clean fclean re bonus update dirs merge_in_master
