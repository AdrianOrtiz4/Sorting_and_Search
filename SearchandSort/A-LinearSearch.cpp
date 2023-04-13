#include <iostream>
#include <vector>
int Linearsearch(int arr[], int size, int target);
int RecursiveLinearSearch(int arr[], int size, int x);
int RVlinearSearch(std::vector<int>& arr, int target, int index);

int main(){
     int arr [5] = {2,5,6,9,4 };
    
    //Linear search Time  complexity O(n)
    //std::cout << Linearsearch(arr, 5, 9) << std::endl;
    //std::cout << RecursiveLinearSearch(arr, 5, 2) << std::endl;
}

int Linearsearch(int arr[], int size, int target){
    int i;
    for (i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int RecursiveLinearSearch(int arr[], int size, int x){
      
    size--;
      
    // Base case (Element not present in the array)
    if (size < 0) {
        return -1;
    }
    // Base case (Element found, return its position)
    if (arr[size] == x) {
        return size;
    }
  
    // Recursive case
    return RecursiveLinearSearch(arr, size, x);
    }
int RVlinearSearch(std::vector<int>& arr, int target, int index) {
    // Base case: target not found
    if (index == arr.size()) {
        return -1;
    }

    // Base case: target found
    if (arr[index] == target) {
        return index;
    }

    // Recursive case: search next element in vector
    return RVlinearSearch(arr, target, index+1);
}