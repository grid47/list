
+++
authors = ["grid47"]
title = "Leetcode 2351: First Letter to Appear Twice"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2351: First Letter to Appear Twice in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "zIFHijNYeCE"
youtube_upload_date="2022-07-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zIFHijNYeCE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char c:s){
            v[c-'a']++;
            if(v[c-'a']>1)return c;
        }
        return 'a';
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the first character in a given string `s` that repeats. If no character repeats, the function should return `'a'`. The string `s` consists only of lowercase English letters.

We need to identify the first character in the string that occurs more than once and return that character. If all characters are unique (no repetition), return the character `'a'`.

### Approach

To solve this problem, we need to efficiently identify the first repeating character in the string. A brute-force solution would involve comparing each character with all the other characters, but that would take too much time, especially for larger strings.

Instead, we can use a more efficient approach by leveraging an auxiliary data structure (an array or hash map) to track the occurrence of characters as we traverse the string. This way, we can check for repetition in constant time for each character, significantly improving the efficiency of the solution.

### Optimized Approach Using an Array

1. **Character Tracking**:  
   Since the string contains only lowercase English letters (from `'a'` to `'z'`), we can use a fixed-size array of length 26 to store the count of each character. Each index of the array corresponds to a character (where `'a'` maps to index 0, `'b'` maps to index 1, and so on).

2. **Traversing the String**:  
   We iterate through the string character by character. For each character, we calculate its corresponding index in the array using the expression `c - 'a'`, where `c` is the current character. If the value at the corresponding index in the array is greater than 0, it means that the character has been encountered before, so we immediately return that character as it is the first repeated one.

3. **Returning `'a'`**:  
   If the loop completes without finding any repeated character, it means no character in the string repeats. In this case, the function should return `'a'`.

This approach ensures that we are able to solve the problem efficiently in linear time, O(n), where `n` is the length of the string. The space complexity is O(1), as the array size is fixed (26 elements).

### Code Breakdown (Step by Step)

#### 1. **Array Initialization**
```cpp
vector<int> v(26);
```
- We initialize a vector `v` of size 26, which will be used to track the frequency of each character. Each index of the vector corresponds to a specific letter in the alphabet, where:
  - `v[0]` corresponds to the count of `'a'`,
  - `v[1]` corresponds to the count of `'b'`,
  - ...
  - `v[25]` corresponds to the count of `'z'`.

#### 2. **Iterating Through the String**
```cpp
for (char c : s) {
    v[c - 'a']++;
    if (v[c - 'a'] > 1) return c;
}
```
- We loop through each character `c` in the input string `s`.
- For each character `c`, we compute its corresponding index in the array `v` by subtracting the ASCII value of `'a'` from `c` (i.e., `c - 'a'`). This gives us a value between 0 and 25, which corresponds to the character's position in the alphabet.
- We increment the count at the corresponding index in the array `v`. If the count at that index becomes greater than 1, it means the character `c` has been encountered before, and we immediately return that character as the first repeated character.

#### 3. **Returning `'a'` if No Repetition is Found**
```cpp
return 'a';
```
- If no character is repeated by the time the loop finishes, we return `'a'` as the default result.

### Time Complexity

The time complexity of the solution is **O(n)**, where `n` is the length of the string `s`. This is because we iterate through the string exactly once, and for each character, we perform constant-time operations (array indexing and updating counts).

### Space Complexity

The space complexity of this solution is **O(1)**, as the size of the auxiliary array `v` is fixed at 26, regardless of the size of the input string. The space usage does not scale with the size of the input string.

### Edge Cases Handled

1. **String with No Repeated Characters**:  
   If the string has no repeated characters, the function will return `'a'` as specified in the problem statement.
   
2. **String with Only One Character**:  
   If the string consists of a single character (e.g., `"a"`), there will be no repetition, and the function will return `'a'`.

3. **String with Multiple Repetitions**:  
   If the string contains multiple repeated characters, the function will return the first character that repeats.

### Example Walkthrough

Let's walk through an example to understand the flow of the solution:

#### Input 1: `"abca"`
- Initially, `v = [0, 0, 0, ..., 0]` (all values are 0).
- The first character is `'a'`:
  - `v[0]` is incremented to 1.
- The second character is `'b'`:
  - `v[1]` is incremented to 1.
- The third character is `'c'`:
  - `v[2]` is incremented to 1.
- The fourth character is `'a'`:
  - `v[0]` is incremented to 2.
  - Since `v[0] > 1`, we immediately return `'a'`.

#### Input 2: `"abc"`
- Initially, `v = [0, 0, 0, ..., 0]`.
- The first character is `'a'`:
  - `v[0]` is incremented to 1.
- The second character is `'b'`:
  - `v[1]` is incremented to 1.
- The third character is `'c'`:
  - `v[2]` is incremented to 1.
- No character repeats, so we return `'a'`.

### Conclusion

This solution efficiently solves the problem of finding the first repeated character in a string by using a fixed-size array to track the occurrence of each character. It runs in linear time, O(n), and uses constant space, O(1), which makes it highly efficient even for large strings.

By iterating through the string once and leveraging an array to track character frequencies, we ensure that the solution is optimal both in terms of time complexity and space complexity. The solution also gracefully handles edge cases where no characters repeat or where the string contains only one character.

[`Link to LeetCode Lab`](https://leetcode.com/problems/first-letter-to-appear-twice/description/)

---
{{< youtube zIFHijNYeCE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
