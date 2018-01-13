void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

int partition(int* arr, int left, int right){
	int privot = arr[left];

	while(left < right){
		while(left < right && arr[right] > privot) right--;
		swap(arr[left], arr[right]);
		while(left < right && arr[left] < privot) left++;
		swap(arr[left], arr[right]);
	}

	arr[left] = privot;
	return left;
}

void quicksort(int* arr, int left, int right){
	if(left < right){
		int q = partition(arr, left, right);
		quicksort(arr, left, q-1);
		quicksort(arr, q+1, right);
	}	
}
