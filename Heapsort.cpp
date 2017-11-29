//2012004236_정구열
#include <stdio.h>

#define MAX_NUM 100000

void Max_Heapify(int [], int, int);
void Heapsort(int[],int,int);
void Build_Heap(int[],int);

int main() {
    int num, k, i;
    int heapArr[MAX_NUM];
    
    scanf("%d %d",&num,&k);
    
    for(i=1;i<=num;i++)
        scanf("%d",&heapArr[i]);
    Build_Heap(heapArr, num);
    Heapsort(heapArr, num, k);
    for(i=1;i<=num-k;i++)
        printf("%d ",heapArr[i]);
    return 0;
}

void Heapsort(int arr[], int n, int k){
    int i,tmp;
    for(i=n;i>n-k;i--){
        printf("%d ",arr[1]);
        tmp=arr[i];
        arr[i]=arr[1];
        arr[1]=tmp;
        Max_Heapify(arr, i-1, 1);
    }
    printf("\n");
}

void Build_Heap(int arr[],int n){
    int i;
    for(i=n/2;i>0;i--)
        Max_Heapify(arr, n, i);
}

void Max_Heapify(int arr[], int n, int i)
{
    int tmp;
    int lar = i;
    int l = 2*i;
    int r = 2*i+1;
    
    if (l <= n && arr[l] > arr[lar])
        lar = l;
    
    if (r <= n && arr[r] > arr[lar])
        lar = r;
    
    if (lar != i)
    {
        tmp=arr[i];
        arr[i]=arr[lar];
        arr[lar]=tmp;
        Max_Heapify(arr, n, lar);
    }
}
