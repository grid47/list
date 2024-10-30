
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 75: Sort Colors"
date = "2024-08-17"
description = "Solution to Leetcode 75"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-colors/description/)

---
{{< youtube 4xbWSRZHqac >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        
        for(int k = 0; k < n; k++) {
            
            while(nums[k] == 2 && k < j) {
                swap(nums[k], nums[j--]);                
            }
            while(nums[k] == 0 && k > i) {
                swap(nums[k], nums[i++]);  
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/75.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

