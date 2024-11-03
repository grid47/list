
+++
authors = ["Crafted by Me"]
title = "Leetcode 2644: Find the Maximum Divisibility Score"
date = "2017-08-07"
description = "In-depth solution and explanation for Leetcode 2644: Find the Maximum Divisibility Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-maximum-divisibility-score/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& div) {
        int n = div.size();
        int m = nums.size();
        vector<int> cnt(n, 0);
        int mx = 0, idx = *min_element(div.begin(), div.end());
        map<int, vector<int>> mp;
        for(int i = 0; i < m; i++) {
            if(mp.count(nums[i])) {
                for(int x: mp[nums[i]]) {
                    cnt[x]++;
                    if(cnt[x] > mx || (cnt[x] == mx && div[x] < div[idx])) {
                        mx = cnt[x];
                        idx = x;
                    }
                }
            } else {
                for(int j = 0; j < n; j++) {
                    if(nums[i] % div[j] == 0) {
                        mp[nums[i]].push_back(j);
                        cnt[j]++;
                        if(cnt[j] > mx || (cnt[j] == mx && div[j] < div[idx])) {
                            mx = cnt[j];
                            idx = j;
                        }                        
                    }
                }
            }
        }
        return mx == 0? idx:div[idx];
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

