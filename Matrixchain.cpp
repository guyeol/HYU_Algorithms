//2012004236_jeongguyeol

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void print_parentheses(int, int);
void matrix_chain(int *, int);

int S[MAX+1][MAX+1];
int main() {
    
    int n, i;
    int *p;
    
    scanf("%d",&n);
    p = (int*)malloc(sizeof(int)*(n+1));
    
    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);
    
    matrix_chain(p, n);
    
    free(p);
    return 0;
}

void matrix_chain(int *p, int n){
    int m[n+1][n+1];
    int i, j, k, r;
    int min, tmp, min_k;
    
    for(r = 1; r<=n ;r++){
        j = r;
        for(i = 1; i<=n-r+1; i++){
            if(i==j)
                m[i][j] = 0;
            else if(i<j){
                min = m[i+1][j] + p[i-1]*p[i]*p[j];
                min_k = i;
                for(k=i+1;k<j;k++){
                    tmp = m[i][k]+m[k+1][j]+(p[i-1])*(p[k])*(p[j]);
                    if(min>tmp){
                        min = tmp;
                        min_k = k;
                    }
                }
                S[i][j] = min_k;
                m[i][j] = min;
            }
            j++;
        }
    }
    printf("%d\n",m[1][n]);
    print_parentheses(1, n);
    printf("\n");
}

void print_parentheses(int i, int j){

    if(i == j)
        printf("%d ",i);
    else{
        printf("( ");
        print_parentheses(i, S[i][j]);
        print_parentheses(S[i][j]+1, j);
        printf(") ");
    }
}
