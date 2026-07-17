#include <iostream>
using namespace std;

int main()
{
    // insertion sort
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}