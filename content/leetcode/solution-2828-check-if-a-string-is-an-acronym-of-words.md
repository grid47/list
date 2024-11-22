
+++
authors = ["grid47"]
title = "Leetcode 2828: Check if a String Is an Acronym of Words"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2828: Check if a String Is an Acronym of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "GcgV-AtAmkg"
youtube_upload_date="2023-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/GcgV-AtAmkg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        for(string w: words)
            res += w[0];
        return s == res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining if a given string `s` is an acronym formed from a list of words in `words`. An acronym is formed by concatenating the first letter of each word in the list. Given a list of words and a string `s`, we need to check if `s` matches the acronym formed by the first letter of each word in the list. The input consists of a vector of strings `words` and a string `s`, and the task is to return `true` if `s` is the acronym of the words in `words`, otherwise return `false`.

### Approach

To solve this problem, we can break it down into the following steps:
1. **Extract the First Letters**: The acronym is formed by concatenating the first letter of each word in the list `words`. Thus, the first step is to iterate through each word in the list and take the first character.
2. **Compare with the Target String**: Once we have the acronym formed by the first letters, we simply compare it with the given string `s`. If the two strings are equal, return `true`; otherwise, return `false`.

### Code Breakdown (Step by Step)

#### 1. Function Declaration

```cpp
bool isAcronym(vector<string>& words, string s) {
```

- The function `isAcronym` is defined with two parameters:
  - `words`: a vector of strings, where each string represents a word.
  - `s`: a string which is the acronym that we need to check.

#### 2. Initialize an Empty String `res`

```cpp
    string res = "";
```

- We declare a string `res` to store the acronym formed by the first letter of each word in the `words` vector.

#### 3. Iterate Over the Words to Build the Acronym

```cpp
    for(string w: words)
        res += w[0];
```

- We loop through each word `w` in the `words` vector.
  - `w[0]` retrieves the first character of the word `w`.
  - The character `w[0]` is then appended to the `res` string using the `+=` operator.
- After this loop, `res` will contain the concatenated first letters of all words in the `words` list.

#### 4. Return the Comparison Result

```cpp
    return s == res;
}
```

- Finally, we compare the string `s` with the string `res` formed from the first letters of the words.
  - If they are equal (`s == res`), the function returns `true`, indicating that `s` is indeed the acronym.
  - Otherwise, it returns `false`.

#### Summary of the Code Execution

1. **Initialization**: A string `res` is initialized to an empty string to store the acronym.
2. **Acronym Formation**: A loop iterates through the `words` vector, appending the first letter of each word to `res`.
3. **Comparison**: The function then checks if the string `s` is equal to the formed acronym `res` and returns the result.

### Complexity

1. **Time Complexity**:
   - The time complexity of this algorithm is **O(n)**, where `n` is the number of words in the `words` vector. 
     - The loop that iterates through the vector `words` takes **O(n)** time, where each word is processed in constant time.
     - Concatenating characters to the string `res` is a constant time operation for each word since we only append a single character at a time.
   - The final comparison (`s == res`) also takes **O(n)** time in the worst case, where `n` is the length of the strings being compared. Since the length of `s` will be the same as the number of words in `words`, this comparison step is also linear in terms of the number of words.

2. **Space Complexity**:
   - The space complexity is **O(n)**, where `n` is the number of words in the `words` vector, because we are storing the acronym in the string `res`. The space used by `res` will be proportional to the number of words in `words`.

### Conclusion

This problem is solved efficiently using a simple approach that:
1. **Builds the Acronym**: By concatenating the first letter of each word in the `words` vector.
2. **Compares the Acronym with the Target String**: We compare the constructed acronym (`res`) with the given string `s` to determine if they are identical.

The solution runs in **O(n)** time, where `n` is the number of words in the input vector, making it efficient for large input sizes. The space complexity is also **O(n)** due to the space required to store the acronym string. This approach is optimal for the problem, offering a clear and straightforward solution using basic string operations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/)

---
{{< youtube GcgV-AtAmkg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
