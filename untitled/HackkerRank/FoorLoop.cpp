//
// Created by Will&Carm on 21/12/2023.
//

#include <iostream>
#include <string>

#define u32 unsigned int
#define max(a, b) (((a)>(b))? a: b)

inline std::string evenOrOdd(u32);
 std::string wordNumber(u32);
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    u32 first, second;
    cin >> first >> second;

    u32 maxNum = max(first, second);

    for (u32 i = first; i <= maxNum; i++) {
        switch (i) {
            case 1:
                cout << "one" << endl;
                break;
            case 2:
                cout << "one" << endl;
                break;
            case 3:
                cout << "one" << endl;
                break;
            case 4:
                cout << "one" << endl;
                break;
            case 5:
                cout << "one" << endl;
                break;
            case 6:
                cout << "one" << endl;
                break;
            case 7:
                cout << "one" << endl;
                break;
            case 8:
                cout << "one" << endl;
                break;
            case 9:
                cout << "one" << endl;
                break;

            default : {
                evenOrOdd(i);
                break;
            }
        }
    }
    return 0;
}


inline string evenOrOdd(u32 number) {
    string description;

    if (number % 2 == 0) {
        description = "even";
    } else {
        description = "odd";
    }

    return description;
}