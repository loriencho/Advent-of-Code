//
// Created by Lorie on 12/4/2020.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string line, passport;
    int count=0, inputLength=1001;
    for(int i =0; i<inputLength; i++) {
        getline(cin, line);
        passport+= line;
        if(line.empty()) {
            bool hasAll = passport.find("byr:") != string::npos;
            hasAll = hasAll && passport.find("iyr:") != string::npos;
            hasAll = hasAll && passport.find("eyr:") != string::npos;
            hasAll = hasAll && passport.find("hgt:") != string::npos;
            hasAll = hasAll && passport.find("hcl:") != string::npos;
            hasAll = hasAll && passport.find("ecl:") != string::npos;
            hasAll = hasAll && passport.find("pid:") != string::npos;
            if(hasAll){
                count++;
            }
            passport = "";
        }
    }
    cout<<count;

}
