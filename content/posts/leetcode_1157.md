
+++
authors = ["Crafted by Me"]
title = "Leetcode 1157: Online Majority Element In Subarray"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1157: Online Majority Element In Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/online-majority-element-in-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class MajorityChecker {
public:
    vector<int> arr;
    unordered_map<int, vector<int>> mp;
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    int frq(int num, int l, int r) {
        if(!mp.count(num)) return 0;
        auto it = lower_bound(mp[num].begin(), mp[num].end(), l);
        if(it == mp[num].end()) return 0;
        auto it2 = upper_bound(mp[num].begin(), mp[num].end(), r);
        return it2 - it;
    }
    
    int idx(int l, int r) {
        return rand() % (r - l + 1) + l;
    }
    
    int query(int left, int right, int thq) {

        for(int i = 0; i < 20; i++) {
            int num = arr[idx(left, right)];
            if(frq(num, left, right) >= thq)
                return num;
        }

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1157.md" >}}
---
{{< youtube rPo0zvXvwMQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1158: Market Analysis I](https://grid47.xyz/posts/leetcode_1158) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

