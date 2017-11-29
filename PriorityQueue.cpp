//2012004236_jeong guyeol
#include <stdio.h>

#define MAX_NUM 100000

void Down_Heapify(int[],int);
void Up_Heapify(int[],int);
void Substitute(int[],int,int);
void Heapsort(int[],int,int);
void Insertion(int[],int);
void Extract_Max(int[]);
void Print_Heap(int[]);

int heap_size=0, deleted_cnt=0;
int deleted_key[MAX_NUM];

int main() {
    int command, data1,data2;
    int arr[MAX_NUM];
    
    while(1){
        scanf("%d",&command);
        switch(command){
            case 0:
                Print_Heap(arr);
                return 0;
                break;
            case 1:
                scanf("%d",&data1);
                Insertion(arr,data1);    //insert into tree
                break;
            case 2:
                Extract_Max(arr);              //Delete Maximum key from the tree
                break;
            case 3:
                scanf("%d",&data1);
                scanf("%d",&data2);
                Substitute(arr, data1, data2);        // substitute the third integer for the element indexed by the second number
                break;
            default:
                printf("Wrong input typed\n");
                break;
        }
    }
    return 0;
}

void Substitute(int arr[], int i, int key){
    if (arr[i]>key){
        arr[i] = key;
        Down_Heapify(arr, i);
    }
    else if (arr[i]<key){
        arr[i] = key;
        Up_Heapify(arr, i);
    }
    else
        arr[i] = key;
}

void Down_Heapify(int arr[],  int i)
{
    int tmp;
    int lar = i;
    int l = 2*i;
    while (i <= heap_size / 2)
    {
        l = i * 2;
        if (heap_size >= l + 1)
        {
            if (arr[l + 1] >= arr[l])
                lar = l + 1;
            else
                lar = l;
        }
        else
        {
            lar = l;
        }
        if (arr[i]<arr[lar])
        {
            tmp=arr[i];
            arr[i]=arr[lar];
            arr[lar]=tmp;
            i = lar;
        }
        else
            break;
    }
}

void Up_Heapify(int arr[], int i){
    int tmp;
    int parent = i/2;
    while((i!=1) && arr[i]>arr[parent]){
        tmp=arr[i];
        arr[i]=arr[parent];
        arr[parent]=tmp;
        i=parent;
        parent/=2;
    }
}

/*
 *Insert key into the tree's end
 */
void Insertion(int arr[], int key){
    int i;
    i=++heap_size;
    while((i!=1) && key>arr[i/2]){
        arr[i] = arr[i/2];
        i/=2;
    }
    arr[i]=key;
}
/*
 * Extract_Max is extract maximum data from the tree's root, then re-build the tree
 */
void Extract_Max(int arr[]){
    deleted_key[deleted_cnt++]=arr[1];
    arr[1]=arr[heap_size];
    heap_size--;
    Down_Heapify(arr, 1);
}

void Print_Heap(int arr[]){
    int i;
    if(deleted_cnt!=0){
        for(i=0;i<deleted_cnt;i++)
            printf("%d ",deleted_key[i]);
        printf("\n");
    }
    for(i=1;i<=heap_size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
