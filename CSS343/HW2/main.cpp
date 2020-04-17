#include "SearchTree.h"
#include "comparable.h"

#include <fstream>
#include <string>
//#include <sstream>
#include <iostream>

using namespace std;

int main() {
    cout << "Testing Comparable Class" << endl;
    Comparable a,b,c;
    cout << "Type in desired char for a & c: " << endl;
    cin >> a >> c;
    cout << " a = " << a << " c = " << c << endl;
    cout << "Type in desired char for b: " << endl;
    cin >> b;
    bool test = a > b;
    cout << "Result of a > b: " << test << endl;
    test = a == c;
    cout << "Result of a == c: " << test << endl;
    Comparable* ptr = &a;
    Comparable* ptr2 = &b; //copies the address of a
    cout << "Ptr2 to ptr: " << ptr2 << endl;
    ptr2 = ptr;
    int temp = *(int)a;
    if(*ptr == a){
        cout << "This is a space" << endl;
    }
    cout << "Ptr to a: " << ptr << endl;
    cout << "Ptr2 to ptr: " << ptr2 << endl;

    cout << "************************" << endl;
    cout << "Testing SearchTree Class" << endl;

    SearchTree tree;

    cout << tree;



    return 0;
}
