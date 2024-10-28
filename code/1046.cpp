class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int x: stones) {
            pq.push(x);
        }
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            
            int y = pq.top();
             pq.pop();
             if(y == x) {}
             else {
                    pq.push(abs(y-x));
             }            
        }
        return 0;
    }
};