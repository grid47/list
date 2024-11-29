
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
comments = true
+++



---
In a kingdom, there is a well-defined hierarchy of inheritance, starting with the king. The inheritance order depends on the family's birth and death events. Implement a class to keep track of the order, excluding the dead members.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of commands and their arguments representing actions like initializing the kingdom, adding a new child, marking someone deceased, or getting the inheritance order.
- **Example:** `["king", "andy"]`
- **Constraints:**
	- 1 <= kingName.length, parentName.length, childName.length, name.length <= 15
	- All name arguments consist of lowercase English letters only.
	- At most 105 calls will be made to birth and death.
	- At most 10 calls will be made to getInheritanceOrder.

{{< dots >}}
### Output Specifications 📤
- **Output:** The result of each getInheritanceOrder call is a list of members currently alive in the inheritance order, excluding any deceased individuals.
- **Example:** `["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]`
- **Constraints:**
	- The list should exclude dead members and maintain the birth order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To maintain an efficient way of getting the current inheritance order and adjusting it based on births and deaths.

- Initialize the king as the root of the inheritance tree.
- Use a family tree to represent the relationships between parents and children.
- For each birth, add a child to the parent's list.
- For each death, mark the person as deceased.
- For each getInheritanceOrder call, traverse the family tree and return the order of alive members.
{{< dots >}}
### Problem Assumptions ✅
- Each birth event adds a new member, and each death event removes one from the inheritance order.
{{< dots >}}
## Examples 🧩
- **Input:** `["king", "andy"]`  \
  **Explanation:** After initializing with the king, Andy is born and added to the inheritance order.

{{< dots >}}
## Approach 🚀
To implement the ThroneInheritance class, we need to maintain a tree structure for the family and track the alive status of each member.

### Initial Thoughts 💭
- We need to efficiently manage births, deaths, and inheritance order retrieval.
- We can use a hashmap to represent the family tree and a set to track dead members.
{{< dots >}}
### Edge Cases 🌐
- If no birth events are called, the inheritance order will only contain the king.
- The solution should efficiently handle up to 105 birth and death events.
- Ensure that deaths are handled without affecting the family tree structure.
- Make sure to handle all edge cases like multiple deaths in a row or no births.
{{< dots >}}
## Code 💻
```cpp
unordered_map<string, vector<string>> family;  
string root;
public:
ThroneInheritance(string kingName) {
    root = kingName;
}

void birth(string parentName, string childName) {
    family[parentName].push_back(childName);    // Appending at the end takes care of oldest to youngest 
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
```

This class defines the 'ThroneInheritance' system where the royal family tree is represented by a map of parent-child relationships, and a method tracks the inheritance order considering deaths in the family.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	unordered_map<string, vector<string>> family;  
	```
	This initializes a 'family' map that associates a string (parent name) with a list of child names (vector of strings). This structure is used to represent the family tree.

2. **Variable Initialization**
	```cpp
	string root;
	```
	This initializes the 'root' variable as a string, which holds the name of the king (the root of the family tree).

3. **Access Control**
	```cpp
	public:
	```
	This indicates the beginning of the public section of the class, where methods are accessible from outside the class.

4. **Constructor**
	```cpp
	ThroneInheritance(string kingName) {
	```
	This is the constructor of the 'ThroneInheritance' class, which initializes the root of the family tree (the king) with the given 'kingName'.

5. **Constructor**
	```cpp
	    root = kingName;
	```
	This assigns the 'kingName' to the 'root' variable, setting the initial king of the family tree.

6. **Method Definition**
	```cpp
	void birth(string parentName, string childName) {
	```
	This method is called when a new child is born, and it adds the child to the list of children under the given parent.

7. **Method Logic**
	```cpp
	    family[parentName].push_back(childName);    // Appending at the end takes care of oldest to youngest 
	```
	This line adds the 'childName' to the list of children of the specified 'parentName'. The comment explains that the children are stored in order of birth, with the oldest child added first.

8. **Method Definition**
	```cpp
	void death(string name) {
	```
	This method marks a family member as deceased by setting their status in the 'dead' map.

9. **Method Logic**
	```cpp
	    dead[name] = true;
	```
	This line updates the 'dead' map to mark the person with the name 'name' as deceased.

10. **Method Definition**
	```cpp
	void dfs(vector<string> &ans, string root) {
	```
	This method performs a depth-first search (DFS) to recursively traverse the family tree and collect the names of family members in the inheritance order.

11. **Method Logic**
	```cpp
	    if (!dead[root]) {           // Just check if dead before inserting into the order.
	```
	This checks whether the person is dead before adding them to the inheritance order. If they are not dead, their name is added to the list.

12. **Method Logic**
	```cpp
	        ans.push_back(root);
	```
	If the person is not dead, their name ('root') is added to the 'ans' vector, which stores the inheritance order.

13. **Method Logic**
	```cpp
	    for (string child: family[root]) {
	```
	This loops through all children of the current 'root' in the family tree, and recursively calls the 'dfs' method to process each child.

14. **Recursive Call**
	```cpp
	        dfs(ans, child);
	```
	This makes a recursive call to the 'dfs' method for each child, ensuring the inheritance order is traversed.

15. **Method Definition**
	```cpp
	vector<string> getInheritanceOrder() {
	```
	This method returns a vector of strings that contains the inheritance order by calling the 'dfs' method.

16. **Method Logic**
	```cpp
	    vector<string> ans;
	```
	This initializes a vector 'ans' to hold the final inheritance order.

17. **Method Logic**
	```cpp
	    dfs(ans, root);
	```
	This calls the 'dfs' method to populate the 'ans' vector with the inheritance order starting from the 'root' (king).

18. **Method Logic**
	```cpp
	    return ans;
	```
	This returns the populated 'ans' vector containing the inheritance order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The worst-case time complexity for getInheritanceOrder is O(n), where n is the number of family members.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the family tree and dead members.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/throne-inheritance/description/)

---
{{< youtube VId-YNg9IG0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
