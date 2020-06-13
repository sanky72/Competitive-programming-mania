#include<bits/stdc++.h> 
using namespace std; 

void combinationUtil(int arr[], int data[], 
					int start, int end, 
					int index, int r) 
{ 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++) 
			cout << data[j] << " "; 
		cout << endl; 
		return; 
	} 
 
	for (int i = start; i <= end && 
		end - i + 1 >= r - index; i++) 
	{ 
		data[index] = arr[i]; 
		combinationUtil(arr, data, i+1, 
						end, index+1, r); 
	} 
} 

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5}; 
	int r = 3; 
	int n = sizeof(arr)/sizeof(arr[0]); 
  int data[r]; 

	// Print all combination using 
	// temprary array 'data[]' 
	combinationUtil(arr, data, 0, n-1, 0, r); 
} 

