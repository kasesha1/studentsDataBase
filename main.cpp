#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iomanip>   
#include <cassert>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin.ignore(); 
    std::getline(std::cin, student.name);
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin.ignore();
    std::getline(std::cin, student.major);
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "\nСписок студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << std::fixed << std::setprecision(2) << student.gpa << "\n\n";
    }
}

// Функция для сортировки по имени (по возрастанию)
void sortByName(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.name < b.name;
        });
    std::cout << "Сортировка по имени завершена.\n";
}

// Функция для сортировки по имени (по убыванию)
void sortByNameDesc(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.name > b.name;
        });
    std::cout << "Сортировка по имени (по убыванию) завершена.\n";
}

// Функция для сортировки по среднему баллу (по возрастанию)
void sortByGPA(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.gpa < b.gpa;
        });
    std::cout << "Сортировка по среднему баллу завершена.\n";
}

// Функция для сортировки по среднему баллу (по убыванию)
void sortByGPADesc(std::vector<Student>& database) {
    std::sort(database.begin(), database.end(), 
        [](const Student& a, const Student& b) {
            return a.gpa > b.gpa;
        });
    std::cout << "Сортировка по среднему баллу (по убыванию) завершена.\n";
}

// Функция для отображения меню сортировки
void showSortMenu() {
    std::cout << "\nМеню сортировки:\n";
    std::cout << "1. Сортировать по имени (А-Я)\n";
    std::cout << "2. Сортировать по имени (Я-А)\n";
    std::cout << "3. Сортировать по среднему баллу (по возрастанию)\n";
    std::cout << "4. Сортировать по среднему баллу (по убыванию)\n";
    std::cout << "0. Назад в главное меню\n";
    std::cout << "Выберите действие: ";
}

void runTests() {
    std::cout << "\n=== ЗАПУСК ТЕСТОВ ===\n";
    
    // Тест 1: Сортировка по имени (по возрастанию)
    std::vector<Student> testDb1 = {
        {"Иван", 20, "Прогрммист", 73.8},
        {"Анастасия", 21, "Химик", 84.0},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByName(testDb1);
    assert(testDb1[0].name == "Анастасия");
    assert(testDb1[1].name == "Иван");
    assert(testDb1[2].name == "Станислав");
    std::cout << "✔ Тест 1: Сортировка по имени (А-Я) пройден\n";
    
    // Тест 2: Сортировка по имени (по убыванию)
    std::vector<Student> testDb2 = {
        {"Иван", 20, "Прогрммист", 73.8},
        {"Анастасия", 21, "Химик", 84.0},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByNameDesc(testDb2);
    assert(testDb2[0].name == "Станислав");
    assert(testDb2[1].name == "Иван");
    assert(testDb2[2].name == "Анастасия");
    std::cout << "✔ Тест 2: Сортировка по имени (Я-А) пройден\n";
    
    // Тест 3: Сортировка по среднему баллу (по возрастанию)
    std::vector<Student> testDb3 = {
        {"Иван", 20, "Прогрммист", 73.8},
        {"Анастасия", 21, "Химик", 84.0},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByGPA(testDb3);
    assert(testDb3[0].gpa == 73.5);
    assert(testDb3[1].gpa == 73.8);
    assert(testDb3[2].gpa == 84.0);
    std::cout << "✔ Тест 3: Сортировка по GPA (возрастание) пройден\n";
    
    // Тест 4: Сортировка по среднему баллу (по убыванию)
    std::vector<Student> testDb4 = {
        {"Иван", 20, "Прогрммист", 73.8},
        {"Анастасия", 21, "Химик", 84.0},
        {"Станислав", 19, "Инженер", 73.5}
    };
    
    sortByGPADesc(testDb4);
    assert(testDb4[0].gpa == 84.0);
    assert(testDb4[1].gpa == 73.8);
    assert(testDb4[2].gpa == 73.5);
    std::cout << "✔ Тест 4: Сортировка по GPA (убывание) пройден\n";
    
    // Тест 5: Пустая база данных (граничный случай)
    std::vector<Student> emptyDb;
    sortByName(emptyDb);    // Не должно вызывать ошибок
    sortByGPADesc(emptyDb); // Не должно вызывать ошибок
    std::cout << "✔ Тест 5: Работа с пустой базой данных пройден\n";
    
    // Тест 6: Одинаковые имена (дополнительный тест)
    std::vector<Student> sameNamesDb = {
        {"Иван", 20, "Прогрммист", 73.8},
        {"Иван", 21, "Химик", 84.0},
        {"Анастасия", 19, "Инженер", 73.5}
    };
    
    sortByName(sameNamesDb);
    assert(sameNamesDb[0].name == "Анастасия");
    assert(sameNamesDb[1].name == "Иван");
    assert(sameNamesDb[2].name == "Иван");
    std::cout << "✔ Тест 6: Сортировка с одинаковыми именами пройден\n";
    
    std::cout << "=== ВСЕ 6 ТЕСТОВ ПРОЙДЕНЫ УСПЕШНО! ===\n\n";
}


int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "\nГлавное меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Сортировать студентов\n";
        std::cout << "4. Запустить тесты\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3: {
                int sortChoice;
                do {
                    showSortMenu();
                    std::cin >> sortChoice;
                    
                    switch (sortChoice) {
                        case 1:
                            sortByName(database);
                            break;
                        case 2:
                            sortByNameDesc(database);
                            break;
                        case 3:
                            sortByGPA(database);
                            break;
                        case 4:
                            sortByGPADesc(database);
                            break;
                        case 0:
                            std::cout << "Возврат в главное меню.\n";
                            break;
                        default:
                            std::cout << "Неверный выбор. Попробуйте снова.\n";
                    }
                } while (sortChoice != 0);
                break;
            }
            case 4:
                runTests();
                break; 
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
