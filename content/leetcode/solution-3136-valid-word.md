
+++
authors = ["grid47"]
title = "Leetcode 3136: Valid Word"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3136: Valid Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-sU51QkOwLY"
youtube_upload_date="2024-05-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-sU51QkOwLY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValid(string word) {
        set<char> st;
        bool upper = false, lower = false;
        bool vowel = false, conso = false, number = false;
        
        for(char x : word) {
            
            if(x >= 'a' && x <= 'z') lower = true;
            if(x >= 'A' && x <= 'Z') upper = true;
            st.insert(x);
            if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
               x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                    vowel = true;
            else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
                    conso  = true;
            else if(isdigit(x)) {}
            else    return false;
            
        }
        
        return vowel && conso && st.size() >= 3;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to check if a given word is **valid** based on a series of conditions:
1. The word must contain at least one lowercase letter.
2. The word must contain at least one uppercase letter.
3. The word must contain at least one vowel and at least one consonant.
4. The word must have at least three distinct characters.
5. The word can contain letters and digits but should not contain any special characters.

We need to implement a function `isValid` that takes a string `word` and returns a boolean indicating whether the word satisfies all the above conditions.

### Approach

To solve this problem, we can iterate through each character of the word and keep track of the following:
- Whether the word contains a lowercase letter (`lower`).
- Whether the word contains an uppercase letter (`upper`).
- Whether the word contains a vowel (`vowel`).
- Whether the word contains a consonant (`conso`).
- A set to ensure the word contains at least three distinct characters (`st`).

The conditions can be checked during the iteration as follows:
- For lowercase letters, set the `lower` flag to `true`.
- For uppercase letters, set the `upper` flag to `true`.
- For vowels (both uppercase and lowercase), set the `vowel` flag to `true`.
- For consonants (letters that are not vowels), set the `conso` flag to `true`.
- For any other character (digits and special characters), ignore the character or immediately return `false` if the character is invalid.

After processing all characters, we check the following conditions:
1. Both `vowel` and `conso` should be `true` (the word must contain both a vowel and a consonant).
2. The size of the set `st` must be at least `3` (the word must have at least three distinct characters).
3. Both `lower` and `upper` should be `true` (the word must contain both lowercase and uppercase letters).

If all these conditions are met, return `true`, otherwise return `false`.

### Code Breakdown

#### Step 1: Initialize Variables

```cpp
set<char> st;
bool upper = false, lower = false;
bool vowel = false, conso = false, number = false;
```
Here, we initialize:
- `st` as a set to track distinct characters.
- `upper` and `lower` as booleans to track the presence of uppercase and lowercase letters, respectively.
- `vowel` and `conso` as booleans to track the presence of vowels and consonants, respectively.
- `number` is unused and could be removed, as we only need to check for vowels, consonants, and distinct characters.

#### Step 2: Iterate Through Each Character in the Word

```cpp
for(char x : word) {
    if(x >= 'a' && x <= 'z') lower = true;
    if(x >= 'A' && x <= 'Z') upper = true;
    st.insert(x);
```
- We loop through each character `x` in the word.
- If `x` is a lowercase letter, set `lower = true`.
- If `x` is an uppercase letter, set `upper = true`.
- Add `x` to the set `st` to track distinct characters.

#### Step 3: Check for Vowels, Consonants, and Invalid Characters

```cpp
if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
   x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    vowel = true;
else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
    conso  = true;
else if(isdigit(x)) {}
else return false;
```
- If `x` is a vowel (either uppercase or lowercase), set `vowel = true`.
- If `x` is a consonant (any letter that is not a vowel), set `conso = true`.
- If `x` is a digit, we do nothing (we can ignore digits as they are allowed).
- If `x` is neither a letter nor a digit (i.e., it's a special character), we immediately return `false` because the word contains an invalid character.

#### Step 4: Check Final Conditions

```cpp
return vowel && conso && st.size() >= 3;
```
After the loop:
- We check if the word contains both a vowel and a consonant (`vowel && conso`).
- We check if the word contains at least three distinct characters by checking the size of the set `st` (`st.size() >= 3`).

If both conditions are met, the function returns `true`, indicating that the word is valid. Otherwise, it returns `false`.

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the length of the string `word`. We iterate through each character in the word once, performing constant-time operations (set insertions, comparisons, etc.) for each character.

#### Space Complexity:
- **O(k)**, where `k` is the number of distinct characters in the word (in the worst case, `k` could be `n`, the length of the word). The space complexity comes from the set `st` that stores distinct characters.

### Conclusion

This approach efficiently checks if a given word satisfies all the required conditions for being "valid". By iterating through the word once and using boolean flags to track whether the word contains the necessary components (uppercase, lowercase, vowels, consonants), the algorithm ensures that we make the necessary checks with minimal computational overhead. The use of a set helps track distinct characters, and the logic is designed to immediately exit early if an invalid character is found. This solution is simple, clear, and has linear time complexity, making it suitable for handling reasonably large input strings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-word/description/)

---
{{< youtube -sU51QkOwLY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
