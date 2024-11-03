
+++
authors = ["Crafted by Me"]
title = "Leetcode 2273: Find Resultant Array After Removing Anagrams"
date = "2018-08-13"
description = "In-depth solution and explanation for Leetcode 2273: Find Resultant Array After Removing Anagrams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


"| 2274: Maximum Consecutive Floors Without Special Floors |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

