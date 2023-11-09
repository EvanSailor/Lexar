/*Citations:
For the split function: https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/#
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <vector>

vector<string> fileImport(string fileName) {
    string importString = "";
    ifstream myfile;
    vector<string> importVector;
    myfile.open(fileName);
    while (getline(myfile, importString)) {
        importVector.push_back(importString);
    }
    myfile.close();
    return importVector;
}

vector<string> split(vector<string> fileInput) {
    string s;
    vector<string> v;
    for (int i = 0; i < fileInput.size(); i++) {
        string tempString = fileInput[i];
        stringstream ss(tempString);

        while (getline(ss, s, ' ')) {
            // store token string in the vector
            if (s.empty() == false) {
                v.push_back(s);
            }
        }
    }
    return v;
}

string lexarCheck(string split) {
    //These are comments
    if (split == "//" or split == "/*" or split == "*/") {
        return("(Comment, '" + split + "')");
    }
    //these are Keywords
    else if(split == "if" or split == "for" or split == "while"
        or split == "then" or split == "return" or split == "true"
        or split == "elif" or split == "else" or split == "cout"
        or split == "endl" or split == "return" or split == "string"
        or split == "") {
        return("(Keywords, '" + split + "')");
    }
    //these are operators
    else if (split == "+" or split == "-" or split == "<<" or
        split == ">>" or split == "*" or split == "%" or 
        split == "/" or split == "=" or split == ">" or
        split == "<" or split == "==") {
        return("(Operators, '" + split + "')");
    }
    //these are separators
    else if (split == ";" or split == "{" or split == "}"
        or split == "(" or split == ")" or split == "true") {
        return("(Seperators, '" + split + "')");
    }
    //These are literals
        
    else {
        return("(Literals, '" + split + "')");
    }
}

int main() {
    string fileExtension;
    cout << "What is the file extension:";
    cin >> fileExtension;

    vector<string> importedFile = fileImport(fileExtension);

    string test = "Final = 9 + a";

    vector<string> fileVector = fileImport(fileExtension);
    vector<string> splitString = split(fileVector);
    vector<string> finalVector;

    for (int i = 0; i < splitString.size(); i++) {
        finalVector.push_back(lexarCheck(splitString[i]));
    }
    for (int i = 0; i < finalVector.size(); i++) {
        cout << finalVector[i] << endl;
    }
}