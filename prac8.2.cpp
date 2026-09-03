#include <iostream>
using namespace std;

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;          
    int left = 2 * i + 1;      
    int right = 2 * i + 2;     

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
int main()
{
    int arr[] = {40, 20, 30, 10, 50, 15};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    printArray(arr, n);

    buildMinHeap(arr, n);

    cout << "Min Heap:" << endl;
    printArray(arr, n);

    return 0;
}
