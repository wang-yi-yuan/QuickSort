#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void QuickSort(int *arr, int high, int low); 

int main(int argc, char *argv[]) 
{
	//�㷨��ϰ�������㷨
	int a[SIZE] = {0};/*�������� */ 
	int maxlen = SIZE;
	int i;
	for(i=0;i<maxlen;i++)
	{
		a[i] = rand();
	}

	/*���������㷨*/ 
	QuickSort(a, maxlen-1, 0);

	/*������*/
	for(i=0;i<SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}

/*�㷨����*/
/*****************************************************
��������QuickSort
���������arr ָ�� ���ڽ�������
		  high ��̬���� ����ָʾ��Ҫ�������������ұ�
		  low ��̬���� ����ָʾ��Ҫ��������������� 
����ֵ���ޣ�void�� 
******************************************************/ 

void QuickSort(int *arr, int high, int low)
{
	if(low < high)//�����ж��Ƿ�ʣһ�������������������򷵻� 
	{
		int benchmark_number = arr[low]; //��׼�� 
		int l = low;   //��ָ�� 
		int h = high;  //��ָ��
		
		/*�ߵ�ָ���������Թ�*/
		while(l<h)
		{
			/*����������С�ڻ�׼����benchmark_number������*/ 
			while(arr[h]>=benchmark_number && l<h) 
			{
				h--;
			}
			
			if(l<h)// ���ڹ���l=h������ѭ�� 
			{
				arr[l++] = arr[h];
			}
			
			
			/*���������Ҵ��ڻ�׼����benchmark_number������*/ 
			while(arr[l]<benchmark_number && l<h)
			{
				l++;
			}
			
			if(l<h)//���ڹ���l=h������ѭ�� 
			{
				arr[h--] = arr[l];
			} 
			
		}
		arr[h] = benchmark_number; 
		
		/*�ݹ����*/
		QuickSort(arr,l-1,low);//�Ի�׼������� 
		QuickSort(arr,high,l+1);//�Ի�׼�ұ����� 
	}

}  

 
