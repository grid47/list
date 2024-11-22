
+++
authors = ["grid47"]
title = "Leetcode 97: Interleaving String"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 97: Interleaving String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/97.webp"
youtube = "3Rw3p9LrgvE"
youtube_upload_date="2021-06-22"
youtube_thumbnail="https://i.ytimg.com/vi/3Rw3p9LrgvE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/97.webp" 
    alt="Two glowing strings weaving together in an intricate, peaceful interleaving pattern."
    caption="Solution to LeetCode 97: Interleaving String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s1, s2, s3;
    vector<vector<int>> memo;
    bool dp(int i, int j) {
        if(i == s1.size() && j == s2.size()) return true;

        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        int k = i + j;
        if(i < s1.size() && s1[i] == s3[k])
            ans |= dp(i + 1, j);
        
        if(j < s2.size() && s2[j] == s3[k])
            ans |= dp(i, j + 1);
        
        return memo[i][j] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if(s1.size() + s2.size() != s3.size()) return false;
        memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}
---

Here’s a beautified version of your explanation with improved formatting and a more structured flow:

---

### 💡 **Interleaving String Problem** – Let’s Solve It Together!

The **Interleaving String** problem asks whether a given string `s3` can be formed by the interleaving of two strings `s1` and `s2`. The challenge is to determine if `s3` can be created by alternating characters from `s1` and `s2` while maintaining the relative order of characters from each string.

#### **Example:**
- **Input:**  
  `s1 = "abc"`,  
  `s2 = "def"`,  
  `s3 = "adbcef"`  
  **Output:** `true`  
  **Explanation:** `s3` can be formed by interleaving `s1` and `s2` while maintaining the order.

- **Input:**  
  `s3 = "abdecf"`  
  **Output:** `false`  
  **Explanation:** The order of characters in `s1` and `s2` is violated, making `s3` not a valid interleaving.

---

### 📝 **Problem Breakdown**

You are given:
- **String `s1`**: The first string.
- **String `s2`**: The second string.
- **String `s3`**: The target string that might be formed by interleaving `s1` and `s2`.

The goal is to **return true** if `s3` can be formed by interleaving `s1` and `s2` while maintaining their relative order.

---

### 🔍 **Approach: Dynamic Programming**

We’ll solve this problem using **dynamic programming (DP)**. The idea is to break down the problem into smaller subproblems and store intermediate results to avoid redundant computations.

#### **Steps:**

1. **Base Case Check**:  
   If the sum of the lengths of `s1` and `s2` doesn't match the length of `s3`, return `false`. If the lengths don’t match, `s3` can’t be an interleaving of `s1` and `s2`.

2. **Memoization**:  
   Use a 2D table `memo` to store the results of subproblems. `memo[i][j]` will indicate whether the first `i` characters of `s1` and the first `j` characters of `s2` can form the first `i + j` characters of `s3`.

3. **Recursive Function**:  
   Define a function `dp(i, j)` to check whether the substring `s3[i + j:]` can be formed by interleaving the substrings `s1[i:]` and `s2[j:]`.

4. **Final Check**:  
   The recursion starts at `dp(0, 0)`, and the result will be stored in `memo[0][0]` after evaluating all possibilities.

---

### 🧑‍💻 **Code Implementation**

Here’s how we can implement the solution in C++:

```cpp
class Solution {
public:
    string s1, s2, s3;
    vector<vector<int>> memo;

    bool dp(int i, int j) {
        // Base case: both strings are exhausted
        if (i == s1.size() && j == s2.size()) return true;
        
        // Check if the result is already memoized
        if (memo[i][j] != -1) return memo[i][j];
        
        int ans = 0;
        int k = i + j;  // Current index in s3
        
        // Check if the character in s1 matches the current character in s3
        if (i < s1.size() && s1[i] == s3[k])
            ans |= dp(i + 1, j);
        
        // Check if the character in s2 matches the current character in s3
        if (j < s2.size() && s2[j] == s3[k])
            ans |= dp(i, j + 1);
        
        // Memoize the result
        return memo[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        
        // Base case: If lengths don't match, return false
        if (s1.size() + s2.size() != s3.size()) return false;
        
        // Initialize memo table with -1 (indicating uncomputed values)
        memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        
        // Start the recursion from the beginning of both strings
        return dp(0, 0);
    }
};
```

---

### 🌟 **Key Concepts:**

1. **Memoization**:  
   By storing the results of previously computed subproblems in the `memo` table, we avoid recalculating the same results multiple times, leading to an optimized solution.

2. **Recursive Approach**:  
   We break down the problem into smaller subproblems by considering each character of `s1`, `s2`, and `s3` and deciding whether to move forward in `s1` or `s2` based on matches.

3. **Time Complexity**:  
   The time complexity of the solution is **O(m * n)**, where `m` is the length of `s1` and `n` is the length of `s2`. This is because we solve each subproblem once, and the total number of subproblems is proportional to the product of the lengths of `s1` and `s2`.

4. **Space Complexity**:  
   The space complexity is **O(m * n)** due to the `memo` table used to store the results of the subproblems.

---

### 💡 **Why This Approach Works Well:**

This dynamic programming solution efficiently checks if a string `s3` can be formed by interleaving two strings `s1` and `s2`. The memoization ensures that we don’t redo calculations for the same subproblems, making the algorithm highly efficient. The time and space complexities of **O(m * n)** are optimal for this problem.

---

### 🏁 **Final Thoughts**: Keep Coding, Keep Growing!

By tackling this problem using dynamic programming, you not only learned how to solve a complex interleaving problem, but also reinforced key concepts like recursion, memoization, and optimal problem-solving techniques. Keep coding, and with each challenge, you'll become a more proficient developer! 💪✨

Happy coding!

[`Link to LeetCode Lab`](https://leetcode.com/problems/interleaving-string/description/)

---
{{< youtube 3Rw3p9LrgvE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
