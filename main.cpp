#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

void printMenu() {
    cout << "����:" << endl;
    cout << "1. ����� �����" << endl;
    cout << "2. ������ �����" << endl;
    cout << "3. �������� �����" << endl;
    cout << "4. ���������� �����" << endl;
    cout << "5. ������� ������� � �����" << endl;
    cout << "6. �������� ������� � ����" << endl;
    cout << "7. ����� � ��������" << endl;
    cout << "������� �����: ";
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
            cout << "������ ����� ��� ������: ";
            cin >> word;
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                cout << "��������! ��������: " << it->second << endl;
            }
            else {
                cout << "����� �� ��������." << endl;
            }
            break;
        }
        case 2: {
            cout << "������ �����: ";
            cin >> word;
            cout << "������ ��������: ";
            cin >> meaning;
            dictionary[word] = meaning;
            cout << "����� ������ ������ �� ��������." << endl;
            break;
        }
        case 3: {
            cout << "������ ����� ��� ���������: ";
            cin >> word;
            if (dictionary.erase(word)) {
                cout << "����� ������ �������� � ��������." << endl;
            }
            else {
                cout << "����� �� �������� � ��������." << endl;
            }
            break;
        }
        case 4: {
            cout << "������ ����� ��� �����������: ";
            cin >> word;
            cout << "������ ���� ��������: ";
            cin >> meaning;
            dictionary[word] = meaning;
            cout << "�������� ����� ������ ��������." << endl;
            break;
        }
        case 5: {
            cout << "������ ��'� ����� ��� ����������: ";
            cin >> filename;
            ifstream inFile(filename);
            if (!inFile.is_open()) {
                cout << "�������! ��������� ������� ����." << endl;
            }
            else {
                dictionary.clear(); 
                while (inFile >> word >> meaning) {
                    dictionary[word] = meaning;
                }
                cout << "������� ������ ������� � �����." << endl;
                inFile.close();
            }
            break;
        }
        case 6: {
            cout << "������ ��'� ����� ��� ������: ";
            cin >> filename;
            ofstream outFile(filename);
            if (!outFile.is_open()) {
                cout << "�������! ��������� ������� ����." << endl;
            }
            else {
                for (const auto& pair : dictionary) {
                    outFile << pair.first << " " << pair.second << endl;
                }
                cout << "������� ������ �������� � ����." << endl;
                outFile.close();
            }
            break;
        }
        case 7:
            cout << "�� ���������!" << endl;
            break;
        default:
            cout << "������� ����. ���� �����, ������� ���� �����." << endl;
        }
    } while (choice != 7);

    return 0;
}
