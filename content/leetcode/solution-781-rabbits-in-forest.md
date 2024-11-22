
+++
authors = ["grid47"]
title = "Leetcode 781: Rabbits in Forest"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 781: Rabbits in Forest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/781.webp"
youtube = "leiSa1i-QrI"
youtube_upload_date="2021-01-11"
youtube_thumbnail="https://i.ytimg.com/vi/leiSa1i-QrI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/781.webp" 
    alt="A forest where rabbits are hiding, with each rabbit's position glowing softly as it’s found."
    caption="Solution to LeetCode 781: Rabbits in Forest Problem"
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
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for(int i: answers)
        c[i]++;
        int res = 0;
        for(auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves determining the minimum number of rabbits that could be in a forest, given a list of answers to a question. Each rabbit in the forest is asked how many rabbits have the same color as them, and the number of rabbits that have the same color is known for each rabbit. The task is to find the minimum number of rabbits required to satisfy all the answers.

In essence, for each rabbit's answer `x`, the rabbit claims that there are exactly `x` other rabbits with the same color. Therefore, a rabbit's answer tells you how many other rabbits share the same color. The goal is to calculate the smallest number of rabbits that satisfies all the answers, taking into account the fact that multiple rabbits may give the same answer.

### Approach

The approach to solving this problem is based on understanding how the answers can be grouped to minimize the number of rabbits. The idea is to consider that each rabbit's answer `x` tells us how many rabbits with the same color they expect to see. This leads to the conclusion that the number of rabbits with the same color must be at least `x + 1` (since the rabbit itself is also counted in the total number of rabbits with the same color).

We can think of it as a process of grouping rabbits with the same answer. For each unique answer `x`, we need to calculate how many groups of `x + 1` rabbits we would need to satisfy the answer `x`.

To do this, we will count how many times each answer occurs and then, for each answer `x`, calculate the number of full groups of size `x + 1` required to accommodate all rabbits who gave that answer. The minimum number of rabbits is the sum of the rabbits in all such groups.

### Code Breakdown (Step by Step)

The code below implements the approach described:

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for (int i : answers)
            c[i]++;  // Count how many times each answer appears
        
        int res = 0;
        for (auto i : c) {
            // For each unique answer x, calculate how many groups of size x + 1 we need
            res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        }
        return res;
    }
};
```

#### Step-by-Step Explanation

1. **Count the Frequency of Answers**:
   - The `unordered_map<int, int> c;` is used to store the frequency of each unique answer in the `answers` array.
   - The loop `for (int i : answers) c[i]++;` iterates through the `answers` array and counts how many times each answer appears. The key `i` in the map represents an answer, and the value `c[i]` represents how many times that answer appears.

2. **Calculating the Minimum Number of Rabbits**:
   - After counting the frequencies, the algorithm needs to calculate the total number of rabbits.
   - The loop `for (auto i : c)` iterates over each unique answer (the key `i.first`) and its frequency (the value `i.second`).
   - For each answer `x`, we need to calculate the number of full groups of size `x + 1` (since each group must consist of at least `x + 1` rabbits).
   - The formula `(i.second + i.first) / (i.first + 1) * (i.first + 1)` computes how many full groups of size `x + 1` are required for `i.second` rabbits who gave answer `x`.
     - `(i.second + i.first) / (i.first + 1)` gives the number of full groups needed to fit all rabbits that gave the answer `x`.
     - Multiplying by `(i.first + 1)` gives the total number of rabbits in those full groups.

3. **Summing the Results**:
   - The total number of rabbits is accumulated in the variable `res`, which is initialized to 0.
   - For each unique answer, the number of rabbits required is added to `res`.

4. **Return the Result**:
   - After processing all answers, the value of `res` is returned, which represents the minimum number of rabbits that could satisfy the given answers.

### Complexity Analysis

#### Time Complexity:
- **O(n)**: The algorithm involves iterating through the `answers` array once to count the frequencies, which takes O(n) time, where `n` is the number of elements in the array. Then, the second loop iterates over the distinct answers (which can be at most `n` distinct answers), and for each answer, it performs a constant amount of work (a few arithmetic operations). Therefore, the overall time complexity is O(n), where `n` is the size of the `answers` array.

#### Space Complexity:
- **O(m)**: The space complexity is determined by the space used to store the frequencies of each answer. In the worst case, all the answers could be distinct, requiring O(n) space to store them in the `unordered_map`. Therefore, the space complexity is O(m), where `m` is the number of distinct answers.

### Conclusion

The problem asks us to compute the minimum number of rabbits that could satisfy the given answers based on certain constraints. The approach described efficiently solves the problem using a hash map to count the frequencies of each answer, followed by calculating the number of full groups of size `x + 1` needed to accommodate all rabbits for each answer `x`.

The solution operates in linear time, O(n), making it well-suited for large inputs, as it processes the answers array in a single pass. The space complexity is O(m), where `m` is the number of distinct answers, which is efficient and scalable.

By understanding how to group rabbits based on their answers and ensuring that each group consists of at least `x + 1` rabbits, we can derive the minimum number of rabbits required. This approach guarantees an optimal solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/rabbits-in-forest/description/)

---
{{< youtube leiSa1i-QrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
