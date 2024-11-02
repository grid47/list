
+++
authors = ["Crafted by Me"]
title = "Leetcode 1985: Find the Kth Largest Integer in the Array"
date = "2018-05-27"
description = "Solution to Leetcode 1985"
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


---
{{< youtube lRCaNiqO3xI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

