
+++
authors = ["Crafted by Me"]
title = "Leetcode 2824: Count Pairs Whose Sum is Less than Target"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2824: Count Pairs Whose Sum is Less than Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int countPairs(vector<int>& nums, int target) {
      int ans = 0;
      for(int i = 0; i < nums.size(); ++i){
          for(int j = i + 1; j < nums.size(); ++j){
              if(nums[i] + nums[j] < target) ans++;
          }
      }
      return ans;
  }
};
{{< /highlight >}}


---
{{< youtube Xe1teNERwSY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2825: Make String a Subsequence Using Cyclic Increments](https://grid47.xyz/posts/leetcode_2825) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
