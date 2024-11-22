
+++
authors = ["grid47"]
title = "Leetcode 2696: Minimum String Length After Removing Substrings"
date = "2024-02-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2696: Minimum String Length After Removing Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "8SD0rcmgFMU"
youtube_upload_date="2023-05-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8SD0rcmgFMU/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int res = n;
        for(int i = 0; i < n - 1; i++) {
            int p = i, q = i + 1;
            while((p >= 0 && q < n && s[p] == 'A' && s[q] == 'B') ||
               (p >= 0 && q < n && s[p] == 'C' && s[q] == 'D') ) {
                s[p] = 'X';
                s[q] = 'X';                
                res -= 2;
                while(q < n && s[q] == 'X') q++;
                while(p >= 0&& s[p] == 'X') p--;                
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to reduce a given string by repeatedly removing adjacent pairs of characters: specifically, "AB" and "CD". For every such pair, we delete both characters from the string and keep performing this operation until no more such pairs are found. The goal is to return the final length of the string after all such operations have been applied.

### Approach

We will solve this problem using a greedy approach. The idea is to iterate through the string and check for adjacent pairs of characters that can be removed. When a valid pair ("AB" or "CD") is found, we replace both characters with 'X' (to indicate that they've been removed) and continue the process. This helps in reducing the string efficiently.

To optimize the process:
1. We will use two pointers (`p` and `q`) to track potential adjacent pairs.
2. Every time we find a valid pair, we reduce the string length by 2 and move the pointers inward to continue searching for further valid pairs.
3. Once a pair is removed, we skip over the 'X' characters (which are placeholders for removed characters) to continue checking the string efficiently.

### Code Breakdown (Step by Step)

#### Step 1: Initialization

```cpp
int n = s.size();
int res = n;
```

- The variable `n` holds the size of the input string `s`.
- The variable `res` is initialized to `n` and will track the length of the string as it is reduced by removing adjacent pairs.

#### Step 2: Iterating Through the String

```cpp
for(int i = 0; i < n - 1; i++) {
    int p = i, q = i + 1;
```

- We loop through the string from index `0` to `n-2` (because we are checking adjacent pairs).
- `p` and `q` represent the two adjacent characters at positions `i` and `i+1`.

#### Step 3: Removing Valid Pairs

```cpp
while((p >= 0 && q < n && s[p] == 'A' && s[q] == 'B') ||
      (p >= 0 && q < n && s[p] == 'C' && s[q] == 'D')) {
```

- Inside the loop, we check if we have found one of the valid adjacent pairs:
  - "AB"
  - "CD"
- If a valid pair is found, we proceed to remove the characters.

#### Step 4: Marking Characters as Removed

```cpp
s[p] = 'X';
s[q] = 'X';
res -= 2;
```

- We replace the characters at positions `p` and `q` with 'X' to indicate that they have been removed.
- We decrease the result (`res`) by 2 because we've removed two characters from the string.

#### Step 5: Skipping Over 'X' Characters

```cpp
while(q < n && s[q] == 'X') q++;
while(p >= 0 && s[p] == 'X') p--;
```

- After removing a valid pair, we move the pointers `p` and `q` inward to skip over any 'X' characters (which are placeholders for removed characters).
- We increment `q` to find the next valid character to check and decrement `p` to do the same in the opposite direction.

#### Step 6: Continue Loop Until No Valid Pair is Found

The outer `while` loop continues as long as valid pairs are being removed from the string. This ensures that the string is reduced as much as possible by repeatedly removing valid pairs.

#### Step 7: Return Final Length of the String

```cpp
return res;
```

- After the loop terminates (i.e., no more valid pairs are found), we return `res`, which holds the final length of the string after all possible reductions.

### Complexity

#### Time Complexity

- The time complexity of this solution is **O(n)**, where `n` is the size of the input string. This is because each character in the string is visited at most once: we scan the string for adjacent pairs, and each time we find a pair, we mark both characters as removed ('X') and skip over them.
- We only loop through the string once with the two pointers, so the solution is linear in terms of time complexity.

#### Space Complexity

- The space complexity is **O(1)**, assuming that we modify the string in-place. We only use a few additional integer variables (`res`, `p`, and `q`), which occupy constant space.

### Conclusion

This approach efficiently reduces the string by removing adjacent pairs "AB" and "CD" using a greedy method. The algorithm works in linear time, making it suitable for handling large strings. By iterating through the string once and marking removed characters, we achieve optimal performance with a minimal space footprint. The solution ensures that all possible reductions are made and provides the correct final length of the string.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/)

---
{{< youtube 8SD0rcmgFMU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
