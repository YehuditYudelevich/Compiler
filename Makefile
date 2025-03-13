# שם קובץ הבינארי
TARGET = cpq

# קבצי המקור
LEXER_SRC = lexer.l
PARSER_SRC = parser.y
MAIN_SRC = main.c
AST_SRC = ast.c  # 📌 הוספת קובץ ast.c

# קבצי הפלט מ-Lex ו-Bison
LEXER_C = lexer.c
PARSER_C = parser.c
PARSER_H = parser.tab.h

# מהדר
CC = gcc

# דגלים לקימפול
CFLAGS = -Wall -g
LDFLAGS = -lfl  # מחייב את הספרייה של flex

# פקודת ברירת מחדל – בניית המהדר
all: $(TARGET)

# בונים את הפרסר (Bison) לפני הלקסר
$(PARSER_C) $(PARSER_H): $(PARSER_SRC)
	bison -d -o $(PARSER_C) $(PARSER_SRC)

# בונים את הלקסר (Flex) אחרי שהפרסר נוצר
$(LEXER_C): $(LEXER_SRC) $(PARSER_H)
	flex -o $(LEXER_C) $(LEXER_SRC)

# קומפילציה של כל הקבצים
$(TARGET): $(LEXER_C) $(PARSER_C) $(AST_SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(LEXER_C) $(PARSER_C) $(AST_SRC) $(MAIN_SRC) $(LDFLAGS)

# ניקוי קבצים שנוצרו במהלך הקומפילציה
clean:
	rm -f $(TARGET) $(LEXER_C) $(PARSER_C) $(PARSER_H)
