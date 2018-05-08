//Knapsack Problem with Dynamic Programming(Memo)
#include<stdio.h>
#define CAPA 1000
#define N 5
#define C 10
int max(int, int);
int rec_dp(int,int);
int table[N+1][C+1];
char items[6][100]={"tea","vegitable","poak","rice","beaf"};
int weights[5]={10,3,5,1,7};
int values[5]={12,5,2,3,8};

int main(){
    int i,j;
    int res;
    
    for(i=0; i<N+1; i++){
        for(j=0;j<C+1;j++){
          printf("%d",table[i][j]);
          table[i][j] = -1;
        }
        printf("\n");
    }
    
    printf("Max value with Dynamic Programming is %d.\n",rec_dp(0,C));

    for(i=0; i<N+1; i++){
        for(j=0;j<C;j++){
          printf("%3d",table[i][j]);
        }
        printf("\n");
    }
    return(0);
}

//i番目以降の品物から重さの和がj以下になるように選んだ時の価値の和の最大値を返す
int rec_dp(int i, int j){
    printf("(%d,%d,%d)\n",i,j,values[i]);
    if(table[i][j] != -1){
      return table[i][j];
    }
    int res;
    if(i >= N){
        res = 0;
    }else if(j < weights[i]){
        res = rec_dp(i+1, j);
    }else{
        //品物iを入れるか入れないかを調べる
        res = max( rec_dp(i+1, j), rec_dp(i+1, j-weights[i])+values[i] );
    }
    return table[i][j] = res;
}

int max(int x, int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}
