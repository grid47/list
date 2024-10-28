
+++
authors = ["Yasir"]
title = "Leetcode 2456: Most Popular Video Creator"
date = "2018-02-07"
description = "Solution to Leetcode 2456"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-popular-video-creator/description/)

---

**Code:**

{{< highlight html >}}
#define ll long long
class Solution {

    static bool cmp(pair<ll, string> p1, pair<ll, string> p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        else return p1.first > p2.first;
    }

public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        long long n = creators.size(), maxi = INT_MIN;
        map<string, ll> m1;
        map<string, vector<pair<ll, string>>> m2;

        for(int i = 0; i < n; i++) {
            m1[creators[i]] += views[i];
            m2[creators[i]].push_back(make_pair(views[i], ids[i]));
            maxi = max(maxi, m1[creators[i]]);
        }

        for(auto &[l, r] : m1) {
            if(r == maxi) {
                sort(m2[l].begin(), m2[l].end(), cmp);
                ans.push_back({l, m2[l].front().second});
            }
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

