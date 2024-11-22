
+++
authors = ["grid47"]
title = "Leetcode 532: K-diff Pairs in an Array"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 532: K-diff Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/532.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/532.webp" 
    alt="An array where each valid pair with a difference of `k` is softly illuminated."
    caption="Solution to LeetCode 532: K-diff Pairs in an Array Problem"
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
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        int res = 0;
        for(auto const &[i, j] : mp)
            if((k > 0 && mp.count(i - k)) ||
              (k == 0 && (j > 1)) )
                res++;
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to count unique pairs in an array such that the absolute difference between the two numbers in each pair equals a given integer \( k \). This means we need to find how many unique pairs \((a, b)\) exist in the array where \( |a - b| = k \). The array can have duplicate elements, and \( k \) can be zero.

### Approach

To solve this problem efficiently, we utilize a frequency map (or hash map) that tracks the occurrences of each number in the array. The approach leverages this map to check for each number if there exists another number that would form a valid pair according to the given condition \( |a - b| = k \).

1. **Building the Frequency Map**: First, we create a map to store each unique number in the array as a key, along with the frequency of that number as the value.

2. **Finding Pairs Based on k**:
   - If \( k > 0 \): For each unique number \( i \) in the map, we check if \( i - k \) also exists in the map. This condition ensures that the pair \((i, i - k)\) has the required absolute difference of \( k \).
   - If \( k == 0 \): We are looking for pairs where both elements are the same, so we simply check if any number appears more than once in the array. If a number's frequency is greater than 1, it forms a valid pair with itself.

3. **Counting Pairs**: For each valid condition met, we increment our result counter.

### Code Breakdown (Step by Step)

#### Step 1: Create a Frequency Map

```cpp
map<int, int> mp;
for(int i : nums)
    mp[i]++;
```

- We iterate over the `nums` array, populating a map (`mp`) where each key is a number from the array, and its corresponding value is the count of occurrences.
- This frequency map allows us to check the existence and frequency of any number in constant time.

#### Step 2: Count Valid Pairs

```cpp
int res = 0;
for(auto const &[i, j] : mp)
    if((k > 0 && mp.count(i - k)) ||
      (k == 0 && (j > 1)) )
        res++;
```

- We initialize `res` to store the count of valid pairs.
- For each entry `[i, j]` in the map (`i` represents the number, and `j` represents its frequency):
  - If \( k > 0 \): We check if `i - k` exists in the map. If it does, it means \((i, i - k)\) is a valid pair with the difference \( k \), and we increment `res`.
  - If \( k == 0 \): We look for numbers that appear more than once, as they can form pairs with themselves. If `j > 1`, we increment `res`.

#### Step 3: Return the Result

```cpp
return res;
```

- Finally, we return `res`, which holds the total count of unique pairs with the given difference \( k \).

### Complexity

#### Time Complexity
- **Building the Frequency Map**: This requires `O(n)` time, where `n` is the size of the array.
- **Counting Valid Pairs**: We iterate over the map, which has a maximum of `n` unique entries in the worst case. Thus, this step takes `O(n)` time as well.
- **Overall Time Complexity**: `O(n)`, which is efficient for large arrays.

#### Space Complexity
- We use a map to store the frequency of each number, which requires `O(n)` space in the worst case.

### Conclusion

This solution efficiently counts unique pairs in an array that have a specific difference. By leveraging a frequency map, we avoid the need for nested loops, reducing the time complexity from `O(n^2)` to `O(n)`. This approach is both optimal and intuitive, as it simplifies the process of finding pairs through straightforward conditions based on the difference \( k \). The code is also compact and highly readable, making it a practical solution for real-world applications where performance is critical.

[`Link to LeetCode Lab`](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
