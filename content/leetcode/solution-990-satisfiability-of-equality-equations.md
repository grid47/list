
+++
authors = ["grid47"]
title = "Leetcode 990: Satisfiability of Equality Equations"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 990: Satisfiability of Equality Equations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d3MkgeCo8l4"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/d3MkgeCo8l4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n, 0);
        for(int i = 0; i < n; i++)
            chd[i] = i;
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            chd[i] = j;
            cnt--;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == chd[x]) return x;
        return chd[x] = find(chd[x]);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& eqn) {
        UF* uf = new UF(26);
        for(int i = 0; i < eqn.size(); i++) {
            int a = eqn[i][0] - 'a';
            int b = eqn[i][3] - 'a';
            if(eqn[i][1] == '=')
                uf->uni(a, b);
        }
        for(int i = 0; i < eqn.size(); i++) {
            int a = eqn[i][0] - 'a';
            int b = eqn[i][3] - 'a';
            if(eqn[i][1] == '!')
                if(uf->find(a) == uf->find(b))
                    return false;
        }        
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine if a set of equations involving letters can be satisfied, given certain equality and inequality constraints. The equations involve characters from 'a' to 'z', and the constraints are either equality (denoted as `==`) or inequality (denoted as `!=`). 

You are given an array of strings, each representing an equation. You need to determine whether it is possible to satisfy all of the equations. Specifically, you need to check if it's possible to assign letters such that:
- For every equality equation `a == b`, the characters 'a' and 'b' belong to the same group.
- For every inequality equation `a != b`, the characters 'a' and 'b' belong to different groups.

### Approach

This problem can be efficiently solved using the **Union-Find (Disjoint Set Union, DSU)** data structure, which allows for quick union and find operations. The goal is to use the Union-Find structure to group characters that must be equal and to check for any contradictions with the inequality equations.

#### Key Concepts:
1. **Union-Find Data Structure**: This data structure is used to keep track of a partition of elements into disjoint sets. Each element starts in its own set, and we can perform the following operations:
   - **Find**: Determine which set an element belongs to.
   - **Union**: Merge two sets into one.
   
2. **Path Compression and Union by Rank**: These are optimizations to make the Union-Find operations efficient. Path compression ensures that the tree representing the sets remains flat, and union by rank keeps the smaller set under the larger set during union operations.

#### Plan:
1. **First Pass (Equality Constraints)**:
   - Iterate over the equations. For every equation `a == b`, perform a union operation to group 'a' and 'b' together.
   
2. **Second Pass (Inequality Constraints)**:
   - For every equation `a != b`, check if 'a' and 'b' are in the same set using the find operation. If they are, it means a contradiction is found (since they should be different groups), and we return `false`.

3. If no contradictions are found, return `true` as the equations are satisfiable.

### Code Breakdown (Step by Step)

#### 1. **Union-Find Class (`UF`)**:

```cpp
class UF {
public:
    vector<int> chd;  // Array to store the parent of each node (or representative of the set)
    int cnt;  // The number of disjoint sets

    UF(int n) {
        chd.resize(n, 0);  // Initialize the array with 0
        for(int i = 0; i < n; i++)
            chd[i] = i;  // Each node is its own parent initially
        cnt = n;  // Number of disjoint sets
    }

    bool uni(int x, int y) {
        int i = find(x);  // Find the parent of 'x'
        int j = find(y);  // Find the parent of 'y'
        if(i != j) {
            chd[i] = j;  // Union the two sets by making one root point to the other
            cnt--;  // Decrease the number of disjoint sets
            return true;
        }
        return false;  // Return false if they are already in the same set
    }

    int find(int x) {
        if(x == chd[x]) return x;  // If 'x' is its own parent, return 'x'
        return chd[x] = find(chd[x]);  // Path compression: flatten the tree
    }
};
```

- The **Union-Find** class manages the disjoint sets. The `chd` array stores the parent for each element, and `cnt` keeps track of the number of disjoint sets.
- **`uni(int x, int y)`**: This method connects two elements 'x' and 'y'. If they are in different sets, it merges them and reduces the number of disjoint sets.
- **`find(int x)`**: This method returns the root or representative of the set that contains 'x'. It uses path compression to flatten the tree for more efficient future operations.

#### 2. **Main Logic (Equations Checking)**:

```cpp
class Solution {
public:
    bool equationsPossible(vector<string>& eqn) {
        UF* uf = new UF(26);  // Create a Union-Find data structure for 26 letters
        for(int i = 0; i < eqn.size(); i++) {
            int a = eqn[i][0] - 'a';  // Convert 'a' to 0, 'b' to 1, ..., 'z' to 25
            int b = eqn[i][3] - 'a';  // Same conversion for the second character
            if(eqn[i][1] == '=')
                uf->uni(a, b);  // If the equation is 'a == b', union the two sets
        }
        
        for(int i = 0; i < eqn.size(); i++) {
            int a = eqn[i][0] - 'a';  // Convert the characters to indices again
            int b = eqn[i][3] - 'a';
            if(eqn[i][1] == '!')  // If the equation is 'a != b'
                if(uf->find(a) == uf->find(b))  // If they are in the same set, return false
                    return false;
        }        
        return true;  // If no contradictions were found, return true
    }
};
```

- **Main Logic**:
  - **First Pass (Equality Constraints)**: We loop through all the equations. For each equation `a == b`, we call the `uni()` method to unite the two sets containing 'a' and 'b'.
  - **Second Pass (Inequality Constraints)**: We then loop through all the equations again. For each inequality equation `a != b`, we check if 'a' and 'b' belong to the same set using the `find()` method. If they are in the same set, it implies a contradiction, and we return `false`. If no contradiction is found, the function returns `true`.

### Complexity

#### Time Complexity:
- **Union and Find Operations**: Both union and find operations take **O(α(n))** time, where α is the **inverse Ackermann function** (which grows extremely slowly). For all 26 letters (fixed size), these operations can be considered nearly constant time.
- **Iterating Through Equations**: We process each equation twice, once for equality and once for inequality. Each loop iteration involves performing union or find operations. Thus, the time complexity is **O(E)**, where `E` is the number of equations.
  
Thus, the overall time complexity is **O(E)**.

#### Space Complexity:
- The Union-Find structure uses an array of size 26 to store the parent of each element, leading to a space complexity of **O(26) = O(1)** (since the number of letters is fixed).
- The additional space used for the `UF` object and the input list is **O(E)**.

Thus, the overall space complexity is **O(1)** for the Union-Find structure and **O(E)** for the input.

### Conclusion

This approach efficiently solves the problem using the Union-Find data structure, which is ideal for handling dynamic connectivity problems such as this one. By separating the processing of equality and inequality constraints, we ensure that we can check if the equations can be satisfied in linear time with respect to the number of equations. The space complexity is constant with respect to the size of the input (as the number of letters is fixed), making this solution both time and space efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/satisfiability-of-equality-equations/description/)

---
{{< youtube d3MkgeCo8l4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
