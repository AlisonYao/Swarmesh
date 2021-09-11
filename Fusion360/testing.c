#include <stdio.h>
int intArr[3];
int main(){
    for(int k = 0; k < 8; k++){
//---------------------------------------------------------------------------------------------
            // Decimal binary conversion

        int l = k;
        intArr[2] = l & 0x01;
        intArr[1] = (l >> 1) & 0x01;
        intArr[0] = (l >> 2) & 0x01;
        printf("%d\t%d\t%d\n", intArr[0], intArr[1], intArr[2]);
    }
}