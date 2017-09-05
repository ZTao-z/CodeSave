#define SWAP(a,b){ int t; t = a; a = b; b = t; }


int partition(E number[], int left, int right)
{
    int i, j, s;

    s = number[right];
    i = left-1;

    for(j = left; j < right; j++){
        if(number[j] <= s){
            i++;
            SWAP(number[i],number[j]);
        }
    }
    SWAP(number[i+1], number[right]);
    return i+1;
}

void quicksort(E number[], int left, int right)
{
    int q;
    if(left < right){
        q = partition(number,left,right);
        quicksort(number,left,q-1);
        quicksort(number,q+1,right);
    }
}