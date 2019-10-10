#include <iostream>
#include <climits>

using namespace std;

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int jumpNumber(int target[],  int length){

    if(length == 0 || target[0] == 0)
        return INT_MAX;

    //jumpTable[i] contains the # of needed jumps to reach target[i] from target[0]
    int jumpTable[length];

    jumpTable[0] = 0;

    for(int i = 1; i < length; i++){

        for(int j = 0; j < i; j++){
            jumpTable[i] = INT_MAX;

            if( i <= j + target[j] && jumpTable[j] != INT_MAX){
                jumpTable[i] = min( jumpTable[i], jumpTable[j] + 1);
                break;
            }

        }

    }

    return jumpTable[length-1];
}
