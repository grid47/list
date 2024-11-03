
+++
authors = ["Crafted by Me"]
title = "Leetcode 726: Number of Atoms"
date = "2022-11-07"
description = "In-depth solution and explanation for Leetcode 726: Number of Atoms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-atoms/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    
    void merge(map<string, int> &to, map<string, int> &from, int mul) {
        for(auto [key, val]: from) {
            to[key] += val * mul;
        }
    }
    
    string atom(string &eqn, int &i) {
        int i1 = i++;
        while(i < n && islower(eqn[i])) i++;
        return eqn.substr(i1, i - i1);
    }
    
    int num(string &eqn, int &i) {
        int i1 = i;
        while(i < n && isdigit(eqn[i])) i++;
        return i1 == i? 1: stoi(eqn.substr(i1, i - i1));
    }
    
    map<string, int> unit(string &eqn, int &i) {
        map<string, int> cnt;
        if(eqn[i] == '(') {
            map<string, int> cur = formula(eqn, ++i);
            int frq = num(eqn, ++i);
            merge(cnt, cur, frq);
        } else {
            string str = atom(eqn, i);
            int frq = num(eqn, i);
            cnt[str] = frq;
        }
        return cnt;
    }
    
    map<string, int> formula(string &eqn, int &i) {
        map<string, int> cnt;
        while(i < n && eqn[i] != ')') {
            map<string, int> res = unit(eqn, i);
            int mul = num(eqn, i);
            merge(cnt, res, mul);
        }
        return cnt;
    }
    
    string countOfAtoms(string eqn) {
        n = eqn.size();
        string ans = "";
        int i = 0;
        map<string, int> mp = formula(eqn, i);
        for(auto [key, val]: mp) {
            ans += (key + ((val == 1)? "" : to_string(val)));
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/726.md" >}}
---
{{< youtube 1rp7kIKlajI >}}

"| 727: Minimum Window Subsequence |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

