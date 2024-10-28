
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2406: Divide Intervals Into Minimum Number of Groups"
date = "2018-03-29"
description = "Solution to Leetcode 2406"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minGroups(vector<vector<int>>& list) {
        sort(list.begin(), list.end());
        
        int res = 1, cnt = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
                
        int n = list.size();
        
        pq.push(list[0][1]);
        
        if(n == 1) return 1;
        for(int i = 1; i < n; i++) {
            int next = list[i][0];            
            while(!pq.empty() && next > pq.top()) {
                pq.pop();
                cnt--;
            }
            pq.push(list[i][1]);
            cnt++;
            res = max(res, cnt);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

