#include "binary.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <stdio.h> 
#include<vector>
#include <cassert> 

using namespace std;

int main() {

    Binary newBin(4);
    cout << "newBin: " << newBin << endl;  //should be 4 or 100
    Binary secBin(2);
    cout << "secBin: " << secBin << endl;  //should be 2 or 10 
    Binary newOn = newBin + secBin; //4 + 2 
    cout << newOn << endl; //should be 6 or 110 
    newBin += newOn;   //4 + 6 
    cout << newBin << endl;  //10 or 1010
    newOn = secBin - newBin; //2 - 10
    cout << newOn << endl; //should be -8 or -1000

    assert(newOn != secBin);
    assert(newOn != newBin);
    assert(newOn == newOn);
    Binary c = newBin;
    assert(c == newBin);

    Binary d(111), e(76), y = 1;
    d -= e; // d = 111 - 76 =  35 
    cout << d << endl;
    e = y + 3 + d; //  1 + 3 + 35 = 39 
    cout << "e1:" << e << endl;
    cout << y << " + " << d << " - " << e << endl;
    e = y + d - e; //1+ 35 - 39 = -3
    cout << e << endl;
    cout << "Type in num: " << endl;
    cin >> y;
    cout << "This is it's binary form: " << endl;
    cout << y << endl;
    cout << "This y + 3: " << y + 3 << endl;
    cout << "This y - 3: " << y - 3 << endl;
    Binary test(11);
    cout << test << endl;
    test.toggleBit(3);
    cout << test << endl;
    cout << "YAY!" << endl;

    Binary a, b(42), x; //, c(b), d = -13, x, y = x + 1;
    cout << "Enter integer to be converted to binary:  ";
    cin >> a;
    cout << "The binary representation of this number is: " << endl;
    cout << a << endl;
    cout << "The 4th bit (four bits away from bit 0) is: " << endl;
    cout << a.getBit(4) << endl << endl;
    cout << "Compute c = a + b" << endl;
    c = a + b; cout << "c = " << c << endl;
    cout << "Compute d = a + b - c" << endl;
    d = a + b - c; cout << "d = " << d << endl << endl;
    cout << "Does a == c? " << endl;
    cout << ((a == c) ? "a == c" : "a != c") << endl << endl;

    cout << "Test assignment operators" << endl;
    cout << "Enter d: ";
    cin >> d;
    x = c = d = d;
    y += a -= b += b;
    cout << "x = " << x << "    y = " << y << endl << endl; a.setBit(-1);

    Binary var1, var2(-21);
    var1 = var2;
    cout << var1 << endl;
    _CrtMemState s1;
    _CrtMemCheckpoint(&s1);
    _CrtMemDumpStatistics(&s1);
}
