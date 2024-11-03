
+++
authors = ["Crafted by Me"]
title = "Leetcode 1552: Magnetic Force Between Two Balls"
date = "2020-08-03"
description = "In-depth solution and explanation for Leetcode 1552: Magnetic Force Between Two Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int l = 0;
        int r = pos[n - 1]-pos[0];
        while(l < r) {
            int mid = r - (r - l) / 2;
            if(isValid(pos, mid, m)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    bool isValid(vector<int> &nums, int mid, int cnt) {
        int res = 1, cur = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] - cur >= mid) {
                res++;
                cur = nums[i];
            }
        }
        return res >= cnt;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1553: Minimum Number of Days to Eat N Oranges](https://grid47.xyz/posts/leetcode_1553) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

