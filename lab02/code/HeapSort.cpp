#include <iostream>
#include <utility>
using namespace std;

//HEAPIFY FUNCTION
void buildheap(int arr[], int s, int i)
{
    int l = (2*i)+1; //Left child in tree
    int r = (2*i)+2;//Right child in tree
    int target = i;
    
    if(l < s && arr[l]>arr[i]) //compare left child to root
        target = l;
    
    if(r < s && arr[r]>arr[target]) // compare right
        target = r;
    
    if(target != i)
    {
        swap(arr[i], arr[target]);
        buildheap(arr, s, target);
    }
}
//heap sort pseudocode
void HeapSort(int arr[], int s)
{
    //transform array into a heap
    for (int i = (s/2) - 1; i >= 0; i--)
    {
        buildheap(arr, s, i);
    }
    for (int i= s-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        //increased sorted region
        buildheap(arr, i, 0);
        //rebuilds heap
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
    HeapSort(Sequence, arraySize);
    
    // Output the result
    for(int i=0; i<arraySize; i++)
        cout << Sequence[i] << endl;
    
    // Free allocated space
    delete[] Sequence;
}

//heapsort arr, n; where n is index size and arr array
