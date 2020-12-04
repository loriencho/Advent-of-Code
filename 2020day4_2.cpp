//
// Created by Lorie on 12/4/2020.
//

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


bool checkPassport(string passport) {
    string field;
    stringstream ss(passport);

    bool hasAll = passport.find("byr:") != string::npos;
    hasAll = hasAll && passport.find("iyr:") != string::npos;
    hasAll = hasAll && passport.find("eyr:") != string::npos;
    hasAll = hasAll && passport.find("hgt:") != string::npos;
    hasAll = hasAll && passport.find("hcl:") != string::npos;
    hasAll = hasAll && passport.find("ecl:") != string::npos;
    hasAll = hasAll && passport.find("pid:") != string::npos;

    if (!hasAll) return false;
    while (ss >> field) {
        if (field.substr(0, 3) == "byr") {
            int value = stoi(field.substr(4, string::npos));
            if (value < 1920 || value > 2002) return false;
        }
        else if (field.substr(0, 3) == "iyr") {
            int value = stoi(field.substr(4, string::npos));
            if (value < 2010 || value > 2020) return false;
        }
        else if (field.substr(0, 3) == "eyr") {
            int value = stoi(field.substr(4, string::npos));
            if (value < 2020 || value > 2030) return false;
        }
        else if (field.substr(0, 3) == "hgt") {
            int value = stoi(field.substr(4, field.length() - 5));
            if (field.substr(field.length() - 2, 2) == "cm") {
                if (value < 150 || value > 193) return false;
            } else {
                if (value < 59 || value > 76) return false;
            }
        }
        else if (field.substr(0, 3) == "hcl") {
            if (field[4] != '#' || field.substr(5, string::npos).length() != 6) ;
            string allowed = "0123456789abcdef";
            for (int i = 0; i < 6; i++) {
                if (allowed.find(field[5 + i]) == string::npos) return false;
            }
        }
        else if (field.substr(0, 3) == "ecl") {
            string allowed = " amb blu brn gry grn hzl oth ";
            if (allowed.find(" " + field.substr(4, string::npos) + " ") == string::npos) return false;
        }
        else if (field.substr(0, 3) == "pid") {
            string value = field.substr(4, string::npos);
            if (value.length() != 9) return false;
            for (int i = 0; i < value.length(); i++) {
                if (!isdigit(value[i]))return false;
            }
        }
    }
    return true;
}

int main(){
    string line, passport;
    int count=0, inputLength=1001;
    for(int i =0; i<inputLength; i++) {
        passport += " ";
        getline(cin, line);
        passport+= line;
        if(line.empty()) {
            if(checkPassport(passport)){
                count++;
            }
            passport = "";
        }
    }
    cout<<count;

}
