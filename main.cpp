#include <iostream>
#include <string>
#include <iomanip>
#include "TextEditorLibrary.cpp"
using namespace std;
void menu(){
    cout<<
    "------------------------------------\n"
    "Welcome To Text Editor Application.\n"
    "------------------------------------\n"
    "1.Add new text to the end of the file.\n"
    "2.Display the content of the file.\n"
    "3.Empty the file.\n"
    "4.Encrypt the file content.\n"
    "5.Decrypt the file content.\n"
    "6.Merge another file.\n"
    "7.Count the number of words in the file.\n"
    "8.Count the numbers of characters in the file.\n"
    "9.Count the number of lines in the file.\n"
    "10.Search for a word in the file.\n"
    "11.Count the number of times a word exists in the file.\n"
    "12.Turn the file content to upper case.\n"
    "13.Turn the file content to lower case.\n"
    "14.Turn file content to first caps.\n"
    "15.Save the file.\n"
    "0.Exit\n\n";
}
int main() {
    string choice,filename;
    while(true){
        menu();
        cout << "Please, Enter the name of the file: "; cin >> filename;
        if(filename.find(".txt") == string::npos) // if .txt is not exist
        {
            filename += ".txt";
        }
        cout <<"Select What You Want From The Following: "; cin >> choice;
        if(choice == "1"){
            isExist(filename);
            appendText(filename);
        }
        else if(choice == "2"){
            displayContent(filename);
        }
        else if(choice == "3"){
            emptyFile(filename);
        }
        else if(choice == "4"){
            encryptFile(filename);
        }
        else if(choice == "5"){
            decryptFile(filename);
        }
        else if(choice == "6"){
            mergeFile(filename);
        }
        else if(choice == "7") {
            cout << "There is " << countWords(filename) << " words in the file.\n\n" <<  endl;
        }
        else if (choice == "8"){
            cout << "There is " << countChars(filename) << " characters in the file.\n\n" <<  endl;
        }
        else if(choice == "9"){
            cout << "There is " << countLines(filename) << " lines in the file.\n\n" <<  endl;
        }
        else if(choice == "10"){
            if(searchWord(filename)){
                cout << "Word is exist in the file.\n\n";
            }else{
                cout << "Word not found.\n\n";
            }
        }
        else if(choice == "11"){
            cout << "The count of the word in the file: " << wordCount(filename) << "\n\n";
        }
        else if(choice == "12"){
            convertToUpper(filename);
        }
        else if(choice == "13"){
            convertToLower(filename);
        }
        else if(choice == "14"){
            firstCaps(filename);
        }
        else if(choice == "15"){
            save(filename);
        }
        else if(choice == "0"){
            cout << "Thank You For Using Text Editor Application.\n";
            exit(0);
        }
        else{
            cout << "Invalid input, Try again.\n\n";
        }
    }
}
