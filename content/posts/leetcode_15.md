
+++
authors = ["Crafted by Me"]
title = "Leetcode 15: 3Sum"
date = "2024-10-17"
description = "Solution to Leetcode 15"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/3sum/description/)

---

{{< youtube 8IjCNFIo8YI >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while(s < e) {
                if(nums[s] + nums[e] < target) {
                   s++;
                } else if (nums[s] + nums[e] > target) {
                    e--;
                } else {
                    vector<int> res = {nums[i], nums[s], nums[e]};
                    ans.push_back(res);
                    while(s < e && nums[s] == res[1]) s++;
                    while(s < e && res[2] == nums[e]) e--;                    
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/15.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

