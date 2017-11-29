//2012004236_정구열

#include <stdio.h>
#include <string.h>

#define MAX_NUM 501
#define MAX(a,b) ((a)>(b)) ? (a) : (b)
#define IS_BIGGER(a,b) ((a)>(b)) ? 1 : 0

void longest_common_sequence(char *, char *, int, int);

int main() {
    
    char seq_a[MAX_NUM], seq_b[MAX_NUM];
    int len_a, len_b;
    scanf("%s %s",seq_a, seq_b);
    len_a = (int)strlen(seq_a);
    len_b = (int)strlen(seq_b);
    
    if(IS_BIGGER(len_a, len_b))
        longest_common_sequence(seq_a, seq_b, len_a, len_b);
    else
        longest_common_sequence(seq_b, seq_a, len_b, len_a);
    
    return 0;
}

void longest_common_sequence(char *X, char *Y, int m, int n){
    
    int i, j;
    int L[m+1][n+1];
    
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = MAX(L[i-1][j], L[i][j-1]);
        }
    }
    
    int index = L[m][n];
    char lcs[index+1];
    
    i = m;
    j = n;
    
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    
    printf("%s\n",lcs);
}
