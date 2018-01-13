void Merge(int* arr, int left, int mid, int right){
	int temp[right-left+1];
	int i = left, j = mid+1;
	int k = 0;
	while(i != mid+1 && j != right+1){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i != mid+1) temp[k++] = arr[i++];
	while(j != right+1) temp[k++] = arr[j++];
	for(int h = left; h <= right; h++)
		arr[h] = temp[h - left];
}

void MergeSort(int* arr, int left, int right){
	if(left < right){
		int tmp = (left + right) / 2;
		MergeSort(arr, left, tmp);
		MergeSort(arr, tmp+1, right);
		Merge(arr, left, tmp, right);
	}
}
