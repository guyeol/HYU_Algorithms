//2012004236_정구열

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN(a,b) ((a)>(b))?(b):(a)

int main() {
    int i, j;
    int n;
    int e1, e2;
    int x1, x2;
    int a[2][MAX], t[2][MAX];
    int S[2][2], L[2][MAX];
    int path[MAX];
    
    scanf("%d",&n);
    scanf("%d %d", &e1, &e2);
    scanf("%d %d", &x1, &x2);
    
    for(i=0;i<2;i++){
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<2;i++){
        for(j=0;j<n-1;j++)
            scanf("%d",&t[i][j]);
    }
    
    S[0][0] = a[0][0] + e1;
    S[1][0] = a[1][0] + e2;
    
    for(i=0;i<n-1;i++){
        S[0][1] = MIN(S[0][0] + a[0][i+1], S[1][0] + t[1][i] + a[0][i+1]);
        S[1][1] = MIN(S[1][0] + a[1][i+1], S[0][0] + t[0][i] + a[1][i+1]);
        
        if(S[0][1] == S[0][0] + a[0][i+1])
            L[0][i+1] = 1;
        else
            L[0][i+1] = 2;
        
        if(S[1][1] == S[1][0] + a[1][i+1])
            L[1][i+1] =2;
        else
            L[1][i+1] = 1;
        S[0][0] = S[0][1];
        S[1][0] = S[1][1];
    }
    
    if(S[0][1] + x1>S[1][1] +x2){
        L[1][n] = 2;
        L[0][n] = -1;
        printf("%d\n",S[1][1] + x2);
    }
    else{
        L[1][n] = -1;
        L[0][n] = 1;
        printf("%d\n",S[0][1] + x1);
    }
    
    if(L[0][n] != -1)
        path[n] = 1;
    else
        path[n] = 2;
    
    for(i=n-1;i>0;i--)
        path[i] = L[path[i+1]-1][i];
    for(i=1;i<=n;i++)
        printf("%d %d\n",path[i],i);
    
    return 0;
}
