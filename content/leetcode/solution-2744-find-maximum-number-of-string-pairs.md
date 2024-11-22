
+++
authors = ["grid47"]
title = "Leetcode 2744: Find Maximum Number of String Pairs"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2744: Find Maximum Number of String Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "f8qWoxowloA"
youtube_upload_date="2023-06-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/f8qWoxowloA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
    int vis[676] = {}, res = 0;
    for (const auto &w : words) {
        res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
        vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
    }
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the maximum number of pairs of strings that can be formed from a list of strings such that each pair consists of two strings that are reverse of each other. The goal is to count how many such pairs exist within the given list of words.

For example:
- Given the list `["cd", "dc", "gg", "cd"]`, we have one pair "cd" and "dc", and the answer would be 1.
- In the list `["ab", "ba", "ab", "ba"]`, we would count the pair "ab" and "ba" twice.

### Approach

The approach used in this solution is based on hashing and indexing. Specifically, we use an integer array `vis` to record which word pairs have already been seen. For each word, we check whether its reverse has been encountered before. If so, we increment the result counter `res` because a valid pair has been found. 

The algorithm works in the following way:
1. **Indexing Words**: For each word, we create an index that uniquely represents the word and its reverse.
2. **Hash Map (or Array)**: We maintain a boolean array `vis[676]`, where each index corresponds to a unique pair of characters.
3. **Counting Pairs**: As we iterate through the list of words, for each word, we check whether its reverse has been seen before using the `vis` array. If it has, we increment the result.
4. **Efficiency**: By using the `vis` array, we avoid repeatedly checking every pair, which makes the solution efficient.

### Code Breakdown (Step by Step)

#### 1. **Initialization of the `vis` Array**

```cpp
int vis[676] = {}, res = 0;
```

- **`vis[676]`**: This array holds boolean values where each index represents a unique combination of two lowercase letters (from 'a' to 'z'). The size 676 is because there are 26 lowercase letters, and the total number of combinations of two letters is \(26 \times 26 = 676\).
- **`res = 0`**: This variable will store the number of valid pairs of words found.

#### 2. **Iterating Over the Words**

```cpp
for (const auto &w : words) {
    res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
    vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
}
```

- **Iterating through the list of words**: The `for` loop goes through each string in the `words` array one by one.
  
#### 3. **Calculating the Reverse Pair Index**

- **First line inside the loop**:

```cpp
res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
```

Here, we are checking if the reverse of the current word has been encountered before.
- **`w[0]` and `w[1]`**: These refer to the two characters in the word `w`. `w[0]` is the first character and `w[1]` is the second character of the word.
- **Index calculation**: The expression `(w[1] - 'a') * 26 + w[0] - 'a'` calculates a unique index based on the two characters of the word. This works as follows:
  - Subtract `'a'` from `w[0]` and `w[1]` to get their zero-based index (0 for 'a', 1 for 'b', etc.).
  - Then, we calculate the index for the reversed string by swapping the positions of `w[0]` and `w[1]`, and use the formula `(w[1] - 'a') * 26 + (w[0] - 'a')` to create a unique index for this reversed pair.
  
  For example, for the word "ab", the reverse is "ba", and the index for "ba" is calculated as `(1 * 26) + 0 = 26`. If "ba" has been encountered before, `vis[26]` will be `true`, and we can increment `res`.

- **Incrementing the result**: If `vis[(w[1] - 'a') * 26 + w[0] - 'a']` is non-zero, it means that the reverse of the current word has been seen before, so we increment `res`.

#### 4. **Marking the Current Word Pair as Seen**

```cpp
vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
```

- **Mark the pair as seen**: After checking for the reverse pair, we mark the current word as seen by setting `vis[(w[0] - 'a') * 26 + w[1] - 'a']` to `true`. This allows us to check for future occurrences of words that may form valid pairs with subsequent words.

#### 5. **Returning the Result**

```cpp
return res;
```

- After processing all the words in the list, we return `res`, which now holds the total count of valid word pairs.

### Complexity

#### Time Complexity

The time complexity of this solution is \(O(n)\), where \(n\) is the number of words in the input list. This is because we iterate over the list once, and for each word, we perform constant-time operations (indexing and checking the `vis` array).

- **Word iteration**: We iterate over the `words` array once, taking \(O(n)\) time.
- **Index computation**: For each word, calculating the index and updating the `vis` array takes constant time, i.e., \(O(1)\).
  
Thus, the overall time complexity is \(O(n)\).

#### Space Complexity

The space complexity is \(O(1)\), as the `vis` array is of fixed size (676), which does not depend on the size of the input list. Other than that, we use only a few additional integer variables, which require constant space.

### Conclusion

This solution efficiently counts the maximum number of pairs of strings that are reverses of each other by using a hash-based approach. The key idea is to represent the reversed word pairs using a unique index and store them in a fixed-size array. As we iterate through the words, we check if the reverse of each word has been seen before and update the result accordingly.

- **Time Complexity**: \(O(n)\), where \(n\) is the number of words in the list.
- **Space Complexity**: \(O(1)\), due to the fixed-size `vis` array.

This approach is optimal and solves the problem efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/)

---
{{< youtube f8qWoxowloA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
