#include <iostream>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while(str != ""){
        pos = str.find(" ");
        if(pos > str.length())
            pos = str.length();
        cout << str.substr(0, pos) << endl;
        str.erase(0, pos+1);
    }
}