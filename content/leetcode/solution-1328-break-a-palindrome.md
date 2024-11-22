
+++
authors = ["grid47"]
title = "Leetcode 1328: Break a Palindrome"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1328: Break a Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B5v5rDR7c9A"
youtube_upload_date="2021-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/B5v5rDR7c9A/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        for(int i = 0; i < n / 2; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return n < 2 ? "" : palindrome;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to modify a given string that is a palindrome in such a way that it is no longer a palindrome, while aiming to achieve this with the minimum lexicographical change. A palindrome is a string that reads the same forward and backward. The problem specifically requires replacing characters in the palindrome string to ensure that the result is still a valid string and is not empty. If it is impossible to break the palindrome, the function should return an empty string.

### Approach
The solution employs a straightforward strategy:
1. **Iterate through the First Half**: The algorithm iterates through the first half of the string to find the first character that is not 'a'. This is crucial because replacing any character with 'a' will generally yield a lexicographically smaller string.
  
2. **Replace the Character**: If a character other than 'a' is found, it is replaced with 'a', and the modified string is returned. This ensures that the palindrome is broken by the smallest possible change.

3. **Special Case for All 'a' Palindromes**: If the entire palindrome consists of the letter 'a', the last character is changed to 'b' to break the palindrome. Additionally, if the length of the string is less than 2, returning an empty string is necessary, as a single character or an empty string cannot form a non-palindromic result.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
```
- The `breakPalindrome` function is defined within the `Solution` class. It takes a string `palindrome` as input and determines its length, `n`.

```cpp
        for(int i = 0; i < n / 2; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
```
- The `for` loop iterates from the beginning of the string up to the middle (`n / 2`). For each character, it checks if it is not 'a'. If a non-'a' character is found, it is replaced with 'a', effectively breaking the palindrome, and the modified string is returned immediately.

```cpp
        palindrome[n - 1] = 'b';
        return n < 2 ? "" : palindrome;
    }
};
```
- If the loop completes without finding a non-'a' character, it means the string is composed entirely of 'a's. The last character is then changed to 'b', ensuring the string is no longer a palindrome. The function then checks if the length of the string is less than 2; if true, it returns an empty string, as no valid modification can be made.

### Complexity Analysis

- **Time Complexity**:
  - The overall time complexity is \(O(n)\), where \(n\) is the length of the input string. This is due to the single traversal through half of the string.

- **Space Complexity**:
  - The space complexity is \(O(1)\) since the modifications are made in-place, and no additional data structures are required.

### Conclusion
The provided code effectively addresses the problem of breaking a palindrome by utilizing a simple yet efficient strategy. By modifying the first non-'a' character to 'a', the algorithm achieves the desired outcome of creating a non-palindromic string with the least lexicographical impact. The special handling for all-'a strings demonstrates a careful consideration of edge cases, ensuring robust functionality.

In practical applications, understanding how to manipulate strings and maintain efficiency is crucial. This solution exemplifies how basic string operations and condition checks can yield effective results in algorithm design. The ability to break a palindrome while adhering to constraints is a valuable skill in competitive programming and coding interviews, making this solution a useful addition to any programmer's toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/break-a-palindrome/description/)

---
{{< youtube B5v5rDR7c9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
