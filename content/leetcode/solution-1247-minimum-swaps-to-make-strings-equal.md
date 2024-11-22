
+++
authors = ["grid47"]
title = "Leetcode 1247: Minimum Swaps to Make Strings Equal"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1247: Minimum Swaps to Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for(int i = 0; i < s1.size(); i++) {
                 if(s1[i] == 'x' && s2[i] == 'y') xy++;
            else if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        if(xy % 2 != yx % 2) return -1;
        return xy/2 + yx/2 + (xy%2) * 2;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem requires us to determine the minimum number of swaps needed to make two strings equal. The strings, `s1` and `s2`, consist only of characters 'x' and 'y'. A swap is defined as exchanging one 'x' from `s1` with one 'y' from `s2` (or vice versa) at the same index. If it is impossible to make the strings equal through swaps, the function should return -1.

### Approach
To solve this problem, we can use the following approach:

1. **Count Mismatches**: Traverse both strings simultaneously to count the number of mismatched pairs:
   - Count how many times an 'x' in `s1` is paired with a 'y' in `s2` (let's call this count `xy`).
   - Count how many times a 'y' in `s1` is paired with an 'x' in `s2` (let's call this count `yx`).

2. **Check Parity**: After counting the mismatched pairs, we check the parity (even or odd) of both `xy` and `yx`. If their parities differ (i.e., one is even and the other is odd), it is impossible to make the strings equal through any number of swaps, so we return -1.

3. **Calculate Minimum Swaps**: If the parities are the same, the minimum number of swaps required can be calculated using the formula:
   - Each pair of `xy` or `yx` can be resolved with one swap, which means `xy / 2` swaps can fix `xy` mismatches and `yx / 2` swaps can fix `yx` mismatches.
   - If there is an odd mismatch, it can be resolved with two swaps (one additional swap is needed for one unmatched pair). Thus, we account for this by adding `(xy % 2) * 2` to the total swaps.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
```
- **Lines 1-2**: We define the `Solution` class and declare the public method `minimumSwap`, which takes two strings `s1` and `s2` as input parameters.

```cpp
        int xy = 0, yx = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            else if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }
```
- **Lines 3-9**: We initialize two integer variables `xy` and `yx` to count the mismatches. We then loop through the characters of `s1` and `s2`. For each index `i`:
  - If `s1[i]` is 'x' and `s2[i]` is 'y', we increment `xy`.
  - If `s1[i]` is 'y' and `s2[i]` is 'x', we increment `yx`.

```cpp
        if(xy % 2 != yx % 2) return -1;
```
- **Line 10**: After counting the mismatches, we check if the parities of `xy` and `yx` are different. If they are, it implies that it is impossible to make the strings equal through swaps, and we return -1.

```cpp
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
};
```
- **Lines 11-12**: If we reach this point, it means that it is possible to make the strings equal. We calculate the minimum number of swaps:
  - `xy / 2` gives the swaps needed for `xy` pairs.
  - `yx / 2` gives the swaps needed for `yx` pairs.
  - `(xy % 2) * 2` accounts for any additional unmatched pair that requires two swaps.
- Finally, we return the total number of swaps calculated.

### Complexity
1. **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the length of the input strings. We make a single pass through both strings to count the mismatches.

2. **Space Complexity**: The space complexity is \( O(1) \) since we only use a constant amount of space for the integer counters `xy` and `yx`.

### Conclusion
The `minimumSwap` function efficiently determines the minimum number of swaps required to make two strings equal by counting mismatched pairs and utilizing simple arithmetic operations to compute the result. The approach leverages the properties of mismatched characters to ensure that it handles even and odd cases appropriately. With a linear time complexity and constant space usage, this solution is both optimal and easy to understand, making it suitable for similar problems involving character manipulation in strings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
