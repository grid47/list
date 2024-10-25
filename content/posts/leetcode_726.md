
+++
authors = ["Yasir"]
title = "Leetcode 726: Number of Atoms"
date = "2022-11-01"
description = "Solution to Leetcode 726"
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

{{< highlight html >}}
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

