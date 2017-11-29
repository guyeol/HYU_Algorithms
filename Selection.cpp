//2012004236_정구열
#include <stdio.h>
#define MAX_NUM 30000

int main()
{
    int i, j, num, step, min, tmp;
    int arr[MAX_NUM];
    
    scanf("%d %d",&num,&step);
    
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<step;i++)
    {
        min=i;
        for(j=i+1;j<num;j++)
        {
            if(arr[min]>arr[j])
                min=j;
        }
        tmp=arr[min];
        arr[min]=arr[i];
        arr[i]=tmp;
    }
    for(i=0;i<num;i++)
        printf("%d\n",arr[i]);
    return 0;
}

