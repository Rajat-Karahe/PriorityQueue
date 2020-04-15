//SpaceComplexity O(K)

#include<vector>
#include<queue>

class Triplet{
    public:
    int element;
    int arrIndex;
    int eleIndex;
};

class Compare
{
    public:
        bool operator() (Triplet a, Triplet b)
        {
            if(a.element > b.element){
                return true;
            }
            return false;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    vector<int> ans;
    vector<int> *temp = NULL;
    priority_queue<Triplet, vector<Triplet>, Compare> pq;
    int k = input.size();
    
    for(int i=0; i<k; i++){
        temp = input.at(i);
        Triplet p;
        p.element = temp->at(0);
        p.arrIndex = i;
        p.eleIndex = 0;
        pq.push(p);
    }
    
    while(!pq.empty()){
       	Triplet p = pq.top();
        pq.pop();        
        ans.push_back(p.element);
        int i = p.arrIndex;
        int j = p.eleIndex;
        temp = input.at(i);
        if(j < temp->size()-1){
            p.element = temp->at(j+1);
            p.eleIndex = j+1;
            pq.push(p);
        } 
    }
    
    return ans;
}
