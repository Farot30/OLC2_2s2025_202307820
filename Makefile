CC = gcc
BISON = bison
FLEX = flex

SRC_DIR = src
PARSER_DIR = $(SRC_DIR)/parser
AST_DIR = $(SRC_DIR)/AST

all: parser

parser: $(SRC_DIR)/main.c \
    	$(PARSER_DIR)/parser.tab.c \
    	$(PARSER_DIR)/lexer.c \
    	$(AST_DIR)/ast.c \
    	$(SRC_DIR)/semantico/semantico.c \
    	$(SRC_DIR)/semantico/tipos.c \
    	$(SRC_DIR)/semantico/tabla_simbolo.c \
    	$(SRC_DIR)/semantico/Instrucciones/asignacion.c \
    	$(SRC_DIR)/semantico/Instrucciones/declaracion.c
	$(CC) -o parser $(SRC_DIR)/main.c \
    	$(PARSER_DIR)/parser.tab.c \
    	$(PARSER_DIR)/lexer.c \
    	$(AST_DIR)/ast.c \
    	$(SRC_DIR)/semantico/semantico.c \
    	$(SRC_DIR)/semantico/tipos.c \
    	$(SRC_DIR)/semantico/tabla_simbolo.c \
    	$(SRC_DIR)/semantico/Instrucciones/asignacion.c \
    	$(SRC_DIR)/semantico/Instrucciones/declaracion.c -lfl

$(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/parser.tab.h: $(PARSER_DIR)/parser.y
	$(BISON) -d -o $(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/parser.y

$(PARSER_DIR)/lexer.c: $(PARSER_DIR)/lexer.l $(PARSER_DIR)/parser.tab.h
	$(FLEX) -o $(PARSER_DIR)/lexer.c $(PARSER_DIR)/lexer.l

clean:
	rm -f parser $(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/parser.tab.h $(PARSER_DIR)/lexer.c parser

.PHONY: all clean