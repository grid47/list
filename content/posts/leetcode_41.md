
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 41: First Missing Positive"
date = "2024-09-18"
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

{{< highlight cpp >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

