// Given an array of elements of length N, ranging from 0 to N-1, your task is to write a program that rearranges the elements of the array. All elements may not be present in the array, if the element is not present then there will be -1 present in the array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

// { Driver Code Starts
#include <iostream>
using namespace std;

int *Rearrange(int *arr, int n);

int main()
{
    //code

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int *b = Rearrange(a, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends

int *Rearrange(int *arr, int n)
{
    // Complete the function

    for (int i = 0; i < n;)
    {
        if (arr[i] != i && arr[i] >= 0)
        {
            swap(arr[i], arr[arr[i]]);
        }
        else
            i++;
    }

    return arr;
}
