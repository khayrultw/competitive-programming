#include <bits/stdc++.h>

using namespace std;

vector<string> ship;

int indexOf(string str){
    for(int i = 0; i < ship.size(); i++){
        if(ship[i] == str)
            return i;

    }
    ship.push_back(str);
    return ship.size()-1;
}

int main(){

}