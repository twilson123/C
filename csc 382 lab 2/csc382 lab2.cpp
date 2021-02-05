#include<iostream>
#include<iomanip>
using namespace std;
const int max_value = 200000;
int B[max_value];
void InsertionSort(int A[], int n) 
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (A[j] < A[j - 1])
		{
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
}
void Merge(int A[], int first, int mid, int last) 
{
	int i = first, j = mid + 1, p;
	int k = first;//use in b[];
	while ((i <= mid) && (j <= last))
	{
		//exactly one of the pointers will reach its limit

			if (A[i] <= A[j])
			{
				B[k] = A[i]; //push A[i] to B[k]
				i++;
			}
			else
			{ //we must A[h] to B
				B[k] = A[j];
				j++;
			}
		k++;
	} 
	//push the remaining elements into B.
	if (i > mid)
	{
		//we pushed the remaining elements starting at A[h]
		for (p = j; p <= last; p++) 
		{
			B[k] = A[p];
			k++;
		}
	}
	else
	{
		for (p = i; p <= mid; p++)
		{ 
			//we push remaining elements starting at A[l]
			B[k] = A[p];
			k++;
		}
	}
	//Next we move B[low:high] to A[low:high]
	for (i = first; i <= last; i++)
	{
		A[i] = B[i];
	} 
} 

void MergeSort(int A[], int first, int last)
{
	int mid;
	if (first < last) 
	{ 
		//if the sub-list has more than one element
		mid = (first + last) / 2;
		MergeSort(A, first, mid); //Mergesort for the first half
		MergeSort(A, mid + 1, last); //Mergesort for the second half,
		Merge(A, first, mid, last);//two halves are sorted
	}
}

void HeapSort(int A[], int n) 
{
	int temp;
	for (int i = (n / 2); i >= 1; i--)
		
	
	for (int i = n - 1; i >= 1; i--) 
	{
		temp = A[i + 1];
		
		A[i + 1] = temp;
	}
}
void timeUse(int num)
{
	int bound = 5000000, random;
	int Sequence[max_value];
	for (int i = 0; i < num; i++)
	{
		random = rand() % bound;
		Sequence[i] = random;
	}
	cout << setw(10) << num << fixed;
	double clockTime1, clockTime2, clockTime3, clockTime4, clockTime5, clockTime6;
	clockTime1 = clock();//Insertion Sort
	InsertionSort(Sequence, num);
	clockTime2 = clock();
	cout << setw(14) << setprecision(3) << (clockTime2 - clockTime1) / CLOCKS_PER_SEC;
	clockTime3 = clock();//Merge Sort
	MergeSort(Sequence, 0, num - 1);
	clockTime4 = clock();

	cout << setw(17) << setprecision(3) << (clockTime4 - clockTime3) / CLOCKS_PER_SEC;
	clockTime5 = clock();//Heap Sort
	HeapSort(Sequence, num);
	clockTime6 = clock();
	cout << setw(14) << setprecision(3) << (clockTime6 - clockTime5) / CLOCKS_PER_SEC << endl;
}
int main()
{
	cout << setw(12) << "Input Size\t" << setw(10) << "Insertion Sort\t" << setw(12) << "Merge Sort";
	cout << setw(14) << "Heap Sort\t" << endl;
	int dataNeed[] = { 100, 200, 300, 400, 500, 1000, 4000, 10000 };
	int value = *(&dataNeed + 1) - dataNeed;
	long length;
	for (int i = 0; i < value; i++) 
	{
		length = dataNeed[i];
		timeUse(length);
	}
	return 0;
}