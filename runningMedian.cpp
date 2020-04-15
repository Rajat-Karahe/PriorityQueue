//You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
//Print the only integer part of median.

//really bad complexity greater than O(n2)

#include<vector>
#include<queue>
using namespace std;
void findMedian(int arr[], int n){
	for(int i=0; i<n; i++){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int j=0; j<=i; j++){
            pq.push(arr[j]);
        }
        int size = i+1;
        if(size % 2 != 0){
            int mid = size/2;
            for(int k=0; k<size; k++){
                if(k==mid){
                    cout << pq.top() << endl;
                    break;
                }
                pq.pop();
            }
        }
        else{
            int mid1 = size/2;
            int mid2 = mid1-1;
            int val1;
            int val2;
            for(int k=0; k<size; k++){
                if(k==mid1){
                    val1 = pq.top();
                    break;
                }
                if(k==mid2){
                    val2 = pq.top();
                }
                pq.pop();
            }
            cout << (val1+val2)/2 << endl;
        }
    }
}
