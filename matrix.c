#include<stdio.h>

const int MAX_N = 2;

int x[MAX_N][MAX_N];
int y[MAX_N][MAX_N];
int z[MAX_N][MAX_N];
void initialize(int);
void dot();
void printMatrix(int[][MAX_N]);

int main(){

    initialize(0);
    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;

    y[0][0] = 5;
    y[0][1] = 6;
    y[1][0] = 7;
    y[1][1] = 8;

    dot();
    printMatrix(x);
    printMatrix(y);
    printMatrix(z);
    return (0);


}

void initialize(int n){
    int i,j;
    for(i=0;i<MAX_N;i++){
        for(j=0;j<MAX_N;j++){
            x[i][j] = n;
            y[i][j] = n;
            z[i][j] = n;
        }
    }
}

void dot(){
    int i,j,k;
    for(i=0;i<MAX_N;i++){
        for(j=0;j<MAX_N;j++){
            for(k=0;k<MAX_N;k++){
                z[i][j] += x[i][k]*y[k][j];
            }
        }
    }
}

void printMatrix(int a[][MAX_N]){
    int i,j;
    for(i=0;i<MAX_N;i++){
        for(j=0;j<MAX_N;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
