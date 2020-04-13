#include <vector>

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        int ans = pq.at(0);
        pq.at(0) = pq.at(pq.size()-1);
        pq.pop_back();
        
        int parentIndex = 0;
        
        while(parentIndex < pq.size()-1){
            int childIndex1 = 2*parentIndex + 1;
            int childIndex2 = 2*parentIndex + 2;
            int minIndex = -1;
            
            if(childIndex1 >= pq.size()){
                break;
            }
            else if(childIndex2 >= pq.size()){
                minIndex = childIndex1;
            }
            else{
                if(pq[childIndex1] <= pq[childIndex2]){
                    minIndex = childIndex1;
                }
                else{
                    minIndex = childIndex2;
                }
            }
            
            if(pq[minIndex] < pq[parentIndex]){
                int temp = pq[minIndex];
                pq[minIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            parentIndex = minIndex;
        }
        
        return ans;
    }
    
    
};
