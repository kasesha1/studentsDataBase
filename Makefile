CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
TARGET = student_db
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

coverage: $(SRC)
	$(CXX) $(CXXFLAGS) --coverage -fprofile-arcs -ftest-coverage -o $(TARGET)_cov $(SRC)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET)_cov *.gcno *.gcda *.gcov

.PHONY: test clean coverage
