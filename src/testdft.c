#include <cmplx.h>

#include <io.h>

#include <stdio.h>

#include <fcntl.h>

#include <sys/stat.h>

#include <unistd.h>

#include <math.h>



int main()

{

    int fd, i;

    cmplx_t input[200], dft[200];

    for (i = 0; i < 200; i++)

    {

        input[i][0] = sin(M_PI * 0.5 * i);

        input[i][1] = 0;

        input[i][0] = input[i][0] == 0 ? 0 : input[i][0];

        input[i][0] = roundf(input[i][0] * 10000) / 10000;

    }

    cmplx_dft(input, dft, 200);

    fd = open("dft.bin", O_WRONLY | O_CREAT, S_IRWXU);

    for (i = 0; i < 200; i++)

    {

        write_word(fd, (int)dft[i][0]);

        write_word(fd, (int)dft[i][1]);

    }

    close(fd);

    return 0;

}
