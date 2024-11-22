
+++
authors = ["grid47"]
title = "Leetcode 2496: Maximum Value of a String in an Array"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2496: Maximum Value of a String in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uGUaazmui2k"
youtube_upload_date="2022-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/uGUaazmui2k/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution 
{
public:
    int maximumValue(vector<string>& strs) 
    {
        int m = 0;
        for (string s : strs)
            if (all_of(s.begin(), s.end(), ::isdigit))
                m = max(m, stoi(s));
            else
                m = max(m, (int)s.size());
        return m;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the maximum value among a given list of strings. Each string can either be:
1. A numerical string (composed entirely of digits), in which case its value is the integer it represents.
2. A non-numerical string, in which case its value is determined by its length (the number of characters it contains).

The goal is to determine the largest value, either by converting the string to an integer if it's numerical or by using the length of the string if it's non-numerical.

### Approach

To solve this problem efficiently, we need to iterate through all the strings in the input list and, based on the content of each string, calculate its value. We will check:
1. **If a string is numerical**: This can be determined using the `all_of` function in C++ which checks if all characters in the string are digits.
2. **If a string is non-numerical**: In this case, we simply calculate the length of the string.
   
For each string, we compute the value (either the integer value or the string length) and keep track of the maximum value encountered.

The steps involved are:
1. Initialize a variable `m` to store the maximum value encountered, initially set to zero.
2. For each string in the input list, determine if it is a numerical string or a non-numerical string.
3. If it is a numerical string, convert it to an integer and compare it with the current maximum value.
4. If it is a non-numerical string, compute its length and compare it with the current maximum value.
5. Finally, return the maximum value after processing all the strings.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Maximum Value

```cpp
int m = 0;
```

We start by initializing the variable `m` to zero. This variable will hold the maximum value encountered while processing the strings in the list.

#### Step 2: Loop Over Each String in the Input List

```cpp
for (string s : strs)
```

We iterate through each string `s` in the list `strs`. The list contains a collection of strings, and we need to evaluate each string one by one.

#### Step 3: Check if the String is Numeric

```cpp
if (all_of(s.begin(), s.end(), ::isdigit))
```

To determine if the string `s` consists entirely of digits, we use the C++ function `all_of` from the `<algorithm>` library. This function checks if all characters in the string satisfy the condition provided (in this case, being a digit).

- `s.begin()` and `s.end()` provide iterators to the start and end of the string, respectively.
- `::isdigit` is a standard library function that returns `true` if a character is a digit.

If the string is numeric (i.e., it contains only digits), the `if` block is executed.

#### Step 4: Convert the Numeric String to an Integer

```cpp
m = max(m, stoi(s));
```

If the string is numeric, we convert it to an integer using the `stoi` function, which converts a string to an integer. We then compare this integer with the current maximum value `m` and update `m` to the larger of the two values.

#### Step 5: Handle Non-Numeric Strings

```cpp
else
    m = max(m, (int)s.size());
```

If the string is not numeric, it must be a non-numeric string. In this case, we compute the length of the string using the `size()` function, which returns the number of characters in the string. We then compare the length of the string with the current maximum value `m` and update `m` to the larger value.

#### Step 6: Return the Maximum Value

```cpp
return m;
```

Once all strings have been processed, the function returns the maximum value `m`, which contains the largest value found—whether it was from a numerical string or the length of a non-numeric string.

### Complexity Analysis

#### Time Complexity:
- The time complexity of the solution is **O(n * k)**, where `n` is the number of strings in the list `strs`, and `k` is the average length of the strings.
  - For each string, the function checks if all characters are digits using `all_of(s.begin(), s.end(), ::isdigit)`, which has a time complexity of **O(k)** for each string.
  - The `stoi(s)` operation also runs in **O(k)**, as it needs to parse each character in the string to convert it to an integer.
  - The total time complexity is thus **O(n * k)**, where we process each string and perform operations proportional to the length of the string.

#### Space Complexity:
- The space complexity of the solution is **O(1)**. The algorithm only uses a constant amount of extra space for the variable `m` and does not require additional space proportional to the input size.
- The space used for storing the strings in the input list `strs` is not counted in the space complexity since it is part of the input.

### Conclusion

This solution effectively solves the problem by iterating over the list of strings and calculating the maximum value based on whether the string is numeric or not. The use of `all_of` to check for numeric strings and `stoi` to convert numeric strings to integers ensures that we handle both numeric and non-numeric strings efficiently.

The time complexity of **O(n * k)** makes this approach feasible for lists containing a large number of strings or strings of varying lengths. The space complexity of **O(1)** indicates that the solution uses minimal extra space, making it efficient in terms of memory usage.

In summary:
- **Time Complexity**: O(n * k)
- **Space Complexity**: O(1)
- **Efficiency**: The solution is both time and space efficient, with the ability to handle large inputs effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/)

---
{{< youtube uGUaazmui2k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
