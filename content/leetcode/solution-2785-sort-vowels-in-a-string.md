
+++
authors = ["grid47"]
title = "Leetcode 2785: Sort Vowels in a String"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2785: Sort Vowels in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ESF0Q-rrol0"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/ESF0Q-rrol0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
    }
    string sortVowels(string s) {
        string v;
        copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
            return isVowel(tolower(ch)); 
        });
        sort(begin(v), end(v));
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (isVowel(tolower(s[i])))
                s[i] = v[j++];
        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires sorting only the vowels in a given string while keeping the positions of the consonants unchanged. The vowels in the string should be sorted in ascending order, and their relative positions should be preserved with respect to the consonants.

### Approach

The strategy to solve this problem is divided into the following steps:
1. **Extract all vowels** from the string while ignoring consonants.
2. **Sort the vowels** in ascending order.
3. **Reconstruct the string** by placing the sorted vowels back into their original positions, leaving consonants intact.

We can achieve this by using a combination of the `copy_if` function to collect vowels, `sort` to sort the vowels, and a simple loop to replace the vowels back into the string.

### Code Breakdown (Step by Step)

#### Step 1: Identify Vowels
```cpp
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i';
}
```
- This function checks whether a given character `ch` is a vowel. The vowels are considered to be the characters `'a'`, `'e'`, `'i'`, `'o'`, and `'u'` (in lowercase). The function returns `true` if `ch` is a vowel and `false` otherwise.

#### Step 2: Extract Vowels from the String
```cpp
string sortVowels(string s) {
    string v;
    copy_if(begin(s), end(s), back_inserter(v), [&](char ch) { 
        return isVowel(tolower(ch)); 
    });
```
- We create an empty string `v` to store the vowels from the string `s`.
- `copy_if(begin(s), end(s), back_inserter(v), ...)` is a standard library function that copies elements from the range `[begin(s), end(s))` into the string `v`, but only if the element satisfies the condition in the predicate. Here, the predicate is checking if the character is a vowel. 
- We use `tolower(ch)` to ensure that the function works for both uppercase and lowercase vowels. This is done to handle cases where vowels might be in uppercase in the input string.

#### Step 3: Sort the Vowels
```cpp
    sort(begin(v), end(v));
```
- After collecting all the vowels from the string `s` into `v`, we use the `sort` function from the standard library to sort the characters in the string `v`. This ensures that the vowels will be in ascending order, which is the requirement of the problem.

#### Step 4: Reconstruct the String
```cpp
    for (int i = 0, j = 0; i < s.size(); ++i)
        if (isVowel(tolower(s[i])))
            s[i] = v[j++];
```
- In this step, we iterate through the original string `s`.
- For each character `s[i]`, we check if it is a vowel (using `isVowel(tolower(s[i]))`). If it is a vowel, we replace it with the next vowel from the sorted list `v`. The variable `j` keeps track of the index of the next vowel in `v` that we need to place into `s`.
- The index `j` is incremented after each vowel replacement.

#### Step 5: Return the Result
```cpp
    return s;
}
```
- After replacing all vowels in `s` with the sorted vowels from `v`, we return the modified string `s`.

### Complexity

#### Time Complexity:
- **O(n log n)**: The main time complexity comes from sorting the vowels. Sorting requires `O(n log n)` time, where `n` is the number of vowels. The process of copying vowels and reconstructing the string both take **O(n)** time, but the sorting step dominates the complexity, making the overall time complexity **O(n log n)**.
- Here, `n` refers to the length of the string `s`.

#### Space Complexity:
- **O(n)**: We need an additional string `v` to store the vowels, and the size of this string is proportional to the number of vowels in the input string. Therefore, the space complexity is **O(n)**, where `n` is the length of the string `s`.

### Conclusion

This solution provides an efficient approach to solving the problem of sorting only the vowels in a string while keeping the positions of the consonants unchanged. The algorithm performs the following steps:
1. Extracts the vowels from the string.
2. Sorts the vowels in ascending order.
3. Replaces the vowels in the original string with the sorted vowels.

The algorithm's time complexity is dominated by the sorting step, making it **O(n log n)**, where `n` is the number of vowels in the string. The space complexity is **O(n)** due to the use of an additional string to store the vowels.

This solution is both time-efficient and space-efficient, handling various edge cases like uppercase vowels and strings with no vowels. It is easy to understand and implement using standard C++ functions like `copy_if`, `sort`, and `tolower`.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-vowels-in-a-string/description/)

---
{{< youtube ESF0Q-rrol0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
