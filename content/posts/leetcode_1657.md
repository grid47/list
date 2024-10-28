
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1657: Determine if Two Strings Are Close"
date = "2020-04-16"
description = "Solution to Leetcode 1657"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

