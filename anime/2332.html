class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size();
        int m = passengers.size();
        queue<int> q;
        set<int> st;
        
        for(auto a: passengers) {
            q.push(a);
            st.insert(a);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int curbus = buses[i];
            int count = 0;
            int x ;

            while(!q.empty() && count < capacity && q.front() <= curbus) {
                x = q.front();
                q.pop();
                if(st.find(x - 1) == st.end()) ans = x - 1;
                count++;
            }

            if(count < capacity) {
                while(st.find(curbus) != st.end())
                 curbus--;
                ans = max(ans, curbus);
            }
        }
        return ans;
    }
};