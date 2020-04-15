//If two people have same priority

#include<queue>
int buyTicket (int *arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int> pq;
    queue<int> q;
    
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        q.push(arr[i]);
    }
    
    int count=0;
    while(!pq.empty()){
        if(q.front() == pq.top()){
            if(k == 0){
                return count+1;
            }
            else{
                count++;
                pq.pop();
                q.pop(); 
                k--;
            }
            
        }
        
        else{
         	q.push(q.front());
            q.pop();
            if(k==0){
                k = q.size()-1;
            }
            else{
                k--;
            }
        }
    }
    return count;
}
