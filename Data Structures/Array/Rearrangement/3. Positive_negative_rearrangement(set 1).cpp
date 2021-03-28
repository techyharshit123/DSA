// An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively
// Rearrange positive and negative numbers in O(n) time and O(1) extra space

//BUT BUT BUT
//In this method on rearranging the relative order of elements changes

#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void rearrange(int arr[], int n)
{

    // The following few lines are
    // similar to partition process
    // of QuickSort. The idea is to
    // consider 0 as pivot and
    // divide the array around it.
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Now all positive numbers are at
    // end and negative numbers at the
    // beginning of array. Initialize
    // indexes for starting point of
    // positive and negative numbers
    // to be swapped
    int pos = i + 1, neg = 0;

    // Increment the negative index by
    // 2 and positive index by 1,
    // i.e., swap every alternate negative
    // number with next positive number
    print(arr, n);
    cout << endl;
    while (pos < n && neg < pos && arr[neg] < 0)
    {
        swap(arr[neg], arr[pos]);
        print(arr, n);
        cout << endl;
        pos++;
        neg += 2;
    }
}

int main()
{
    int arr[] = {-1, -2, -3, 4, 5, 6, -7, 8, 9};
    rearrange(arr, 9);
    print(arr, 9);
}