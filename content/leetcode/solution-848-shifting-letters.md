
+++
authors = ["grid47"]
title = "Leetcode 848: Shifting Letters"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 848: Shifting Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
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
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = shifts.size();
        for(int i = n - 2; i >= 0; i--)
        shifts[i] = (shifts[i] + shifts[i + 1] ) % 26;

        for(int i = 0; i < s.size(); i++)
        s[i] = 'a' + ((s[i] - 'a'+ shifts[i]) % 26);

        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to perform a series of shifting operations on the characters of a string. Each shift operation moves a character in the string forward by a number of positions in the alphabet, with wrap-around from 'z' back to 'a'. The challenge is that each character in the string may have multiple shifts applied, and these shifts are defined by a vector of integers. 

The task is to calculate the final string after applying all shifts. Each shift value in the vector represents how many positions to move a character in the string. The trick is that each character gets a different amount of shift based on its position and the subsequent characters' shifts.

### Example:
- **Input**: `s = "abc"`, `shifts = [3, 5, 9]`
- **Output**: `"rpl"`

In this case, the shifting operations are:
1. The first character 'a' is shifted by `3` (it becomes 'd').
2. The second character 'b' is shifted by `3 + 5 = 8` (it becomes 'j').
3. The third character 'c' is shifted by `3 + 5 + 9 = 17` (it becomes 'r').

Thus, the final string after all the shifts is `"rpl"`.

### Approach

The solution to this problem involves two main steps:
1. **Cumulative Shifting**: The shifts provided are cumulative from the last character to the first. That is, each character's shift depends on the sum of shifts starting from that character to the end of the string.
2. **Character Shifting**: After calculating the cumulative shifts, we apply the shift to each character in the string, adjusting the character by the appropriate number of positions in the alphabet.

#### Step 1: Cumulative Shifting
To efficiently compute the total shift for each character, we traverse the `shifts` array from right to left, accumulating the shifts for each character. By the time we reach the first character, the shift for that character will be the sum of all shifts applied to it (and subsequent characters).

#### Step 2: Applying the Shifts to the String
Once we have the cumulative shifts, we apply each shift to the corresponding character in the string. This is done by:
- Taking the current character's ASCII value (e.g., `'a'` has a value of 97).
- Adjusting it by adding the shift and wrapping around using modulo 26 to ensure the shift remains within the bounds of the alphabet.
- Updating the string with the new shifted character.

The solution performs these operations in a linear scan, which ensures that we handle the problem efficiently.

### Code Breakdown (Step by Step)

#### Step 1: Cumulative Shifting

```cpp
int n = shifts.size();
for(int i = n - 2; i >= 0; i--)
    shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
```

In this loop, we traverse the `shifts` vector from the second-to-last element to the first. For each `i`, we accumulate the shifts from the right side:
- The shift at `shifts[i]` is updated by adding the value of `shifts[i + 1]` to it, ensuring that it reflects the total shift for character `i` and all subsequent characters.
- The `% 26` operation ensures that the total shift remains within the bounds of the alphabet (0 to 25, corresponding to 'a' to 'z').

#### Step 2: Applying Shifts to the String

```cpp
for(int i = 0; i < s.size(); i++)
    s[i] = 'a' + ((s[i] - 'a' + shifts[i]) % 26);
```

This loop iterates over each character in the string:
- For each character `s[i]`, we first convert it to a zero-based index (`s[i] - 'a'`), so 'a' becomes 0, 'b' becomes 1, and so on.
- We then add the corresponding shift from the `shifts` array.
- The `% 26` ensures that the shift wraps around the alphabet, i.e., after 'z', it will go back to 'a'.
- Finally, we convert the zero-based index back to a character and update the string.

#### Step 3: Return the Result

```cpp
return s;
```

After all characters have been shifted, the modified string is returned as the final result.

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(n)**, where `n` is the length of the string `s`. The two main operations—computing the cumulative shifts and applying the shifts to the string—both take linear time.

1. The first loop (computing cumulative shifts) runs in **O(n)**, as it processes each element of the `shifts` vector once.
2. The second loop (applying the shifts to the string) also runs in **O(n)**, as it processes each character in the string once.

Since both operations are linear, the overall time complexity is **O(n)**.

#### Space Complexity:
The space complexity is **O(1)** if we disregard the space used for the input and output. The `shifts` vector is modified in place, and no additional data structures are used (apart from a constant amount of space for temporary variables in the loops).

If we count the input string as part of the space complexity, it would be **O(n)** because the string `s` is given as input and modified in place. However, the space used by the `shifts` array is already accounted for in the input, so the space complexity is constant beyond that.

### Conclusion

The solution to this problem efficiently computes the result by first calculating the cumulative shifts for each character in the string and then applying those shifts in a second loop. The use of modulo 26 ensures that the alphabet wraps around correctly, and the overall time complexity of **O(n)** makes this solution optimal for large inputs. By modifying the `shifts` array in place and performing a single pass through the string, the solution also maintains constant extra space, making it both time and space efficient.

This approach ensures that the problem is solved with minimal overhead, making it ideal for scenarios where performance is crucial, such as in competitive programming or real-time systems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/shifting-letters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
