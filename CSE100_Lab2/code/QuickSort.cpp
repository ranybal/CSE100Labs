#include <iostream>
#include <utility>
#include <stdlib.h>
#include <string>

using namespace std;

int PARTITION(int *Arr, int p, int r) //ADAPTED FROM PSEUDOCODE GIVEN
{
    int a = Arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (Arr[j] <= a)
        {
            i++;
            swap(Arr[i], Arr[j]);
        }
    }
    swap(Arr[i + 1], Arr[r]);
    return i + 1;
}
/*
 PARTITION(A,p,r)
 x = A[r]
 i = p - 1
 for j = p to r - 1
 if A[j] <= x
 i = i + 1
 exchange A[i] and A[j]
 exchange A[i+1] and A[r]
 return i + 1
 */

void QUICKSORT(int *Arr, int p, int r)
{
    if (p < r)
    {
        int q = PARTITION(Arr, p, r);
        QUICKSORT(Arr, p, q - 1);
        QUICKSORT(Arr, q + 1, r);
    }
}


int main(int argc,char **argv)
{
    int *Sequence;
    int arraySize;
    
    // Get the size of the sequence
    cin >> arraySize;
    
    // Allocate enough memory to store "arraySize" integers
    Sequence = new int[arraySize];
    
    // Read in the sequence
    for ( int i=0; i<arraySize; i++ )
        cin >> Sequence[i];
    
    // Run your algorithms to manipulate the elements in Sequence
    QUICKSORT(Sequence, 0, arraySize - 1);
    
    // Output the result
    for(int i=0; i<arraySize; i++)
        cout << Sequence[i] << endl;
    
    // Free allocated space
    delete[] Sequence;
}