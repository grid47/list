
+++
authors = ["grid47"]
title = "Leetcode 2729: Check if The Number is Fascinating"
date = "2024-02-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2729: Check if The Number is Fascinating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "B1JUo4KREiU"
youtube_upload_date="2023-06-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/B1JUo4KREiU/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isFascinating(int n) {
        int n1 = 2 * n;
        int n2 = 3 * n;
        vector<bool> yes(10, false); 
        string s = to_string(n) + to_string(n1) + to_string(n2);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') return false;
            if(yes[s[i] - '0']) return false;
            yes[s[i] - '0'] = true;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to check if a given integer `n` is a "fascinating number". A fascinating number is defined as follows:

- The number `n` must form a concatenated sequence when multiplied by 2 and 3.
- Specifically, if we concatenate the number `n`, `2 * n`, and `3 * n` as strings, the sequence should consist of the digits from 1 to 9 exactly once, in any order. Importantly, no digit should be repeated, and no digit should be zero.

The task is to return `true` if the number is fascinating, and `false` otherwise.

### Approach

The approach to solving this problem involves these key steps:
1. **Concatenate the Numbers**: First, we generate three values:
   - `n`: the given number.
   - `2 * n`: double of `n`.
   - `3 * n`: triple of `n`.
   These values are then concatenated into a single string.
   
2. **Check for Fascinating Properties**: The concatenated string must:
   - Contain only the digits from 1 to 9.
   - Contain each of these digits exactly once.
   - Not contain any zeros or repeating digits.

3. **Implementation Details**:
   - Convert the numbers into strings to easily manipulate their digits.
   - Use a boolean array `yes` of size 10 to track which digits have already been encountered, ensuring there are no duplicates.
   - As we loop through the concatenated string, we check if a zero is encountered or if any digit is repeated. If either condition is true, return `false`.
   - If no issues are found, check if all digits from 1 to 9 are present. If so, return `true`.

### Code Breakdown

#### Step 1: Multiply `n` by 2 and 3

```cpp
int n1 = 2 * n;
int n2 = 3 * n;
```

- These two lines compute the values `2 * n` and `3 * n`, which are needed for forming the concatenated sequence. The number `n` is the base value, and we calculate its double (`n1`) and triple (`n2`).

#### Step 2: Create the Concatenated String

```cpp
string s = to_string(n) + to_string(n1) + to_string(n2);
```

- We concatenate the string representations of `n`, `2 * n` (`n1`), and `3 * n` (`n2`). The `to_string()` function is used to convert each of these numbers into their string representations, and the `+` operator concatenates them into one string `s`. The string `s` now contains the digits of `n`, `n1`, and `n2` in that order.

#### Step 3: Create a Boolean Array to Track Digits

```cpp
vector<bool> yes(10, false);
```

- We create a boolean array `yes` of size 10 (for digits 0 through 9), initially set to `false`. This array will help us track whether each digit has been seen in the concatenated string `s`. If a digit is encountered, we mark it as `true`.

#### Step 4: Loop Through the String and Check Digits

```cpp
for(int i = 0; i < s.size(); i++) {
    if(s[i] == '0') return false;
    if(yes[s[i] - '0']) return false;
    yes[s[i] - '0'] = true;
}
```

- We loop through each character of the string `s`.
- First, we check if the character is `'0'`. If it is, we immediately return `false` because `0` is not allowed in a fascinating number.
- Next, we check if the current digit has already been seen using the `yes` array. If the digit has been encountered before, we return `false` because duplicates are not allowed.
- If the digit has not been seen before, we mark it as `true` in the `yes` array to ensure that we don't encounter it again in the future.

#### Step 5: Return True if All Conditions are Met

```cpp
return true;
```

- If we have successfully looped through all the digits and there were no zeros or duplicates, we return `true`, indicating that the number `n` is fascinating.

### Complexity Analysis

#### Time Complexity

The time complexity of this solution is **O(k)**, where `k` is the total number of digits in the concatenated string `s`. Since `s` is formed by concatenating `n`, `2 * n`, and `3 * n`, the number of digits is proportional to the length of `n`. Specifically:
- If `n` has `d` digits, then `n1` and `n2` will also have roughly `d` digits.
- Therefore, the total number of digits in `s` is approximately `3 * d`.

Since we loop through each digit of `s` once and perform constant-time operations within the loop (checking and updating the boolean array), the overall time complexity is **O(d)**, where `d` is the number of digits in the input number `n`.

#### Space Complexity

The space complexity is **O(1)**, as the only extra space used is for the boolean array `yes` of size 10. This space is constant, regardless of the size of `n`.

### Conclusion

This solution efficiently checks if a number is fascinating by leveraging string manipulation and a boolean array to track the occurrence of digits. The approach runs in linear time relative to the number of digits in the input number, and it uses constant space for the digit tracking array. This makes it both time and space efficient, suitable for large input numbers within reasonable limits.

The key insight in solving this problem is recognizing the need to form a concatenated string and checking for digit uniqueness and absence of zeros, which ensures the number is fascinating.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-the-number-is-fascinating/description/)

---
{{< youtube B1JUo4KREiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
