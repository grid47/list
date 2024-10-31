
+++
authors = ["Crafted by Me"]
title = "Leetcode 1233: Remove Sub-Folders from the Filesystem"
date = "2021-06-17"
description = "Solution to Leetcode 1233"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/)

---

**Code:**

{{< highlight cpp >}}
class TrieNode {
    vector<TrieNode*> letter;
    bool main;
public:
    TrieNode (bool m) {
        letter.resize(27, NULL);
        main = m;
    }
    
    bool add(string key) {
        TrieNode* root = this;
        for (int i = 1; i < key.size(); i++) {
            int nxt;
            if (key[i] == '/') nxt = 26;
            else               nxt = key[i] - 'a';

            if (root->letter[nxt] == NULL) {
                if(nxt != 26) root->letter[nxt] = new TrieNode(false);
                else {
                    if (root->main) return false;
                    root->letter[nxt] = new TrieNode(false);
                }
            }
            root = root->letter[nxt];
        }
        if(!root->main) {
            root->main = true;
            root->letter.resize(27, NULL);
        }
        return true;
    }
};

// plane sequence equated till they match
//     sufix is a letter        - go head its new directory with prefix name natches
//     sufix is a  : bar
//          is current a main dir then cut else create new dir
//                 - new folder - create it,
//                 - sub dir    - stop do not proceed or add

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());
        vector<string> ans;
        TrieNode* root = new TrieNode(false);
        for(int i = 0; i < folder.size(); i++) {
            if(root->add(folder[i]))
                ans.push_back(folder[i]);
        }
        return ans;
    }
};
{{< /highlight >}}



---

{{< youtube sFv6T_wLS4k >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

