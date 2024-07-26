#include "TextEditorLibrary.h"

void isExist(string& filename){
    file.open(filename, ios::in);
    if(file.is_open()){
        cout << "File " << filename << " is already exist.\n" ;
    }
    else{
        file.open(filename, ios::out);
        if(file.is_open()){
            cout << "File " << filename << " is not exist and has been created.\n";
        }
        else{
            cout << "Failed to create the file.\n";
        }
    }
    file.close();
}
void appendText(string& filename) {
    file.open(filename, ios::app);
    string text;

    cout << "Enter the text: ";
    getline(cin >> ws, text);
    file << text << "\n";

    cout << "Text has been added to the file.\n\n";
    file.close();
}

void displayContent(string& filename){
    file.open(filename, ios::in);
    if(file.is_open()) {
        file.seekg(0,ios::end);
        if (file.tellp() == 0) {
            cout << "File "<< filename << " is empty.\n\n";
        }
        else {
            file.seekg(ios::beg);
            cout << "Content inside the file: \n";
            cout << file.rdbuf() << endl;
        }
    }
    else{
        cout << "File is not exist.\n\n";
    }
    file.close();
}
void emptyFile(string& filename){
    file.open(filename, ios::trunc | ios::out);
    if(file.is_open()) {
        cout<< "File is Empty.\n\n";
    }else{
        cout << "File is not exist.\n\n";
    }
    file.close();
}

void encryptFile(string& filename){
    file.open(filename,ios::in);
    file2.open("EncryptedFile.txt", ios::out);
    string text;
    while(file >> text){
        for(char& ch : text){
            ch += 1;
        }
        file2 << text;
    }
    cout << "File encrypted successfully, and written to EncryptedFile.txt file.\n\n";
    file.close();
    file2.close();
}

void decryptFile(string& filename){
    file.open(filename,ios::in);
    file2.open("DecryptedFile.txt", ios::out);
    string text;
    while(file >> text){
        for(char& ch : text){
            ch -= 1;
        }
        file2 << text;
    }
    cout << "File decrypted successfully, and written to DecryptedFile.txt file.\n\n";
    file.close();
    file2.close();
}

void mergeFile(string& filename){
    file.open(filename,ios::app);
    string filename2,text;
    cout << "Enter the name of the other file: "; cin >> filename2;
    if(filename2.find(".txt") == string::npos)
    {
        filename2 += ".txt";
    }
    file2.open(filename2,ios::in);
    while(getline(file2,text,'\n')){
        file << text << endl;
    }
    cout << "Two files merged in " << filename << " \n\n";
    file.close();
    file2.close();
}

int countWords(string& filename){
    file.open(filename,ios::in);
    int count = 0; string word;
    while(file >> word){
        count++;
    }
    file.close();
    return count;
}
int countChars(string& filename){
    file.open(filename, ios::in);
    int count = 0; char ch;
    while(file >> ch){
        count++;
    }
    file.close();
    return count;
}
int countLines(string& filename){
    file.open(filename,ios::in);
    int count = 0; string line;
    while(getline(file, line)){
        count++;
    }
    file.close();
    return count;
}
bool searchWord(string& filename){
    file.open(filename, ios::in);
    string words, word;
    cout << "Please, Enter the word you want to search for: ";
    cin >> word;
    while(file >> words){
        if(word == words){
            return true;
        }
    }
    file.close();
    return false;
}

int wordCount(string& filename){
    file.open(filename, ios::in);
    string words, word;
    int count = 0;
    cout << "Please, Enter the word you want to count its existence in the file: "; cin >> word;
    while(file >> words){
        if(word == words){
            count++;
        }
    }
    file.close();
    return count;
}

void convertToUpper(string& filename){
    file.open(filename, ios::in);
    file2.open("UpperCaseFile.txt", ios::out);
    string line;
    while(getline(file, line)){
        for(char& ch : line){
            ch = toupper(ch);
        }
        file2 << line;
    }
    cout << "File converted to upper case, and written to UpperCaseFile.txt file.\n\n";
    file.close();
    file2.close();

}
void convertToLower(string& filename){
    file.open(filename, ios::in);
    file2.open("LowerCaseFile.txt", ios::out);
    string line;
    while(getline(file,line)){
       for(char& ch : line){
           ch = tolower(ch);
       }
       file2 << line;
    }
    cout << "File converted to lower case, and written to LowerCaseFile.txt file.\n\n";
    file.close();
    file2.close();
}

void firstCaps(string& filename){
    file.open(filename, ios::in);
    file2.open("FirstCapsFile.txt", ios::out);
    string line;
    while(getline(file, line, '\n')){
        for(int i=0; i<line.size(); i++){
            if(isspace(line[i])){
                line[i + 1] = toupper(line[i + 1]);
            }
            else {
                line[0] = toupper(line[0]);
                line[i + 1] = tolower(line[i + 1]);
            }
        }
        file2 << line << endl;
    }
    cout << "File converted to first caps, and written to FirstCapsFile.txt file.\n\n";
    file.close();
    file2.close();
}

void save(string& filename) {
    char choice;
    string filename2;
    cout << "Do u want to save in another file y/n? : ";
    cin >> choice;
    if (choice == 'y') {
        cout << "Enter the name of the file: "; cin >> filename2;
        if(filename2.find(".txt") == string::npos) // if .txt is not exist
        {
            filename2 += ".txt";
        }
        file.open(filename, ios::in);
        file2.open(filename2, ios::out);
        string line;
        while (getline(file, line)) {
            file2 << line << endl;
        }
        emptyFile(filename);
        file.close();
        file2.close();
    } else if (choice == 'n') {
        cout << "Saved in the same file.\n\n";
    } else {
        cout << "Invalid Choice.\n\n";
    }
}