
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

### Problem Statement

The problem involves creating a locking tree data structure that allows for the management of node locking and unlocking operations in a tree. The tree is defined by a parent array where each index represents a node, and the value at that index represents its parent. The locking mechanism includes three main operations:
1. **Lock a Node**: A user can lock a node if it is not already locked.
2. **Unlock a Node**: A user can unlock a node if they are the one who locked it.
3. **Upgrade a Node**: A node can be upgraded if it is not locked and at least one of its descendants is locked. During an upgrade, the node becomes locked, and all locked descendants are unlocked.

The objective is to implement these functionalities efficiently in the `LockingTree` class.

### Approach

To implement the `LockingTree`, we can use the following approach:

1. **Data Structures**:
   - **Parent Array**: To store the parent of each node.
   - **Children List**: A list of vectors to maintain the children of each node for easy traversal.
   - **Map for Locks**: A map that tracks the current user who has locked each node.

2. **Operations**:
   - **Lock**: Check if the node is already locked. If not, lock it by adding it to the map.
   - **Unlock**: Check if the node is locked by the same user. If so, remove it from the map.
   - **Check**: Traverse up the tree to check if any ancestor is locked.
   - **Descendants**: Traverse down the tree to count and unlock all descendants.
   - **Upgrade**: Ensure the node is not locked and check if any descendants are locked. If valid, lock the node and unlock all its locked descendants.

### Code Breakdown (Step by Step)

Here is a detailed explanation of the provided code:

```cpp
class LockingTree {
    vector<int> nodes;
    vector<vector<int>> chd;
    map<int, int> mp; // Map to track locked nodes and their user IDs
```
We define a class `LockingTree` with three member variables: `nodes` to store the parent information, `chd` for the children of each node, and `mp` which maps locked nodes to the users who locked them.

```cpp
public:
    LockingTree(vector<int>& parent) {
        nodes = parent;
        vector<vector<int>>temp(parent.size());
        
        for(int i=1;i<parent.size();i++){
            temp[parent[i]].push_back(i);
        }
        
        chd=temp;
    }
```
The constructor initializes the tree based on the parent array. It creates a children list by iterating through the parent array and adding child nodes to their respective parents.

#### Lock Operation

```cpp
    bool lock(int num, int user) {
        if(mp.find(num)==mp.end()){
            mp[num]=user; // Lock the node for the user
            return true;
        }
        
        return false;
    }
```
The `lock` method checks if the node `num` is already locked. If it is not, it locks the node by inserting it into the map with the user's ID and returns `true`. If it is locked, it returns `false`.

#### Unlock Operation

```cpp
    bool unlock(int num, int user) {
        if(mp.find(num)!=mp.end()){
            if(mp[num]==user){ // Check if the unlocking user matches
                mp.erase(num); // Unlock the node
                return true;
            }
            return false; // User does not match
        }
        return false;        
    }
```
The `unlock` method checks if the node is locked and whether the user unlocking it is the same one who locked it. If both conditions are met, it unlocks the node by removing it from the map and returns `true`. Otherwise, it returns `false`.

#### Check Operation

```cpp
    bool check(int num) {
        if(mp.find(num)!=mp.end()) return true; // Node is locked
        if(nodes[num] != -1 && check(nodes[num])) return true; // Check parent
        return false;
    }
```
The `check` method verifies if a node or any of its ancestors are locked. It returns `true` if it finds a locked ancestor, otherwise `false`.

#### Descendants Traversal

```cpp
    void desc(int num, int &total) {
        for(int n : chd[num]) {
            if(mp.count(n)) {
                mp.erase(n); // Unlock the descendant
                total++;
            }
            desc(n, total); // Recursive call for children
        }
    }
```
The `desc` method is used to count and unlock all locked descendants of a given node. It iterates through the children, unlocking each one and incrementing the total count.

#### Upgrade Operation

```cpp
    bool upgrade(int num, int user) {
        if(mp.find(num)!=mp.end()) return false; // Cannot upgrade if locked
        
        if(check(num)) return false; // Cannot upgrade if an ancestor is locked
        
        int total = 0;
        desc(num, total); // Count locked descendants
        if(total == 0) return false; // No locked descendants to upgrade

        mp[num] = user; // Lock the current node
        return true;
    }
};
```
The `upgrade` method checks if the node is already locked or has locked ancestors. If neither is true, it counts locked descendants using `desc`. If at least one locked descendant is found, it locks the current node and returns `true`; otherwise, it returns `false`.

### Complexity

- **Time Complexity**: 
  - **Lock**: \(O(1)\) – checking and inserting into the map takes constant time.
  - **Unlock**: \(O(1)\) – checking and removing from the map also takes constant time.
  - **Check**: \(O(h)\) where \(h\) is the height of the tree, as it may need to traverse up to the root.
  - **Descendants**: \(O(n)\) in the worst case if all nodes are descendants.
  - **Upgrade**: \(O(n + h)\) due to counting descendants and checking for locked ancestors.

- **Space Complexity**: 
  - The space complexity is \(O(n)\) for storing the tree structure and the lock map.

### Conclusion

The `LockingTree` class efficiently manages locking and unlocking operations in a tree structure. By using a combination of a parent array for structure and a map for tracking locked nodes, the implementation allows for quick operations while maintaining the integrity of the tree. This structure is particularly useful for scenarios where resource locking and hierarchical relationships are important.

### Example Usage

Here’s how you can utilize the `LockingTree` class:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1}; // Example parent array
    LockingTree* tree = new LockingTree(parent);

    cout << tree->lock(2, 1) << endl; // Should return true
    cout << tree->lock(3, 2) << endl; // Should return true
    cout << tree->unlock(2, 1) << endl; // Should return true
    cout << tree->upgrade(0, 3) << endl; // Should return true
    cout << tree->lock(1, 4) << endl; // Should return false (already locked)
    
    delete tree; // Clean up
    return 0;
}
```

This example initializes a `LockingTree`, performs various lock and unlock operations, and demonstrates how the locking mechanism works effectively in a hierarchical structure.

[`Link to LeetCode Lab`](https://leetcode.com/problems/operations-on-tree/description/)

---
{{< youtube qK4PtjrVD0U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
