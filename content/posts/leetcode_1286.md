
+++
authors = ["Crafted by Me"]
title = "Leetcode 1286: Iterator for Combination"
date = "2021-04-26"
description = "Solution to Leetcode 1286"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/iterator-for-combination/description/)

---

**Code:**

{{< highlight cpp >}}
class CombinationIterator {
public:
    string str;
    int len;
    vector<string> ans;
    map<int, int> mp;
    void bt(int idx, string &tmp) {
        if(tmp.size() == len) {
            ans.push_back(tmp);
            return;
        }
        if(idx == str.size()) {
            return;
        }
        
        for(int i = idx; i < str.size(); i++) {
            tmp += str[i];
            bt(i + 1, tmp);
            tmp.pop_back();
        }
        
    }
    int idx = 0;
    CombinationIterator(string chars, int len) {
        this->len = len;
        sort(chars.begin(), chars.end());
        str = chars;
        string tmp = "";
        bt(0, tmp);
    }
    
    string next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        if(idx < ans.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

