#include <stdio.h>
#include <stack>
using namespace std;

int main(void) {
    int number, i = 0;
    int new_building;
    long long int total = 0;
    stack<int> buildings;  // stack for buildings with different height, monopoly decrease
    stack<int> count;      // count for buildings with same height

    scanf("%d", &number);
    while (i != number) {
        scanf("%d", &new_building);

        while (!buildings.empty() && buildings.top() < new_building) {
            total += count.top();
            count.pop();
            buildings.pop();
        }
        if (buildings.empty() || buildings.top() > new_building) {
            buildings.push(new_building);
            count.push(1);
        } else {
            total += count.top();
            count.top()++;
        }
        if (buildings.size() > 1) total++;
        i++;
    }

    printf("%lld", total*2);
    return 0;
}
/*
 use stack
*/





// #include <iostream>
// #include <stack>
// using namespace std;

// int main(void) {
//     int number, i = 0;
//     int new_building;
//     int total = 0;
//     stack<int> buildings;  // stack for buildings with different height, monopoly decrease
//     stack<int> count;      // count for buildings with same height

//     cin >> number;
//     while (i != number) {
//         cin >> new_building;

//         while (!buildings.empty()) {
//             if (buildings.top() < new_building) {
//                 total += count.top();
//                 count.pop();
//                 buildings.pop();
//             } else {
//                 if (buildings.top() > new_building) {
//                     total += 1;
//                     count.push(1);
//                     buildings.push(new_building);
//                 // } else (buildings.top() == new_building) {
//                 } else {
//                     if (buildings.size() == 1) total = total + count.top();
//                     else                       total = total + count.top() + 1;
//                     count.top()++;
//                 }
//                 break;
//             }
//         }
//         if (buildings.empty()) {
//             buildings.push(new_building);
//             count.push(1);
//         }
//         i++;
//     }
//     cout << total*2;
//     return 0;
// }
// /*
//  use stack
// */

