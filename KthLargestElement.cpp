#include <vector> 
#include <queue>

using namespace std;
int kthLargest (vector<int> arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    
    for(int i=k; i<n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}
