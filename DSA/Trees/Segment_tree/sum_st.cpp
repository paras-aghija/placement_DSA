#include<bits/stdc++.h>
using namespace std;


void updateValueUtil(int* st, int l, int r, int i, int diff, int curr) {
	if(i < l || i > r)	return;
	st[curr] += diff;
	if(l == r)
		return;
	int mid = l + (r - l) / 2;
	updateValueUtil(st, l, mid, i, diff, 2 * curr + 1);
	updateValueUtil(st, mid + 1, r, i, diff, 2 * curr + 2);
}

void updateValue(int arr[], int *st, int n, int i, int newVal) {
	if(i < 0 || i > n - 1) {
		cout << "Invalid Input!!" << endl;
		return;
	}
	int diff = newVal - arr[i];
	arr[i] = newVal;
	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

int getSum(int* st, int l, int r, int qSt, int qEnd, int i) {  
    if (qSt <= l && qEnd >= r)  
        return st[i];  
    if (r < qSt || l > qEnd)  
        return 0;  
    int mid = l + (r -l) / 2;   
    return getSum(st, l, mid, qSt, qEnd, 2 * i + 1) +  
        getSum(st, mid + 1, r, qSt, qEnd, 2 * i + 2);  
}

int sumQuery(int* st, int n, int left, int right) {  
    // Range Validation
    if (left < 0 || right > n-1 || left > right) {  
        cout << "Range Invalid!!";  
        return -1;  
    }  
    return getSum(st, 0, n-1, left, right, 0);  
} 

int constructSegTree(int arr[], int l, int r, int *st, int ind) {  
    if (l == r) {  
        st[ind] = arr[l];  
        return arr[l];  
    }  
    int mid = l + (r -l) / 2;  
    st[ind] = constructSegTree(arr, l, mid, st, 2 * ind + 1) + constructSegTree(arr, mid+1, r, st, 2 * ind + 2);  
    return st[ind];  
}

int* segTree(int arr[], int n) {  
    int ht = (int) (ceil(log2(n)));  
    int maxSize = 2 * pow(2, ht) - 1;  
	// Allocated Memory
    int* st = new int[maxSize];  
    constructSegTree(arr, 0, n-1, st, 0);  
    return st;  
}

int main() {  
    int arr[] = {1, 4, 6, 8, 10, 12, 15};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    int* st = segTree(arr, n);  
    cout << "Query-1 => Range [2 - 4] : " << sumQuery(st, n, 2, 4) << endl;   
  	cout << "Query-2 => Range [1 - 5] : " << sumQuery(st, n, 1, 5) << endl;
  	updateValue(arr, st, n, 2, 7);
	
    return 0;  
}