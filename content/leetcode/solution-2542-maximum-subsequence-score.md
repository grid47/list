
+++
authors = ["grid47"]
title = "Leetcode 2542: Maximum Subsequence Score"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2542: Maximum Subsequence Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vJ7ZWmfO1Rw"
youtube_upload_date="2023-05-25"
youtube_thumbnail="https://i.ytimg.com/vi/vJ7ZWmfO1Rw/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subsequence-score/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2542.md" >}}
---
{{< youtube vJ7ZWmfO1Rw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2544: Alternating Digit Sum](https://grid47.xyz/leetcode/solution-2544-alternating-digit-sum/) |
| --- |
