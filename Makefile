CC = gcc
BISON = bison
FLEX = flex

SRC_DIR = src
PARSER_DIR = $(SRC_DIR)/parser

all: parser

parser: $(SRC_DIR)/main.c $(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/lexer.c
	$(CC) -o parser $(SRC_DIR)/main.c $(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/lexer.c -lfl

$(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/parser.tab.h: $(PARSER_DIR)/parser.y
	$(BISON) -d -o $(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/parser.y

$(PARSER_DIR)/lexer.c: $(PARSER_DIR)/lexer.l $(PARSER_DIR)/parser.tab.h
	$(FLEX) -o $(PARSER_DIR)/lexer.c $(PARSER_DIR)/lexer.l

clean:
	rm -f parser $(PARSER_DIR)/parser.tab.c $(PARSER_DIR)/parser.tab.h $(PARSER_DIR)/lexer.c parser

.PHONY: all clean