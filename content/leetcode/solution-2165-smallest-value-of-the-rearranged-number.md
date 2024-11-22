
+++
authors = ["grid47"]
title = "Leetcode 2165: Smallest Value of the Rearranged Number"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2165: Smallest Value of the Rearranged Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fe3yn96MAoI"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fe3yn96MAoI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long smallestNumber(long long num) {
        auto s = to_string(abs(num));
        sort(s.begin(), s.end(), [&](char a, char b){
            return num > 0? a < b: b < a;
        });
        if(num > 0)
        swap(s[0], s[s.find_first_not_of('0')]);
        return stoll(s) * (num < 0? -1: 1);
    }
};
{{< /highlight >}}
---

### Problem Statement
Given a long integer `num`, return the smallest possible integer that can be formed using the digits of `num`. If `num` is positive, the digits should be rearranged to form the smallest positive number. If `num` is negative, rearrange the digits (excluding the negative sign) to form the largest negative number. The output should retain the sign of the original `num`.

### Approach
To solve the problem, the approach varies based on whether `num` is positive or negative:
1. **For positive numbers**:
   - Sort the digits in ascending order to create the smallest possible number.
   - Ensure that any leading zero is moved to an appropriate position to avoid invalid results (e.g., "0123" should become "1023").
2. **For negative numbers**:
   - Sort the digits in descending order to create the numerically largest negative number.
   - Maintain the negative sign while constructing the final result.

### Code Breakdown (Step by Step)
1. **Convert the Number to a String**:
   ```cpp
   auto s = to_string(abs(num));
   ```
   - Convert the absolute value of `num` to a string for easy manipulation of its digits.
   - `abs(num)` ensures the conversion works consistently whether `num` is positive or negative.

2. **Sort the Digits**:
   ```cpp
   sort(s.begin(), s.end(), [&](char a, char b){
       return num > 0 ? a < b : b < a;
   });
   ```
   - Use the `sort` function with a custom comparator:
     - If `num` is positive (`num > 0`), sort the digits in ascending order (`a < b`).
     - If `num` is negative (`num < 0`), sort the digits in descending order (`b < a`) to maximize the magnitude when prefixed by a negative sign.

3. **Handle Leading Zeros for Positive Numbers**:
   ```cpp
   if(num > 0)
       swap(s[0], s[s.find_first_not_of('0')]);
   ```
   - For positive numbers, ensure that the first character is not a zero:
     - `s.find_first_not_of('0')` finds the first non-zero digit in `s`.
     - Swap this non-zero digit with the first digit to avoid leading zeros in the result.

4. **Convert the String Back to a Long Integer**:
   ```cpp
   return stoll(s) * (num < 0 ? -1 : 1);
   ```
   - Convert the sorted string `s` back to a long integer using `stoll`.
   - Multiply by `-1` if `num` was originally negative, ensuring the correct sign is retained.

### Example Walkthroughs
**Example 1**: `num = 310`
- Convert `num` to a string: `"310"`.
- Sort digits in ascending order for a positive number: `"013"`.
- Swap leading zero with the first non-zero digit: `"103"`.
- Convert back to integer: `103`.

**Example 2**: `num = -7605`
- Convert `num` to a string: `"7605"`.
- Sort digits in descending order for a negative number: `"7650"`.
- Convert back to integer and apply negative sign: `-7650`.

### Complexity
- **Time Complexity**:
  - O(n log n), where `n` is the number of digits in `num`. This results from sorting the digits.
- **Space Complexity**:
  - O(n), for storing the string representation and the sorted result.

### Conclusion
This solution is effective for rearranging the digits of a number to form the smallest positive or largest negative result based on the sign of the input. By using basic string manipulation and sorting, the approach remains straightforward and efficient. It ensures that leading zeros are handled correctly for positive numbers and that the sign of `num` is preserved in the final output. This method can be utilized in applications involving numerical digit rearrangement for optimization problems or formatting tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/)

---
{{< youtube fe3yn96MAoI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
