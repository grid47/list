
+++
authors = ["Crafted by Me"]
title = "Leetcode 2251: Number of Flowers in Full Bloom"
date = "2018-09-03"
description = "Solution to Leetcode 2251"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flo, vector<int>& peo) {
        
        sort(flo.begin(), flo.end());

        vector<pair<int, int>> pp;
        
        for(int i = 0; i < peo.size(); i++) {
            pp.push_back(make_pair(peo[i], i));
        }

        sort(pp.begin(), pp.end());        
        
        vector<int> ans(peo.size(), 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int j = 0;
        for(int i = 0; i < peo.size(); i++) {

            while(!pq.empty() && pp[i].first > pq.top()) {
                // cout << pq.top() << ',';
                pq.pop();
            }
            // cout << '-';            
            
            while(j < flo.size() && pp[i].first >= flo[j][0]) {
                // cout << flo[j][1] << ',';
                if (pp[i].first <= flo[j][1])
                pq.push(flo[j][1]);
                j++;
            }
            // cout << '_';
            // cout << pp[i].first;
            // cout << '\n';
            
            ans[pp[i].second] = pq.size();
        }
        return ans;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

