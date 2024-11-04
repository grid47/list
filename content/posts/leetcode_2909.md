
+++
authors = ["Crafted by Me"]
title = "Leetcode 2909: Minimum Sum of Mountain Triplets II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2909: Minimum Sum of Mountain Triplets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> smallestRight(nums.size(), nums.back());
        for(int i = nums.size()-2; i >= 0; i--){
            smallestRight[i] = min(smallestRight[i+1], nums[i]);
        }
        int smallestLeft = nums[0], ans = -1;
        for(int i = 1; i < nums.size(); i++){
            if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
                if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
                else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
            }
            smallestLeft = min(smallestLeft, nums[i]);
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube PU5YZP1-uVA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2910: Minimum Number of Groups to Create a Valid Assignment](https://grid47.xyz/posts/leetcode_2910) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

