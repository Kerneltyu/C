#include<stdio.h>
#include<stdlib.h>
#define N 10

void heap_sort();
void merge_sort(int, int);
void quick_sort(int, int);
void printData();

int data[N];
int buff[N];
int main(){
    int i;
    srand(10);
    for(i=0;i<N;i++){
        data[i] = rand()%100;
        printf("%3d",data[i]);
    }
    printf("\n");
    quick_sort(0, N-1);
    printData();
}

void printData(){
    int i;
    for(i=0;i<N;i++){
        printf("%3d",data[i]);
    }
    printf("\n");
}

void heap_sort(){
    int i,j,k,x;
    //ヒープ木の構築
    for(k=N/2;k>=0;k=k-1){
        i=k; j=2*i; x=data[i];
        while(j<=N){
            if(j<N && data[j+1]>data[j]) j=j+1;
            if(x<data[j]){
                data[i]=data[j];
                i=j;
                j=2*i;
            }else break;
        }
        data[i]=x;
    }

    printData();
    //ヒープ木からの取り出し
    for(k=N-2;k>=0;k=k-1){
        x = data[k+1]; 
        //先頭の根を最後尾へ
        data[k+1]=data[0];
        i=0;j=1;
        //ヒープの更新(最後尾の値をどこに入れるかを決定)
        while(j<=k){
            if(j<k && data[j+1]>data[j]) j=j+1;
            if(x<data[j]){
                data[i] = data[j]; i=j;j=i*2;
            }else break;
        }
        data[i] = x;
        printData();
    }
}

void merge_sort(int left, int right){
    if(left < right){
        int i;
        int center = (left+right)/2;
        int p=0;
        int j=0;
        int k=left;

        merge_sort(left, center);
        merge_sort(center+1, right);

        //マージ
        for(i=left; i<=center; i++){
            buff[p++] = data[i];
        }
        while(i<=right && j<p){
            data[k++] = (buff[j] <= data[i]) ? buff[j++]:data[i++];
        }

        while(j<p){
            data[k++] = buff[j++];
        }

    }
}

void quick_sort(int left, int right){
    if(left < right){
        int center = (left + right)/2;
        int x = data[center];
        int i=left;
        int j=right;
        int tmp;
        while(i<=j){
            while(data[i] < x) i++;
            while(data[j] > x) j--;
            if(i<=j){
                tmp = data[i]; 
                data[i]=data[j]; 
                data[j] = tmp;
                i++;
                j--;
            }
        }
        quick_sort(left, j);
        quick_sort(i, right);
    }
}
