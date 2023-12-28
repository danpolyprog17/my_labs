#include <iostream>
#include <cstring>

void showMenu();

void readString(char* text) {  // Функция для считывания строки из консоли
    int i = 0;
    std::cin >> text[i];
    while (text[i] != '.') {
        i++;
        std::cin >> text[i];
    }
    text[i] = '\0';
}

bool isPalindrome(char* text) { // проверка на палиндром
    int len = strlen(text);
    int i = 0, j = len - 1;

    while (i < j) {
        while (!isalpha(text[i])) {
            i++;
        }
        while (!isalpha(text[j])) {
            j--;
        }

        if (std::isupper(text[i])) {
            text[i] = std::tolower(text[i]);
        }
        if (std::isupper(text[j])) {
            text[j] = std::tolower(text[j]);
        }

        if (text[i] != text[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int* findSubstring(const char* str_for_search_in, const char* substring) {
    int len1 = strlen(str_for_search_in);
    int len2 = strlen(substring);
    int count = 0;

    for (int i = 0; i <= len1 - len2; ++i) {
        int j;
        for (j = 0; j < len2; ++j) {
            if (str_for_search_in[i + j] != substring[j]) {
                break;
            }
        }
        if (j == len2) {
            count++;
        }
    }

    int* positions = new int[count];
    int index = 0;

    for (int i = 0; i <= len1 - len2; ++i) {
        int j;
        for (j = 0; j < len2; ++j) {
            if (str_for_search_in[i + j] != substring[j]) {
                break;
            }
        }
        if (j == len2) {
            positions[index++] = i;
        }
    }

    return positions;
}

void encrypt(char* str_for_encrypt, int key) {
    int len = strlen(str_for_encrypt);
    for (int i = 0; i < len; ++i) {
        if (isalpha(str_for_encrypt[i])) {
            if (isupper(str_for_encrypt[i])) {
                str_for_encrypt[i] = char(int(str_for_encrypt[i] + key - 65) % 26 + 65);
            } else {
                str_for_encrypt[i] = char(int(str_for_encrypt[i] + key - 97) % 26 + 97);
            }
        }
    }
}

void printNames(const char* text) {
    bool inQuotes = false;
    for (int i = 0; i < strlen(text); ++i) {
        if (text[i] == '"') {
            inQuotes = !inQuotes;
        } else if (inQuotes) {
            std::cout << text[i];
        } else if (text[i] == ' ' && !inQuotes) {
            std::cout << " | ";
        }
    }
}

void showMenu() {
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Проверка на палиндром" << std::endl;
    std::cout << "2. Поиск подстроки в строке" << std::endl;
    std::cout << "3. Шифрование сдвигами (шифр Цезаря)" << std::endl;
    std::cout << "4. Вывод всех названий из текста" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
}

int main() 
{
    const int maxLength = 255;
    char input[maxLength];

    int option;
    do {
        showMenu();
        std::cout << "Выберите опцию: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cin.ignore();
                std::cout << "Введите строку: ";
                std::cin.getline(input, maxLength);
                if (isPalindrome(input)) {
                    std::cout << "Это палиндром." << std::endl;
                } else {
                    std::cout << "Это не палиндром." << std::endl;
                }
                break;
            }
            case 2: {
                std::cin.ignore(); // Очищаем буфер ввода
                std::cout << "Введите строку для поиска: ";
                std::cin.getline(input, maxLength);
                
                const char* substring = "ghd";

                int* positions = findSubstring(input, substring);
                std::cout << "Выход: [";
                for (int i = 0; i < strlen(input); ++i) {
                    std::cout << positions[i];
                    if (i != strlen(input) - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << "]" << std::endl;
                delete[] positions;
                break;
            }

            case 3: {
                std::cin.ignore(); // Очистка буфера
                std::cout << "Введите строку для шифрования: ";
                std::cin.getline(input, maxLength);
                encrypt(input, 2);
                std::cout << "Зашифрованная строка: " << input << std::endl;
                break;
            }
            case 4: {
                std::cin.ignore(); // Очищаем буфер ввода
                std::cout << "Введите текст для поиска названий: ";
                std::cin.getline(input, maxLength);

                std::cout << "Выход: ";
                printNames(input);
                std::cout << std::endl;
                break;
            }
            case 0:
                std::cout << "Программа завершена." << std::endl;
                break;
            default:
                std::cout << "Некорректная опция. Попробуйте еще раз." << std::endl;
                break;
        }
        
    } 
    while (option != 0);

    return 0;
}
