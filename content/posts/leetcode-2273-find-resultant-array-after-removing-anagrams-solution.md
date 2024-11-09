
+++
authors = ["grid47"]
title = "Leetcode 2273: Find Resultant Array After Removing Anagrams"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2273: Find Resultant Array After Removing Anagrams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& A) {
        vector<string> ans;
        int n= size(A);
        for(int i=0;i<n;){
            int j=i+1;
            while( j<n and isang(A[i],A[j]) ) j++;
            ans.push_back(A[i]);
            i=j;
        }
        return ans;
    }
    //function for checking if two string are anagrams or not
    bool isang(string p,string q){
        vector<int> cnt(26);
        int res=0;
        for(auto i:p) cnt[i-'a']++;
        for(auto i:q) cnt[i-'a']--;         
        for(auto i:cnt) if(i!=0) return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2273.md" >}}
---
{{< youtube AdiW8KjFiyg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2274: Maximum Consecutive Floors Without Special Floors](https://grid47.xyz/posts/leetcode-2274-maximum-consecutive-floors-without-special-floors-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
