#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file;
    string file_name, line_content;
    cout << "Enter the file name to open file: ";
    cin >> file_name;
    if(file_name.length() < 4 || file_name.substr(file_name.length()-4) != ".txt") {
        file_name = file_name + ".txt";
    }
    file.open(file_name, ios::in);
    if (file.fail()) cout << "Could not find txt file \"" << file_name << "\" please check file name! \n";
    else if (file.is_open()){
        while(getline(file, line_content)){
            cout << line_content <<"\n";
        }
    }
    file.close();
    return 0;
}