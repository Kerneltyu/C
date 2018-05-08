#include<stdio.h>

void merge_sort(int [], int, int);

void merge_sort(int a[], int left, int right){
    if(left<=right){
        int i=0;
        int j=0;
        int p=0;
        int k=0;
        int center = (left+right)/2
        merge_sort(a[],left,center);
        merge_sort(a[],center+1, right);

        for(i=0; i<center; i++){
            buff[k++] = a[i];
        }

        while(i<=right && j<k){
            d[p++] = (buff[j] < a[i]) ? buff[j++]:a[i++];
        }
        while(j<k){
            d[p++] = buff[j++];
        }
    }

}

void heap_sort(){
    int i=0;
    int j=0;
    int x;
    for(i=N/2;i>0;i--){
        k=i; j=2*i; x=data[k];
        while(j<N){
            if(data[j]<data[j+1]) j=j+1;
            if(data[j]>x){
                data[k] = data[j];
                k=j;
                j=2*k;
            }else break;
        }
        data[k]=x;
    }
}


