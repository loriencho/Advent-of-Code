//
// Created by Lorie on 12/3/2020.
//

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int inputLength = 323;
    int inputWidth = 31;
    int numHits = 0;
    vector<vector<bool>> grid(inputLength);

    for(int i =0; i < inputLength; i++){
        string s;
        cin>>s;
        for(int j =0; j < inputWidth; j++){
            if(s[j] == '#'){
                grid[i].push_back(true);
            }
            else{
                grid[i].push_back(false);
            }
        }
    }
    int x = 0;

    for(int y=0; y<inputLength; y+=2){
        if(grid[y][x % inputWidth]){
            numHits++;
        }
        x+=1;
    }
    cout<<numHits;
    //58 * 209 * 58 * 64 * 35
}