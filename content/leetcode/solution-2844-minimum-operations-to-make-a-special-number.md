
+++
authors = ["grid47"]
title = "Leetcode 2844: Minimum Operations to Make a Special Number"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2844: Minimum Operations to Make a Special Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xFshDEg_Ul4"
youtube_upload_date="2023-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/xFshDEg_Ul4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(string num) {
        bool fivefound = false;
        bool zerofound = false;
        for (int i =num.size()-1; i >=0;i--) {
            
            if (zerofound && num[i]=='0') return num.size()-2-i;
            if (zerofound && num[i]=='5') return num.size()-2-i;
            if (fivefound && num[i]=='2') return num.size()-2-i;
            if (fivefound && num[i]=='7') return num.size()-2-i;
            if (num[i]=='5') fivefound = true;
            if (num[i]=='0') zerofound = true;
            
        }
        if (zerofound) return num.size()-1;
        return num.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

Given a string `num` representing a non-negative integer, the goal is to find the minimum number of operations required to make the number divisible by 25. In each operation, we can remove any digit from the string. The task is to find how few digits we need to remove to make the number divisible by 25.

A number is divisible by 25 if it ends in either `00`, `25`, `50`, or `75`. Therefore, the challenge is to identify the minimum number of digits to remove so that the number ends with one of these pairs.

### Approach

The approach involves iterating through the digits of the given number `num` from right to left. By starting from the right, we can attempt to find one of the valid pairs (`00`, `25`, `50`, or `75`) that make the number divisible by 25. Once a valid pair is found, the number of digits removed is determined by the position of the pair.

### Code Breakdown (Step by Step)

#### Step 1: Initialization of Boolean Flags
```cpp
bool fivefound = false;
bool zerofound = false;
```
- We initialize two boolean flags: `fivefound` and `zerofound`. These flags will help us track the positions where we have encountered the digits `5` and `0`. This is important because the valid pairs for divisibility by 25 include `25`, `50`, `75`, and `00`, so we need to find these digits in the correct order.

#### Step 2: Loop Through the Digits in Reverse
```cpp
for (int i = num.size() - 1; i >= 0; i--) {
```
- We loop through the digits of the number `num` starting from the last index (`num.size() - 1`) and moving towards the first index (`i >= 0`). This is because the valid pairs must appear at the end of the number for it to be divisible by 25.

#### Step 3: Check for Valid Pairs and Count Operations
```cpp
if (zerofound && num[i] == '0') return num.size() - 2 - i;
if (zerofound && num[i] == '5') return num.size() - 2 - i;
if (fivefound && num[i] == '2') return num.size() - 2 - i;
if (fivefound && num[i] == '7') return num.size() - 2 - i;
```
- For each digit `num[i]`, we check if we have already encountered a `0` or `5` (using the `zerofound` and `fivefound` flags). If we find a valid pair, we calculate how many digits need to be removed to form the valid pair.
  - If we encounter a `0` after a `0` has already been found, we return `num.size() - 2 - i`. This is because we want the number to end with `00`, and this is the number of digits to remove to leave just the `00` at the end.
  - If we encounter a `5` after a `0` has been found, we return `num.size() - 2 - i`, as this forms the pair `50`.
  - If we encounter a `2` after a `5` has already been found, we return `num.size() - 2 - i`, as this forms the pair `25`.
  - If we encounter a `7` after a `5` has already been found, we return `num.size() - 2 - i`, as this forms the pair `75`.

#### Step 4: Mark the Digits We Encounter
```cpp
if (num[i] == '5') fivefound = true;
if (num[i] == '0') zerofound = true;
```
- If we encounter a `5`, we set the `fivefound` flag to `true`. If we encounter a `0`, we set the `zerofound` flag to `true`. These flags help us know whether the required digits for forming a valid pair have been found yet.

#### Step 5: Handle the Case When No Valid Pair is Found
```cpp
if (zerofound) return num.size() - 1;
return num.size();
```
- If the number contains at least one `0`, but no valid pair is found (i.e., the number cannot be made divisible by 25), we return `num.size() - 1`. This is because we would need to remove all digits except for the last one to make it divisible by 25.
- If no valid pair is found and there is no `0` in the number, we return `num.size()`, indicating that it is not possible to make the number divisible by 25 by removing any digits.

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the length of the string `num`.
  - The algorithm iterates over each character of the string exactly once, checking if it is part of a valid pair. The checking and updating of flags are constant time operations (`O(1)`), so the time complexity is linear in the size of the input string.

#### Space Complexity:
- **O(1)**, as we are only using a constant amount of extra space for the boolean flags (`fivefound`, `zerofound`) and other variables like `i` for iteration. There are no additional data structures used whose size depends on the input size.

### Conclusion

This approach efficiently solves the problem of finding the minimum number of operations to make a number divisible by 25 by removing digits. It works by scanning the digits of the number from right to left and looking for valid pairs (`00`, `25`, `50`, `75`). Once such a pair is found, it calculates how many digits need to be removed to leave the pair at the end of the number. The solution operates in linear time with constant space, making it optimal for this problem. The solution is simple and easy to understand, and it effectively handles various edge cases such as when the number is already divisible by 25 or when it's impossible to make the number divisible by 25.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/)

---
{{< youtube xFshDEg_Ul4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
