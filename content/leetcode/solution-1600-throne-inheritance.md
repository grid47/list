
+++
authors = ["grid47"]
title = "Leetcode 1600: Throne Inheritance"
date = "2024-05-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1600: Throne Inheritance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VId-YNg9IG0"
youtube_upload_date="2020-09-27"
youtube_thumbnail="https://i.ytimg.com/vi/VId-YNg9IG0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class ThroneInheritance {
    unordered_map<string, bool> dead;   // Just to keep track of alive people
    unordered_map<string, vector<string>> family;  
    string root;
public:
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);    // Appending at the end takes care of oldest to yongest 
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    void dfs(vector<string> &ans, string root) {
        if (!dead[root]) {           // Just check if dead before inserting into the order.
            ans.push_back(root);
        }
        for (string child: family[root]) {
            dfs(ans, child);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, root);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires implementing a system to manage a royal family tree, where each member can have children and can also "die." The system should allow tracking the inheritance order based on who is alive at any given time. The primary functionalities include:
1. Adding a child to a parent.
2. Marking a family member as dead.
3. Retrieving the order of inheritance based on living family members.

### Approach

To achieve the functionalities described in the problem statement, we will implement a `ThroneInheritance` class with the following key components:

1. **Data Structures**: 
   - A `unordered_map` to track whether a family member is alive or dead.
   - A second `unordered_map` to represent the family tree structure, where each member maps to a list of their children.
   - A string to denote the root of the family tree, which represents the king.

2. **Member Functions**:
   - **Constructor**: Initializes the root member (king) of the family.
   - **Birth Function**: Adds a child to the specified parent.
   - **Death Function**: Marks a member as deceased.
   - **DFS (Depth First Search)**: A helper function to traverse the family tree and construct the inheritance order based on living members.
   - **Get Inheritance Order**: Returns the list of living members in the correct inheritance order.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code:

```cpp
class ThroneInheritance {
    unordered_map<string, bool> dead;   // Just to keep track of alive people
    unordered_map<string, vector<string>> family;  
    string root;
public:
```
- **Class Definition**: We define the `ThroneInheritance` class. Inside this class, we declare two `unordered_map`s: `dead` for tracking if a member is dead, and `family` for storing the family structure as a tree. We also have a string variable `root` that stores the king's name.

```cpp
    ThroneInheritance(string kingName) {
        root = kingName;
    }
```
- **Constructor**: This constructor initializes the `root` with the name of the king when an instance of `ThroneInheritance` is created.

```cpp
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);    // Appending at the end takes care of oldest to youngest 
    }
```
- **Birth Function**: The `birth` method takes a `parentName` and a `childName`, adding the child to the parent's list of children in the `family` map. This ensures that the oldest child is always listed before the younger ones.

```cpp
    void death(string name) {
        dead[name] = true;
    }
```
- **Death Function**: The `death` method marks a family member as dead by setting their entry in the `dead` map to `true`.

```cpp
    void dfs(vector<string> &ans, string root) {
        if (!dead[root]) {           // Just check if dead before inserting into the order.
            ans.push_back(root);
        }
        for (string child: family[root]) {
            dfs(ans, child);
        }
    }
```
- **DFS Function**: This recursive function performs a depth-first search starting from the given `root` member. It checks if the member is alive (not dead) before adding them to the result list `ans`. It then recursively visits all children of the current member.

```cpp
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, root);
        return ans;
    }
};
```
- **Get Inheritance Order Function**: The `getInheritanceOrder` method initializes a vector to hold the result and calls the `dfs` function starting from the `root` (the king). It then returns the ordered list of living members.

### Complexity

- **Time Complexity**: 
  - The time complexity for the `birth` and `death` methods is \(O(1)\) since they involve simple map operations.
  - The `getInheritanceOrder` method involves a depth-first traversal of the family tree, which takes \(O(n)\), where \(n\) is the total number of family members.

- **Space Complexity**: 
  - The space complexity is also \(O(n)\) for storing the family tree and tracking dead members, as well as for the recursion stack in the DFS function.

### Conclusion

The `ThroneInheritance` class effectively models the family tree structure required for tracking inheritance. The key features of this implementation include:

1. **Dynamic Family Structure**: Members can be added or marked as dead dynamically, reflecting changes in the family tree as they occur.
  
2. **Efficient Retrieval**: The inheritance order can be quickly retrieved using a depth-first search, ensuring that only living members are listed in the correct order.

3. **Scalability**: The use of `unordered_map`s provides average-case constant time complexity for insertions and lookups, allowing the system to efficiently handle large family trees.

In summary, the `ThroneInheritance` implementation is a robust solution for simulating a royal family’s inheritance order based on the given requirements. It is both efficient and straightforward, ensuring easy maintenance and usability for future extensions or modifications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/throne-inheritance/description/)

---
{{< youtube VId-YNg9IG0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
