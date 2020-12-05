//
// Created by Lorie on 12/5/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int inputLength = 761;
    string seat;
    vector<int> ids;
    for(int i =0; i<inputLength; i++){
        int high=127, low=0;
        int column, row;
        cin>>seat;
        for(int i=0; i< 7; i++){
            char c = seat[i];
            if(c=='B'){
                low = (high+low)/2 +1;
            }
            else{
                high = (high+low)/2;
            }
        }
        row=low;
        low = 0, high=7;
        for(int i=7; i <10; i++){
            char c = seat[i];
            if(c=='R'){
                low = (high+low)/2 +1;
            }
            else{
                high = (high+low)/2;
            }
        }
        column = low;

        ids.push_back(8*row + column);

    }

    sort(ids.begin(), ids.end());

    for(int i=0; i<ids.size()-1; i++){
        if((ids[i] + 2) == ids[i+1]){
            cout<<ids[i]+1;
        }
    }
}