
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2293: Min Max Game"
date = "2018-07-22"
description = "Solution to Leetcode 2293"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-max-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1) return nums[0];  // Base case
        vector<int> newNum(n/2); 
        for(int i=0; i<n/2; i++) { 
            if(i%2==0) newNum[i] = min(nums[2 * i], nums[2 * i + 1]); 
            else newNum[i] = max(nums[2 * i], nums[2 * i + 1]); 
        } 
        int res = minMaxGame(newNum); // Recursive call
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

