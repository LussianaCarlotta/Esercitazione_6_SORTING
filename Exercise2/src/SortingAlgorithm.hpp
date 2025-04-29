#pragma once

#include <iostream>
#include <vector>
#include <concepts>

using namespace std;


namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> convertible_to<bool>;
};

/// BUBBLE SORT
template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
	
    for (unsigned int i = 0; i < n - 1; i++)
    {
        for (unsigned int j = i+1; j < n; j++)
        {
            if (v[j] < v[i])
            {
				// swap(v[j], v[i])
				T tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
            }
        }
    }
}
//***************************************************************

// Heap per HeapSort
template<typename T>
void Heap(std::vector<T>& v, int n, int i)
{
    int radice = i;
    int vsx = 2*i + 1; //figlio sinistro
    int vdx = 2*i + 2; //figlio destro

    if (vsx < n && v[vsx] > v[radice])
        radice = vsx;

    if (vdx < n && v[vdx] > v[radice])
        radice = vdx;

    if (radice != i)
    {
		// swap(v[i], v[radice])
		T tmp = v[i];
		v[i] = v[radice];
		v[radice] = tmp;
	
        Heap(v, n, radice);
    }
}

///HEAP SORT
template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    const int n = v.size();
	
	// enqueve heaptree
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap(v, n, i);
	
	//dequeve heaptree
    for (int i = n - 1; i > 0; i--)
    {
		// swap(v[0], v[i])
		T tmp = v[0];
		v[0] = v[i];
		v[i] = tmp;
		
        Heap(v, i, 0);
    }
}

}



