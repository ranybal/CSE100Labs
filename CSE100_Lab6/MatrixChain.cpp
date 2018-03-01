#include <iostream>
using namespace std;

void printParenthesis(int i, int j, int bracket, int *name)
{
    /*
     PrintOptimalParens(s,i,j)
     */
    //BASED ON GIVEN PSEUDOCODE
    if (i == j)
    {
        //cout<<name++;
        cout <<"A"<<(i-1);
        return;
    }
   else
   cout << "(";
    
    printParenthesis(i, *((name+i*bracket)+j), bracket, name);
    // Recursively put brackets around subexpression
    
    printParenthesis(*((name+i*bracket)+j) + 1, j, bracket, name);
    
    cout << ")";
   
}

void matrixChainOrder(int p[], int n) //returns table m, brack
//BASED ON PSEUDOCODE
{
    int m[n][n];
    
    int brack[n][n];//stores optimal break point
    
    int i, j, k, c, q;
    
    for (i=1; i<n; i++)
    {
        m[i][i] = 0;
    }
    
    
    for (c=2; c<n; c++)   //c = chain length
    {
        for (i=1; i<n-c+1; i++)
        {
            j = i+c-1;//end index for chain of length c
            
            m[i][j] = 123456789; //INFINITY
            for (k=i; k<=j-1; k++)
            {
                
                q = m[i][k] + m[k+1][j] + ((p[i-1]) * (p[k])* (p[j]));
                
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    
                    brack[i][j] = k;//index for optimal split
                }
            }
        }
    }
    //return m and s
    cout << m[1][n-1];
    
    cout << endl;
    
    printParenthesis(1, n-1, n, (int *)brack);
    
    cout<<endl;
}


int main()
{
    int n;
    cin >> n;
    int * array = new int[n];
    for (int i=0; i<=n; i++)
    {
        cin >> array[i];
    }
    
    matrixChainOrder(array, n+1);
    
    return 0;
}
