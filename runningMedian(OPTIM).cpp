// O(nlog(n))

#include<vector>
#include<queue>
using namespace std;
void findMedian(int arr[], int n){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    maxHeap.push(arr[0]);
    cout << arr[0] << endl;
    
    for(int i=1; i<n; i++){
        if(arr[i] > maxHeap.top()){
            minHeap.push(arr[i]);
        }
        else{
            maxHeap.push(arr[i]);
        }
        
        if((int)maxHeap.size() - (int)minHeap.size() >= 2){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
                
        else if((int)minHeap.size() - (int)maxHeap.size() >= 2){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        
        if(maxHeap.size() > minHeap.size()){
            cout << maxHeap.top() << endl;
        }
        else if(minHeap.size() > maxHeap.size()){
            cout << minHeap.top() << endl;
        }
        else{
            cout << (minHeap.top() + maxHeap.top())/2 << endl;
        }
        
    }
}
