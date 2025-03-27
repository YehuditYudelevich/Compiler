# 🔹 שם קובץ הבינארי
TARGET = cpq

# 🔹 קבצי המקור
LEXER_SRC = lexer.l
PARSER_SRC = parser.y
MAIN_SRC = main.c
AST_SRC = ast.c
QUAD_SRC = quad.c
CODEGEN_SRC = codegen.c

# 🔹 קבצי פלט מ-Flex ו-Bison
LEXER_C = lexer.c
PARSER_C = parser.c
PARSER_H = parser.tab.h

# 🔹 מהדר ודגלים
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lfl

# 🔹 מטרת ברירת מחדל
all: $(TARGET)

# 🔹 Bison – parser.c והקובץ כותרת שלו
$(PARSER_C) $(PARSER_H): $(PARSER_SRC)
	bison -d -o $(PARSER_C) $(PARSER_SRC)

# 🔹 Flex – lexer.c (דורש את parser.tab.h)
$(LEXER_C): $(LEXER_SRC) $(PARSER_H)
	flex -o $(LEXER_C) $(LEXER_SRC)

# 🔹 קומפילציה לקובץ בינארי
$(TARGET): $(LEXER_C) $(PARSER_C) $(MAIN_SRC) $(AST_SRC) $(QUAD_SRC) $(CODEGEN_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(LEXER_C) $(PARSER_C) $(MAIN_SRC) $(AST_SRC) $(QUAD_SRC) $(CODEGEN_SRC) $(LDFLAGS)

# 🔹 ניקוי קבצים שנוצרו
clean:
	rm -f $(TARGET) $(LEXER_C) $(PARSER_C) $(PARSER_H)
