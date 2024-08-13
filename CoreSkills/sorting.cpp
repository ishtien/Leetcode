#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> & arr) {
    for(int i = 0; i < arr.size(); i++) {
        int pivot = arr[i];
        int j = i - 1;
        while(j >= 0 && pivot < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pivot;
    }
}

void bubbleSort(vector<int> & arr) {
    bool swapped;
    for(int i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for(int j = 0; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if(!swapped) break;
    }
}

void selectionSort(vector<int>& arr) {
    for(int i = 0; i < arr.size() - 1 ; i++) {
        int minNum = i;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[minNum]) {
                minNum = j;
            }
        }
        if(minNum != i) swap(arr[i], arr[minNum]);
    }
}
void merge(vector<int>& arr, int lo, int hi, int mid);
void mergeSort(vector<int>& arr, int lo, int hi) {
    if(hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, hi, mid);
}
void merge(vector<int>& arr, int lo, int hi, int mid) {
    vector<int> nums1(mid - lo + 1);
    vector<int> nums2(hi - mid);
    copy(arr.begin() + lo, arr.begin() + mid + 1, nums1.begin());
    copy(arr.begin() + mid + 1, arr.begin() + hi + 1, nums2.begin());

    int i = 0;
    int j = 0;

    for(int k = lo; k <= hi; k++) {
        if(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                arr[k] = nums1[i++];
            } else {
                arr[k] = nums2[j++];
            }
        }else if(i >= nums1.size()) {
            arr[k] = nums2[j++];
        }else if(j >= nums2.size()) {
            arr[k] = nums1[i++];
        }
    }
}
int partition(vector<int>& arr, int lo, int hi);
void quickSort(vector<int>& arr, int lo, int hi) {
    if(lo >= hi) return;
    int pivotIdx = partition(arr, lo, hi);
    quickSort(arr, lo, pivotIdx-1);
    quickSort(arr, pivotIdx+1, hi);
}
int partition(vector<int>& arr, int lo, int hi) {
    int i = lo - 1;
    int pivot = arr[hi];
    for(int k = lo ; k <= hi - 1; k++) {
        if(arr[k] <= pivot) {
            i++;
            swap(arr[i], arr[k]);
        }
    }
    i++;
    swap(arr[hi], arr[i]);
    return i;
}


void heapify(vector<int>& arr, int i, int sz) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l < sz && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < sz && arr[r]> arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, sz);
    }

}
void buildMaxHeap(vector<int>& arr) {
    int sz = arr.size();
    for(int i = sz/2 - 1; i>=0; i--) {
        heapify(arr, i, sz);
    }
}
void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    for(int i = arr.size()-1; i >=0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    
    std::cout << "原始數組: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // insertionSort(arr);
    // bubbleSort(arr);
    // selectionSort(arr);
    // mergeSort(arr, 0, arr.size()-1);
    // quickSort(arr, 0, arr.size()-1);
    heapSort(arr);
    
    std::cout << "排序後的數組: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
