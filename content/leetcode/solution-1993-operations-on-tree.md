
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
comments = true
+++



---
You are given a tree with `n` nodes numbered from `0` to `n - 1` represented by a `parent` array. You need to implement the `LockingTree` class with methods for locking, unlocking, and upgrading nodes in the tree based on certain conditions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following operations in order: initialization of the tree with the `parent` array, followed by the `lock`, `unlock`, and `upgrade` operations.
- **Example:** `[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]`
- **Constraints:**
	- 2 <= n <= 2000
	- 0 <= num <= n - 1
	- 1 <= user <= 104
	- parent[0] == -1
	- At most 2000 calls in total will be made.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output for each operation is a boolean indicating whether the operation was successful or not.
- **Example:** `[null, true, false, true, true, true, false]`
- **Constraints:**
	- The return value should be `null` for the initialization of the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement the methods to manage the locking, unlocking, and upgrading of tree nodes based on the conditions provided.

- 1. Initialize the tree using the `parent` array.
- 2. Implement the `lock`, `unlock`, and `upgrade` methods to modify the locking state of nodes.
{{< dots >}}
### Problem Assumptions ✅
- The input tree structure is valid and represents a tree with no cycles.
{{< dots >}}
## Examples 🧩
- **Input:** `[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]`  \
  **Explanation:** This sequence of operations first initializes the tree, then locks and unlocks nodes as per the conditions, with an upgrade operation successfully locking node 0.

{{< dots >}}
## Approach 🚀
The approach involves implementing a class with the methods for locking, unlocking, and upgrading nodes. Each operation checks the conditions before performing the action.

### Initial Thoughts 💭
- Each node can be locked or unlocked by different users.
- The upgrade operation is a combination of locking a node and unlocking its descendants.
- The challenge lies in efficiently checking the conditions for each operation.
{{< dots >}}
### Edge Cases 🌐
- If there are no nodes in the tree, the operations should handle the empty state.
- With `n` up to 2000, ensure the solution can handle large trees efficiently.
- Handle cases where the root node is involved in locking or upgrading.
- Ensure that operations respect the constraints regarding locked nodes and ancestors.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> chd;
map<int, int> mp;
public:
LockingTree(vector<int>& parent) {
    nodes = parent;
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
    return false;
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
}

bool check(int num) {
    if(mp.find(num)!=mp.end()) return true;
    if(mp.count(num)) return true;
    if(nodes[num] != -1 && check(nodes[num])) return true;
    return false;
}

void desc(int num, int &total) {
    for(int n : chd[num]) {
        if(mp.count(n)) {
            mp.erase(n);
            total++;
        }
        desc(n, total);
    }
}

bool upgrade(int num, int user) {
    if(mp.find(num)!=mp.end()) return false;
    if(check(num)) return false;
    int total = 0;
    desc(num, total);
    if(total == 0) return false;
    mp[num] = user;
    return true;
}
```

This is the implementation of a LockingTree data structure, which supports three main operations: lock, unlock, and upgrade. It uses a map to store the locks and a tree structure to check conditions for upgrades.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<int>> chd;
	```
	This initializes a 2D vector to store the child nodes for each node in the tree.

2. **Variable Initialization**
	```cpp
	map<int, int> mp;
	```
	This initializes a map to store the locked nodes, where the key is the node number and the value is the user who locked it.

3. **Constructor Definition**
	```cpp
	public:
	```
	This marks the beginning of the public section of the class, where the main functions are defined.

4. **Constructor Initialization**
	```cpp
	LockingTree(vector<int>& parent) {
	```
	The constructor that initializes the LockingTree object using the parent vector to define the tree structure.

5. **Constructor Logic**
	```cpp
	    nodes = parent;
	```
	Assigns the provided parent vector to the nodes vector, representing the parent of each node.

6. **Tree Construction**
	```cpp
	    vector<vector<int>>temp(parent.size());
	```
	Creates a temporary 2D vector to store the child nodes of each node.

7. **Tree Construction**
	```cpp
	    for(int i=1;i<parent.size();i++){
	```
	Starts a loop to iterate through each node in the parent array.

8. **Tree Construction**
	```cpp
	        temp[parent[i]].push_back(i);
	```
	Adds the current node as a child of its parent in the temporary vector.

9. **Tree Assignment**
	```cpp
	    chd=temp;
	```
	Assigns the constructed tree (temporary vector) to the chd variable.

10. **Lock Function**
	```cpp
	bool lock(int num, int user) {
	```
	Defines the lock function to lock a node if it's not already locked.

11. **Lock Logic**
	```cpp
	    if(mp.find(num)==mp.end()){
	```
	Checks if the node is not already locked by any user.

12. **Lock Logic**
	```cpp
	        mp[num]=user;
	```
	Locks the node by associating it with the user.

13. **Lock Success**
	```cpp
	        return true;
	```
	Returns true if the node was successfully locked.

14. **Lock Failure**
	```cpp
	    return false;;
	```
	Returns false if the node is already locked.

15. **Unlock Function**
	```cpp
	bool unlock(int num, int user) {
	```
	Defines the unlock function to unlock a node if it is locked by the user.

16. **Unlock Check**
	```cpp
	    if(mp.find(num)!=mp.end()){
	```
	Checks if the node is locked.

17. **Unlock Check**
	```cpp
	        if(mp[num]==user){
	```
	Checks if the user is the one who locked the node.

18. **Unlock Success**
	```cpp
	            mp.erase(num);
	```
	Removes the lock from the node.

19. **Unlock Success**
	```cpp
	            return true;
	```
	Returns true if the node was successfully unlocked.

20. **Unlock Failure**
	```cpp
	        }
	```
	Ends the if block for checking if the user is the one who locked the node.

21. **Unlock Failure**
	```cpp
	        return false;
	```
	Returns false if the node is locked by another user.

22. **Unlock End**
	```cpp
	    return false;
	```
	Returns false if the node is not locked.

23. **Check Function**
	```cpp
	bool check(int num) {
	```
	Defines the check function to verify if a node is locked.

24. **Check Logic**
	```cpp
	    if(mp.find(num)!=mp.end()) return true;
	```
	Returns true if the node is locked.

25. **Check Logic**
	```cpp
	    if(mp.count(num)) return true;
	```
	Checks if the node is locked by any user.

26. **Check Logic**
	```cpp
	    if(nodes[num] != -1 && check(nodes[num])) return true;
	```
	Checks recursively if any parent node is locked.

27. **Check Failure**
	```cpp
	    return false;
	```
	Returns false if the node or any parent node is not locked.

28. **Desc Function**
	```cpp
	void desc(int num, int &total) {
	```
	Defines a recursive function to descend through the tree and count unlocked nodes.

29. **Desc Logic**
	```cpp
	    for(int n : chd[num]) {
	```
	Iterates over all child nodes.

30. **Desc Logic**
	```cpp
	        if(mp.count(n)) {
	```
	Checks if the current child node is locked.

31. **Desc Logic**
	```cpp
	            mp.erase(n);
	```
	Removes the lock from the child node.

32. **Desc Logic**
	```cpp
	            total++;
	```
	Increments the total count of unlocked nodes.

33. **Desc Recursion**
	```cpp
	        }
	        desc(n, total);
	```
	Recursively calls desc function for each child node.

34. **Upgrade Function**
	```cpp
	bool upgrade(int num, int user) {
	```
	Defines the upgrade function to lock a node if its conditions are met.

35. **Upgrade Failure**
	```cpp
	    if(mp.find(num)!=mp.end()) return false;
	```
	Checks if the node is already locked.

36. **Upgrade Failure**
	```cpp
	    if(check(num)) return false;
	```
	Checks if any parent of the node is locked.

37. **Upgrade Success**
	```cpp
	    int total = 0;
	```
	Initializes a counter to track the number of child nodes unlocked.

38. **Upgrade Success**
	```cpp
	    desc(num, total);
	```
	Calls the desc function to count unlocked nodes in the tree.

39. **Upgrade Success**
	```cpp
	    if(total == 0) return false;
	```
	Checks if no nodes were unlocked.

40. **Upgrade Success**
	```cpp
	    mp[num] = user;
	```
	Locks the node and assigns the user to it.

41. **Upgrade End**
	```cpp
	    return true;
	```
	Returns true if the node was successfully upgraded.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for simple lock/unlock operations.
- **Average Case:** O(n) for checking descendants in upgrade operations.
- **Worst Case:** O(n) for operations involving the entire tree.

The time complexity is influenced by the need to check multiple nodes, especially for the upgrade operation.

### Space Complexity 💾
- **Best Case:** O(1) for small trees with minimal operations.
- **Worst Case:** O(n) for storing locked nodes and their users.

Space complexity is determined by the number of locked nodes and the tree structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/operations-on-tree/description/)

---
{{< youtube qK4PtjrVD0U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
