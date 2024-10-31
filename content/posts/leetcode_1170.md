
+++
authors = ["Crafted by Me"]
title = "Leetcode 1170: Compare Strings by Frequency of the Smallest Character"
date = "2021-08-19"
description = "Solution to Leetcode 1170"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> bp(26, 0), ans(w.size(), 0), res(q.size(), 0);
        
        int j = 0;
        for(auto s: w) {
            bp= vector<int>(26, 0);
            for(char x: s) {
                bp[x - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(bp[i] > 0) {
                    ans[j] = bp[i];
                    break;
                }
            }
            j++;
        }
        
        sort(ans.begin(), ans.end());
        
        j = 0;
        for(auto s: q) {
            bp= vector<int>(26, 0);
            for(char x: s) {
                bp[x - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                if(bp[i] > 0) {
                    res[j] = bp[i];
                    break;
                }
            }
            j++;
        }
        // for(auto x: res)
        //     cout << x << " ";
        // cout << "\n";        
        vector<int> ret(q.size(), 0);
        for(int i = 0; i < res.size(); i++) {
            int qr = res[i];
            auto it = upper_bound(ans.begin(), ans.end(), qr);
            ret[i] = ans.end() - it;
            // cout << ret[i] << " ";
        }
        return ret;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

