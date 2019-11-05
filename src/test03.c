#include <stdio.h>
#include <cmplx.h>
typedef float cmplx_t[2];
int main(){
    cmplx_t i;
    i[0]=0;
    i[1]=2;
    if(2!=cmplx_mag(i)){
            printf("Test 3: fail!\n");
            return 0;
    }

    printf("Test 3: ok!\n");

return 0;
}
