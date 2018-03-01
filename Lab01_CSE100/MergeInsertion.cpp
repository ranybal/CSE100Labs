#include <iostream>
using namespace std;

// insertion sort function
void insertionsort(int size, int *arr){
    int i,j,hold = 0;
    for (i = 1; i < size; i++) {//for loop that compares each value
        int hold = arr[i]; //keeps value of the current cell
        j = i;
        while(j > 0 && arr[j-1] > hold){ //loop used for sorting
            arr[j] = arr[j-1];
            arr[j-1] = hold;
            j--;
        }
        
        arr[j] = hold; //after loop exited, hold takes value cell ended
    }
}

void merge(int*, int, int, int, int);

void mergesort(int*array, int begin, int end, int size){
    //recursive function with first and last indecies of array
    int mid;
    if(begin - end >= 100){
        mid = (begin + end)/2;
        mergesort(array, begin, mid, size);
        mergesort(array, mid+1, end, size);
        merge(array, begin, end, mid, size);
    }
    else
    {
        insertionsort(size, array);
    }
    
    return;
    
}

void merge(int *array, int begin, int end, int mid, int size){
    int bindex, eindex, oindex, output[size];
    
    bindex = begin;
    eindex = mid+ 1;
    oindex = begin;
    
    while(bindex <= mid && eindex <= end){
        if(array[bindex] < array[eindex]){
            output[oindex] = array[bindex];
            
            oindex++;
            bindex++;
            
        }
        else {
            output[oindex] = array[eindex];
            oindex++;
            eindex++;
        }
    }
    while(bindex <= mid) {
        output[oindex] = array[bindex];
        
        oindex++;
        bindex++;
    }
    while(eindex <= mid) {
        output[oindex] = array[eindex];
        
        oindex++;
        eindex++;
    }
    for(bindex = begin; bindex < oindex; bindex++){
        array[bindex] = output[bindex];
    }
}



int main(int argc, char **argv) {
    //int array;
    int *array;
    int n;
    cin >> n;
    // int array[n];
    array = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    //cout << endl;
    
    mergesort(array, 0, n-1, n);
    //DISPLAY
    for(int j = 0; j < n; j++)
    {
        cout << array[j];
        cout << endl;
    }
    
    
    delete[] array;
}