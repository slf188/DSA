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
#include <cstring>
using namespace std;

int main() {
    char const *postfix = "35*62/+4-";
    cout << evaluationPostfix(postfix) << endl;
    return 0;
}
