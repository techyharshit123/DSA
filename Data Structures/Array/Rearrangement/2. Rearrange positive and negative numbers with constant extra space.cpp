// Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array without using any additional data structure like hash table, arrays, etc.The order of appearance should be maintained.

// https: //www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/

// TWO PONTER APPROACH
// C++ implementation of the above approach
#include <iostream>
using namespace std;

void RearrangePosNeg(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (true)
    {
        // Loop until arr[i] < 0 and
        // still inside the array
        while (arr[i] < 0 && i < n)
            i++;

        // Loop until arr[j] > 0 and
        // still inside the array
        while (arr[j] > 0 && j >= 0)
            j--;

        // if i is less than j
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
            break;
    }
}

// Driver Code
int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    RearrangePosNeg(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
