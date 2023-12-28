#include <iostream>
#include <fstream>
#include <sstream>

// Получить расширение файла
std::string file_format(const std::string& file_path_full) {
    std::string extension;
    size_t dotIndex = file_path_full.find_last_of('.');
    if (dotIndex != std::string::npos) {
        extension = file_path_full.substr(dotIndex + 1);
    }
    return extension;
}

// Получить имя файла
std::string file_name(const std::string& file_path_full) {
    size_t slashIndex = file_path_full.find_last_of('/');
    if (slashIndex != std::string::npos) {
        return file_path_full.substr(slashIndex + 1);
    }
    return file_path_full;
}

// Получить путь к файлу
std::string file_path(const std::string& file_path_full) {
    size_t slashIndex = file_path_full.find_last_of('/');
    if (slashIndex != std::string::npos) {
        return file_path_full.substr(0, slashIndex);
    }
    return "";
}

// Получить название диска
char file_disk(const std::string& file_path_full) {
    if (file_path_full.length() > 0 && file_path_full[1] == ':') {
        return file_path_full[0];
    }
    return ' ';
}

// Переименовать файл
bool file_rename(std::string& file_path_full, const std::string& new_name) {
    try {
        std::rename(file_path_full.c_str(), (file_path(file_path_full) + "/" + new_name).c_str());
        file_path_full = file_path(file_path_full) + "/" + new_name;
        return true;
    } catch (const std::exception&) {
        return false;
    }
}

// Создать копию файла
bool file_copy(const std::string& file_path_full) {
    std::ifstream source(file_path_full, std::ios::binary);
    if (!source.is_open()) {
        return false;
    }

    std::string copy_path = file_path_full + "_copy";
    std::ofstream dest(copy_path, std::ios::binary);
    if (!dest.is_open()) {
        source.close();
        return false;
    }

    dest << source.rdbuf();

    source.close();
    dest.close();
    return true;
}

// Отобразить меню
void showMenu() {
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Получить расширение файла" << std::endl;
    std::cout << "2. Получить имя файла" << std::endl;
    std::cout << "3. Получить путь к файлу" << std::endl;
    std::cout << "4. Получить название диска" << std::endl;
    std::cout << "5. Переименовать файл" << std::endl;
    std::cout << "6. Создать копию файла" << std::endl;
    std::cout << "0. Выйти" << std::endl;
}

int main() {
    std::string file_path_full;
    int option;

    do {
        showMenu();
        std::cout << "Выберите опцию: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file_path_full;
                std::cout << "Расширение файла: " << file_format(file_path_full) << std::endl;
                break;
            }
            case 2: {
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file_path_full;
                std::cout << "Имя файла: " << file_name(file_path_full) << std::endl;
                break;
            }
            case 3: {
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file_path_full;
                std::cout << "Путь к файлу: " << file_path(file_path_full) << std::endl;
                break;
            }
            case 4: {
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file_path_full;
                std::cout << "Название диска: " << file_disk(file_path_full) << std::endl;
                break;
            }
            case 5: {
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file_path_full;
                std::string new_name;
                std::cout << "Введите новое имя файла: ";
                std::cin >> new_name;
                if (file_rename(file_path_full, new_name)) {
                    std::cout << "Файл успешно переименован." << std::endl;
                } else {
                    std::cout << "Ошибка при переименовании файла." << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << "Введите полный путь к файлу: ";
                std::cin >> file_path_full;
                if (file_copy(file_path_full)) {
                    std::cout << "Создана копия файла." << std::endl;
                } else {
                    std::cout << "Ошибка при создании копии файла." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Программа завершена." << std::endl;
                break;
            default:
                std::cout << "Некорректная опция. Попробуйте еще раз." << std::endl;
                break;
        }

    } while (option != 0);

    return 0;
}
