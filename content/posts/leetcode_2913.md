
+++
authors = ["Crafted by Me"]
title = "Leetcode 2913: Subarrays Distinct Element Sum of Squares I"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2913: Subarrays Distinct Element Sum of Squares I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumCounts(vector<int>& ar) {
        int n=ar.size();
        int ans=0;
        map<int,int>fr;
        //sort(ar.begin(),ar.end());
        for(int i=0;i<n;i++){
            int val=0;
             map<int,int>fr;
            for(int j=i;j<n;j++){
                if(fr[ar[j]]==0) val++;
                fr[ar[j]]++;
                ans=ans+val*val;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2913.md" >}}
---
{{< youtube vBSxcFdwcQU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2914: Minimum Number of Changes to Make Binary String Beautiful](https://grid47.xyz/posts/leetcode_2914) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
