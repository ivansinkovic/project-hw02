#include <stdio.h>
#include <math.h>
#include "cmplx.h"
typedef float cmplx_t[2];
int main(){
	cmplx_t i1;
	scanf("%f %f",&i1[0],&i1[1]);
	printf("\n%f",cmplx_mag(i1));

}
