//Lab13-1
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;
void pressEnterToContinue();
bool readFromFile(string filename);
void CountChars(string filename);
void countWords(string filename);



int main() {
    string datafile;
    cout << "input file: ";
    getline(cin, datafile);
    bool status = readFromFile(datafile);
    if (status) cout << "Success!\n";
    else cout << "failure.\n";
    countWords(datafile);
    CountChars(datafile);
    pressEnterToContinue();
}

bool readFromFile(string filename) {
    ifstream inFile;
    string text;
    istringstream thisLine;
    inFile.open(filename);

    if (inFile.fail()) {
        cout << "read error";
        return false;
    }
    while (true) {
        getline(inFile, text);
        if (inFile.fail()) break;
        thisLine.clear();
        thisLine.str(text);
        cout << text << endl;
    }
    inFile.close();
    return true;
}

void countWords(string filename) {
    ifstream inFile;
    int tot = 0;
    int words = 0;
    string ch;

    inFile.open(filename);
    while (inFile >> ch) {
        for (int i = 0; i < ch.length(); i++) {
            if (ch[i] >= 'a' && ch[i] <= 'z' || ch[i] >= 'A' && ch[i] <= 'Z') {
                words++;
                break;
            }
        }
        
    }
    inFile.close();
    
    cout << "Words: " << words << endl;
}

void CountChars(string filename) {
    ifstream inFile;
    int tot = 0;
    char ch;
    inFile.open(filename);
    while (inFile >> ch) {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
            tot++;
        }
    }
    inFile.close();
    cout << "Characters: " << tot << endl;
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n');
}
