
+++
authors = ["grid47"]
title = "Leetcode 128: Longest Consecutive Sequence"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 128: Longest Consecutive Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/128.webp"
youtube = "P6RZZMu_maU"
youtube_upload_date="2020-06-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P6RZZMu_maU/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/128.webp" 
    alt="A smooth, radiant path showing consecutive numbers, glowing brighter as the sequence length increases."
    caption="Solution to LeetCode 128: Longest Consecutive Sequence Problem"
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
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int x: nums)
            s.insert(x);
        if(s.empty()) return 0;
        int mx = 1;
        for(int i = 0; i < nums.size(); i++) {
            int y = nums[i];
            int c = 1;
            if(!s.count(y + 1))
            while(s.count(y - 1)) {
                c++;
                y = y -1;
                mx = max(mx, c);
            }
        }
        return mx;
    }
};
{{< /highlight >}}
---

### 💡 **Longest Consecutive Sequence: Finding the Longest Chain of Consecutive Numbers**

The **Longest Consecutive Sequence** problem challenges us to find the length of the longest consecutive sequence in an unsorted array of integers. The sequence must consist of elements that follow each other in a continuous manner, i.e., each element must be exactly one more than its predecessor. Our goal is to determine the length of the longest such sequence.

---

#### **Problem Statement**

Given:
- An unsorted array of integers `nums`.

We need to find the **length of the longest consecutive sequence** where:
1. The elements in the sequence are consecutive (i.e., each number is one more than the previous).
2. The sequence does not need to be contiguous in the array but must consist of consecutive numbers.

---

#### **Example**

- **Input**:
  - `nums = [100, 4, 200, 1, 3, 2]`
  
- **Output**: 
  - `4`
  
  **Explanation**: The longest consecutive sequence is `[1, 2, 3, 4]`, so the length is 4.

---

### 🛠️ **Approach: Efficient Solution Using a Set**

Instead of sorting the array, we use a **set** to efficiently check for consecutive numbers and avoid redundant operations. By leveraging the set's O(1) average time complexity for insertion and lookup, we can solve this problem in **O(n)** time, which is optimal for large input sizes.

---

### ✨ **Steps to Solve the Problem**

#### 1️⃣ **Function Definition**

```cpp
int longestConsecutive(vector<int>& nums)
```

This function accepts a vector `nums` containing integers and returns the length of the longest consecutive sequence.

#### 2️⃣ **Inserting Elements into a Set**

```cpp
set<int> s;
for (int x : nums)
    s.insert(x);
```

- A set `s` is created to store all the unique elements from the array. 
- We loop through the array `nums` and insert each element `x` into the set. If there are duplicate elements in the array, they are automatically handled by the set.

#### 3️⃣ **Edge Case: Empty Set**

```cpp
if (s.empty()) return 0;
```

- Before proceeding, we check if the set is empty. If it is, there are no elements in the array, and thus no consecutive sequence can exist. We return `0` in this case.

#### 4️⃣ **Finding the Longest Consecutive Sequence**

```cpp
int mx = 1;
for (int i = 0; i < nums.size(); i++) {
    int y = nums[i];
    int c = 1;
    if (!s.count(y + 1))
        while (s.count(y - 1)) {
            c++;
            y = y - 1;
            mx = max(mx, c);
        }
}
```

- We initialize `mx = 1` to keep track of the maximum length of the consecutive sequence found.
- We iterate through each element `y` in the array `nums`:
  - If `y + 1` is not in the set, it means `y` could be the start of a new consecutive sequence.
  - We then check for consecutive numbers backward from `y`. If `y - 1` is found in the set, we keep decrementing `y` and counting the consecutive numbers.
  - The counter `c` tracks the length of the current sequence. We update `mx` if the current sequence length `c` exceeds the previous maximum.

#### 5️⃣ **Returning the Result**

```cpp
return mx;
```

- After iterating through the entire array and finding the longest consecutive sequence, we return `mx`, which contains the length of the longest sequence.

---

### 🔍 **Example Walkthrough**

Let’s walk through the example **`nums = [100, 4, 200, 1, 3, 2]`**:

1. **Insert into Set**: First, insert all elements into the set: `{1, 2, 3, 4, 100, 200}`.
2. **Iterate over Array**:
   - For `100`: No smaller consecutive number (`100 - 1`) exists, so the sequence length is `1`.
   - For `4`: The set contains `3, 2, 1`, so the sequence `[1, 2, 3, 4]` is formed. Length of sequence is `4`.
3. **Result**: The longest sequence has a length of `4`.

---

### 🧑‍💻 **Time and Space Complexity**

- **Time Complexity:** `O(n)`
  - Inserting all elements into the set takes O(n) time, where `n` is the number of elements in the array.
  - Each insertion and lookup in the set takes O(1) time on average. Thus, the overall time complexity is O(n).
  - We only iterate through the array once and check consecutive numbers in the set without redundant work.
  
- **Space Complexity:** `O(n)`
  - The space complexity is O(n) due to the set storing the unique elements from the array.

---

### 🏁 **Conclusion**

This approach solves the "Longest Consecutive Sequence" problem efficiently by using a **set**. By checking for consecutive elements directly in the set, we can avoid unnecessary sorting and redundant work, achieving an optimal **O(n)** time complexity. This makes the solution suitable for large input sizes. The space complexity is also **O(n)**, as we store all unique elements in the set. With this solution, you can quickly find the longest consecutive sequence in an unsorted array of integers.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-consecutive-sequence/description/)

---
{{< youtube P6RZZMu_maU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
