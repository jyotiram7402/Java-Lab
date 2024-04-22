#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void bubble_sort_odd_even(vector<int>& arr) {
	bool isSorted = false;
	while(!isSorted) {
		isSorted = true;
		
		#pragma omp parallel for
		for(int i = 0; i < arr.size()-1; i+= 2){
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
				isSorted = false;
			}
		}
		#pragma omp parallel for
		for(int i = 1; i < arr.size()-1; i += 2) {
			if(arr[i] > arr[i + 1]) {
				swap(arr[i],arr[i+1]);
				isSorted = false;
			}
		}
	}
}

void print(vector<int> const &arr)
{
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << ' ';
    }
    cout<<endl;
}

int main() {
	vector<int> arr = {5, 2, 9, 1, 7, 6, 8, 3, 4};
	double start, end;
	cout<<"Original Input Before Sorting:";
	print(arr);
// Measure performance of parallel bubble sort using odd-even transposition
	start = omp_get_wtime();
	bubble_sort_odd_even(arr);
	end = omp_get_wtime();
	cout<<"After Sorting:";
	print(arr);
	cout << "Parallel bubble sort using odd-even transposition time: "<<end-start << endl;
	
}
