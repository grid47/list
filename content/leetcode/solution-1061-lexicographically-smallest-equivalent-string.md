
+++
authors = ["grid47"]
title = "Leetcode 1061: Lexicographically Smallest Equivalent String"
date = "2024-07-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1061: Lexicographically Smallest Equivalent String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YQ-q0oydRl4"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/YQ-q0oydRl4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> par;
    
    UF(int n) {
        par.resize(n, 0);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            if(i < j)   par[j] = i;
            else        par[i] = j;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
};


class Solution {
public:

    int cnv(char x) {
        return x - 'a';
    }

    string smallestEquivalentString(string s1, string s2, string base) {
        
        int n = s1.size();
        UF* uf = new UF(26);
        
        for(int i = 0; i < n; i++) {
            uf->uni(cnv(s1[i]), cnv(s2[i]));
            uf->uni(cnv(s2[i]), cnv(s1[i]));            
        }
        
        string res = "";
        for(int i = 0; i < base.size(); i++) {
            res += uf->find(cnv(base[i])) + 'a';
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
Given two strings `s1` and `s2`, where each character in `s1` is equivalent to the character at the same position in `s2`, and a third string `base`, the goal is to convert the `base` string into the lexicographically smallest equivalent string using the equivalence relations defined by `s1` and `s2`.

### Approach
The solution employs the Union-Find data structure to group equivalent characters. The process can be summarized in the following steps:
1. **Union-Find Initialization**: Create a Union-Find structure to manage the equivalence classes of characters.
2. **Union Operation**: For each pair of characters in `s1` and `s2`, perform union operations to establish the equivalences.
3. **Find Smallest Equivalent**: Traverse the `base` string and replace each character with its smallest equivalent character by using the union-find structure to find the root representative.

### Code Breakdown (Step by Step)

1. **Union-Find Class Definition**:
   The `UF` class represents the union-find structure, which maintains a list of parents for each character.
   
   ```cpp
   class UF {
   public:
       vector<int> par;
       
       UF(int n) {
           par.resize(n, 0);
           for(int i = 0; i < n; i++)
               par[i] = i;
       }
   ```

   - The constructor initializes the `par` array, where each character initially points to itself.

2. **Union Operation**:
   The `uni` function connects two characters by linking their roots.

   ```cpp
   bool uni(int x, int y) {
       int i = find(x);
       int j = find(y);
       if(i != j) {
           if(i < j)   par[j] = i;
           else        par[i] = j;
           return true;
       } else return false;
   }
   ```

   - It checks the root of both characters. If they are different, it unions them based on their root values to keep the structure balanced.

3. **Find Operation**:
   The `find` function retrieves the root representative for a character.

   ```cpp
   int find(int x) {
       if(x == par[x]) return x;
       return par[x] = find(par[x]);
   }
   ```

   - It uses path compression to flatten the structure, ensuring efficient future queries.

4. **Solution Class Implementation**:
   The `Solution` class contains the method to generate the smallest equivalent string.

   ```cpp
   class Solution {
   public:
       int cnv(char x) {
           return x - 'a'; // Convert character to an index
       }
   ```

   - The `cnv` function maps a character to its corresponding index (0 for 'a', 1 for 'b', etc.).

5. **Processing Input Strings**:
   The `smallestEquivalentString` function processes the input strings `s1` and `s2`.

   ```cpp
   string smallestEquivalentString(string s1, string s2, string base) {
       int n = s1.size();
       UF* uf = new UF(26); // Create a Union-Find for 26 letters
       
       for(int i = 0; i < n; i++) {
           uf->uni(cnv(s1[i]), cnv(s2[i]));
           uf->uni(cnv(s2[i]), cnv(s1[i]));            
       }
   ```

   - It iterates through the pairs of characters in `s1` and `s2`, applying the union operation to link them together.

6. **Building the Result**:
   After establishing the equivalences, the function constructs the result string.

   ```cpp
   string res = "";
   for(int i = 0; i < base.size(); i++) {
       res += uf->find(cnv(base[i])) + 'a';
   }
   return res;
   ```

   - For each character in `base`, it finds its root and appends the corresponding smallest character to the result string.

### Complexity Analysis
- **Time Complexity**: The time complexity is \(O(n \cdot \alpha(m))\), where \(n\) is the length of the strings and \(m\) is the number of characters (26 for lowercase letters). The \(\alpha\) function is the inverse Ackermann function, which grows very slowly and can be considered nearly constant for practical purposes.
  
- **Space Complexity**: The space complexity is \(O(1)\) for the fixed size of the Union-Find structure (26 characters). The additional space used for the result string is \(O(m)\), where \(m\) is the length of the `base` string.

### Conclusion
The provided solution effectively addresses the problem of finding the smallest equivalent string using a union-find data structure. By establishing equivalence classes and efficiently managing them, the approach allows for quick lookups and results in a lexicographically minimal output.

This method is particularly valuable in problems involving character substitutions, equivalence relationships, or connectivity issues. The union-find technique demonstrates its power in handling such equivalences efficiently, showcasing the effectiveness of data structures in algorithm design.

In summary, this implementation not only solves the problem at hand but also exemplifies best practices in using union-find for managing relationships between elements in a structured way.


[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/)

---
{{< youtube YQ-q0oydRl4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
