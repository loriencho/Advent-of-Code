#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> nums;
int preambleLength = 25;

bool checkSums(int indexNum){
    long long num = nums[indexNum];
    for(int i = indexNum - preambleLength; i < indexNum; i++){
        for(int j = i; j < indexNum; j++){
            if(nums[i] + nums[j] == num){
                return true;
            }
        }
    }
    return false;
}

int main(){
    long long num;

    while(cin>>num){
        nums.push_back(num);
    }

    int i = preambleLength;
    while(checkSums(i) && i < nums.size()){
        i++;
    }

    cout <<  nums[i];
}
