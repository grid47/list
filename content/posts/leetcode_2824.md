
+++
authors = ["Crafted by Me"]
title = "Leetcode 2824: Count Pairs Whose Sum is Less than Target"
date = "2017-02-07"
description = "Solution to Leetcode 2824"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

