
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2542: Maximum Subsequence Score"
date = "2017-11-15"
description = "Solution to Leetcode 2542"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subsequence-score/description/)

---
{{< youtube vJ7ZWmfO1Rw >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<pair<int, int>> nums;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        n = nums2.size(); 
        for(int i = 0; i < n; i++)
            nums.push_back({nums2[i], nums1[i]});
        
        sort(nums.rbegin(), nums.rend());
        
        long long score = 0, sum = 0;

        for(auto& [n2, n1]: nums) {
            
            pq.push(n1);
            sum += n1;
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k)
            score = max(score, sum * n2);
        }

        return score;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

