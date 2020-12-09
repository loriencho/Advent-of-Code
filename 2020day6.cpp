#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int inputLength = 2133;
    int count = 0;
    string line;
    bool firstLine = true;
    vector<char> everyone;
    for(int i = 0; i<inputLength; i++){
        getline(cin, line);

        if(line.empty()){
            count+= everyone.size();
            firstLine = true;
            everyone.clear();
        }
        else if (firstLine){
            for(int j=0; j < line.length(); j++){
                everyone.push_back(line[j]);
            }
            firstLine = false;
        }
        else {
            vector<char> newEveryone;

            for(int j=0; j < everyone.size(); j++){
                if(find(line.begin(), line.end(), everyone[j]) != line.end()){
                    newEveryone.push_back(everyone[j]);
                }
            }
            everyone = newEveryone;

        }
    }

    cout<< count;
}