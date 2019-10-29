#include "cmplx.h"
#include <math.h>
typedef float cmplx_t[2];

double cmplx_mag(cmplx_t a){
	return sqrt(a[0]*a[0]+a[1]*a[1]);
}

double cmplx_phs(cmplx_t a){
	return atan(a[1]/a[0]);
}

double cmplx_real(double mag, double phs){
	return mag*cos(phs);
}

double cmplx_imag(double mag, double phs){
	return mag*sin(phs);
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
	for (int i=0;i<N;i++){
		double sumreal=0;
		double sumimag=0;
		for (int j=0;j<N;j++){
			double angle=2*M_PI*i*j/N;
			sumreal+=input[j][0]*cos(angle)+input[j][i]*sin(angle);
			sumimag+=-input[j][0]*sin(angle)+input[j][i]*cos(angle);
		}
		output[i][0]=sumreal;
	        output[i][1]=sumimag;
	}
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
	for (int i=0;i<N;i++){
                double sumreal=0;
                double sumimag=0;
                for (int j=0;j<N;j++){
                        double angle=2*M_PI*i*j/N;
                        sumreal+=input[j][0]*cos(angle)+input[j][i]*sin(angle);
                        sumimag+=-input[j][0]*sin(angle)+input[j][i]*cos(angle);
                }
                output[i][0]=sumreal/N;
                output[i][1]=sumimag/N;
        }

}

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
        c[0]=cmplx_real(cmplx_mag(a)/cmplx_mag(b),cmplx_phs(a)-cmplx_phs(b));
        c[1]=cmplx_imag(cmplx_mag(a)/cmplx_mag(b),cmplx_phs(a)-cmplx_phs(b));

}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
        c[0]=cmplx_real(cmplx_mag(a)*cmplx_mag(b),cmplx_phs(a)+cmplx_phs(b));
        c[1]=cmplx_imag(cmplx_mag(a)*cmplx_mag(b),cmplx_phs(a)+cmplx_phs(b));
}

