
#include <iostream>
#include <map>
#include <chrono>

using namespace std;



int* deepcopy(int* arr, int size){
    int* temp = new int[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = arr[i];
    }
    return temp;
}


bool isSubset1(int arr1[], int arr2[],
              int m, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
  

        if (j == m)
            return 0;
    }
  

    return 1;
}
int binarySearch(int arr[], int low,
                 int high, int x)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
  
        if ((mid == 0 || x > arr[mid - 1]) && (arr[mid] == x))
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid - 1), x);
    }
    return -1;
}
  
void exchange(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
  
int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;
  
    for (j = si; j <= ei - 1; j++) {
        if (A[j] <= x) {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange(&A[i + 1], &A[ei]);
    return (i + 1);
}
  

void quickSort(int A[], int si, int ei)
{
    int pi; /* Partitioning index */
    if (si < ei) {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
bool isSubset2(int arr1[], int arr2[],
              int m, int n)
{
    int i = 0;
  
    quickSort(arr1, 0, m - 1);
    for (i = 0; i < n; i++) {
        if (binarySearch(arr1, 0, m - 1,
                         arr2[i])
            == -1)
            return 0;
    }
  

    return 1;
}
bool isSubset3(int arr1[], int m,
              int arr2[], int n)
{
    map<int, int> frequency;
      
    for (int i = 0; i < m; i++)
    {
        frequency[arr1[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (frequency[arr2[i]] > 0)
            frequency[arr2[i]]--;
        else
        {
            return false;
        }
    }
    return true;
}


void test_isSubset1(int arr1[], int arr2[],int m, int n){
    cout << "algorithm 1:" << endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    if (isSubset1(arr1, arr2, m, n))
        cout << ("arr2[] is subset of arr1[] ") << "\n";
    else {
        cout << ("arr2[] is not a subset of arr1[]") <<   "\n";
    }
    


    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}

void test_isSubset2(int arr1[], int arr2[],int m, int n){
    cout << "algorithm 2:" << endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    if (isSubset2(arr1, arr2, m, n))
        cout << ("arr2[] is subset of arr1[] ") << "\n";
    else {
        cout << ("arr2[] is not a subset of arr1[]") <<   "\n";
    }
    


    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}
void test_isSubset3(int arr1[], int arr2[],int m, int n){
    cout << "algorithm 3:" << endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    if (isSubset3(arr1, m, arr2, n))
        cout << ("arr2[] is subset of arr1[] ") << "\n";
    else {
        cout << ("arr2[] is not a subset of arr1[]") <<   "\n";
    }
    


    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}



int main() {

    int n_lookup [] = { 100000,100000,
        200000,200000,500000,500000,800000,800000,1000000,1000000,2000000,2000000,3000000,3000000,4000000,4000000,5000000,5000000,6000000,6000000};
    int m_lookup[] = {1000, 10000,1000, 10000,1000, 10000,1000, 10000,1000, 10000,1000, 10000,1000, 10000,1000, 10000,1000, 10000,1000, 10000};
    for (int j = 0;j<20;j++){
        cout <<"\n" << "n = "<< n_lookup[j] << " m= "<<m_lookup[j]  << endl;
        int n =  n_lookup[j];
        int* arr1 = new int[n];
        for(int i=0;i<n;i++)
            arr1[i]=rand()%100000;
        int m =m_lookup[j] ;
        int* arr2 = new int[m];
        for(int i=0;i<m;i++)
            arr2[i]=rand()%100000;
        
        int * copy_arr = deepcopy(arr1,  n);
        test_isSubset1(copy_arr, arr2, n, m);
        delete [] copy_arr;
        copy_arr = deepcopy(arr1,  n);
        test_isSubset2(copy_arr, arr2, n, m);
        delete [] copy_arr;
        copy_arr = deepcopy(arr1,  n);
        test_isSubset3(copy_arr, arr2, n, m);
        delete [] copy_arr;
        delete [] arr1;
        delete [] arr2;
    }
    return 0;
}
