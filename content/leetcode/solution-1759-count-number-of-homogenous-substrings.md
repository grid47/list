
+++
authors = ["grid47"]
title = "Leetcode 1759: Count Number of Homogenous Substrings"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1759: Count Number of Homogenous Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I3BzhnS9MwA"
youtube_upload_date="2021-02-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/I3BzhnS9MwA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHomogenous(string s) {
        long long j = 0, cnt = 0, n = s.size();
        int mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(s[j] == s[i]) continue;
            else {
                long long len = i - j;
                cnt += len * (len + 1) / 2;
                j = i;                
            }
        }
        long long len = n - j;
        cnt += len * (len + 1) / 2; 
        return cnt % mod;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires counting the number of homogenous substrings in a given string. A homogenous substring is defined as a substring where all characters are the same. For example, in the string `"abb"`:
- The homogenous substrings are: `"a"`, `"b"`, `"b"`, `"bb"`.
- The total count of homogenous substrings is 5.

The task is to compute this count efficiently, especially for longer strings.

### Approach

The solution involves a linear scan through the string, counting contiguous characters that are the same. When a character changes, we calculate how many homogenous substrings can be formed from the previous sequence of identical characters. 

The formula to calculate the number of homogenous substrings formed by `len` contiguous characters is given by:

\[
\text{count} = \frac{len \times (len + 1)}{2}
\]

This formula accounts for all possible substrings of different lengths that can be formed from the contiguous segment of identical characters.

The algorithm is structured as follows:
1. Traverse the string, maintaining a count of contiguous characters.
2. When a character change is detected, calculate the number of homogenous substrings for the previous segment and reset the counter for the new character.
3. At the end of the string, ensure to account for the last segment of contiguous characters.
4. Return the total count modulo \(10^9 + 7\) to prevent overflow.

### Code Breakdown (Step by Step)

Here is the detailed breakdown of the `countHomogenous` function:

1. **Class Definition**: The method is defined within the class `Solution`.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The `countHomogenous` method takes a single string `s` as input and returns an integer.

   ```cpp
   public:
       int countHomogenous(string s) {
   ```

3. **Variable Initialization**: Several variables are initialized:
   - `j` is a pointer that tracks the start of a contiguous segment of characters.
   - `cnt` will hold the total count of homogenous substrings.
   - `n` stores the length of the string.
   - `mod` is used for the modulo operation to avoid overflow.

   ```cpp
   long long j = 0, cnt = 0, n = s.size();
   int mod = (int) 1e9 + 7;
   ```

4. **Loop Through the String**: A `for` loop iterates through each character of the string using the index `i`.

   ```cpp
   for(int i = 0; i < n; i++) {
   ```

5. **Check for Homogenous Characters**: Inside the loop, the first condition checks if the current character matches the character at index `j` (the start of the current segment). If they match, the loop continues.

   ```cpp
   if(s[j] == s[i]) continue;
   ```

6. **Calculate Count for the Previous Segment**: When a character change is detected:
   - Calculate the length of the contiguous segment as `len = i - j`.
   - Use the formula to calculate the number of homogenous substrings for this segment and add it to `cnt`.
   - Update `j` to the current index `i`.

   ```cpp
   else {
       long long len = i - j;
       cnt += len * (len + 1) / 2;
       j = i;                
   }
   ```

7. **Account for the Last Segment**: After the loop, there may still be a contiguous segment to account for (the last characters). Calculate the length and add to the total count.

   ```cpp
   long long len = n - j;
   cnt += len * (len + 1) / 2; 
   ```

8. **Return the Total Count**: Finally, return the total count modulo \(10^9 + 7\).

   ```cpp
   return cnt % mod;
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the length of the string. This is because each character is processed exactly once in the linear scan.
  
- **Space Complexity**: The space complexity is \(O(1)\) as only a constant amount of additional space is used, regardless of the size of the input string.

### Conclusion

In summary, the `countHomogenous` function efficiently counts the number of homogenous substrings in a given string by leveraging a linear traversal and mathematical calculations to sum up possible substrings from segments of identical characters. This approach is optimal and concise, making it suitable for handling long strings while ensuring the solution remains within reasonable time and space constraints. By maintaining clarity in counting contiguous characters and using the mathematical formula for substring counting, the implementation successfully tackles the problem with elegance. This method showcases a valuable technique in substring-related problems that can be applied in various algorithmic challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-homogenous-substrings/description/)

---
{{< youtube I3BzhnS9MwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
