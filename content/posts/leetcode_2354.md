
+++
authors = ["Crafted by Me"]
title = "Leetcode 2354: Number of Excellent Pairs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2354: Number of Excellent Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Bit Manipulation"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-excellent-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        set<int> cnt;
        vector<int> arr;
        for(int i = 0; i < n; i++)
            if(cnt.count(nums[i])) continue;
            else {
                arr.push_back(__builtin_popcount(nums[i]));
                cnt.insert(nums[i]);
            }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] * 2 >= k) {
                
                ans += 2 * (arr.size() - (i + 1));
                ans++;

            } else {

                int x = k - arr[i];

                auto it = lower_bound(arr.begin(), arr.end(), x);
                if(it == arr.end()) continue;

                int y = arr.end() - it;
                ans += 2 * y;
            }
        }
        if(arr.back() * 2 >= k) ans++;
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube yHfTzZ5AJ48 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2355: Maximum Number of Books You Can Take](https://grid47.xyz/posts/leetcode_2355) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
