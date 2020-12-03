//
// Created by Lorie on 12/1/2020.
//
#include <iostream>
#include <vector>
using namespace std;
 vector<int> nums;

int checkOther(int start, int target){
    int i = start + 1;
    while(i < nums.size()){
        if (nums.at(i) ==  target-nums.at(start)){
            return i;
        }
        i++;
    }

    return -1;
}
int main(){
    freopen("input.txt", "r", stdin);
    string num;
    while(getline(cin, num)){
        nums.push_back(stoi(num));
    }
    int i =0, other = -1;
    int j = 0, other2 = -1;

    while(i < nums.size() && other2 == -1){
        j = i + 1, other2 = -1;
        while(j < nums.size() && other2 == -1){
            other2 = checkOther(j, 2020-nums.at(i));
            j++;
        }
        i++;
    }
    cout<<nums[other2]<<endl;
    cout<<nums[j-1]<<endl;
    cout<<nums[i-1]<<endl;
    cout<<nums[other]*nums[i-1];
}