
+++
authors = ["grid47"]
title = "Leetcode 744: Find Smallest Letter Greater Than Target"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 744: Find Smallest Letter Greater Than Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/744.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/744.webp" 
    alt="A string where the smallest letter greater than the target is found and highlighted with a soft glow."
    caption="Solution to LeetCode 744: Find Smallest Letter Greater Than Target Problem"
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
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(int i = 0; i < letters.size(); i++) {
            if(letters[i] > target) {
                ans = letters[i];
                break;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the **next greatest letter** in a sorted list of letters that is strictly greater than a given target character. The list of letters is sorted in **non-decreasing** order, and the target is a single character. The goal is to determine the smallest letter in the list that is strictly greater than the target. If no such letter exists, the next greatest letter should be the smallest letter in the list.

For example:
- Given the letters `['c', 'f', 'j']` and the target `a`, the next greatest letter is `c`.
- Given the letters `['c', 'f', 'j']` and the target `c`, the next greatest letter is `f`.
- Given the letters `['c', 'f', 'j']` and the target `k`, the next greatest letter is `c`, because there are no letters greater than `k` in the list.

### Approach

To solve this problem, we need to:
1. **Iterate through the list** of letters.
2. **Find the first letter** that is strictly greater than the given target.
3. If no such letter is found, return the **first letter** in the list, as the list is sorted and wrapping around should give us the smallest letter.

The key observation here is:
- The list is sorted, which allows us to efficiently search for the next greatest letter.
- We can perform a **linear scan** of the list because we are only required to find the first letter greater than the target, which avoids the complexity of binary search for this problem.

### Code Breakdown (Step by Step)

#### Step 1: Initialization

We begin by initializing `ans` to the first letter in the list. This is a fallback value in case the target is greater than or equal to the largest element in the list, which will ensure that the smallest letter is returned.

```cpp
char ans = letters[0];  // Initialize answer to the first letter
```

#### Step 2: Iterate Through the List

We loop through the `letters` vector and compare each letter with the target character. If we find a letter that is greater than the target, we set it as our answer and **break** the loop.

```cpp
for (int i = 0; i < letters.size(); i++) {
    if (letters[i] > target) {
        ans = letters[i];  // Update the answer
        break;  // Stop the loop once we find the first letter greater than the target
    }
}
```

#### Step 3: Return the Answer

After completing the loop, we return the character stored in `ans`. If no letter was found greater than the target (i.e., the target is greater than or equal to the largest letter in the list), `ans` will still contain the first letter of the list, as initialized.

```cpp
return ans;
```

#### Full Code:

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];  // Default answer if no greater letter is found
        for(int i = 0; i < letters.size(); i++) {
            if(letters[i] > target) {
                ans = letters[i];  // Update the answer
                break;  // Exit the loop as soon as we find the first greater letter
            }
        }
        return ans;  // Return the next greatest letter
    }
};
```

### Complexity

#### Time Complexity:
- **O(n)** where `n` is the number of elements in the `letters` list.
  - In the worst case, we iterate through all `n` letters once to find the first one that is greater than the target. This is a linear scan, which ensures an optimal time complexity for this approach.

#### Space Complexity:
- **O(1)** because we only use a few extra variables (`ans`, `i`) to store intermediate results. We are not using any additional data structures that grow with the input size.

### Conclusion

This solution efficiently solves the problem of finding the next greatest letter in a sorted list. By leveraging a **linear scan**, we ensure that we find the first letter greater than the target in **O(n)** time, which is optimal for this problem given the constraints. The simplicity of the approach and the constant space usage makes it an effective solution for a variety of input sizes.

By iterating through the sorted list and breaking early when a valid answer is found, this approach ensures both clarity and performance. The solution is easy to implement and read, making it ideal for understanding and quick usage in similar problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
