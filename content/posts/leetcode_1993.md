
+++
authors = ["Crafted by Me"]
title = "Leetcode 1993: Operations on Tree"
date = "2019-05-20"
description = "In-depth solution and explanation for Leetcode 1993: Operations on Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/operations-on-tree/description/)

---

**Code:**

{{< highlight cpp >}}
class LockingTree {
    vector<int> nodes;
    vector<vector<int>> chd;
    map<int, int> mp;
public:
    LockingTree(vector<int>& parent) {
        nodes = parent;
        // chd.resize(parent.size(), vector<int>());
        // for(int i = 1; i < parent.size(); i++) 
        //     chd[parent[i]].push_back(i);

        vector<vector<int>>temp(parent.size());
        
        for(int i=1;i<parent.size();i++){
            temp[parent[i]].push_back(i);
        }
        
        chd=temp;
            
    }
    
    bool lock(int num, int user) {
        if(mp.find(num)==mp.end()){
            mp[num]=user;
            return true;
        }
        
        return false;;

       //  if(mp.count(num)) return false;
       //  
       //  mp[num] = user;
       //  return true;
    }
    
    bool unlock(int num, int user) {
        if(mp.find(num)!=mp.end()){
            if(mp[num]==user){
                mp.erase(num);
                return true;
            }
            return false;
        }
        return false;        
        // if(!mp[num]) return false;
        // if(mp[num] != user) return false;
        // mp.erase(num);
        // return true;
    }
    
    bool check(int num) {
        // cout<< num << mp[num];        
        if(mp.find(num)!=mp.end()) return true;
        if(mp.count(num)) return true;
        // cout<< num << "-"<< nodes[num];
        if(nodes[num] != -1 && check(nodes[num])) return true;

        return false;
    }

    void desc(int num, int &total) {
        for(int n : chd[num]) {
            if(mp.count(n)) 
            {
                mp.erase(n);
                total++;
            }
            desc(n, total);
        }
    }

    bool upgrade(int num, int user) {
        if(mp.find(num)!=mp.end()) return false;
        
        cout<< "hi";
        if(check(num)) return false;
        cout<< "hi1";
        int total = 0;
        desc(num, total);
        if(total == 0) return false;

        mp[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
{{< /highlight >}}


---
{{< youtube qK4PtjrVD0U >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1994: The Number of Good Subsets](https://grid47.xyz/posts/leetcode_1994) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

