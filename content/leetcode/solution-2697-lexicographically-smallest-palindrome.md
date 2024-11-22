
+++
authors = ["grid47"]
title = "Leetcode 2697: Lexicographically Smallest Palindrome"
date = "2024-02-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2697: Lexicographically Smallest Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "EzAjKrEQLFs"
youtube_upload_date="2023-05-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EzAjKrEQLFs/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            char tmp = min(s[i], s[j]);
            s[i] = s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to convert a given string into its lexicographically smallest palindrome. A palindrome is a string that reads the same backward as forward. The task is to modify the string so that it is a palindrome, while ensuring that it is the smallest possible palindrome lexicographically.

For each character in the string, if two characters (one from the beginning and one from the end) are different, we should replace both characters with the lexicographically smaller of the two. This operation is repeated until the entire string becomes a palindrome.

### Approach

To solve this problem efficiently, we can use the following approach:

1. **Two-pointer approach**: Use two pointers, `i` and `j`, to traverse the string from both ends towards the middle.
2. **Character comparison**: For each pair of characters (one from the beginning and one from the end), if they are not equal, replace both characters with the smaller one to ensure the smallest possible palindrome.
3. **Termination**: The loop continues until the two pointers meet or cross each other, at which point we will have transformed the string into the smallest lexicographically palindrome possible.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int n = s.size();
int i = 0, j = n - 1;
```

- `n` holds the size of the input string `s`.
- `i` and `j` are the two pointers, initialized to the start (`i = 0`) and the end (`j = n - 1`) of the string, respectively. These pointers will help us compare characters from both ends of the string and modify them to form a palindrome.

#### Step 2: While Loop for Comparison

```cpp
while(i < j) {
    char tmp = min(s[i], s[j]);
    s[i] = s[j] = tmp;
    i++;
    j--;
}
```

- The `while` loop runs as long as `i` is less than `j`. This ensures that we only need to compare each pair of characters once. The loop proceeds from the outermost characters towards the center of the string.
- Inside the loop, we compare the characters at positions `i` and `j` (`s[i]` and `s[j]`). We use the `min` function to determine which of the two characters is lexicographically smaller.
- Both characters are replaced with the smaller of the two. This ensures that the string is being transformed into the lexicographically smallest palindrome.
- After replacing the characters, we increment `i` (move the left pointer) and decrement `j` (move the right pointer) to compare the next pair of characters.

#### Step 3: Return the Result

```cpp
return s;
```

- After the loop terminates, we have transformed the string into the smallest palindrome possible. The modified string is returned as the result.

### Complexity

#### Time Complexity

The time complexity of this solution is **O(n)**, where `n` is the length of the string `s`. This is because we only iterate through half of the string once. In each iteration, we perform a constant time operation of comparing two characters and replacing them. Since we only loop once from the beginning to the middle of the string, the time complexity is linear.

#### Space Complexity

The space complexity of this solution is **O(1)**. We are modifying the string `s` in place without using any extra space (besides a few integer variables and a temporary variable `tmp`). Therefore, the space complexity is constant.

### Conclusion

This solution is optimal for the problem of converting a string into its lexicographically smallest palindrome. By using a two-pointer approach and replacing mismatched characters with the lexicographically smaller of the two, we efficiently modify the string in a single pass. The algorithm runs in linear time, making it suitable for large strings, and it does not require any extra space, making it very memory efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographically-smallest-palindrome/description/)

---
{{< youtube EzAjKrEQLFs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
