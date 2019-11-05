#include <stdio.h>
#include <cmplx.h>
int main(){
	/*cmplx_t i1,i2,o;
	i1[0]=2;
	i1[1]=2;
	i2[0]=1;
	i2[1]=1;
	cmplx_div(i1,i2,o);
	printf("\n%f %f i",o[0],o[1]);*/
    int fd,i;
    cmplx_t a,b,c;
    a[0]=1;
    a[1]=1;
    b[0]=0;
    b[1]=1;
    cmplx_mul(a,b,c);
    if(c[0]!=-1 && c[1]!=1){
            printf("Test 1:Fail!\n");
            return 0;
    }

    printf("Test 1:Ok!\n");

return 0;
	

}
