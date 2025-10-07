#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>


struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};


void sortByName(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.name < b.name;
        });
}

void sortByNameDesc(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.name > b.name;
        });
}

void sortByGPA(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.gpa < b.gpa;
        });
}

void sortByGPADesc(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.gpa > b.gpa;
        });
}

// Вспомогательная функция для проверки сортировки
bool isSortedByName(const std::vector<Student>& database) {
    for (size_t i = 1; i < database.size(); ++i) {
        if (database[i-1].name > database[i].name) return false;
    }
    return true;
}

// Тесты
TEST(SortingTest, SortByNameAscending) {
    std::vector<Student> students = {
        {"Иван", 20, "Программист", 73.8},
        {"Анастасия", 21, "Химик", 84.0},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByName(students);
    
    EXPECT_EQ(students[0].name, "Анастасия");
    EXPECT_EQ(students[1].name, "Иван");
    EXPECT_EQ(students[2].name, "Станислав");
    EXPECT_TRUE(isSortedByName(students));
}

TEST(SortingTest, SortByNameDescending) {
    std::vector<Student> students = {
        {"Анастасия", 21, "Химик", 84.0},
        {"Иван", 20, "Программист", 73.8},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByNameDesc(students);
    
    EXPECT_EQ(students[0].name, "Станислав");
    EXPECT_EQ(students[1].name, "Иван");
    EXPECT_EQ(students[2].name, "Анастасия");
}

TEST(SortingTest, SortByGPAAscending) {
    std::vector<Student> students = {
        {"Иван", 20, "Программист", 73.8},
        {"Анастасия", 21, "Химик", 84.0},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByGPA(students);
    
    EXPECT_DOUBLE_EQ(students[0].gpa, 73.5);
    EXPECT_DOUBLE_EQ(students[1].gpa, 73.8);
    EXPECT_DOUBLE_EQ(students[2].gpa, 84.0);
}

TEST(SortingTest, SortByGPADescending) {
    std::vector<Student> students = {
        {"Станислав", 19, "Инженер", 73.5},
        {"Иван", 20, "Программист", 73.8},
        {"Анастасия", 21, "Химик", 84.0}
    };
    
    sortByGPADesc(students);
    
    EXPECT_DOUBLE_EQ(students[0].gpa, 84.0);
    EXPECT_DOUBLE_EQ(students[1].gpa, 73.8);
    EXPECT_DOUBLE_EQ(students[2].gpa, 73.5);
}

TEST(SortingTest, EmptyVector) {
    std::vector<Student> students;
    
    EXPECT_NO_THROW(sortByName(students));
    EXPECT_NO_THROW(sortByNameDesc(students));
    EXPECT_NO_THROW(sortByGPA(students));
    EXPECT_NO_THROW(sortByGPADesc(students));
    EXPECT_TRUE(students.empty());
}

TEST(SortingTest, SameNames) {
    std::vector<Student> students = {
        {"Иван", 20, "Программист", 73.5},
        {"Иван", 21, "Химик", 84.0},
        {"Анастасия", 19, "Инженер", 73.8}
    };
    
    sortByName(students);
    
    EXPECT_EQ(students[0].name, "Анастасия");
    EXPECT_EQ(students[1].name, "Иван");
    EXPECT_EQ(students[2].name, "Иван");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
