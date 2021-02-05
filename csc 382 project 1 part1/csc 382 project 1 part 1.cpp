#include<iostream> 
#include<cstdlib> 
#include<cmath> 
#include<ctime> 
#include<algorithm> 
using namespace std;

//function to fill random array of size n 
void fillArray(int arr[], int N, int n)
{
	int no;

	for (int i = 0;i < n;i++)
	{
		no = rand() % N + 1;
		arr[i] = no;
	}
}

void swap(int& a, int& b)
{
	int temp;

	temp = a;

	a = b;
	b = temp;
}

void bubble_sort(int a[], int n)
{
	int temp;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[32000];

	int N[5] = {5000,8000,10000};
	int n[10] = {100,300,500,1000,2000,4000};

	int a, b, i;

	const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;

	cout << "Table to find the smallest in random array" << endl;
	cout << "Where n is size of array and N is range of element in array" << endl;
	cout << "-------------------------------" << endl;
	cout << " n   N   i  item Time(in MS)" << endl;
	cout << "-------------------------------" << endl;


	for (a = 0; a < 3; a++)
	{
		for (b = 0; b < 6; b++)
		{
			clock_t Start1 = clock(); //start time  

			fillArray(arr, N[a], n[b]); //generate random array 

			bubble_sort(arr, n[b]);

			i = rand() % n[a]; //find random i between 0 to n 

			int item = arr[i]; //read i in smallest element in sorted array 

			clock_t End1 = clock();

			int elapsedTime1 = (End1 - Start1) / CLOCKS_PER_MS; //end time

			cout << n[b] << " " << N[a] << " " << i << " " << arr[i + 1] << " " << elapsedTime1 << endl;
		}
	}
}