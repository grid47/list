
+++
authors = ["Crafted by Me"]
title = "Leetcode 1657: Determine if Two Strings Are Close"
date = "2020-04-20"
description = "In-depth solution and explanation for Leetcode 1657: Determine if Two Strings Are Close in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-two-strings-are-close/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size() != w2.size()) return false;
        int n = w1.size();
        map<char, int> m1, m2;
        int mask1 = 0, mask2 = 0;
        for(int i = 0; i < n; i++) {
            m1[w1[i]]++;
            m2[w2[i]]++;
            mask1 |= (1 << (w1[i] - 'a'));
            mask2 |= (1 << (w2[i] - 'a'));          
        }
        if(mask1 != mask2) return false;
        vector<int> arr, nums;
        for(auto it: m1) {
            arr.push_back(it.second);
        }
        sort(arr.begin(), arr.end());
        // for(int x: arr)
        //     cout << x << " ";
        // cout << "\n";
        for(auto it: m2) {
            nums.push_back(it.second);
        }
        sort(nums.begin(), nums.end());        
        // for(int x: nums)
        //     cout << x << " ";
        cout << "\n";        
        return nums == arr;
    }
};
{{< /highlight >}}


---
{{< youtube -jXQK-UeChU >}}
| Next : [LeetCode #1658: Minimum Operations to Reduce X to Zero](https://grid47.xyz/posts/leetcode_1658) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

