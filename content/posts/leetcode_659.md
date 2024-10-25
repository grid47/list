
+++
authors = ["Yasir"]
title = "Leetcode 659: Split Array into Consecutive Subsequences"
date = "2023-01-07"
description = "Solution to Leetcode 659"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        
        for(int num: nums)
            left[num]++;

        for(int num: nums) { // nums is in increasing order
            if(left[num] == 0) continue;
            
            left[num]--;
            
            if(end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            else if(left[num + 1] > 0 && left[num + 2] > 0) {
                left[num + 1]--;
                left[num + 2]--;
                end [num + 2]++;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}

