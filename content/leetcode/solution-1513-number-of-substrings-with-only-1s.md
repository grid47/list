
+++
authors = ["grid47"]
title = "Leetcode 1513: Number of Substrings With Only 1s"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1513: Number of Substrings With Only 1s in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9cPoRqw5I_8"
youtube_upload_date="2020-07-12"
youtube_thumbnail="https://i.ytimg.com/vi/9cPoRqw5I_8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSub(string s) {
        long cnt = 0, mod = (int) 1e9 + 7;

        long tmp = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                tmp++;
            }
            
            if(s[i] == '0' || i == n - 1) {
                cnt = (cnt + tmp * (tmp + 1) / 2) % mod;
                tmp = 0;
            }
            
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to count the number of substrings in a binary string `s` that consist solely of the character '1'. Each substring contributes to the total count based on its length. Specifically, if a substring has length `L`, it contributes \( \frac{L \cdot (L + 1)}{2} \) to the total count, as there are \( L \) substrings of length 1, \( L-1 \) of length 2, and so forth down to 1 substring of length \( L \). The result should be returned modulo \( 10^9 + 7 \).

### Approach

To efficiently count the number of valid substrings, we can use a single pass through the string while maintaining a count of consecutive '1's. When we encounter a '0' or reach the end of the string, we can calculate the contribution of the accumulated '1's to the total count. 

Here’s a step-by-step breakdown of the approach:

1. **Initialization**: Start with a counter for the total substrings (`cnt`), a temporary counter for consecutive '1's (`tmp`), and a modulo value to handle large numbers.

2. **Iterate Through the String**: Loop through each character in the string:
   - If the character is '1', increment the temporary counter (`tmp`).
   - If the character is '0' or if we reach the end of the string, compute the contribution of the accumulated '1's to `cnt`, and reset `tmp`.

3. **Final Calculation**: After processing all characters, return the total count of substrings modulo \( 10^9 + 7 \).

### Code Breakdown (Step by Step)

Here is the detailed explanation of the provided code:

```cpp
class Solution {
public:
```
- We define a class named `Solution` with a public method `numSub`.

```cpp
    int numSub(string s) {
```
- The method `numSub` takes a string `s` as input, which represents a binary string.

```cpp
        long cnt = 0, mod = (int) 1e9 + 7;
```
- We initialize `cnt` to 0 to store the total number of valid substrings. The variable `mod` is set to \( 10^9 + 7 \) to handle large numbers through modular arithmetic.

```cpp
        long tmp = 0, n = s.size();
```
- `tmp` will keep track of the number of consecutive '1's, and `n` is the length of the string `s`.

```cpp
        for(int i = 0; i < n; i++) {
```
- We start a loop that iterates over each character in the string from index 0 to \( n - 1 \).

```cpp
            if(s[i] == '1') {
                tmp++;
            }
```
- If the current character is '1', we increment the `tmp` counter, indicating we have found another '1'.

```cpp
            if(s[i] == '0' || i == n - 1) {
```
- If we encounter a '0' or reach the last character in the string, we process the count of '1's stored in `tmp`.

```cpp
                cnt = (cnt + tmp * (tmp + 1) / 2) % mod;
```
- We calculate the contribution of the current sequence of '1's to the total count using the formula \( \frac{L \cdot (L + 1)}{2} \) and update `cnt`. The modulo operation ensures we do not exceed the limits of typical integer types.

```cpp
                tmp = 0;
            }
```
- After adding the contribution of the current sequence, we reset `tmp` to 0 in preparation for the next sequence of '1's.

```cpp
        }
```
- The loop continues until all characters have been processed.

```cpp
        return cnt;
    }
};
```
- Finally, we return the total count of substrings stored in `cnt`.

### Complexity

#### Time Complexity
- The time complexity of this solution is \(O(n)\), where \(n\) is the length of the input string. We iterate through the string only once.

#### Space Complexity
- The space complexity is \(O(1)\) because we use a constant amount of space for the counters and do not use any additional data structures that grow with input size.

### Conclusion

This solution efficiently counts the number of valid substrings of '1's in a binary string by maintaining a running total of consecutive '1's. 

**Key Insights**:
- **Mathematical Insight**: Understanding how to count the contributions of sequences of '1's is crucial to solving this problem efficiently.
- **Modular Arithmetic**: Using modulo \( 10^9 + 7 \) ensures that we can handle very large counts without encountering overflow errors.

The code is concise and leverages mathematical properties effectively, making it an optimal solution for the problem at hand. The approach can be applied to similar problems involving counting specific substrings or patterns within strings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-substrings-with-only-1s/description/)

---
{{< youtube 9cPoRqw5I_8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
