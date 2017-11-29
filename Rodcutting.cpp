//2012004236_정구열

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, max;
    int *p, *r, *s;
    
    scanf("%d",&n);
    
    p=(int*)malloc(sizeof(int)*(n+1));
    r=(int*)malloc(sizeof(int)*(n+1));
    s=(int*)malloc(sizeof(int)*(n+1));
    
    p[0]=0;
    r[0]=0;
    s[0]=0;
    
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    
    for(i=1;i<=n;i++){
        max = -1;
        for(j=1;j<=i;j++){
            if(max<p[j]+r[i-j]){
                max = p[j]+r[i-j];
                s[i] = j;
            }
        }
        r[i] = max;
    }
    
    printf("%d",r[n]);
    printf("\n");
    while(n>0){
        printf("%d ",s[n]);
        n -= s[n];
    }
    printf("\n");
    
    free(s);
    free(r);
    free(p);
    
    return 0;
}
