#include <iostream>
#include <vector>

void selectionSort(vector<int>& arr);
void recurSelectionSort(int a[], int n, int index = 0);
int minIndex(int a[], int i, int j);
using namespace std;

//Time complexity O(n^2)
int main() {
    // Example usage
    vector<int> arr = {5, 2, 8, 4, 1};

    // Call selection sort function
    selectionSort(arr);

    // Print sorted vector
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Iterative function for selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted subarray
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the minimum element with the first element in unsorted subarray
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int minIndex(int a[], int i, int j)
{
    if (i == j)
        return i;
 
    // Find minimum of remaining elements
    int k = minIndex(a, i + 1, j);
 
    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}
 
// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void recurSelectionSort(int a[], int n, int index = 0)
{
    // Return when starting and size are same
    if (index == n)
       return;
 
    // calling minimum index function for minimum index
    int k = minIndex(a, index, n-1);
 
    // Swapping when index and minimum index are not same
    if (k != index)
       swap(a[k], a[index]);
 
    // Recursively calling selection sort function
    recurSelectionSort(a, n, index + 1);
}