#include <cmplx.h>
#include <stdio.h>
typedef float cmplx_t[2];
int main(){
    cmplx_t a,b,c;
    a[0]=1;
    a[1]=1;
    b[0]=1;
    b[1]=-1;
    cmplx_div(a,b,c);
    if(c[0]!=0 && c[1]!=1){
            printf("Test 2:Fail!\n");
            return 0;
    }

    printf("Test 2:Ok!\n");

return 0;
}
