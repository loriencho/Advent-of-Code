#include <iostream>
using namespace std;

int calculate_fuel(int mass) {
    int mass_total = 0;
    mass /=  3;
    mass -= 2;
    mass_total += mass;
    if ((mass/3)-2 > 0){
        mass_total += calculate_fuel(mass);
    }
    return mass_total;
}

int main(){
    freopen("2019_Day_1_Input.txt", "r", stdin);
    int total = 0, mass, total_fuel;
    for (int i = 0; i < 100; i++) {
        cin >> mass;
        total_fuel = calculate_fuel(mass);
        total += total_fuel;
    }
    cout << total;
}

