#include <cmplx.h>
#include <stdio.h>
#include <math.h>
int main(){
    if(cmplx_real(2,(2*M_PI))!=2){
            printf("Test 5: fail!\n");
            return 0;
    }

    printf("Test 5: ok!\n");

return 0;

}
