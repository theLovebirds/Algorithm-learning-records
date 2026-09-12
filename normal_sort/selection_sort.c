#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int *sort(int *array)
{
    int i, k, temp, swapNum;
    for (i = 0; i < ARRAYLEN; i++)
    {
        swapNum = i;
        for (k = i; k < ARRAYLEN; k++)
        {
            // 遍历寻找最小元素
            if (array[k] < array[swapNum])
            {
                swapNum = k;
            }
        }
        // 将最小元素放置于已排序数组末尾
        temp = array[i];
        array[i] = array[swapNum];
        array[swapNum] = temp;
    }
    return array;
}

int *createArray(int *array)
{
    int i;
    for (i = 0; i < ARRAYLEN; i++)
    {
        array[i] = rand() % 21;
    }
    return array;
}

int *cheakArray(int *array){
    int i;
    for(i = 0;i < ARRAYLEN;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int *array = malloc(sizeof(int) * ARRAYLEN);
    array = createArray(array);
    sort(array);
    free(array);
    return 0;
}