
+++
authors = ["grid47"]
title = "Leetcode 1985: Find the Kth Largest Integer in the Array"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1985: Find the Kth Largest Integer in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Divide and Conquer","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "lRCaNiqO3xI"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1986: Minimum Number of Work Sessions to Finish the Tasks](https://grid47.xyz/leetcode/solution-1986-minimum-number-of-work-sessions-to-finish-the-tasks/) |
| --- |
