
+++
authors = ["Crafted by Me"]
title = "Leetcode 1985: Find the Kth Largest Integer in the Array"
date = "2019-05-28"
description = "In-depth solution and explanation for Leetcode 1985: Find the Kth Largest Integer in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class cmp {
   
public:
    bool operator () (string &b, string &a) {
        
        if (a.size() != b.size())
            return a.length() < b.length();
        
        return a < b;
        
    }
    
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;
        for(int i = 0; i < nums.size(); i++) {
            
            pq.push(nums[i]);
            while(pq.size() > k) {
                pq.pop();
            }


        }
        
        return pq.top();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1985.md" >}}
---
{{< youtube lRCaNiqO3xI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1986: Minimum Number of Work Sessions to Finish the Tasks](https://grid47.xyz/posts/leetcode_1986) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

