//2012004236_정구열
#include <stdio.h>

#define MAX_NUM 100000

void Merge_Sort(int[],int,int);
void Merge(int[],int,int,int);

int main() {
    int arr[MAX_NUM], num, i;
    
    scanf("%d",&num);
    
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    Merge_Sort(arr, 0, num-1);
    for(i=0;i<num;i++)
        printf("%d\n",arr[i]);
    return 0;
}

void Merge_Sort(int arr[], int f, int l)
{
    int mid;
    if(f<l)
    {
        mid=(f+l)/2;
        Merge_Sort(arr, f, mid);
        Merge_Sort(arr, mid+1, l);
        Merge(arr, f, mid, l);
    }
}

void Merge(int arr[],int f, int mid, int l)
{
    int p = f, q = mid+1;
    
    int tmp[l-f+1] , k=0, i;
    
    for(i = f ;i <= l ;i++) {
        if(p > mid)
            tmp[ k++ ] = arr[ q++] ;
        else if ( q > l)
            tmp[ k++ ] = arr[ p++ ];
        else if( arr[ p ] > arr[ q ])
            tmp[ k++ ] = arr[ p++ ];
        else
            tmp[ k++ ] = arr[ q++];
    }
    for (int p=0 ; p< k ;p ++) {
        arr[ f++ ] = tmp[ p ] ;
    }
}
