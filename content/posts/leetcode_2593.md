
+++
authors = ["Crafted by Me"]
title = "Leetcode 2593: Find Score of an Array After Marking All Elements"
date = "2017-09-26"
description = "Solution to Leetcode 2593"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        while(!pq.empty()) {
            while(!pq.empty() && mp.count(pq.top()[1])) pq.pop();
            if(!pq.empty()) {
                score += pq.top()[0];
                mp[pq.top()[1]] = true;
                mp[pq.top()[1] + 1] = true;
                mp[pq.top()[1] - 1] = true;                
                pq.pop();
            }
        }
        return score;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

