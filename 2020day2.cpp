//
// Created by Lorie on 12/2/2020.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int valid = 1000;

    for(int i =0; i < 1000; i++){
        int pos1, pos2;
        cin>>pos1>>pos2;
        pos2 = -1 * pos2;

        char c, trash;
        cin>>c>>trash;

        string str;
        cin>>str;

        if(!(str[pos1-1] == c ^ str[pos2-1] == c)){
            valid--;
        }
    }

    cout<<valid;


}