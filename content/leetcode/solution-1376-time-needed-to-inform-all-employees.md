
+++
authors = ["grid47"]
title = "Leetcode 1376: Time Needed to Inform All Employees"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1376: Time Needed to Inform All Employees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d0xAcl58SXg"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/d0xAcl58SXg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> gph;
        for(int i = 0; i < manager.size(); i++)
        gph[manager[i]].push_back(i);
        
        return dfs(headID, gph, informTime);
    }
    
    int dfs(int cur, map<int, vector<int>> &gph, vector<int> &it) {
        if(!gph.count(cur)) return 0;
        
        int mx = 0;
        for(auto x: gph[cur])
            mx = max(mx, dfs(x, gph, it));
        
        return mx + it[cur];
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem requires calculating the total time needed to inform all employees in a company structured as a tree. In this scenario, we have `n` employees, with one employee designated as the head of the organization. Each employee can have a manager, and the time taken for each employee to inform their subordinates is given. The goal is to determine how long it will take for the head of the company to inform all employees, starting from their initial notification.

### Approach

To solve this problem, we can model the organizational structure as a directed graph (or tree) where each employee points to their subordinates. This can be efficiently represented using an adjacency list. The strategy involves the following steps:

1. **Graph Construction**: Create an adjacency list representation of the employee-manager relationships. Each manager will have a list of their direct reports.

2. **Depth-First Search (DFS)**: Implement a DFS traversal to compute the total time taken to inform all employees. Starting from the head of the organization, we will traverse the tree, calculating the time for each employee based on the time taken by their manager and the time they themselves take to inform their subordinates.

3. **Base Case for DFS**: When an employee has no subordinates (i.e., they are leaf nodes in the tree), the time taken to inform them is zero. Thus, we can return zero for such cases.

4. **Recursive Time Calculation**: For each employee, we will calculate the maximum time taken to inform their subordinates and add the time it takes for them to inform their direct reports.

### Code Breakdown (Step by Step)

The provided C++ code implements this approach effectively. Here’s a detailed breakdown of how it works:

1. **Solution Class**: The `Solution` class contains the main method `numOfMinutes` and a helper method `dfs`.

2. **numOfMinutes Method**:
   - **Parameters**: This method takes in the number of employees `n`, the head's ID `headID`, a vector `manager` indicating each employee's manager, and a vector `informTime` that contains the time taken by each employee to inform their direct reports.
   - **Graph Construction**: The method initializes a map `gph` where each manager ID maps to a vector of their direct reports (subordinates). It iterates through the `manager` vector, populating the graph.
   - **DFS Invocation**: It then calls the `dfs` function starting from the `headID` to compute the total time needed to inform all employees.

3. **dfs Method**:
   - **Parameters**: The `dfs(int cur, map<int, vector<int>> &gph, vector<int> &it)` function takes the current employee ID `cur`, the graph representation `gph`, and the vector `it` containing the informing times.
   - **Base Case**: If the current employee (`cur`) has no subordinates (not present in the graph), the function returns `0`, as there are no further employees to inform.
   - **Time Calculation**: The method initializes a variable `mx` to track the maximum time taken to inform all subordinates. It iterates over the list of direct reports for the current employee, calling `dfs` recursively for each subordinate and updating `mx` with the maximum value returned from the subordinates.
   - **Return Value**: Finally, it returns the maximum time taken to inform all subordinates plus the informing time of the current employee (`it[cur]`).

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(N)\), where \(N\) is the number of employees. Each employee is processed once during the DFS traversal, leading to linear time complexity.

- **Space Complexity**: The space complexity is also \(O(N)\) due to the storage used for the graph representation and the recursion stack. In the worst case, the recursion can go as deep as the number of employees in a skewed tree structure.

### Conclusion

The solution effectively calculates the total time required for the head of the organization to inform all employees by utilizing a tree structure to model the employee-manager relationships. By implementing depth-first search (DFS) to traverse this tree, we can efficiently compute the time taken based on each employee’s informing time and their direct reports. This approach is optimal for this problem and can be extended to similar scenarios involving hierarchical structures. The solution is not only efficient but also clear and maintainable, making it a useful reference for developers and computer science students working with tree and graph data structures in algorithmic challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/time-needed-to-inform-all-employees/description/)

---
{{< youtube d0xAcl58SXg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
