
+++
authors = ["Yasir"]
title = "Leetcode 3043: Find the Length of the Longest Common Prefix"
date = "2016-06-29"
description = "Solution to Leetcode 3043"
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

{{< highlight html >}}
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

