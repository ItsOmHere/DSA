#include <iostream>
using namespace std;

int countZeros(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] != 0)
            left = mid + 1;
        else
            right = mid;
    }  
    if (arr[left] == 1)
        return 0;

    return n - left;
}

int main()
{
    const int n = 7;
    int arr[n] = {1, 1, 1, 1, 0, 0, 0};

    cout << "Number of zeros = " << countZeros(arr, n);

    return 0;
}