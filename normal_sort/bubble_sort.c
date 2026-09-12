#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int *sort(int *array)
{
    int i, k;
    for (i = ARRAYLEN - 1; i > 0; i--)
    {
        int condition = 0;
        // 用于判断是否进行过交换
        for (k = 0; k < i; k++)
        {
            if (array[k] > array[k + 1])
            // 判断是否大于后一个元素
            {
                // 进行交换
                int temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
                condition = 1;
            }
        }
        if (!condition)
        {
            // 如没有进行过交换则排序完成，跳出循环
            break;
        }
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