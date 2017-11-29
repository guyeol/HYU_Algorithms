//2012004236_Guyeol\Jeong

#include <stdio.h>
#include <stdlib.h>

#define BIGGER(a,b) ((a)>(b)?(a):(b))

int max_key(int *a, int n){
    int max=a[0], i;
    
    for(i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

int main() {
    int n,m,i,max;
    int *keyset_a, *keyset_b;
    int *count_arr, num_of_same_key=0;
    
    scanf("%d %d",&n,&m);
    keyset_a=(int*)malloc(sizeof(int)*n);
    keyset_b=(int*)malloc(sizeof(int)*m);
    
    for(i=0;i<n;i++)
        scanf("%d",&keyset_a[i]);
    for(i=0;i<m;i++)
        scanf("%d",&keyset_b[i]);
    max=BIGGER(max_key(keyset_a,n),max_key(keyset_b,m));
    count_arr=(int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<=max;i++)
        count_arr[i]=0;
    
    for(i=0;i<n;i++)
        count_arr[keyset_a[i]]++;
    for(i=0;i<m;i++){
        if(count_arr[keyset_b[i]]>0)
            num_of_same_key++;
    }
    
    printf("%d\n",num_of_same_key);
    
    free(count_arr);
    free(keyset_b);
    free(keyset_a);
    return 0;
}
