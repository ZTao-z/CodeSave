#include <iostream>

using namespace std;

void insertionSortRaise(int* A, int size){
	int key, i;
	for(int j = 1; j < size; j++){
		key = A[j];
		//insert A[j] into the sorted sequence
		i = j - 1;
		while(i >= 0 && A[i] > key){
			A[i+1] = A[i];
			--i;
		}
		A[i+1] = key;
	}
}

void insertionSortDown(int* A, int size){
	int key, i;
	for(int j = size-2; j >= 0; j--){
		key = A[j];
		//insert A[j] into the sorted sequence
		i = j + 1;
		while(i < size && A[i] > key){
			A[i-1] = A[i];
			++i;
		}
		A[i-1] = key;
	}
}

int main(){
	int k[5] = {1,2,3,4,5};
	insertionSortDown(k,5);
	int a = 0;
	while(a < 5)
		cout << k[a++];
}
