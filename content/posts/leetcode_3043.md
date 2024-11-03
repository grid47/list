
+++
authors = ["Crafted by Me"]
title = "Leetcode 3043: Find the Length of the Longest Common Prefix"
date = "2016-07-04"
description = "In-depth solution and explanation for Leetcode 3043: Find the Length of the Longest Common Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int size(int x) {
        int sz = 0;
        while(x > 0) {
            sz++;
            x /= 10;
        }
        return sz;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> mp;
        
        int arr[] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
        
        for(int x: arr1) {
            int p = x;
            int sz = 0;
            for(int i = 0; i < 8; i++) {
                
                if(p / arr[i] > 0) {
                    sz++;
                    mp[p / arr[i]] = sz;
                    // cout << p / arr[i] << " " << sz << "\n";
                }
                
            }
        }
        int mx = 0;
        for(int x: arr2) {
            int p = x;
            for(int i = 0; i < 8; i++) {
                if(p / arr[i] > 0) 
                if(mp.count(p / arr[i]))
                    mx = max(mx, mp[p / arr[i]]);
            }
        }
        return mx;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #3044: Most Frequent Prime](grid47.xyz/leetcode_3044) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

