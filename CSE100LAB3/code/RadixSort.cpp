#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
//COUNTSORT ALGORITHM, given pseudocode
void countSort(vector<int> arr[], int s, int p)
{
   
    vector<int> * output;// use vec instead of int
    output = new vector<int>[s];
    
    int i, count[10] = {0};
    
    for (i = 0; i < s; i++)
    {
        count[ arr[i][p]%10]++;
    }
    
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    
    for (i = s-1; i >= 0; i--)
    {
        output[count[ arr[i][p]%10 ] - 1] = arr[i];
        count[ arr[i][p]%10 ]--;
    }
    for (i = 0; i < s; i++)
    {
        arr[i] = output[i];
    }
}


void radixsort(vector<int> arr[], int s)
{
    for (int p = 9; p >= 0 ; p--) //"10 digits where each digit has a value in 0. . .9."
    {
        countSort(arr, s, p);
    }
}

int main()
{
    int s;
    cin >> s;
    vector<int> *arr;
    arr = new vector<int>[s];
    for(int i =0;i<s;i++)
    {
        for(int j = 0; j<10; j++)
        {
            int n;
            cin>>n;
            arr[i].push_back(n);//values into array
        }
    }
    radixsort(arr, s);
    for (int i = 0; i < s; i++) //PRINT ARRAY
    {
        for(vector<int>::iterator out = arr[i].begin(); out != arr[i].end();out++)
        {
            cout << *out << ";";
        }
        cout << endl;
    }
    
    return 0;
}