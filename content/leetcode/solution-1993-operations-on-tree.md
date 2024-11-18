
+++
authors = ["grid47"]
title = "Leetcode 1993: Operations on Tree"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1993: Operations on Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Depth-First Search","Breadth-First Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qK4PtjrVD0U"
youtube_upload_date="2021-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/qK4PtjrVD0U/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1993.md" >}}
---
{{< youtube qK4PtjrVD0U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1995: Count Special Quadruplets](https://grid47.xyz/leetcode/solution-1995-count-special-quadruplets/) |
| --- |
