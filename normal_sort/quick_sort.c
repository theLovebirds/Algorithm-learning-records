#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

const int ARRAYLEN = 20;

int swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(int * array, int left ,int right){
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && array[j] >= array[left])
        {
            j -= 1;
        }
        while (i < j && array[i] <= array[left])
        {
            i += 1;
        }
        swap(array,i,j);
    }
    swap(array,left,i);
    return i;
}

int *quickSort(int *array, int left, int right)
{
    if(left >= right){
        return array;
    }
    int pivot = partition(array, left, right);
    quickSort(array,left,pivot - 1);
    quickSort(array,pivot + 1,right);
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

int *cheakArray(int *array)
{
    int i;
    for (i = 0; i < ARRAYLEN; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int *array = malloc(sizeof(int) * ARRAYLEN);
    array = createArray(array);
    quickSort(array,0,ARRAYLEN-1);
    free(array);
    return 0;
}