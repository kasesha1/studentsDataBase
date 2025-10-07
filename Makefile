CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
TARGET = student_db
TEST_TARGET = student_tests
MAIN_SRC = main.cpp
TEST_SRC = tests.cpp

# Основная программа
$(TARGET): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_SRC)

# Google Tests
$(TEST_TARGET): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -I/usr/include/gtest -L/usr/lib/x86_64-linux-gnu $(TEST_SRC) -lgtest -lpthread -o $(TEST_TARGET)

# Запуск Google Tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.gcno *.gcda *.gcov

.PHONY: test run-app-tests clean
