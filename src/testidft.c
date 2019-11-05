#include <cmplx.h>

#include <io.h>

#include <stdio.h>

#include <fcntl.h>

#include <sys/stat.h>

#include <unistd.h>

#include <math.h>

int main()

{

    int fd, i, dft_cst;
    
    void *cst;

    cmplx_t input[200], idft[200], dft[200];

    for (i = 0; i < 200; i++)

    {

        input[i][0] = sin(M_PI * 0.5 * i);

        input[i][1] = 0;

        input[i][0] = input[i][0] == 0 ? 0 : input[i][0];

        input[i][0] = roundf(input[i][0] * 10000) / 10000;

    }

    fd = open("dft.bin",  O_CREAT|O_RDONLY, 0777 );

    for (i = 0; i < 200; i++)

    {

        dft_cst=read_word(fd);
	cst = (void *) &dft_cst;
        dft[i][0] = *((float *) cst);

	dft_cst=read_word(fd);
	cst = (void *) &dft_cst;
        dft[i][1] = *((float *) cst);

    }

    close(fd);

    cmplx_idft(dft, idft, 200);

    for (i = 0; i < 200; i++)

    {

        if (input[i][0] != idft[i][0] || input[i][1] != idft[i][1])

        {

            printf("Test idtf: fail!\n");

            printf("Test case %d: test result %f %f, should be %f %f\n", (i+1), idft[i][0], idft[i][1], input[i][0], input[i][1]);

            break;

        }

    }

    printf("All tests passed in tests_idtf!\n");

    return 0;

}
