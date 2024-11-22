
+++
authors = ["grid47"]
title = "Leetcode 457: Circular Array Loop"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 457: Circular Array Loop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/457.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/457.webp" 
    alt="A glowing circular array where elements move in a loop, with each cycle softly illuminated as it repeats."
    caption="Solution to LeetCode 457: Circular Array Loop Problem"
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
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;

            int j = i, k = getIdx(i, nums);
            while(nums[k] * nums[i] > 0 && nums[getIdx(k, nums)] * nums[i] > 0) {
                if(j == k) {
                    if(j == getIdx(j, nums)) break;
                    return true;
                }
                j = getIdx(j, nums);
                k = getIdx(getIdx(k, nums), nums);
            }

            j = i;
            int val = nums[i];
            while(nums[j] * val > 0) {
                int next = getIdx(j, nums);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }

    int getIdx(int i, vector<int> &nums) {
        int n = nums.size();
        return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine if a circular array contains a loop. In a circular array, each element points to another element by the value of the number at that index. If an element is positive, it points forward, and if the element is negative, it points backward. The task is to check whether there exists a loop, where the starting index eventually leads back to itself while following the values.

### Approach

To solve this problem, the goal is to detect whether there is a cycle in the circular array where each number points to the next. This is a typical problem involving cycle detection in a directed graph, where each index in the array represents a node, and the value at that index represents a directed edge to another node.

The main idea behind solving this problem is as follows:

1. **Fast and Slow Pointer (Tortoise and Hare)**:
   - We use two pointers, one moving one step at a time (`slow`), and the other moving two steps at a time (`fast`).
   - If there is a loop, the slow and fast pointers will eventually meet, which signifies the presence of a cycle.
   - If the two pointers meet, we can check if they are part of a valid cycle, i.e., both pointers should continue to move in the same direction and not reverse. Additionally, we check if the loop size is greater than 1.

2. **Cycle Detection**:
   - Start at each unvisited index. If the value at the index is zero (indicating the number has already been processed), skip that index.
   - For each index, follow the pointers and detect whether a cycle forms using the `slow` and `fast` pointers.
   - If a cycle is detected, mark all the indices that form part of the loop as visited to avoid reprocessing them.

3. **Resetting Process**:
   - After determining whether a cycle exists for a starting index, reset all indices visited during the cycle search to zero (indicating they have been processed).

### Code Breakdown (Step by Step)

#### Step 1: Function Definition and Initial Checks

```cpp
bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return false;
```
- We begin by checking if the array size is 1. A single element array cannot form a loop, so we return `false`.

#### Step 2: Loop Through Each Index

```cpp
for(int i = 0; i < n; i++) {
    if(nums[i] == 0) continue;
```
- We iterate through each index of the `nums` array.
- If the value at index `i` is zero (which means the number has been marked as processed), we skip that index.

#### Step 3: Initialize Pointers for Cycle Detection

```cpp
int j = i, k = getIdx(i, nums);
while(nums[k] * nums[i] > 0 && nums[getIdx(k, nums)] * nums[i] > 0) {
    if(j == k) {
        if(j == getIdx(j, nums)) break;
        return true;
    }
    j = getIdx(j, nums);
    k = getIdx(getIdx(k, nums), nums);
}
```
- For each unprocessed index, we use two pointers `j` (slow) and `k` (fast). Initially, `j` starts at `i`, and `k` starts at the next position determined by `getIdx(i, nums)`.
- The while loop continues as long as the pointers move in the same direction (both positive or both negative) and don't visit a zero element.
- If `j` and `k` meet, it indicates a cycle. We check if `j` equals `getIdx(j, nums)` to ensure the cycle has more than one element. If not, we break out of the loop and return `true`, indicating a cycle was found.

#### Step 4: Reset Process for Non-Cycle Elements

```cpp
j = i;
int val = nums[i];
while(nums[j] * val > 0) {
    int next = getIdx(j, nums);
    nums[j] = 0;
    j = next;
}
```
- If no cycle is detected, we move the `j` pointer along the cycle path and mark all indices it visited as zero (indicating they have been processed).
- This ensures we do not revisit these indices during subsequent checks.

#### Step 5: Helper Function to Get the Next Index

```cpp
int getIdx(int i, vector<int> &nums) {
    int n = nums.size();
    return i + nums[i] >= 0 ? (i + nums[i]) % n : n + ((i + nums[i]) % n);
}
```
- The `getIdx` function calculates the next index by adding the value at index `i` to `i`. It ensures the calculation wraps around the array using modulo operation, so it works for both positive and negative values.
- If the result of the addition is negative, the modulo operation ensures that the resulting index is valid (between 0 and `n-1`).

#### Step 6: Return False if No Cycle is Found

```cpp
return false;
```
- After completing the loop for all indices, if no cycle is found, we return `false`.

### Complexity

#### Time Complexity:
- The main loop iterates over each element of the array once, and each cycle check operation involves a series of `getIdx` calls, each of which is constant time.
- In the worst case, every element of the array could be processed multiple times (if the array contains a cycle), making the overall time complexity **O(n)**, where `n` is the size of the array.

#### Space Complexity:
- The algorithm uses a constant amount of extra space for the two pointers and helper variables, so the space complexity is **O(1)**.

### Conclusion

This solution efficiently detects whether there is a loop in a circular array using a fast and slow pointer approach combined with cycle detection. By marking visited nodes and utilizing modulo arithmetic to handle circular indexing, it ensures correctness while maintaining linear time complexity. The solution avoids unnecessary recomputation by resetting processed elements to zero, making it both time and space-efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/circular-array-loop/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
