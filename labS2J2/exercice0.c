#include <stdio.h>
#include <stdlib.h>

void combine(int arr[], int left, int m, int right)
{
	int i, j, k;
	int n1 = m - left + 1;
	int n2 = right - m;

	int Left[128], Right[128];

	for (i = 0; i < n1; i++) // O(n)
		Left[i] = arr[left + i];
	for (j = 0; j < n2; j++) // O(k)
		Right[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) // O(n*k)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int m = left + (right - left) / 2; // m = 0 + (5 - 0) / 2 = 2.5 après la deuxième fois m = 0 + (2 - 0) / 2
		// O(n)

		sort(arr, left, m); // sort(arr, 0, 2);
		sort(arr, m + 1, right);
		// O(n logn)

		combine(arr, left, m, right); // O(n)
	}
}

/* Driver code */
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};

	sort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);

	return 0;
}
