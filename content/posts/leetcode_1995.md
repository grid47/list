
+++
authors = ["Crafted by Me"]
title = "Leetcode 1995: Count Special Quadruplets"
date = "2019-05-18"
description = "In-depth solution and explanation for Leetcode 1995: Count Special Quadruplets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-special-quadruplets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const auto n = nums.size();
        unordered_map<int, int> freq;
        
        freq[nums[n - 1]] = 1;
        size_t answ = 0;
        for (int i = n - 2; i > 1; --i)
        {
            for (int j = i - 1; j > 0; --j)
            {
                for (int k = j - 1; k >= 0; --k)
                {
                    if (freq.count(nums[i] + nums[j] + nums[k]))
                    {
                        answ += freq[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
            freq[nums[i]] += 1;
        }
        return answ;
    }
};
{{< /highlight >}}


---


"| 1996: The Number of Weak Characters in the Game |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

