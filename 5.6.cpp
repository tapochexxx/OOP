/*Разбить текст, хранящийся в текстовом файле,
на слова и вывести их в обратном порядке, используя объявление и методы соответствующего
параметризированного класса vector из стандартной библиотеки шаблонов STL.
Результат записать в новый текстовый файл.*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Error1 (opening input file!)" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error1 (opening output file!)" << endl;
        return 2;
    }

    vector<char> delimiters = { ' ', ',', '.', ';', '!', '?', '(', ')', '\0' };
    vector<vector<char>> words;
    vector<char> word;

    cout << "Text:" << endl;

    char c;
    while (inputFile.get(c)) {
        bool isDelimiter = false;
        for (int i = 0; i < delimiters.size(); i++) {
            char delimiter = delimiters[i];
            if (c == delimiter) isDelimiter = true;
        }

        if (isDelimiter) {
            words.push_back(word);
            word.clear();
        }
        else word.push_back(c);
        cout << c;
    }

    cout << endl << "New words:" << endl;
    for (int i = words.size()-1; i >= 0; i--) {
        for (int j = 0; j < words[i].size(); j++) {
            char c = words[i][j];
            outputFile << c;
            cout << c;
        }
        outputFile << " ";
        cout << " ";
    }

    cout << endl << "Words are written to output.txt" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
