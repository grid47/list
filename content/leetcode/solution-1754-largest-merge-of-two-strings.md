
+++
authors = ["grid47"]
title = "Leetcode 1754: Largest Merge Of Two Strings"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1754: Largest Merge Of Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YB-A6OUj98o"
youtube_upload_date="2021-02-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YB-A6OUj98o/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestMerge(string w1, string w2) {
        if (w1 == "" || w2 == "")
            return w1 + w2;
        else if (w1 < w2)
            return w2[0] + largestMerge(w1, w2.substr(1));
        else return w1[0] + largestMerge(w1.substr(1), w2);
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to merge two strings, `w1` and `w2`, in such a way that the resulting string is the lexicographically largest possible. This means that when both strings are compared, we want to form a new string that is greater than or equal to any possible combination of these two strings when arranged.

### Approach

To achieve this, the solution uses a recursive approach. The key idea is to compare the two strings at each step and append the larger of the two prefixes to the result string. If one string is exhausted, the remaining characters of the other string will be appended directly to the result. The steps can be outlined as follows:

1. **Base Case**: If either string is empty, return the other string. This serves as the termination condition for the recursion.

2. **Comparison**: Compare the two strings:
   - If `w1` is less than `w2` lexicographically, append the first character of `w2` to the result and recursively call the function with `w1` and the remaining characters of `w2`.
   - Otherwise, append the first character of `w1` to the result and recursively call the function with the remaining characters of both strings.

3. **Recursion**: This process continues recursively until both strings are completely merged into the final result.

### Code Breakdown (Step by Step)

Here’s a step-by-step breakdown of the implementation in the `largestMerge` function:

1. **Class Definition**: The function is defined within a class called `Solution`.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The `largestMerge` method takes two strings as input and returns a single string as output.

   ```cpp
   public:
       string largestMerge(string w1, string w2) {
   ```

3. **Base Case**: The first conditional checks if either `w1` or `w2` is empty. If so, it returns the concatenation of the two strings, effectively returning the non-empty string.

   ```cpp
   if (w1 == "" || w2 == "")
       return w1 + w2;
   ```

4. **Lexicographical Comparison**: The next conditional compares `w1` and `w2`. If `w1` is lexicographically smaller than `w2`, it means that `w2` should contribute more to the final merged string. Thus, the function appends the first character of `w2` and makes a recursive call with the remaining characters of `w1` and the substring of `w2` starting from the second character.

   ```cpp
   else if (w1 < w2)
       return w2[0] + largestMerge(w1, w2.substr(1));
   ```

5. **Default Case**: If `w1` is not less than `w2`, the first character of `w1` is appended to the result. The function then makes a recursive call with the substring of `w1` starting from the second character and the entire `w2`.

   ```cpp
   else return w1[0] + largestMerge(w1.substr(1), w2);
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution can be approximated to \(O(n + m)\), where \(n\) and \(m\) are the lengths of the input strings `w1` and `w2`, respectively. This is because each character of both strings will be processed once in the recursion.

- **Space Complexity**: The space complexity is \(O(n + m)\) as well, due to the recursion stack space used for the function calls and the substring creations in each recursive call.

### Conclusion

In conclusion, the `largestMerge` function effectively demonstrates a straightforward recursive strategy to merge two strings into the lexicographically largest possible string. By leveraging string comparison at each recursive step, the solution ensures that the characters are selected optimally to create the desired result. This method is not only efficient but also easy to understand, showcasing how recursion can simplify complex problems involving string manipulations. The approach can be useful in various scenarios where order and combination of elements are crucial, particularly in algorithm design and competitive programming contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-merge-of-two-strings/description/)

---
{{< youtube YB-A6OUj98o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
