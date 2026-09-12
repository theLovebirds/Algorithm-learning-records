# 算法

## 目录

- [排序](#排序)
    - [洗牌](#洗牌)
        - [Fisher-Yates-Shuffle](#fisher-yates-shuffle算法)
        - [Knuth-Durstenfeld-Shuffle](#knuth-durstenfeld-shuffle算法)
        - [Inside-Out-Algorithm](#inside-out-algorithm算法)
    - [冒泡](#冒泡)
    - [选择](#选择)
    - [插入](#插入)
    - [快速](#快速)
- 分治
    - 递归
    - 迭代
- 贪心
- 二分
- 位运算
## 排序
### 洗牌
#### Fisher-Yates-Shuffle算法
随机抽取数组中的一个元素并将其放置到新数组中。该算法对应的是现实中洗牌手法中的抽牌，将随机抽出的元素放到另外一个数组中，从而得到一个被打乱的数组。
[C语言实例](./shuffling/Fisher_Yates_shuffle.c):
~~~
int shuffle(int array[],int targetArray[]){
    int i,k,t = 0;
    for(i = ARRAYLEN;i > 0;i--){
        k = rand() % i;
        targetArray[t++] = array[k];
        for(;k < i;k++){
            array[k] = array[k+1];
            if(k == i-1){
                array[k] = -1;
            }
        }
    }
}
~~~
#### Knuth-Durstenfeld-Shuffle算法
随机抽取一个元素并将其放置到原数组的末尾，并在剩余的元素中继续抽取放置。该算法对应的是现实中洗牌手法中的换牌，在没处理过的数组中抽出一个或多个元素并将其放置到数组末尾末尾，并反复重复该步骤直到将牌堆打乱。
[C语言实例](./shuffling/Knuth_Durstenfeld_shuffle.c):
~~~
int * shuffle(int * array){
    int i,k,temp;
    for(i = ARRAYLEN;i > 0;i--){
        k = rand() % i;
        temp = array[k];
        array[k] = array[i-1];
        array[i-1] = temp;
    }
}
~~~
#### Inside-Out-Algorithm算法
正序遍历数组，将第i个元素随机插入到前i个位置中（包括i）。该算法对应的是现实中洗牌手法中的插牌，将一个数组看做两部分，分别对应已处理与未处理，从未处理的部分中选择元素并将其随机插入到已处理的部分中，通过随机插入将数组打乱。
[C语言实例](./shuffling/Inside_Out_Algorithm.c):
~~~
int * shuffle(int * array){
    int i,k,temp;
    for(i = 0;i < ARRAYLEN;i++){
        k = rand() % (i + 1);
        temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}
~~~

### 冒泡
冒泡排序通过重复的与相邻元素比较和交换，选择未处理部分中最大的元素并依次排序，这个过程就像气泡从底部升到顶部一样，因此得名冒泡排序。

冒泡排序会对数组进行单向遍历，并将数组分作未处理部分与已处理部分，处理过程为：
1. 选择边缘元素
2. 比较相邻元素大小
3. 若大于相邻元素则交换，若小于相邻元素则使用相邻元素进行后续步骤
4. 当元素遍历至末尾已处理部分时，将其排至已处理部分首位，并重复上述步骤

冒泡数组通过选中边缘目标循环对比相邻元素来进行排序，因为每轮循环都会选择未排序部分中最大的元素进行排序，像水中的气泡一样，因此得名冒泡排序。

时间复杂度O(n^2^)，空间复杂度O(1)。
[C语言实例](./normal_sort/bubble_sort.c):
~~~
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
~~~

### 选择
选择排序通过寻找数组未处理部分中的最小元素并插入至已处理部分末尾实现排序

选择排序会对数组进行单向遍历，寻找其中最小的元素，并将其排序，处理过程为：
1. 单向遍历数组未处理部分
2. 记录未处理部分中最小的元素
3. 遍历结束后将未处理部分中最小的元素插入至已处理部分末尾，并重复上述步骤

时间复杂度O(n^2^)，空间复杂度O(1)。
~~~
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
~~~
### 插入
插入排序通过在未处理部分中选择一个元素，并遍历比较已处理部分中的每一个元素，将其插入到合适的位置进行排序


~~~
int *sort(int *array)
{
    int i,k,base;
    for(i = 1;i < ARRAYLEN;i++){
        base = array[i];
        for(k = i - 1;array[k] > base && k >= 0;k--){
            array[k+1] = array[k];
        }
        array[k+1] = base;
    }
    return array;
}
~~~
### 快速
~~~
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
~~~
### 归并
## 分治

### 递归

递（通过反复调用自身将目标拆分为更小的目标）

归（当某个小目标无法再拆解时返回）

1. 确定结束目标
2. 拆解步骤
3. 设置小目标

经典实例-汉诺塔
C语言实例



