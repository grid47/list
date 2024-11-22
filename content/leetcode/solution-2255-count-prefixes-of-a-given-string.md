
+++
authors = ["grid47"]
title = "Leetcode 2255: Count Prefixes of a Given String"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2255: Count Prefixes of a Given String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ctp3MD4jiGg"
youtube_upload_date="2022-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ctp3MD4jiGg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() > s.size()) continue;
            bool flag = true;
            for(int i = 0; i < x.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to count how many strings in a given list of words are prefixes of a string `s`. A prefix is defined as a substring at the beginning of the string that matches exactly with the start of `s`. The goal is to efficiently count the number of strings in the `words` list that are prefixes of `s`.

### Approach

To solve this problem, we will iterate through each word in the `words` list and check if it is a prefix of the string `s`. A prefix is defined as a substring starting at index `0` and having a length equal to or less than the length of `s`. For each word, we will compare its characters to the corresponding characters of `s`. If all characters match, we will count that word as a prefix.

#### Steps:

1. **Initialize a Counter**: We'll start by initializing a counter `cnt` to zero. This will keep track of the number of prefixes found.

2. **Iterate Through the Words**: For each word in the list `words`, check if it is a prefix of the string `s`.

3. **Check Length Condition**: If a word is longer than `s`, it cannot be a prefix of `s`. We can skip these words immediately.

4. **Character-by-Character Comparison**: For words that are shorter than or equal to the length of `s`, we compare each character of the word with the corresponding character in `s`. If all characters match, it means the word is a prefix.

5. **Count the Prefixes**: If the word matches the prefix condition, we increment the counter `cnt`.

6. **Return the Count**: After processing all the words, we return the count of prefixes.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Counter

```cpp
int cnt = 0;
```

- We start by initializing a variable `cnt` to `0`. This variable will store the number of valid prefixes found during the iteration over the `words` list.

#### Step 2: Iterate Over Each Word

```cpp
for(string x: words) {
```

- We loop over each string `x` in the `words` vector. The goal is to check whether each word `x` is a prefix of the string `s`.

#### Step 3: Check Length Condition

```cpp
if(x.size() > s.size()) continue;
```

- Before comparing the characters of `x` with `s`, we first check if the length of the current word `x` is greater than the length of `s`. If `x` is longer than `s`, it cannot be a prefix, and we continue with the next word in the list.

#### Step 4: Compare Characters

```cpp
bool flag = true;
for(int i = 0; i < x.size(); i++) {
    if(x[i] != s[i]) {
        flag = false;
        break;
    }
}
```

- We use a `for` loop to compare each character of the word `x` with the corresponding character of `s`.
- If any character doesn't match, we set `flag` to `false` and break the loop early because we know `x` is not a prefix.
- If all characters match, `flag` remains `true`, indicating that `x` is a valid prefix of `s`.

#### Step 5: Count the Prefixes

```cpp
if(flag) cnt++;
```

- If `flag` is `true`, meaning all characters of `x` matched the corresponding characters in `s`, we increment the counter `cnt`.

#### Step 6: Return the Result

```cpp
return cnt;
```

- After processing all the words, we return the value of `cnt`, which now holds the number of words that are prefixes of `s`.

### Complexity

#### Time Complexity

1. **Iterating Through Words**: We loop through all the words in the `words` vector. The number of words is `n`, so this part takes \( O(n) \), where `n` is the number of words.
2. **Character-by-Character Comparison**: For each word `x`, we compare each of its characters with the corresponding characters in `s`. The length of the word is at most \( m \) (the length of `s`), so the comparison for each word takes \( O(m) \).

Thus, the overall time complexity is \( O(n \times m) \), where:
- `n` is the number of words in the list `words`,
- `m` is the length of the string `s`.

#### Space Complexity

The space complexity is \( O(1) \) since we are using only a constant amount of extra space aside from the input vectors.

### Conclusion

This solution efficiently counts how many words in the `words` list are prefixes of the string `s`. The approach involves iterating over each word, checking its length, and then performing a character-by-character comparison to determine if the word is a prefix of `s`. By leveraging simple string comparisons and early exits when the word is too long to be a prefix, the solution efficiently handles the task.

The time complexity of \( O(n \times m) \) is acceptable for typical problem constraints, where `n` is the number of words and `m` is the length of the string `s`. The space complexity of \( O(1) \) makes this solution very space-efficient. Overall, this approach provides a simple yet effective way to solve the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-prefixes-of-a-given-string/description/)

---
{{< youtube ctp3MD4jiGg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
