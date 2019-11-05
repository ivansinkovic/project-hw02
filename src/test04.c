#include <cmplx.h>
#include <stdio.h>
#include <math.h>
int main(){
	 cmplx_t a;
    a[0]=2;
    a[1]=2;
    if((M_PI/4)!=cmplx_phs(a)){
            printf("Test 4: fail!\n");
            return 0;
    }

    printf("Test 4:Ok!\n");

return 0;
}
