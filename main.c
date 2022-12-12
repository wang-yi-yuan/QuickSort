#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void QuickSort(int *arr, int high, int low); 

int main(int argc, char *argv[]) 
{
	//算法练习：排序算法
	int a[SIZE] = {0};/*排序数组 */ 
	int maxlen = SIZE;
	int i;
	for(i=0;i<maxlen;i++)
	{
		a[i] = rand();
	}

	/*快速排序算法*/ 
	QuickSort(a, maxlen-1, 0);

	/*结果输出*/
	for(i=0;i<SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}

/*算法函数*/
/*****************************************************
函数名：QuickSort
传入参数：arr 指针 用于接收数组
		  high 静态变量 用于指示需要排序的数组的最右边
		  low 静态变量 用于指示需要排序的数组的最左边 
返回值：无（void） 
******************************************************/ 

void QuickSort(int *arr, int high, int low)
{
	if(low < high)//用于判断是否还剩一个数，不是则排序，是则返回 
	{
		int benchmark_number = arr[low]; //基准数 
		int l = low;   //低指针 
		int h = high;  //高指针
		
		/*高低指针相遇则略过*/
		while(l<h)
		{
			/*从右往左找小于基准数（benchmark_number）的数*/ 
			while(arr[h]>=benchmark_number && l<h) 
			{
				h--;
			}
			
			if(l<h)// 用于过滤l=h的跳出循环 
			{
				arr[l++] = arr[h];
			}
			
			
			/*从左往右找大于基准数（benchmark_number）的数*/ 
			while(arr[l]<benchmark_number && l<h)
			{
				l++;
			}
			
			if(l<h)//用于过滤l=h的跳出循环 
			{
				arr[h--] = arr[l];
			} 
			
		}
		arr[h] = benchmark_number; 
		
		/*递归调用*/
		QuickSort(arr,l-1,low);//对基准左边排序 
		QuickSort(arr,high,l+1);//对基准右边排序 
	}

}  

 
