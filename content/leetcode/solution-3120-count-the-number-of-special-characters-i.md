
+++
authors = ["grid47"]
title = "Leetcode 3120: Count the Number of Special Characters I"
date = "2023-12-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3120: Count the Number of Special Characters I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "VV4TTRQ5l0s"
youtube_upload_date="2024-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/VV4TTRQ5l0s/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> ch;
        for(char x: word)
                ch.insert(x);
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(ch.count('a' + i) && ch.count('A' + i))
                cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to count the number of special characters in a given string `word`. A "special character" is defined as any character that appears both in its lowercase and uppercase forms within the string. For example, if the string contains both `'a'` and `'A'`, then `a` is considered a special character.

Given the string `word`, the goal is to count how many characters appear in both their lowercase and uppercase forms. We are required to implement a function that takes this string and returns the count of such "special characters."

For instance:
- For the string `"aAabB"`, the answer is `2` because `'a'` and `'b'` appear in both uppercase and lowercase forms.
- For the string `"abc"`, the answer is `0` because no character appears in both forms.

### Approach

The approach to solving this problem is to:
1. Use a data structure to store the characters in the string.
2. Check for each character in the alphabet if it appears in both lowercase and uppercase forms.
3. Count how many such special characters exist in the string.

#### Approach Outline:
1. **Store characters in a set**: A `set` data structure can be used to keep track of the unique characters present in the string. Since we only care about the presence of characters and not their frequency, a set is ideal because it automatically handles duplicates.
2. **Check for both lowercase and uppercase**: For each character from 'a' to 'z', check if both its lowercase and uppercase versions are present in the set.
3. **Count the special characters**: If both versions of a character (lowercase and uppercase) are present in the set, increase the count of special characters.
4. **Return the count**: After iterating over all characters, return the count of special characters.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Set
```cpp
set<char> ch;
```
- A set `ch` is declared to store the unique characters from the input string `word`. The set is chosen because it automatically handles duplicate characters, ensuring that each character appears only once.

#### Step 2: Insert Characters into the Set
```cpp
for(char x: word)
    ch.insert(x);
```
- We iterate over the string `word` and insert each character `x` into the set `ch`. The `insert` method ensures that each character appears only once in the set, even if it appears multiple times in the string.

#### Step 3: Initialize the Counter
```cpp
int cnt = 0;
```
- A counter `cnt` is initialized to zero. This will keep track of the number of special characters.

#### Step 4: Iterate Over the Alphabet and Check for Special Characters
```cpp
for(int i = 0; i < 26; i++) {
    if(ch.count('a' + i) && ch.count('A' + i))
        cnt++;
}
```
- The loop iterates over all 26 letters of the alphabet (`'a'` to `'z'`).
- For each letter, we check if both its lowercase (`'a' + i`) and uppercase (`'A' + i`) versions are present in the set `ch`. The `count` method of the set is used to check if a character is present in the set. It returns `1` if the character is present, and `0` if it is not.
- If both versions (lowercase and uppercase) of a character are found, we increment the counter `cnt`.

#### Step 5: Return the Result
```cpp
return cnt;
```
- After checking all 26 letters, we return the value of `cnt`, which represents the number of special characters in the string.

### Complexity

#### Time Complexity:
- **O(n + 26)**, where `n` is the length of the input string `word`.
  - The first part of the algorithm involves iterating through the string and inserting each character into the set. This takes **O(n)** time.
  - The second part involves iterating over the alphabet (26 characters) and checking if both the lowercase and uppercase versions of each letter exist in the set. This part takes **O(26)** time, which is constant.
  - Overall, the time complexity is dominated by the first part, so the time complexity is **O(n)**.

#### Space Complexity:
- **O(n)**, where `n` is the length of the input string `word`.
  - The space complexity is determined by the size of the set `ch`, which can hold up to `n` unique characters (in the worst case). Thus, the space complexity is **O(n)**.

### Conclusion

This solution efficiently counts the number of "special characters" in the string, where a special character is defined as a character that appears both in its lowercase and uppercase forms. The use of a set ensures that each character is counted only once, and the checking for both uppercase and lowercase versions of each character is done in constant time.

The algorithm has a time complexity of **O(n)**, which is optimal for this type of problem, as we must inspect each character in the string. The space complexity is also **O(n)**, which is manageable for typical input sizes.

This solution is both time-efficient and space-efficient, making it a great choice for solving the problem in real-world scenarios where performance is important. By leveraging the properties of sets and the simplicity of iterating over the alphabet, the solution provides a clean and effective approach to solving the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

---
{{< youtube VV4TTRQ5l0s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
