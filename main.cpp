#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

void printMenu() {
    cout << "Меню:" << endl;
    cout << "1. Пошук слова" << endl;
    cout << "2. Додати слово" << endl;
    cout << "3. Видалити слово" << endl;
    cout << "4. Редагувати слово" << endl;
    cout << "5. Зчитати словник з файлу" << endl;
    cout << "6. Записати словник у файл" << endl;
    cout << "7. Вийти з програми" << endl;
    cout << "Виберіть опцію: ";
}

int main() {
    system("chcp 1251");
    system("cls");
    map<string, string> dictionary;
    int choice;
    string word, meaning, filename;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введіть слово для пошуку: ";
            cin >> word;
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                cout << "Знайдено! Значення: " << it->second << endl;
            }
            else {
                cout << "Слово не знайдено." << endl;
            }
            break;
        }
        case 2: {
            cout << "Введіть слово: ";
            cin >> word;
            cout << "Введіть значення: ";
            cin >> meaning;
            dictionary[word] = meaning;
            cout << "Слово успішно додано до словника." << endl;
            break;
        }
        case 3: {
            cout << "Введіть слово для видалення: ";
            cin >> word;
            if (dictionary.erase(word)) {
                cout << "Слово успішно видалено з словника." << endl;
            }
            else {
                cout << "Слово не знайдено у словнику." << endl;
            }
            break;
        }
        case 4: {
            cout << "Введіть слово для редагування: ";
            cin >> word;
            cout << "Введіть нове значення: ";
            cin >> meaning;
            dictionary[word] = meaning;
            cout << "Значення слова успішно оновлено." << endl;
            break;
        }
        case 5: {
            cout << "Введіть ім'я файлу для зчитування: ";
            cin >> filename;
            ifstream inFile(filename);
            if (!inFile.is_open()) {
                cout << "Помилка! Неможливо відкрити файл." << endl;
            }
            else {
                dictionary.clear(); 
                while (inFile >> word >> meaning) {
                    dictionary[word] = meaning;
                }
                cout << "Словник успішно зчитано з файлу." << endl;
                inFile.close();
            }
            break;
        }
        case 6: {
            cout << "Введіть ім'я файлу для запису: ";
            cin >> filename;
            ofstream outFile(filename);
            if (!outFile.is_open()) {
                cout << "Помилка! Неможливо відкрити файл." << endl;
            }
            else {
                for (const auto& pair : dictionary) {
                    outFile << pair.first << " " << pair.second << endl;
                }
                cout << "Словник успішно записано у файл." << endl;
                outFile.close();
            }
            break;
        }
        case 7:
            cout << "До побачення!" << endl;
            break;
        default:
            cout << "Невірний вибір. Будь ласка, виберіть іншу опцію." << endl;
        }
    } while (choice != 7);

    return 0;
}
