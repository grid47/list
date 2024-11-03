
+++
authors = ["Crafted by Me"]
title = "Leetcode 1764: Form Array by Concatenating Subarrays of Another Array"
date = "2020-01-04"
description = "In-depth solution and explanation for Leetcode 1764: Form Array by Concatenating Subarrays of Another Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
        
        int numsIdx = 0, grpIdx = 0;
        
        while(numsIdx < nums.size() && grpIdx < group.size()) {
            

            int matchCnt = 0;
            
            while(numsIdx + matchCnt < nums.size() &&
                 matchCnt < group[grpIdx].size() &&
                 nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
                    matchCnt++;
            
            if(matchCnt == group[grpIdx].size()) {
                grpIdx++;
                numsIdx += matchCnt;
            } else numsIdx++;

        }
                
        return grpIdx == group.size();
        
    }
};
{{< /highlight >}}


---


"| 1765: Map of Highest Peak |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

