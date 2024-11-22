
+++
authors = ["grid47"]
title = "Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aoHbYlO8vDg"
youtube_upload_date="2021-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/aoHbYlO8vDg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    string p;
    
    bool pal(string &s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    int dp(int idx, string &s1, string &s2) {
        if(idx == n) {
            if(pal(s1) && pal(s2)) {
                return s1.size() * s2.size();
            }
            return 0;
        }

        s1.push_back(p[idx]);
        int ans = dp(idx + 1, s1, s2);
        s1.pop_back();        
        
        s2.push_back(p[idx]);        
        ans = max(ans, dp(idx + 1, s1, s2));
        s2.pop_back();        
        
        ans = max(ans, dp(idx + 1, s1, s2));
        
        // return mp[idx][s1][s2] = ans;
        return ans;        
    }
    
    
    int maxProduct(string s) {
        p = s;
        n = s.size();
        string s1 = "", s2 = "";
        return dp(0, s1, s2);
    }
};
{{< /highlight >}}
---

### Problem Statement

The challenge is to divide a given string into two non-empty substrings such that both substrings are palindromic, and we want to maximize the product of their lengths. A palindromic string reads the same forwards and backwards, like "radar" or "level." The task is to explore all possible ways to split the string and check for the maximal product of the lengths of two valid palindromic substrings.

### Approach

To tackle this problem, we can use a recursive depth-first search (DFS) approach combined with backtracking. The process involves:

1. **Recursive Functionality**: We will define a recursive function `dp` that takes the current index of the string being processed and two substrings (`s1` and `s2`), which will hold the characters chosen for each partition.

2. **Base Case**: When we reach the end of the string (i.e., `idx == n`), we check if both `s1` and `s2` are palindromic using a helper function. If both substrings are palindromic, we calculate their lengths and return their product. If not, we return 0.

3. **Recursive Exploration**: For each character at the current index, we have three options:
   - Add the character to `s1`.
   - Add the character to `s2`.
   - Skip the character entirely.
   
   We will recursively call `dp` for each of these scenarios, keeping track of the maximum product obtained.

4. **Utilizing Backtracking**: By adding and removing characters from `s1` and `s2`, we ensure we explore all possible partitions of the string.

This method ensures we systematically explore all potential combinations while also checking for the palindromic property efficiently.

### Code Breakdown (Step by Step)

Let’s dissect the code to understand how this approach is implemented:

1. **Class and Member Variables**: We define a class named `Solution` which contains member variables for the length of the string (`n`) and the string itself (`p`).

    ```cpp
    class Solution {
    public:
        int n;
        string p;
    ```

2. **Palindrome Check Function**: The function `pal` checks if a given string is palindromic. It uses two pointers, one starting at the beginning and the other at the end, and moves towards the center, comparing characters.

    ```cpp
    bool pal(string &s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    ```

3. **Recursive Function**: The main recursive function `dp` is defined to explore the string. It takes the current index (`idx`), and the two substrings (`s1` and `s2`) as parameters.

    ```cpp
    int dp(int idx, string &s1, string &s2) {
    ```

4. **Base Case**: If we have processed all characters, we check if both `s1` and `s2` are palindromic. If they are, we return the product of their lengths.

    ```cpp
    if(idx == n) {
        if(pal(s1) && pal(s2)) {
            return s1.size() * s2.size();
        }
        return 0;
    }
    ```

5. **Exploring Substring Choices**: We explore the three possibilities for the current character:
   - Add the character to `s1` and recursively call `dp`.
   - After returning from the first call, we remove the character from `s1` and add it to `s2`, then recursively call `dp`.
   - Finally, we call `dp` again without adding the character to either substring, allowing us to skip it.

    ```cpp
    s1.push_back(p[idx]);
    int ans = dp(idx + 1, s1, s2);
    s1.pop_back();
    
    s2.push_back(p[idx]);
    ans = max(ans, dp(idx + 1, s1, s2));
    s2.pop_back();
    
    ans = max(ans, dp(idx + 1, s1, s2));
    ```

6. **Returning the Result**: The function returns the maximum product of palindromic substring lengths found.

    ```cpp
    return ans;
    ```

7. **Driver Function**: The `maxProduct` function initializes the member variable `p` with the input string and calls the recursive `dp` function starting with index 0 and empty substrings.

    ```cpp
    int maxProduct(string s) {
        p = s;
        n = s.size();
        string s1 = "", s2 = "";
        return dp(0, s1, s2);
    }
    ```

### Complexity

The time complexity of this solution is O(3^n) in the worst case due to the three recursive calls made for each character in the string. This exponential complexity arises because for each character, we have three choices (add to `s1`, add to `s2`, or skip), leading to a significant number of possible combinations. The space complexity is O(n) for the recursion stack, as we could go as deep as the length of the string in our recursive calls.

### Conclusion

In summary, the provided code effectively finds the maximum product of the lengths of two palindromic substrings derived from the input string. Through a systematic exploration of all potential partitions and a diligent check for the palindromic property, the solution highlights a clever use of recursion and backtracking. While the exponential time complexity may pose challenges for very long strings, this method ensures that every possible combination is considered, making it a robust approach to the problem at hand. Overall, this code serves as a prime example of how to leverage recursive techniques to solve complex string manipulation challenges efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/)

---
{{< youtube aoHbYlO8vDg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
