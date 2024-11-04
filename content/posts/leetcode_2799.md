
+++
authors = ["Crafted by Me"]
title = "Leetcode 2799: Count Complete Subarrays in an Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2799: Count Complete Subarrays in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = 0;
        set<int> dist;
        map<int, int> mp;
        for(int x: nums)
            dist.insert(x);
        int cur = 0, req = dist.size();
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp.size() < req) continue;
            while(mp.size() >= req) {
                cnt+= (n - i);
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube 1wXkWZtSD28 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2800: Shortest String That Contains Three Strings](https://grid47.xyz/posts/leetcode_2800) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

