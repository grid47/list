
+++
authors = ["grid47"]
title = "Leetcode 2451: Odd String Difference"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2451: Odd String Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mxdN0xJiJDc"
youtube_upload_date="2022-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mxdN0xJiJDc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    string difference(string& s) {
        string d;
        
        for (int i = 0; i < s.size() - 1; i++) {
            d += s[i + 1] - s[i];
        }
        
        return d;
    }
public:
    string oddString(vector<string>& words) {
        int  n = words[0].size();
        unordered_map<string, vector<string>> mp;
        for (auto &it : words) {
            mp[difference(it)].push_back(it);
        }
        
        for (auto &it : mp) {
            if (it.second.size() == 1) return it.second[0];
        }
        
        return "";
    }
};
{{< /highlight >}}
---

The given code solves a problem where we need to identify a string in a list of strings that has a unique "difference pattern" compared to the other strings. The difference pattern refers to the differences between consecutive characters in the string. The problem is to find the string that has a unique pattern of character differences. Let's break down the problem, the approach, and the code in detail.

### Problem Statement

We are provided with a list of strings where each string has the same length. Our task is to find the string in the list that has a unique pattern of character differences between consecutive characters compared to the other strings. A character difference is calculated as the difference between the ASCII values of two consecutive characters in the string.

For example, given a string "abc", the differences between consecutive characters are:
- Difference between 'b' and 'a' = 1
- Difference between 'c' and 'b' = 1

Thus, the difference pattern for "abc" would be [1, 1].

If we have a list of strings such as ["abc", "abd", "aec"], the task is to find the string that has a unique pattern of differences. If "abc" and "abd" share the same difference pattern but "aec" has a different pattern, then "aec" is the string with the unique difference pattern.

### Approach

To solve this problem, we can break it down into the following steps:

1. **Difference Calculation**: We calculate the difference pattern for each string by iterating over each pair of consecutive characters in the string and finding the difference in their ASCII values.
   
2. **Group Strings by Difference Patterns**: Once we calculate the difference pattern for each string, we can group the strings based on their respective difference patterns. This will allow us to identify the string with a unique pattern.

3. **Identify the Odd String**: After grouping the strings, we check which group contains exactly one string. This string will be the one with the unique difference pattern.

4. **Return the Odd String**: Once we identify the string with the unique difference pattern, we return it.

### Code Breakdown

#### `difference` Function

This function calculates the difference pattern for a given string `s`. It iterates through the string and computes the difference between consecutive characters in terms of their ASCII values. The resulting differences are stored in a new string `d`.

```cpp
string difference(string& s) {
    string d;
    
    // Loop through the string to calculate differences
    for (int i = 0; i < s.size() - 1; i++) {
        d += s[i + 1] - s[i];
    }
    
    return d;
}
```

**Explanation**:
- We initialize an empty string `d` to store the difference pattern.
- We loop through the string from the first character to the second last character (because we are comparing each character with its next neighbor).
- In each iteration, we calculate the difference between consecutive characters (`s[i + 1] - s[i]`) and append this difference to the string `d`.
- Finally, we return the string `d`, which contains the difference pattern for the string `s`.

#### `oddString` Function

This is the main function that solves the problem. It takes a vector of strings `words` as input and returns the string that has a unique difference pattern.

```cpp
string oddString(vector<string>& words) {
    int  n = words[0].size();  // Get the length of the first word
    unordered_map<string, vector<string>> mp;  // Map to store difference patterns as keys, with corresponding words as values
    
    // Loop through each word to calculate its difference pattern
    for (auto &it : words) {
        mp[difference(it)].push_back(it);
    }
    
    // Loop through the map to find the group with exactly one word
    for (auto &it : mp) {
        if (it.second.size() == 1) return it.second[0];  // Return the word with unique difference pattern
    }
    
    return "";
}
```

**Explanation**:
- First, we retrieve the length of the first word in the `words` vector (`n = words[0].size()`). This is useful for ensuring that all words in the list have the same length.
- We then create an unordered map `mp`, where each key is a string representing a difference pattern, and the value is a vector of strings that share that pattern.
- We iterate over each string in `words`, calculate its difference pattern using the `difference` function, and store the string in the map with its corresponding difference pattern as the key.
- After grouping the strings by their difference patterns, we loop through the map and check for the group that contains exactly one string. This is the string with the unique difference pattern.
- If we find such a string, we return it. If no such string exists, we return an empty string `""`.

### Complexity

#### Time Complexity:
- The time complexity of the `difference` function is **O(k)**, where `k` is the length of the string. This is because we iterate through the string once to calculate the differences.
- The time complexity of the `oddString` function is **O(m * k)**, where `m` is the number of words in the `words` vector, and `k` is the length of each word. This is because for each word, we calculate its difference pattern, which takes `O(k)` time.
- The loop that iterates through the unordered map `mp` takes **O(m)** time in the worst case, since there are at most `m` different difference patterns.

Thus, the overall time complexity of the algorithm is **O(m * k)**.

#### Space Complexity:
- The space complexity is **O(m * k)** because in the worst case, each word has a unique difference pattern and we need to store each string in the map. The total space used by the map and the difference patterns is proportional to the number of words and the length of each word.

### Conclusion

This solution effectively solves the problem by calculating the difference patterns for each word and grouping the words based on their patterns. The unique word is identified by checking the map for a group that contains exactly one word. The time and space complexities are both efficient, making this solution scalable for large inputs. The algorithm leverages the unordered map to efficiently group and search for the word with the unique difference pattern.

[`Link to LeetCode Lab`](https://leetcode.com/problems/odd-string-difference/description/)

---
{{< youtube mxdN0xJiJDc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
