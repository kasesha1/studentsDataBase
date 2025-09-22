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

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "\nГлавное меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Сортировать студентов\n";
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
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
