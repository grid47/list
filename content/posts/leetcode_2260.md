
+++
authors = ["Crafted by Me"]
title = "Leetcode 2260: Minimum Consecutive Cards to Pick Up"
date = "2018-08-26"
description = "In-depth solution and explanation for Leetcode 2260: Minimum Consecutive Cards to Pick Up in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int n = cards.size();
        int ans = n + 1;
        
        for(int i = 0; i < n; i++){
            if(mp.count(cards[i])) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;            
        }
        
        return ans == n + 1? -1: ans;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2261: K Divisible Elements Subarrays](https://grid47.xyz/posts/leetcode_2261) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

