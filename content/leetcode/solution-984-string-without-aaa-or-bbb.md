
+++
authors = ["grid47"]
title = "Leetcode 984: String Without AAA or BBB"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 984: String Without AAA or BBB in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
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
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if(B > A) return strWithout3a3b(B, A, b, a);
        while(A-- > 0) {
            res += a;
            if(A > B) res += a, A--;
            if(B-->0) res += b;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to generate a string consisting of characters `'a'` and `'b'`, where the number of `'a'` characters is `A` and the number of `'b'` characters is `B`. The string should be generated such that there are no three consecutive characters that are the same. In other words, the string should not contain three consecutive `'a'` or three consecutive `'b'`.

The task is to return a valid string satisfying the constraints, or an empty string if no such string can be formed.

### Approach

To solve this problem, the main challenge is ensuring that no three consecutive characters of the same type appear in the resulting string. To achieve this, we can adopt a greedy approach:

1. **Greedy Strategy**: 
   - We always aim to add the character with the higher count first to the string. This ensures that we prioritize the character that still has more occurrences to be placed.
   - After placing the first character, if the count of the first character is still higher than the second, we add the same character again.
   - Finally, we add the other character (if any is left) to maintain the balance between the two characters, ensuring that neither `'a'` nor `'b'` appears three times consecutively.

2. **Base Case Handling**:
   - If `A` (the count of `'a'`) is greater than `B` (the count of `'b'`), we simply swap the values of `A` and `B` and swap the characters `'a'` and `'b'` accordingly.
   - This guarantees that the character with the higher count will always be processed first, regardless of whether it's `'a'` or `'b'`.

3. **Greedy Placement**:
   - For each iteration, the logic tries to place two occurrences of the character that appears more frequently (if doing so doesn’t violate the three-consecutive rule), followed by one occurrence of the character that appears less frequently.

4. **Termination**:
   - The loop continues until all occurrences of both characters have been placed in the result string.

### Code Breakdown (Step by Step)

#### 1. **Initial Setup**:
```cpp
string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
    if(B > A) return strWithout3a3b(B, A, b, a);
```
- The function `strWithout3a3b` takes in four parameters: `A`, `B`, the counts of characters `'a'` and `'b'`, and two additional default parameters for the characters `a` and `b`. The result string `res` is initialized as an empty string.
- If `B > A` (i.e., there are more `'b'` characters than `'a'`), we swap the roles of `'a'` and `'b'` by calling the function recursively. This simplifies the logic, as it ensures that the character with the higher count is always processed first.

#### 2. **Adding Characters**:
```cpp
while(A-- > 0) {
    res += a;
    if(A > B) res += a, A--;
    if(B-->0) res += b;
}
```
- We start a `while` loop that continues until all characters are placed in the result string. For each iteration, we first add the character `a` to the result string.
- If the remaining count of `a` is still greater than the remaining count of `b` (i.e., `A > B`), we add another `a` to avoid breaking the rule of not having more than two consecutive `a` characters.
- Finally, if there are any remaining `b` characters (i.e., `B > 0`), we add a `b` to the result string.
- The logic ensures that the string is built progressively without exceeding the allowed repetition of characters.

#### 3. **Returning the Result**:
```cpp
return res;
```
- Once the loop finishes, all characters have been placed in the result string, and it is returned as the solution.

### Complexity

#### Time Complexity:
- **Time Complexity**: The function operates in **O(A + B)** time because we loop through all the `A` and `B` characters exactly once, placing them into the result string. Each step involves constant-time operations (adding characters and adjusting counters).
  
#### Space Complexity:
- **Space Complexity**: The space complexity is **O(A + B)** since we are constructing the result string `res`, which holds a total of `A + B` characters. The extra space used by the function is negligible, as we only use a few extra variables for the characters and counts.

### Conclusion

This solution efficiently solves the problem by using a greedy approach to build the string step by step. It ensures that the string is constructed in a valid manner by avoiding three consecutive identical characters. The function operates in linear time relative to the total number of characters to be placed (`A + B`), making it scalable for larger inputs. The approach is both time and space efficient, offering a simple yet effective solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/string-without-aaa-or-bbb/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
