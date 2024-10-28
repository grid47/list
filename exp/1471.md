class cmp {
    public:
     bool operator() (pair<float,int> &a, pair<float, int> &b) {
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        float m;
        if(n & 1) {
            m = arr[n / 2];
        } else {
            m = arr[n/2-1];
        }
        priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
        
        for(int i = 0; i < n; i++) {
            // cout << abs(arr[i] - m) << " " << arr[i] << " ";
            pq.push({abs(arr[i] - m), arr[i]});
        }
        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};