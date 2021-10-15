//
//  main.cpp
//  Stack
//
//  Created by Felipe Vallejo on 11/10/21.
//

#include <iostream>
#include "Array.h"
#include "LinkedList.h"
#include "CharLL.h"
using namespace std;

int main() {
    char const *exp = "{([a+b]*[c-d])/e}";
    cout << (isBalanced(exp) ? "True\n" : "False\n");
    return 0;
}
