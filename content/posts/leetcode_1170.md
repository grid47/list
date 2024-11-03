
+++
authors = ["Crafted by Me"]
title = "Leetcode 1170: Compare Strings by Frequency of the Smallest Character"
date = "2021-08-20"
description = "In-depth solution and explanation for Leetcode 1170: Compare Strings by Frequency of the Smallest Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1170.md" >}}
---


"| 1171: Remove Zero Sum Consecutive Nodes from Linked List |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

