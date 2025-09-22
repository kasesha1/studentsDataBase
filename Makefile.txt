CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
TARGET = student_db
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: $(TARGET)
	./$(TARGET)  # Можно добавить специальный режим для тестов

clean:
	rm -f $(TARGET)

.PHONY: test clean
