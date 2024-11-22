
+++
authors = ["grid47"]
title = "Leetcode 2491: Divide Players Into Teams of Equal Skill"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2491: Divide Players Into Teams of Equal Skill in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cueOpK5QMEA"
youtube_upload_date="2024-10-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cueOpK5QMEA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int l = 0, r = n - 1;
        
        int sum = skill[l] + skill[r];
        long long prod = skill[l] * skill[r];
        
        l++, r--;
        while(l < r) {
            if(sum != (skill[l] + skill[r])) return -1;
            prod += skill[l] * skill[r];
            l++;
            r--;
        }
        return prod;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to divide a given list of players into two teams such that:
1. Each team has the same sum of skills.
2. The product of the skills of the players in each pair (one player from each team) must be maximized.

The goal is to compute the sum of the products of paired players, ensuring that each pair sums to the same value. If it's not possible to form such pairs, the function should return `-1`.

For example:
- Given a list of player skills: `[3, 1, 2, 4]`, we need to check if we can split the list into pairs such that the sum of the skills in each pair is equal and calculate the sum of the products of those pairs.
- If it's possible, return the sum of the products of the pairs; otherwise, return `-1`.

### Approach

The main idea is to pair players in such a way that:
- The sum of skills in each pair is equal.
- The product of skills in each pair should be maximized.

We can approach the problem in the following manner:
1. **Sort the Skill List**: Start by sorting the list of player skills in ascending order. This allows us to pair players from opposite ends of the sorted list.
2. **Check Pairing Conditions**: Once sorted, the first player (with the lowest skill) can be paired with the last player (with the highest skill). For each pair, we check if their sum is consistent across all pairs. If the sum of any pair differs, we return `-1`.
3. **Calculate Product**: For each valid pair (where the sum is consistent), calculate the product of their skills and accumulate the result.
4. **Return the Final Result**: If all pairs are valid, return the sum of their products. If any pair does not satisfy the conditions, return `-1`.

### Code Breakdown (Step by Step)

#### 1. **Sort the Skill List**

```cpp
sort(skill.begin(), skill.end());
```

- The first step is sorting the input `skill` vector. Sorting helps us easily pick pairs from the two ends of the list, which is a common technique in problems involving pairwise operations.

#### 2. **Initialize Pointers**

```cpp
int n = skill.size();
int l = 0, r = n - 1;
```

- We initialize two pointers, `l` and `r`, which point to the first and last elements of the sorted `skill` list, respectively. These pointers will help in forming pairs by picking players from the start and the end of the list.

#### 3. **Initial Pair Sum and Product**

```cpp
int sum = skill[l] + skill[r];
long long prod = skill[l] * skill[r];
```

- The first pair is formed by the players at indices `l` and `r`. The sum of their skills is calculated and stored in `sum`. The product of their skills is also calculated and stored in `prod`.
- We will use these initial values to check if all subsequent pairs follow the same sum.

#### 4. **Increment and Decrement Pointers**

```cpp
l++, r--;
```

- After processing the first pair, we move the `l` pointer forward and the `r` pointer backward to form the next pair.

#### 5. **Iterate and Check Each Pair**

```cpp
while (l < r) {
    if (sum != (skill[l] + skill[r])) return -1;
    prod += skill[l] * skill[r];
    l++;
    r--;
}
```

- We enter a `while` loop that continues until the `l` pointer meets the `r` pointer. For each pair, we check if the sum of the current pair is equal to the initial sum (`sum`). If the sum differs, it means the pairing is not valid, so we return `-1`.
- If the sum is valid, we calculate the product of the current pair and add it to the accumulated `prod` value.
- Finally, we increment `l` and decrement `r` to check the next pair.

#### 6. **Return the Product**

```cpp
return prod;
```

- Once all pairs are processed and their sums are verified, we return the total product accumulated in `prod`.

### Complexity Analysis

#### Time Complexity:
- The time complexity is **O(n log n)**, where `n` is the size of the `skill` list.
  - Sorting the list takes **O(n log n)** time.
  - The subsequent iteration through the list to form pairs takes **O(n)** time.
  
Thus, the overall time complexity is dominated by the sorting step, which is **O(n log n)**.

#### Space Complexity:
- The space complexity is **O(1)**, as the solution only uses a constant amount of extra space (a few integer variables such as `l`, `r`, `sum`, and `prod`), regardless of the size of the input list.

Thus, the space complexity is **O(1)**.

### Conclusion

This solution efficiently solves the problem of pairing players with equal sum of skills and maximizing the product of skills within each pair. The algorithm works by sorting the skill list and using two pointers to form pairs from opposite ends of the list. It ensures that the sum of each pair is consistent and calculates the sum of their products.

The time complexity of **O(n log n)** makes the solution suitable for relatively large inputs, and the space complexity of **O(1)** ensures that the algorithm uses minimal extra memory.

The approach is simple yet effective for problems involving pairing or matching items under specific conditions. It leverages sorting and the two-pointer technique, both of which are commonly used in algorithms for pairing elements in lists or arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/)

---
{{< youtube cueOpK5QMEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
