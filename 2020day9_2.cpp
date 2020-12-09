#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> sums;
int targetNum = 258585477; //258585477

int getEnd(int index){
    for(int i=index + 1; i < sums.size(); i++){
        if(sums[i] - sums[index-1] == targetNum){
            return i;
        }
    }
    return -1;
}

int main(){
    long long num;
    vector<long long> nums;

    while(cin>>num ){
        if (num < targetNum)
            nums.push_back(num);
    }

    sums.push_back(0);
    long long sum = 0;
    for(long long n : nums){
        sum += n;
        sums.push_back(sum);
    }

    int i = 1;
    while(getEnd(i) == -1 && i < sums.size()){
        i++;
    }


    long long small = targetNum, large = 0;
    for(int j = i-1; j <= getEnd(i)-1; j++){
        small = min(nums[j], small);
        large = max(nums[j], large);
    }

    cout<<small<<endl;
    cout<<large<<endl;

    cout<<"Final answer: " << small+large;
}
