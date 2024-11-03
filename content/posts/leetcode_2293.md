
+++
authors = ["Crafted by Me"]
title = "Leetcode 2293: Min Max Game"
date = "2018-07-24"
description = "In-depth solution and explanation for Leetcode 2293: Min Max Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2294: Partition Array Such That Maximum Difference Is K](https://grid47.xyz/posts/leetcode_2294) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

