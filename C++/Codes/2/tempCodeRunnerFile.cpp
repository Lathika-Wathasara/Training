#include <iostream>
using namespace std;
  
// Merges two subarrays of array[].
// First subarray is arr[begin..mid].
// Second subarray is arr[mid+1..end].
void merge(int array[], int const left, int const mid, int const right)
{
    // number of elements in subarrays
    int const sub_array_L = mid - left + 1;
    int const sub_array_R = right - mid;
  
    // Creating temporary subarrays
    auto *left_array = new int[sub_array_L];
    auto *right_array = new int[sub_array_R];
    // Copying data to temp arrays left[] and right[]
    for (auto i = 0; i < sub_array_L; i++){
        left_array[i] = array[left + i];}
    for (auto j = 0; j < sub_array_R; j++){
        right_array[j] = array[mid + 1 + j];}
  
    int id_array_L = 0,id_array_R = 0; // Initial index of sub-arrays
    int id_of_merged = left; // Initial index of merged array
  
    // Merging the temp arrays back into array
    while (id_array_L < sub_array_L && id_array_R < sub_array_R) {
        if (left_array[id_array_L] <= right_array[id_array_R]) {
            array[id_of_merged] = left_array[id_array_L];
            id_array_L++;
        }
        else {
            array[id_of_merged] = right_array[id_array_R];
            id_array_R++;
        }
        id_of_merged++;
    }
    // Copy the remaining elements of left
    while (id_array_L < sub_array_L) {
        array[id_of_merged] = left_array[id_array_L];
        id_array_L++;
        id_of_merged++;
    }
    // Copy the remaining elements of right
    while (id_array_R < sub_array_R) {
        array[id_of_merged] = right_array[id_array_R];
        id_array_R++;
        id_of_merged++;
    }

}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted.
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  
// Function to print an array.
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
int main()
{
    int size_array;
    std::cin >> size_array;

    int arr[size_array];

    for (int i=0; i<size_array; i++) {
         std::cin >> arr[i];
    }
  
    printArray(arr, size_array);
  
    mergeSort(arr, 0, size_array - 1);

    printArray(arr, size_array);
    return 0;
}