
+++
authors = ["Crafted by Me"]
title = "Leetcode 679: 24 Game"
date = "2022-12-24"
description = "In-depth solution and explanation for Leetcode 679: 24 Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/24-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool judgePoint24(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        do {
            if(valid(nums))
                return true;
        } while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
    
    bool valid(vector<int> &nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if(valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) || valid(a / b, c, d)) return true;
        if(valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) || valid(a, b / c, d)) return true;
        if(valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) || valid(a, b, c / d)) return true;
        return false;
    }
    
    bool valid(double a, double b, double c) {
        if(valid(a + b, c) || valid(a - b, c) || valid(a * b, c) || b && valid(a / b, c)) return true;
        if(valid(a, b + c) || valid(a, b - c) || valid(a, b * c) || c && valid(a, b / c)) return true;        
        return false;
    }
    
    bool valid(double a, double b) {
        if(abs(a + b - 24) < 0.001 || abs(a - b - 24) < 0.001 || abs(a * b - 24) < 0.001 || b && (abs(a / b - 24) < 0.001) ) return true;
        return false;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/679.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

