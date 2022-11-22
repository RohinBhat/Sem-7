#include <bits/stdc++.h>

using namespace std;

void printAnswer(vector<int> &arr)
{
    cout << "Sorted Array: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randPartition(vector<int> &arr, int low, int high)
{
    int range = high - low + 1;
    int randPivot = rand() % range + low;

    swap(arr[low], arr[randPivot]);

    return partition(arr, low, high);
}

void detQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        detQuickSort(arr, low, pivot - 1);
        detQuickSort(arr, pivot + 1, high);
    }
}

void nonDetQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        nonDetQuickSort(arr, low, pivot - 1);
        nonDetQuickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << endl;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    cout << endl;

    cout << "--------- MENU ---------" << endl;
    cout << "1. Deterministic" << endl;
    cout << "2. Non Deterministic" << endl;
    cout << "Choose Option: " << endl;
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        detQuickSort(arr, 0, n - 1);
        printAnswer(arr);
        break;

    case 2:
        nonDetQuickSort(arr, 0, n - 1);
        printAnswer(arr);
        break;

    default:
        cout << "Invalid Input!" << endl;
        break;
    }
}