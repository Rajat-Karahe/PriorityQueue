// A k sorted array is array in which a max displacement of k-1 position is required for each element to sort the array.

#include<iostream>
using namespace std;
#include<queue>

void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(input[i]);
    }
    
    int j=0;
    for(int i=k; i<n; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    
    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int input[] = {10, 12, 6, 7, 9, 1};
    int k = 3;
    kSortedArray(input, 6, k);
    for(int i=0; i<6; i++){
        cout << input[i] << " "; 
    }
}
