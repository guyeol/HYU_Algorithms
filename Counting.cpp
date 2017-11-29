//
//  main.c
//  Algorithm_Counting
//
//  Created by 2012004236_정구열 on 2017. 10. 04..
//  Copyright © 2017년 Unknown. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int main() {
    int n,m,k,i;
    int a[MAX],b[MAX];
    int arr_in[MAX], arr_out[MAX];
    scanf("%d %d %d",&n,&m,&k);
    a[0]=0;
    b[0]=0;
    
    for(i=1;i<=k;i++)
        scanf("%d %d",&a[i],&b[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&arr_in[i]);
    for(i=0;i<=m;i++)
        arr_out[i]=0;
    for(i=1;i<=n;i++)
        arr_out[arr_in[i]]++;
    for(i=2;i<=m;i++)
        arr_out[i]=arr_out[i]+arr_out[i-1];
    for(i=1;i<=k;i++)
        printf("%d\n",arr_out[b[i]]-arr_out[a[i]-1]);
    
    return 0;
}
