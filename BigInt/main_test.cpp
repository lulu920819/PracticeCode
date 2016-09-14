#include <iostream>
#include"BigInt.h"
using namespace std;

int main() {
    //Your Code Here
    BigInteger a = BigInteger("1000000000000000000000000");
    BigInteger b = 100;

    a = a + b;

    cout << a.getNumber() << endl;

    return 0;
}