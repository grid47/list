
+++
authors = ["grid47"]
title = "Leetcode 2531: Make Number of Distinct Characters Equal"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2531: Make Number of Distinct Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MoYeUVe-xPY"
youtube_upload_date="2023-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MoYeUVe-xPY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isItPossible(string w1, string w2) {
        
        map<char, int> ma1, ma2;
        for(int x: w1)
            ma1[x]++;
        for(int x: w2)
            ma2[x]++;
        
        for(auto it1: ma1) {
            for(auto it2: ma2) {
                map<char, int> d1 = ma1, d2 = ma2;
                d1[it2.first]++;
                d2[it1.first]++;
                
                d1[it1.first]--;
                d2[it2.first]--;
                
                if(d1[it1.first] == 0)
                    d1.erase(it1.first);
                if(d2[it2.first] == 0)
                    d2.erase(it2.first);
                
                if(d1.size() == d2.size()) return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine if it is possible to swap one character from string `w1` with one character from string `w2` such that the two strings become anagrams of each other. Specifically, after performing a single swap, the character frequencies of both strings should match. If such a swap is possible, return `true`; otherwise, return `false`.

### Approach

The key observation is that for two strings to become anagrams after swapping one character, they must:
1. **Have the same character frequencies** after the swap.
2. **Only require a swap of characters** between the two strings. This means that there is a way to make the frequencies of each character match by swapping one character from `w1` with one character from `w2`.

#### Detailed Steps

1. **Character Frequency Counting**: First, calculate the frequency of each character in both strings. If the strings have different lengths, we can immediately return `false` since a swap can't make the strings anagrams if their lengths differ.
  
2. **Simulate the Swap**: We will simulate all possible swaps between characters of `w1` and `w2`. For each possible swap, we adjust the frequency of characters in both strings accordingly and check if the two strings become anagrams (i.e., their frequency maps are identical).

3. **Return the Result**: If any of the swaps result in the two strings having the same character frequencies, return `true`. If no such swap exists after iterating through all possibilities, return `false`.

### Code Breakdown (Step by Step)

#### 1. **Initialize Frequency Maps**

```cpp
map<char, int> ma1, ma2;
for (int x : w1) ma1[x]++;
for (int x : w2) ma2[x]++;
```

- First, we initialize two frequency maps, `ma1` and `ma2`, to store the counts of each character in strings `w1` and `w2`, respectively.
- For each character `x` in `w1`, we increment its count in `ma1`. Similarly, we count characters for `w2` in `ma2`.

#### 2. **Iterate Through Each Character Pair**

```cpp
for (auto it1 : ma1) {
    for (auto it2 : ma2) {
```

- We iterate through all pairs of characters, one from `ma1` (the frequency map of `w1`) and one from `ma2` (the frequency map of `w2`).
- The idea is to test if swapping these two characters from `w1` and `w2` will result in both maps becoming identical (i.e., both strings becoming anagrams).

#### 3. **Simulate the Swap**

```cpp
map<char, int> d1 = ma1, d2 = ma2;
d1[it2.first]++;
d2[it1.first]++;
d1[it1.first]--;
d2[it2.first]--;
```

- For each pair of characters, we create copies of the frequency maps `ma1` and `ma2` (stored in `d1` and `d2`).
- We simulate the swap by:
  - Incrementing the count of `it2.first` (the character from `w2`) in `d1` (since we're pretending to add it to `w1`).
  - Similarly, incrementing the count of `it1.first` (the character from `w1`) in `d2` (since we're pretending to add it to `w2`).
  - Decrementing the original characters in the respective maps (`d1[it1.first]--` and `d2[it2.first]--`).

#### 4. **Remove Characters with Zero Frequency**

```cpp
if (d1[it1.first] == 0) d1.erase(it1.first);
if (d2[it2.first] == 0) d2.erase(it2.first);
```

- After adjusting the character counts, we remove any characters from the frequency maps `d1` and `d2` that have a count of zero. This ensures that only characters with non-zero frequencies are present in the maps.

#### 5. **Check if the Maps Are Equal**

```cpp
if (d1.size() == d2.size()) return true;
```

- If the sizes of `d1` and `d2` (i.e., the number of unique characters in each string after the swap) are equal, this indicates that both maps have the same character frequencies. In this case, we return `true` because the strings can be made anagrams by swapping the current pair of characters.

#### 6. **Return False if No Valid Swap Exists**

```cpp
return false;
```

- If no valid swap is found that results in the two strings becoming anagrams, we return `false` after checking all possible swaps.

### Complexity Analysis

#### Time Complexity

- **Building the Frequency Maps**: Both `w1` and `w2` are iterated through once to build the frequency maps. This takes \( O(n + m) \), where \( n \) is the length of `w1` and \( m \) is the length of `w2`.
- **Simulating Swaps**: We iterate over all pairs of characters from the frequency maps of `w1` and `w2`. In the worst case, this can involve iterating over all unique characters in `w1` and `w2`, which takes \( O(c_1 \times c_2) \), where \( c_1 \) and \( c_2 \) are the number of unique characters in `w1` and `w2` respectively.
- **Final Complexity**: Combining the above steps, the time complexity of the solution is \( O(n + m + c_1 \times c_2) \), where \( c_1 \) and \( c_2 \) represent the number of distinct characters in `w1` and `w2`.

#### Space Complexity

- The space complexity is mainly determined by the storage of the frequency maps `ma1` and `ma2`, which are \( O(c_1 + c_2) \), where \( c_1 \) and \( c_2 \) are the number of distinct characters in `w1` and `w2`. The temporary maps `d1` and `d2` also take space proportional to the number of unique characters.

Thus, the space complexity is \( O(c_1 + c_2) \).

### Conclusion

This approach efficiently solves the problem by simulating all possible swaps between characters from two strings `w1` and `w2`. By using frequency maps and testing the effects of each swap, we can determine if a valid swap exists that makes the two strings anagrams. This solution is efficient in terms of both time and space, particularly for cases with a large number of distinct characters in the strings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/)

---
{{< youtube MoYeUVe-xPY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
