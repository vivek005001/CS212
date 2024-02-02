#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getMax(vector<int> arr) {
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(vector<int>& arr, int place) {
    int out[arr.size()];
    int i, count[10] = {0};
    
    for (i = 0; i < arr.size(); i++) {
        count[(arr[i] / place) % 10]++;
    }
    
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (i = arr.size() - 1; i >= 0; i--) {
        out[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    
    for (i = 0; i < arr.size(); i++) {
        arr[i] = out[i];
    }
}



void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    for (int i = 1; m / i > 0; i *= 10) {
        countSort(arr, i);
    }
}

void printArr(vector<int>& arr1, vector<int>& arr2) {
    for (int i = arr1.size() - 1; i >= 0; i--) {
        cout << "-" << arr1[i] << " ";
    }
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    vector<int>arr;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    vector<int>arr1;
    vector<int>arr2;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            arr1.push_back(abs(arr[i]));
            
        }
        else{
            arr2.push_back(arr[i]);
            
        }
    }
    radixSort(arr1);
    radixSort(arr2);
    printArr(arr1,arr2);
    return 0;
}
