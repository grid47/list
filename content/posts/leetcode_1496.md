
+++
authors = ["Yasir"]
title = "Leetcode 1496: Path Crossing"
date = "2020-09-23"
description = "Solution to Leetcode 1496"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-crossing/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0,y=0;
        set<pair<int,int>>s;
        s.insert({0,0});
        for(char p: path){
            if(p == 'N') y++;
            else if(p == 'S')y--;
            else if(p == 'E') x++;
            else x--;
            
            if(s.find({x,y}) != s.end()) return true;
            else s.insert({x,y});
        }
        return false;
    }
};
{{< /highlight >}}

