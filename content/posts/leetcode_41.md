
+++
authors = ["Yasir"]
title = "Leetcode 41: First Missing Positive"
date = "2024-09-14"
description = "Solution to Leetcode 41"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-missing-positive/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i]) {
                cout << nums[i] << " " << nums[nums[i] - 1] << "\n";
                swap(nums[i], nums[nums[i]-1]);      
                i--;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            // cout<< nums[i] << " " << i + 1 << "\n";
            if(nums[i] != i + 1)
                return i + 1;            
        }
        return nums.size() + 1;
    }
};
{{< /highlight >}}

