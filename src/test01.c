#include <math.h>
typedef float cmplx_t[2];
int main(){
	cmplx_t i1,i2,o;
	scanf("%f %f",&i1[0],&i1[1]);
	scanf("%f %f",&i2[0],&i2[1]);
	cmplx_div(i1,i2,o);
	printf("\n%f %f i",o[0],o[1]);

}
