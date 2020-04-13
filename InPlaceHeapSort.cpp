
void inplaceHeapSort(int input[], int n){
    
	for(int i=1; i<n; i++){
        int childIndex = i;
        
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            
            if(input[parentIndex] > input[childIndex]){
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    int size = n;
    while(size){
        int parentIndex = 0;
        int temp = input[0];
        input[0] = input[size-1];
        input[size-1] = temp;
        size--;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        
        while(leftChildIndex < size){
            int minIndex = parentIndex;
            if(input[leftChildIndex] < input[minIndex]){
                minIndex = leftChildIndex;
            }

            if(rightChildIndex < size && input[rightChildIndex] < input[minIndex]){
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex){
                break;
            }

            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;
            parentIndex = minIndex;

            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
    }
}
