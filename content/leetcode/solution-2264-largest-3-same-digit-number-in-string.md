
+++
authors = ["grid47"]
title = "Leetcode 2264: Largest 3-Same-Digit Number in String"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2264: Largest 3-Same-Digit Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vcrOpJQHsSE"
youtube_upload_date="2023-12-04"
youtube_thumbnail="https://i.ytimg.com/vi/vcrOpJQHsSE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestGoodInteger(string num) {
        char res = 0;
    for(int i = 2; i < num.size(); ++i)
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
            res = max(res, num[i]);
    return res == 0 ? "" : string(3, res);
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a string `num` representing a non-negative integer. The task is to find the largest good integer that appears consecutively in the string. A good integer is a three-digit integer in which all three digits are the same. For example, `111`, `222`, `333`, etc., are good integers. 

Your goal is to find the largest good integer that appears in `num`. If no such integer exists, return an empty string.

### Approach

To solve this problem, we need to:
1. **Identify All Possible Good Integers**: A good integer is a three-digit integer where all the digits are identical. Therefore, we are looking for substrings of length 3 where the first, second, and third characters are the same.
2. **Find the Largest Good Integer**: After identifying all possible good integers in the string, we need to determine which one is the largest.
3. **Edge Cases**: If there is no valid good integer, return an empty string.

To efficiently approach this:
- **Iterate Through the String**: Traverse the string from left to right, checking for any sequence of three consecutive digits that are the same.
- **Track the Maximum Good Integer**: As we identify each good integer, compare it with the largest one we’ve found so far.
- **Return the Result**: After scanning the entire string, if a good integer was found, return the largest one. Otherwise, return an empty string.

### Code Breakdown (Step by Step)

#### Step 1: Initialize a variable to track the result

```cpp
char res = 0;
```

- `res` is initialized to `0`. It will store the largest good integer found during the traversal of the string. If no good integer is found, `res` will remain `0`.

#### Step 2: Traverse through the string

```cpp
for(int i = 2; i < num.size(); ++i)
```

- We start the loop from `i = 2` because we need at least three characters to form a three-digit good integer. We will check if the current digit and the two previous digits are identical.

#### Step 3: Check if the current triplet is a good integer

```cpp
if (num[i] == num[i - 1] && num[i] == num[i - 2])
```

- This condition checks if the current digit (`num[i]`) is the same as the previous two digits (`num[i-1]` and `num[i-2]`). If they are equal, we have found a good integer.

#### Step 4: Track the largest good integer

```cpp
res = max(res, num[i]);
```

- If a good integer is found, we compare it with the current largest good integer (`res`). The `max()` function ensures that `res` always holds the largest good integer found so far.

#### Step 5: Return the result

```cpp
return res == 0 ? "" : string(3, res);
```

- After traversing the string, if `res` is still `0`, it means no good integer was found, so we return an empty string.
- If `res` holds a valid digit (the largest good integer), we return a string consisting of three identical digits (`string(3, res)`).

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(n)**, where `n` is the length of the string `num`. The reason is that we are iterating through the string exactly once, performing constant-time operations (comparisons and assignments) in each iteration.

#### Space Complexity:
The space complexity is **O(1)** because we are only using a fixed amount of extra space (`res` to store the largest good integer) regardless of the input size.

### Conclusion

This solution is an efficient way to find the largest good integer in a given string `num`. It has a linear time complexity of **O(n)**, which is optimal for this type of problem where we need to examine every character in the string. The space complexity is constant, as we only need a single variable (`res`) to track the largest good integer found. The solution is both time and space efficient, making it well-suited for large input sizes.

This approach ensures that we:
1. Efficiently scan the string for good integers.
2. Track the largest good integer in constant time.
3. Return the correct result based on the conditions outlined in the problem statement.

Overall, this solution is both simple and effective for solving the problem of finding the largest good integer in a string.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/)

---
{{< youtube vcrOpJQHsSE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
