
+++
authors = ["Yasir"]
title = "Leetcode 2273: Find Resultant Array After Removing Anagrams"
date = "2018-08-08"
description = "Solution to Leetcode 2273"
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

{{< highlight html >}}
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

