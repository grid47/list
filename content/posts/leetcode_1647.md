
+++
authors = ["Yasir"]
title = "Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique"
date = "2020-04-26"
description = "Solution to Leetcode 1647"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mp;
        int n= s.size();
        for(char x: s)
            mp[x]++;
        vector<pair<int, char>> arr;
        for(auto it: mp) {
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end());
        n = arr.size();
        set<int> cnt;
        int del = 0;
        for(int i = 0; i < n; i++) {
            int tmp = arr[i].first;
            while(tmp > 0 && cnt.count(tmp)) {
                tmp--;
                del++;
            }
            if(tmp > 0) cnt.insert(tmp);
        }
        return del;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

