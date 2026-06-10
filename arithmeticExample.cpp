#include<iostream>
using namespace std;
// write a code to solve this expression: z = x + 10 / 3y. Assume x = 10 and y = 5.
int main(){
    float x = 10;
    float y = 5;
    float z;
    z = (x + 10) / (3 * y);
    cout<<z;
    return 0;
}