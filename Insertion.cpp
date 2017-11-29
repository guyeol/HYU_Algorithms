//2012004236_정구열
#include<stdio.h>
#define MAX_KEY 30000

void Insertion_Sort(int[], int);

int main()
{
    int num_of_key, i=0;
    int arr[MAX_KEY];
    
    scanf("%d",&num_of_key);
    while(i<num_of_key)
    {
        scanf("%d",&arr[i]);
        i++;
    }
    Insertion_Sort(arr, num_of_key);
    for(i=0;i<num_of_key;i++)
        printf("%d\n",arr[i]);
    return 0;
}
void Insertion_Sort(int arr[], int num)
{
    int i, j, key;
    for(j=1;j<num;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0&&arr[i]<key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}

