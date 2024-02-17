#ifndef QUICKSORT_H
	#define QUICKSORT_H
	#include "quicksort.h"
#endif
#ifndef PHONEBOOK_H
	#define PHONEBOOK_H
	#include "phonebook.h"
#endif

template< typename T >
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template< typename T, bool descending >
int particion(T *arr, int ini, int fin)
{
	// selecting last as pivot
	T pivot = arr[fin];
	int i, j;
	i = ini;
	j = fin - 1;
	while (i <= fin && j >= ini && i < j)
	{
		if (descending)
		{
			while (i <= fin && arr[i] >= pivot)
				i++;
			while (j >= ini && arr[j] < pivot)
				j--;
		}
		else
		{
			while (i <= fin && arr[i] <= pivot)
				i++;
			while (j >= ini && arr[j] > pivot)
				j--;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	// insert pivot in its final position
	j = fin;
	if (descending)
		while (j > 0 && (arr[j] > arr[j - 1]))
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	else
		while (j > 0 && (arr[j] < arr[j - 1]))
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	return j;
}

template< typename T, bool descending >
void sort(T *arr, int ini, int fin)
{
	while (ini < fin) {
		int piv = particion <T, descending> (arr, ini, fin);
		if (piv - ini < fin - piv) {
			sort <T, descending>(arr, ini, piv - 1);
			ini = piv + 1;
		} else {
			sort <T, descending>(arr, piv + 1, fin);
			fin = piv - 1;
		}
	}
}

template< typename T, bool descending >
void quicksort(T *arr, int size)
{
	if (size == 0)
		return;
	sort< T, descending >(arr, 0, size - 1);
}

template void quicksort< int, true >(int *arr, int size);
template void quicksort< int, false >(int *arr, int size);
template void quicksort< float, true >(float *arr, int size);
template void quicksort< float, false >(float *arr, int size);
template void quicksort< phonebook_t, true >(phonebook_t *arr, int size);
template void quicksort< phonebook_t, false >(phonebook_t *arr, int size);