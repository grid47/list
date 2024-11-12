
+++
authors = ["grid47"]
title = "Leetcode 2273: Find Resultant Array After Removing Anagrams"
date = "2024-03-24"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2274: Maximum Consecutive Floors Without Special Floors](https://grid47.xyz/posts/leetcode-2274-maximum-consecutive-floors-without-special-floors-solution/) |
| --- |
