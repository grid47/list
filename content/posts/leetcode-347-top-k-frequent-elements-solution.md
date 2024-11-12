
+++
authors = ["grid47"]
title = "Leetcode 347: Top K Frequent Elements"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 347: Top K Frequent Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Sorting","Heap (Priority Queue)","Bucket Sort","Counting","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/top-k-frequent-elements/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/347.webp" 
    alt="A sequence of elements where the most frequent ones glow brightly, showing the top K frequencies."
    caption="Solution to LeetCode 347: Top K Frequent Elements Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> ma;
        for(int x: nums)
            ma[x]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto [key, val]: ma)
            pq.push(make_pair(val, key));
        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/347.md" >}}
---
{{< youtube jFZx4Q7UL5c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #349: Intersection of Two Arrays](https://grid47.xyz/posts/leetcode-349-intersection-of-two-arrays-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
