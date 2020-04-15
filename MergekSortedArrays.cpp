#include<vector>
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    vector<int> *temp = NULL;
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = input.size();
	
    for(int i=0; i<k; i++){
        temp = input.at(i);
        for(int j=0; j<temp->size(); j++){
            pq.push(temp->at(j));
        }
    }
    
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}
