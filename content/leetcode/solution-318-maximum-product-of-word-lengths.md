
+++
authors = ["grid47"]
title = "Leetcode 318: Maximum Product of Word Lengths"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 318: Maximum Product of Word Lengths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/318.webp"
youtube = "dE88fgc73jQ"
youtube_upload_date="2021-05-27"
youtube_thumbnail="https://i.ytimg.com/vi/dE88fgc73jQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/318.webp" 
    alt="A set of words with glowing lengths, each word’s length highlighted to show the maximum product of word lengths."
    caption="Solution to LeetCode 318: Maximum Product of Word Lengths Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProduct(vector<string>& words) {

        int len = words.size();
        vector<int> mask(len, 0);

        int res = 0;
        for(int i = 0; i < len; i++) {
            string word = words[i];
            int sz = word.size();
            for(int j = 0; j < sz; j++)
            mask[i] |= (1 << (word[j] - 'a'));

            for(int j = 0; j < i; j++) {
                if((mask[i] & mask[j]) == 0)
                res = max(res, int (words[i].size() * words[j].size() ));
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

We're tackling a fun challenge today! The goal is to find **two words in a list** that have no common letters and to maximize the **product of their lengths**. So, if we have words like `"abcw"`, `"baz"`, `"foo"`, and `"bar"`, we need to find pairs where **no letters overlap** and calculate the best possible length product. Let's dive into how we can solve this effectively!

---

### 🧠 Approach

To solve this, we'll take a unique approach using **bitwise operations**. Here’s the game plan:

1. **Create a Bitmask for Each Word** 🧩:
   - For each word, we’ll create a bitmask where each **bit represents a letter**. If a letter is present in the word, we set that bit to 1. This lets us compactly store all the letters in the word in a single integer.
  
2. **Check for Overlapping Letters with Bitwise AND** 🔍:
   - Two words have no shared letters if their **bitwise AND** results in 0. This way, we can instantly know if two words share any letters without looping through each character. Super efficient!
  
3. **Pair Comparison for Maximum Product** 🎯:
   - We’ll compare each pair of words, checking if their bitmasks overlap. If not, we calculate their length product and track the maximum product we find.

---

### 🔨 Step-by-Step Code Breakdown

Let’s break down each part of the code for clarity.

#### Step 1: Bitmask Setup for Each Word

```cpp
int len = words.size();
vector<int> mask(len, 0);
```

- **Initialize a Mask Array**: We'll use `mask` to store the bitmask of each word in the list.

#### Step 2: Generate Each Word’s Bitmask 🎲

```cpp
for(int i = 0; i < len; i++) {
    string word = words[i];
    for(int j = 0; j < word.size(); j++)
        mask[i] |= (1 << (word[j] - 'a'));
}
```

- **Loop Through Each Word**: For every letter in each word, we set the appropriate bit in that word’s mask.
- **Bit Position Calculation**: We calculate the position as `word[j] - 'a'` and set the bit using `|= (1 << position)`. Each bit in the bitmask represents a letter in the alphabet.

#### Step 3: Compare Each Pair for Maximum Product 📊

```cpp
int res = 0;
for(int i = 0; i < len; i++) {
    for(int j = 0; j < i; j++) {
        if((mask[i] & mask[j]) == 0) {
            res = max(res, int(words[i].size() * words[j].size()));
        }
    }
}
return res;
```

- **Pairwise Comparison**: For every pair of words, we check if they share any letters by checking `(mask[i] & mask[j]) == 0`.
- **Update Maximum Product**: If there are no shared letters, we calculate the product of their lengths and update our maximum product if this new one is larger.

---

### 📈 Complexity Analysis

**Time Complexity**:
- Generating bitmasks takes **O(n \* L)**, where `L` is the average word length.
- Comparing each pair of words takes **O(n^2)**. Each comparison is quick due to bitwise operations, making this efficient enough for moderately large inputs.

**Space Complexity**:
- We only use extra space for the `mask` array, so **O(n)** in space.

---

### 🏁 Conclusion

This solution gives us a smart and efficient way to find the maximum product of two non-overlapping words! By leveraging bitwise operations, we can speed through comparisons without wasting time checking each letter individually. Here’s what we achieved:

1. **Optimized Comparisons** 🛠️: Bitwise AND lets us check for common letters in constant time!
2. **Clear Structure** 📐: Our approach combines bitmasks with simple logic to calculate maximums efficiently.
3. **Scalable for Moderate Inputs** 🌐: With an **O(n^2)** complexity, this solution is ready to handle reasonably large lists of words.

**Keep up the great work on cracking these tricky challenges! 🏆 Each bitwise technique learned is one step closer to becoming a DSA master!**

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-of-word-lengths/description/)

---
{{< youtube dE88fgc73jQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
