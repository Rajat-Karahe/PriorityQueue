//Given an array of integers, check whether it represents max-heap or not.

bool checkMaxHeap(int arr[], int n){
    for(int i=0; i<n; i++){
        int parentIndex = i;
		int leftChildIndex = 2*parentIndex + 1;
    	int rightChildIndex = 2*parentIndex + 2;
        
        if(leftChildIndex < n && arr[parentIndex] < arr[leftChildIndex]){
            return false;
        }    
        if(rightChildIndex < n && arr[parentIndex] < arr[rightChildIndex]){
            return false;
        }
    }    
    
    return true;  
}
