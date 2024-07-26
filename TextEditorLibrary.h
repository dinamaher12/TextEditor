#ifndef TEXTEDITOR_TEXTEDITORLIBRARY_H
#define TEXTEDITOR_TEXTEDITORLIBRARY_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
fstream file;
fstream file2;
void isExist(string& filename);
void appendText(string& filename);
void displayContent(string& filename);
void emptyFile(string& filename);
void encryptFile(string& filename);
void decryptFile(string& filename);
void mergeFile(string& filename);
int countWords(string& filename);
int countChars(string& filename);
int countLines(string& filename);
bool searchWord(string& filename);
int wordCount(string& filename);
void convertToUpper(string& filename);
void convertToLower(string& filename);
void firstCaps(string& filename);
void save(string& filename);

#endif //TEXTEDITOR_TEXTEDITORLIBRARY_H
