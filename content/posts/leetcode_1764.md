
+++
authors = ["Yasir"]
title = "Leetcode 1764: Form Array by Concatenating Subarrays of Another Array"
date = "2019-12-30"
description = "Solution to Leetcode 1764"
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

{{< highlight html >}}
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

