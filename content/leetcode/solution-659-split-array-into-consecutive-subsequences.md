
+++
authors = ["grid47"]
title = "Leetcode 659: Split Array into Consecutive Subsequences"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 659: Split Array into Consecutive Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/659.webp"
youtube = "hbNUEvWyiFU"
youtube_upload_date="2020-07-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hbNUEvWyiFU/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/659.webp" 
    alt="An array where consecutive subsequences are split and highlighted with glowing sections."
    caption="Solution to LeetCode 659: Split Array into Consecutive Subsequences Problem"
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
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        
        for(int num: nums)
            left[num]++;

        for(int num: nums) { // nums is in increasing order
            if(left[num] == 0) continue;
            
            left[num]--;
            
            if(end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            else if(left[num + 1] > 0 && left[num + 2] > 0) {
                left[num + 1]--;
                left[num + 2]--;
                end [num + 2]++;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks whether a given list of integers can be split into **one or more subsequences** such that each subsequence is a **consecutive sequence**. A subsequence is defined as a sequence of numbers that can be derived by deleting some or no elements of the array without changing the order of the remaining elements.

For example:
- For the input `nums = [1, 2, 3, 3, 4, 5]`, the output should be `true` because it can be split into subsequences `[1, 2, 3]` and `[3, 4, 5]`.
- For the input `nums = [1, 2, 3, 4, 5]`, the output should be `true` because it can be split into the subsequence `[1, 2, 3, 4, 5]`.
- For the input `nums = [1, 2, 3, 5, 6]`, the output should be `false` because it cannot form valid consecutive subsequences.

### Approach

The approach to solving this problem is based on **greedy** strategy, where we attempt to build valid subsequences as we traverse the array. The two main components in this solution are:
1. **Tracking elements left to process:** Using a `left` map to count how many occurrences of each number are left to be placed in subsequences.
2. **Tracking the end of subsequences:** Using an `end` map to keep track of the number of subsequences that are ending with a specific number.

#### Key Observations:
1. A valid subsequence must always contain at least 3 consecutive numbers for the sequence to be valid.
2. For any number in the array, we try to either extend an existing subsequence or start a new one by checking if we can use the next consecutive numbers (`num + 1` and `num + 2`).

The logic of the solution is built upon trying to form these valid subsequences in a greedy manner.

### Code Breakdown (Step by Step)

#### 1. **Initialization**
```cpp
unordered_map<int, int> left, end;
```
Here, we define two hash maps:
- `left`: To track how many occurrences of a number are left to be placed into subsequences.
- `end`: To track how many subsequences are currently ending at a specific number.

#### 2. **Populating the `left` map**
```cpp
for(int num: nums)
    left[num]++;
```
We iterate through the input array `nums` and populate the `left` map. This map keeps track of the count of each number in the array, indicating how many times we still need to place that number into a subsequence.

#### 3. **Main Processing Loop**
```cpp
for(int num: nums) {
    if(left[num] == 0) continue;
    left[num]--;
    
    if(end[num - 1] > 0) {
        end[num - 1]--;
        end[num]++;
    }
    else if(left[num + 1] > 0 && left[num + 2] > 0) {
        left[num + 1]--;
        left[num + 2]--;
        end[num + 2]++;
    } else return false;
}
```

##### Explanation:
- **Skip numbers already processed**:  
  The `if(left[num] == 0) continue;` line skips the current number if it has already been placed in a subsequence, as indicated by the `left` map.

- **Try to extend an existing subsequence**:  
  If a subsequence exists that ends with `num - 1`, then we can extend it by adding `num` to that subsequence. We do this by checking if there is any subsequence ending at `num - 1` (`end[num - 1] > 0`). If this is the case, we:
  - Decrease the count of subsequences ending at `num - 1` (`end[num - 1]--`).
  - Increase the count of subsequences ending at `num` (`end[num]++`).

- **Create a new subsequence**:  
  If no subsequence can be extended, we try to start a new subsequence using the current number. A new subsequence can only be formed if `num + 1` and `num + 2` are also available in the `left` map (i.e., `left[num + 1] > 0 && left[num + 2] > 0`). If this condition is true:
  - Decrease the count of `num + 1` and `num + 2` in the `left` map.
  - Add a new subsequence ending at `num + 2` by updating the `end` map.

- **Return False for invalid cases**:  
  If neither extending an existing subsequence nor starting a new one is possible, we return `false` because it's impossible to create valid subsequences for this input.

#### 4. **Returning the result**
```cpp
return true;
```
If we successfully process all the numbers and form valid subsequences, we return `true`, indicating that it's possible to split the array into subsequences of consecutive integers.

### Complexity

#### Time Complexity:
- **O(n)**: The function iterates through the array `nums` once. For each number, we perform constant-time operations (updating the `left` and `end` maps). Since there are at most `n` numbers and each operation takes constant time, the overall time complexity is **O(n)**, where `n` is the length of the input array.

#### Space Complexity:
- **O(n)**: We use two hash maps, `left` and `end`, to store information about the counts of each number in the array and the subsequences ending at each number. In the worst case, where all numbers in the array are distinct, both maps will contain `n` entries. Therefore, the space complexity is **O(n)**.

### Conclusion

This solution efficiently solves the problem using a greedy approach combined with hash maps to track the available numbers for subsequences and the subsequences themselves. The use of two hash maps (`left` and `end`) ensures that we can manage the subsequences dynamically while processing each number. The overall time and space complexity of **O(n)** makes this solution optimal for large inputs. This approach is particularly suitable for scenarios where subsequences must follow specific constraints, such as forming consecutive sequences.

[`Link to LeetCode Lab`](https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/)

---
{{< youtube hbNUEvWyiFU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
