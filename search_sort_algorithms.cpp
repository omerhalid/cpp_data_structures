// Cheat sheet for searching algorithms

/*
The important searching algorithms which frequently asked in interviews are:
1. Linear Search --> O(n)
2. Binary Search --> O(log n)
3. Depth First Search (DFS) --> O(V+E)
4. Breadth First Search (BFS) --> O(V+E)
5. Hashing --> O(1)
*/

/*
The important sorting algorithms which frequently asked in interviews are:
1. Bubble Sort --> O(n^2)
2. Selection Sort --> O(n^2)
3. Insertion Sort --> O(n^2)
4. Merge Sort --> O(n log n)
5. Quick Sort --> O(n^2)
6. Bucket Sort --> O(n^2)
*/

// Linear Search
// Linear search is a very simple search algorithm. In this type of search, a sequential search is made over all items one by one. Every item is checked and if a match is found then that particular item is returned, otherwise the search continues till the end of the data collection.

# include <iostream>
# include <vector>
using namespace std;


int linearSearch(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int x){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int depthFirstSearch(int arr[], int n, int x){
    // with linked list
    return -1;
}

int breadthFirstSearch(int arr[], int n, int x){
    // with linked list
    return -1;
}

int hashing(int arr[], int n, int x){
    // with linked list
    return -1;
}

// Sorting Algorithms

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n){ // where n is the size of the array
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void mergeSort(int arr[], int l, int r){ // where l is the left index and r is the right index
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        int i = l;
        int j = m+1;
        int k = l;
        int temp[100];

        while(i <= m && j <= r){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
                k++;
            }
            else{
                temp[k] = arr[j];
                j++;
                k++;
            }
        }
        while(i <= m){
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j <= r){
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(int p=l; p<=r; p++){
            arr[p] = temp[p];
        }
    }
}

void quickSort(int arr[], int l, int r){ // where l is the left index and r is the right index
    if(l < r){
        int pivot = arr[r];
        int i = l-1;
        for(int j=l; j<r; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[r];
        arr[r] = temp;

        int pi = i+1;

        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    std::vector<float> buckets[n];
    
    // Place array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIdx = n * arr[i];
        buckets[bucketIdx].push_back(arr[i]);
    }
    
    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    
    // Concatenate all buckets into arr[]
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}