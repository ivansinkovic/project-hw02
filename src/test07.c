typedef float cmplx_t[2];
int main(){
	cmplx_t i[5],o[5];
	for(int i=0;i<4;i++){
		scanf("%f %f",&i[i][0],&i[i][1]);
	}
	cmplx_dft(i,o,5);
	for(int i=0;i<4;i++){
		printf("\n%f %f",output[i][0],output[i][1]);
	}
}
