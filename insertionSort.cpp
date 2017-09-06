void insertionSort(int* A, int size){
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

