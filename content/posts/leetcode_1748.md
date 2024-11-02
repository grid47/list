
+++
authors = ["Crafted by Me"]
title = "Leetcode 1748: Sum of Unique Elements"
date = "2019-01-19"
description = "Solution to Leetcode 1748"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-unique-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum= 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]] <= 1)
                sum+= nums[i];
        }
        return sum;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

