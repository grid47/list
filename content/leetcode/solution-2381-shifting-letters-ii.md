
+++
authors = ["grid47"]
title = "Leetcode 2381: Shifting Letters II"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2381: Shifting Letters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dWp_egpuwbU"
youtube_upload_date="2022-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dWp_egpuwbU/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.length();
        vector<int> net(n, 0);
        for(auto &x: sh) {
            int k = x[2] == 1? 1 : -1;
            net[x[0]] += k;
           // net[x[0]] %= 26;
            if(x[1] + 1 < n) {
            net[x[1] + 1] -= k;
           // net[x[1] + 1] %= 26;
                }



        }
        
        partial_sum(net.begin(), net.end(), net.begin());
        
        int i = 0;
        for(char &c : s) {
            
            int res = ((c - 'a') + net[i])% 26;
                     res = (res + 26)%26;
            c = 'a' + res;
            i++;
        }
        
        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to perform a series of shifts on a given string `s` where each shift operation consists of changing a range of characters within the string by a specific amount. Each shift operation is defined by a triplet `[start, end, direction]`:
- `start`: The starting index of the substring to be shifted.
- `end`: The ending index of the substring to be shifted.
- `direction`: A value of `1` means shifting the characters forward by one position in the alphabet, and a value of `-1` means shifting the characters backward by one position.

The goal is to apply all these shift operations to the string `s` and return the final string after all the shifts are applied.

### Approach

This problem can be efficiently solved using the **difference array** technique combined with **prefix sum**. The basic idea is to record the net effect of each shift operation over the string in a separate array and then apply the cumulative shifts using prefix sums.

#### Key Insights:
1. **Difference Array (Net Effect)**: For each shift operation, instead of updating all characters in the given range `[start, end]`, we can just record the effect of the operation at the boundaries of the range. By doing this, we avoid multiple redundant updates and make the solution more efficient.
2. **Prefix Sum**: After recording the changes in the difference array, we can use the **partial sum** (prefix sum) to accumulate the shifts across the string.
3. **Modulo 26 Arithmetic**: Since there are 26 letters in the English alphabet, we must ensure that the shifts wrap around after 26 characters, i.e., after `z` comes `a` again. This requires us to use modulo arithmetic.

### Code Breakdown (Step by Step)

1. **Function Definition**:
   ```cpp
   string shiftingLetters(string s, vector<vector<int>>& sh) {
   ```
   The function `shiftingLetters` takes two inputs:
   - `s`: A string containing lowercase English letters.
   - `sh`: A vector of shift operations, where each element is a triplet `[start, end, direction]`.

2. **Initialization**:
   ```cpp
   int n = s.length();
   vector<int> net(n, 0);
   ```
   - `n`: The length of the string `s`.
   - `net`: A vector of size `n`, initialized with zeros. This array will record the net effect of all shift operations.

3. **Applying Shift Operations (Difference Array Technique)**:
   ```cpp
   for(auto &x: sh) {
       int k = x[2] == 1? 1 : -1;  // Direction of shift: 1 for forward, -1 for backward
       net[x[0]] += k;             // Add shift at the start index
       if(x[1] + 1 < n) {
           net[x[1] + 1] -= k;     // Subtract shift after the end index
       }
   }
   ```
   - We loop through each shift operation in `sh`. For each operation, we determine the direction of the shift (`1` for forward, `-1` for backward) and apply the change to the `net` array:
     - For the start index `x[0]`, we add the direction (`+1` or `-1`).
     - For the index `x[1] + 1`, we subtract the direction to cancel out the effect after the end of the range.
   - This creates a "difference array," where the effect of each operation is recorded at the boundaries.

4. **Prefix Sum Calculation**:
   ```cpp
   partial_sum(net.begin(), net.end(), net.begin());
   ```
   - We calculate the **partial sum** of the `net` array, which effectively accumulates all the shifts into a cumulative effect. After this, each element in `net` contains the total shift applied to the corresponding index of the string `s`.

5. **Applying the Shifts to the String**:
   ```cpp
   int i = 0;
   for(char &c : s) {
       int res = ((c - 'a') + net[i]) % 26;   // Calculate new character after shift
       res = (res + 26) % 26;                  // Ensure result is positive
       c = 'a' + res;                          // Convert back to character
       i++;
   }
   ```
   - We loop through each character in the string `s`.
   - For each character, we calculate the new character after applying the accumulated shift:
     - `c - 'a'` converts the character to its index (0 for 'a', 1 for 'b', ..., 25 for 'z').
     - Adding the cumulative shift (`net[i]`) adjusts the index.
     - Modulo 26 ensures the result wraps around correctly within the alphabet (e.g., after 'z', it should go back to 'a').
     - We also apply `(res + 26) % 26` to ensure that the result remains positive, handling cases where the shift might result in a negative index.
     - Finally, we convert the result back to a character by adding `'a'` to the index and updating the character in `s`.

6. **Return the Final String**:
   ```cpp
   return s;
   ```
   - After applying all shifts to the string, we return the modified string `s`.

### Complexity

1. **Time Complexity**:
   - **O(m + n)**, where `m` is the number of shift operations (`sh.size()`) and `n` is the length of the string `s`.
   - The loop over the shift operations takes **O(m)** time because we process each operation in constant time.
   - The prefix sum calculation takes **O(n)** time, and applying the shifts to the string also takes **O(n)** time.
   - Therefore, the overall time complexity is **O(m + n)**, which is efficient for large inputs.

2. **Space Complexity**:
   - The space complexity is **O(n)** due to the `net` array, which stores the cumulative shifts for each index in the string `s`.
   - No additional significant space is used besides the input and output, making the space complexity linear in terms of the length of the string.

### Conclusion

This solution efficiently solves the problem of applying multiple shift operations to a string by using the **difference array technique** and **prefix sum**. The difference array allows us to record the effect of each shift operation at the boundaries, and the prefix sum allows us to efficiently accumulate all the shifts in a single pass. This reduces the need to repeatedly iterate over the string for each operation, making the solution optimal with a time complexity of **O(m + n)**, where `m` is the number of operations and `n` is the length of the string.

The use of **modulo 26 arithmetic** ensures that the shifts are applied correctly within the bounds of the English alphabet, handling both forward and backward shifts. This makes the solution both correct and efficient for large inputs.

In summary, the combination of the difference array technique with prefix sums provides an elegant and efficient way to apply range updates, and this solution is a great example of how advanced array manipulation can solve string transformation problems in an optimal manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/shifting-letters-ii/description/)

---
{{< youtube dWp_egpuwbU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
