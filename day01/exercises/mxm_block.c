#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
int N=200;
    int NB, i, j, k, ii, jj, kk;
int a[N][N],b[N][N],c[N][N];
double  rate, msec, start, end;
  srand(time(NULL));
  for (int iii = 0; iii < N; iii++) {
        for (int jjj = 0; jjj < N; jjj++) {
            a[iii][jjj] = rand() % 100;  // Generate random values between 0 and 99
            b[iii][jjj] = rand() % 100;
          c[iii][jjj] = 0;  // Initialize matrix C with zeros
        }}
printf("Nmb of Block , time (msec), rate (MB/s)\n");

for (NB=1;NB<200;NB+=20){
 start= (double)clock() /(double) CLOCKS_PER_SEC;
    for (ii = 0; ii < N; ii += NB) {
       for (jj = 0; jj < N; jj += NB) {
            for (kk = 0; kk < N; kk += NB) {
                for (i = ii; i < (ii + NB < N ? ii + NB : N); i++) {
                    for (j = jj; j < (jj + NB < N ? jj + NB : N); j++) {
                        for (k = kk; k < (kk + NB < N ? kk + NB : N); k++) {
                            c[i][j] += a[i][k] * b[k][j];

                    }
                }
            }
        }
    }

end = (double)clock() / (double) CLOCKS_PER_SEC;


      msec = (end-start) * 1000.0; // time in milli-second;
      rate = sizeof(double) * N * (1000.0 / msec) / (1024*1024);

      printf("%d, %f, %f,\n", NB, msec, rate);

}
return 1;
}
