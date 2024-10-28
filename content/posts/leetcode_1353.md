
+++
authors = ["Yasir"]
title = "Leetcode 1353: Maximum Number of Events That Can Be Attended"
date = "2021-02-14"
description = "Solution to Leetcode 1353"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    
    int maxEvents(vector<vector<int>>& e) {
        
        int n = e.size();
        sort(e.begin(), e.end(), cmp);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, cnt = 0;
        for(int d = 1; d <= 100000; d++) {
            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            while(i < n && e[i][0] == d) {
                pq.push(e[i++][1]);
            }
            if(!pq.empty()) {
                pq.pop();
                cnt++;
            }
        }

        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

