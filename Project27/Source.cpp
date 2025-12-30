#include <iostream>
#include <vector>
#include <string>

struct Tusk {
    std::string name;
    int priority;
    std::string description;
    std::string date;

    void input() {
        std::cout << "Напишите имя дела: ";
        std::getline(std::cin, name);

        std::cout << "Напишите приоритет дела (число): ";
        std::string pri_str;
        std::getline(std::cin, pri_str);
        priority = std::stoi(pri_str);

        std::cout << "Напишите описание дела: ";
        std::getline(std::cin, description);

        std::cout << "Напишите дату: ";
        std::getline(std::cin, date);
    }

    void print(int num) const {
        std::cout << "Дело номер " << num << ":\n";
        std::cout << "Имя: " << name << "\n";
        std::cout << "Приоритет: " << priority << "\n";
        std::cout << "Описание: " << description << "\n";
        std::cout << "Дата: " << date << "\n\n";
    }
};

struct TuskManager {
    std::vector<Tusk> tasks;

    void add_task() {
        Tusk new_task;
        new_task.input();
        tasks.push_back(new_task);
        std::cout << "Дело добавлено!\n";
    }

    void print_all() const {
        if (tasks.empty()) {
            std::cout << "Список дел пуст.\n";
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            tasks[i].print(i + 1);
        }
    }

    void remove_task() {
        if (tasks.empty()) {
            std::cout << "Нет дел для удаления.\n";
            return;
        }

        print_all();
        std::cout << "Введите номер дела, которое хотите удалить: ";

        int num;
        std::cin >> num;

        if (num < 1 || num > static_cast<int>(tasks.size())) {
            std::cout << "Неверный номер.\n";
            return;
        }

        tasks.erase(tasks.begin() + num - 1);
        std::cout << "Дело удалено!\n";
    }

    void search_by_name(const std::string& target) {
        bool found = false;
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i].name.find(target) != std::string::npos) {
                tasks[i].print(i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Дела с таким именем не найдено.\n";
        }
    }

    void search_by_priority(int pr) {
        bool found = false;
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i].priority == pr) {
                tasks[i].print(i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Дел с таким приоритетом не найдено.\n";
        }
    }

    void search_by_description(const std::string& desc) {
        bool found = false;
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i].description.find(desc) != std::string::npos) {
                tasks[i].print(i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Дел с таким описанием не найдено.\n";
        }
    }

    void search_by_date(const std::string& dt) {
        bool found = false;
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i].date.find(dt) != std::string::npos) {
                tasks[i].print(i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Дел с такой датой не найдено.\n";
        }
    }

    void choice() {
        while (true) {
            std::cout << "\nМенеджер дел:\n";
            std::cout << "1. Добавить дело\n";
            std::cout << "2. Показать все дела\n";
            std::cout << "3. Удалить дело\n";
            std::cout << "4. Поиск дел\n";
            std::cout << "5. Выйти\n";
            std::cout << "Выберите действие: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                print_all();
                break;
            case 3:
                remove_task();
                break;
            case 4:
                std::cout << "\nТип поиска:\n";
                std::cout << "1. Поиск по названию\n";
                std::cout << "2. Поиск по приоритету\n";
                std::cout << "3. Поиск по описанию\n";
                std::cout << "4. Поиск по дате\n";
                std::cout << "Ваш выбор: ";
                int choice2;
                std::cin >> choice2;

                if (choice2 == 1) {
                    std::cout << "Введите название: ";
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    search_by_name(name);
                }
                else if (choice2 == 2) {
                    std::cout << "Введите приоритет: ";
                    int pri;
                    std::cin >> pri;
                    search_by_priority(pri);
                }
                else if (choice2 == 3) {
                    std::cout << "Введите описание: ";
                    std::string desc;
                    std::cin.ignore();
                    std::getline(std::cin, desc);
                    search_by_description(desc);
                }
                else if (choice2 == 4) {
                    std::cout << "Введите дату: ";
                    std::string dt;
                    std::cin.ignore();
                    std::getline(std::cin, dt);
                    search_by_date(dt);
                }
                else {
                    std::cout << "Ошибка выбора.\n";
                }
                break;
            case 5:
                return;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    TuskManager manager;
    manager.choice();
    return 0;
}