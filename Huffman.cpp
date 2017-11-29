//2012004236_jeongguyeol

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300000

int k;
int n;
int sum;

typedef struct node{
    int fre;
    char c[5];
    struct node* left;
    struct node* right;
}NODE;

void insert(NODE** , NODE* );
NODE* extract(NODE ** );
void heapify_down(NODE** , int );
void heapify_up(NODE** , int );
void swap(NODE** , NODE** );
void build_huffman(NODE** );
void inorder(NODE *, int );
NODE* leaf_merge(NODE * , NODE *);

int main(void)
{
    int N;
    int S;
    int i, t = 0;
    NODE* leaf;
    NODE* heap[MAX_N];
    n = 0;
    k = 0;
    sum = 0;
    scanf("%d", &N);
    leaf = (NODE*)malloc(sizeof(NODE)*N);
    
    for (i = 0; i<N; i++)
    {
        scanf("%s", leaf[i].c);
        scanf("%d", &(leaf[i].fre));
    }
    scanf("%d", &S);
    for (i = 1; i <= N; i++)
    {
        leaf[i - 1].left = NULL;
        leaf[i - 1].right = NULL;
        insert(heap, &leaf[i - 1]);
    }
    build_huffman(heap);
    inorder(heap[1], 0);
    for (i = 1; i<N; i *= 2)
    {
        t++;
    }
    if (N == 1)
    {
        printf("%d\n", S);
        printf("%d\n", S);
    }
    else
    {
        printf("%d\n", S*t);
        printf("%d\n", sum);
    }
    free(leaf);
    return 0;
    
}
void insert(NODE **heap, NODE *input)
{
    int i;
    i = ++n;
    while ((i != 1) && (*input).fre < (*heap[i / 2]).fre)
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = input;
}
NODE* extract(NODE **heap)
{
    NODE* output;
    output = heap[1];
    swap(&heap[1], &heap[n--]);
    heapify_down(heap, 1);
    return output;
}
void heapify_up(NODE ** heap, int child)
{
    int parent = child / 2;
    while ((child != 1) &&
           (*heap[child]).fre<(*heap[parent]).fre)
    {
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent /= 2;
    }
}
void heapify_down(NODE** heap, int parent)
{
    int child, large;
    while (parent <= n / 2)
    {
        child = parent * 2;
        if (n >= child + 1)
        {
            if ((*heap[child + 1]).fre <= (*heap[child]).fre)
                large = child + 1;
            else
                large = child;
        }
        else
        {
            large = child;
        }
        if ((*heap[parent]).fre > (*heap[large]).fre)
        {
            swap(&heap[parent], &heap[large]);
            parent = large;
        }
        else
            break;
    }
}
void swap(NODE** leaf1, NODE**leaf2)
{
    NODE * temp;
    temp = *leaf1;
    *leaf1 = *leaf2;
    *leaf2 = temp;
}
NODE* leaf_merge(NODE* leaf1, NODE* leaf2)
{
    NODE* parent;
    parent = (NODE*)malloc(sizeof(NODE));
    if ((*leaf1).fre < (*leaf2).fre)
    {
        (*parent).left = leaf1;
        (*parent).right = leaf2;;
    }
    else
    {
        (*parent).right = leaf1;
        (*parent).left = leaf2;
    }
    (*parent).fre = (*leaf1).fre + (*leaf2).fre;
    (*parent).c[0] = '\0';
    return parent;
}
void build_huffman(NODE** heap)
{
    NODE* leaf1;
    NODE* leaf2;
    NODE* parent;
    while (n>1)
    {
        leaf1 = extract(heap);
        leaf2 = extract(heap);
        parent = leaf_merge(leaf1, leaf2);
        insert(heap, parent);
    }
}
void inorder(NODE * leaf, int level)
{
    if (leaf)
    {
        inorder(leaf->left, level + 1);
        if (leaf->c[0] != '\0')
            sum += level*(*leaf).fre;
        inorder(leaf->right, level + 1);
    }
    
}
