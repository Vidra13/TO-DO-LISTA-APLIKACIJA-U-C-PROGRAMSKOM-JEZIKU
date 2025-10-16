# Makefile za To-Do Lista aplikaciju

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = todo
SOURCE = todo.c

# Kompajliranje programa
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)
	@echo "Kompajliranje zavrseno! Pokrenite program sa: ./$(TARGET)"

# Čišćenje kompajliranih fajlova
clean:
	rm -f $(TARGET) tasks.txt
	@echo "Fajlovi obrisani!"

# Pokretanje programa
run: all
	./$(TARGET)

# Help komanda
help:
	@echo "Dostupne komande:"
	@echo "  make          - Kompajlira program"
	@echo "  make run      - Kompajlira i pokrece program"
	@echo "  make clean    - Brise kompajlirane fajlove"
	@echo "  make help     - Prikazuje ovu pomoc"
