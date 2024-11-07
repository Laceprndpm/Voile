// #include <stdlib.h>
// #include <assert.h>
// // creat a pq
// int *pq_init(int size)
// {
//     assert(size > 0);
//     int array[] = malloc(size);
//     array[0] = size;
//     return array;
// }

// int pq_insert(int *pq, int num)
// {

// }

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} MinHeap;

// 创建一个新的最小堆
MinHeap *createMinHeap(int capacity)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->data = (int *)malloc(capacity * sizeof(int));
    return heap;
}

// 交换两个元素
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 向上调整
void heapifyUp(MinHeap *heap, int index)
{
    while (index > 0 && heap->data[index] < heap->data[(index - 1) / 2])
    {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// 向下调整
void heapifyDown(MinHeap *heap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

// 插入元素
void insert(MinHeap *heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap is full\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// 删除并返回最小元素
int extractMin(MinHeap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap is empty\n");
        return -1; // 或者其他错误值
    }
    int min = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

// 释放堆内存
void freeMinHeap(MinHeap *heap)
{
    free(heap->data);
    free(heap);
}

int main()
{
    MinHeap *heap = createMinHeap(10);
    int a = -1;
    *((unsigned int*)&a) <<= 1;
    printf("%d", a);
    return 0;
}
