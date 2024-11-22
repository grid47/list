
+++
authors = ["grid47"]
title = "Leetcode 1653: Minimum Deletions to Make String Balanced"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1653: Minimum Deletions to Make String Balanced in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WDStNufBUQ8"
youtube_upload_date="2024-07-30"
youtube_thumbnail="https://i.ytimg.com/vi/WDStNufBUQ8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bcnt = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            char a = s[i];
            if(a == 'a') {                
                dp[i + 1] = min(dp[i] + 1, bcnt);
            } else {
                bcnt++;
                dp[i + 1] = dp[i];
            }
        }
        return dp[n];
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves determining the minimum number of deletions required to ensure that all characters in a given string `s` are of the same type, specifically the character 'a'. In the string, each character is either 'a' or 'b'. The goal is to compute the minimum deletions necessary to convert the string into one consisting entirely of 'a's. 

### Approach

To solve this problem, we can utilize a dynamic programming approach. The idea is to maintain a dynamic programming array `dp`, where `dp[i]` represents the minimum number of deletions required to make the substring `s[0:i]` consist only of 'a's. Additionally, we track the count of 'b's encountered so far with a variable `bcnt`.

The main steps of the approach are as follows:

1. **Initialize Variables**:
   - `n` to store the length of the string.
   - `bcnt` to keep track of the number of 'b's encountered so far.
   - A dynamic programming array `dp` initialized with zeros to store intermediate results.

2. **Iterate Through the String**:
   - For each character in the string, update the `dp` array based on whether the character is 'a' or 'b':
     - If the character is 'a', it can either be counted as a deletion (incrementing `dp[i]`) or we can keep the current count of 'b's.
     - If the character is 'b', we increment the `bcnt` and carry forward the previous deletion count.

3. **Return the Result**:
   - The value at `dp[n]` will provide the minimum number of deletions needed to convert the entire string into 'a's.

### Code Breakdown (Step by Step)

Let's break down the provided code:

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
```
- We define a class `Solution` and a public method `minimumDeletions` that takes a string `s` as input.

```cpp
        int n = s.size(), bcnt = 0;
        vector<int> dp(n + 1, 0);
```
- We compute the length of the string `s` and initialize `bcnt` to zero. The dynamic programming array `dp` is created with a size of `n + 1`, initialized to zeros.

```cpp
        for(int i = 0; i < n; i++) {
            char a = s[i];
```
- We start a loop to iterate over each character of the string `s`. The variable `a` holds the current character.

```cpp
            if(a == 'a') {                
                dp[i + 1] = min(dp[i] + 1, bcnt);
            } else {
                bcnt++;
                dp[i + 1] = dp[i];
            }
```
- **Condition for 'a'**: If the current character `a` is 'a', we update `dp[i + 1]` to the minimum of either:
  - `dp[i] + 1`: Incrementing the deletion count by 1 (deleting the current 'a').
  - `bcnt`: The count of 'b's encountered so far, representing the deletions required to remove all 'b's before this point.
  
- **Condition for 'b'**: If `a` is 'b', we increment `bcnt` and set `dp[i + 1]` to `dp[i]`, effectively carrying forward the previous deletion count without adding any new deletions.

```cpp
        }
        return dp[n];
    }
};
```
- After iterating through the string, we return `dp[n]`, which holds the minimum deletions required to make the entire string consist of 'a's.

### Complexity

- **Time Complexity**:
  - The algorithm runs in \( O(n) \), where \( n \) is the length of the input string `s`. This is due to the single loop that iterates through the string once.
  
- **Space Complexity**:
  - The space complexity is \( O(n) \) because we use a dynamic programming array of size \( n + 1 \) to store intermediate results.

### Conclusion

The `minimumDeletions` method provides an efficient way to determine the minimum number of deletions needed to transform a string composed of 'a's and 'b's into a string of only 'a's. By using dynamic programming, the solution effectively tracks the count of 'b's and evaluates the necessary deletions in a single pass through the string.

**Key Takeaways**:
1. **Dynamic Programming**: This solution demonstrates the use of dynamic programming to solve optimization problems by breaking them down into subproblems and reusing results.
2. **Efficiency**: With a linear time complexity, this algorithm is efficient for long strings, making it suitable for competitive programming and other applications.
3. **Space Utilization**: The use of a single array to track the minimum deletions reduces the need for complex data structures, making the implementation straightforward.

This approach can be extended to similar problems involving character transformations and constraints, showcasing the versatility of dynamic programming in solving string manipulation tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/)

---
{{< youtube WDStNufBUQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
