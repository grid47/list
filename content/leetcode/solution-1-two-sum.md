
+++
authors = ["grid47"]
title = "Leetcode 1: Two Sum"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1: Two Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/1.webp"
youtube = "Yyyi12oaK94"
youtube_upload_date="2022-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Yyyi12oaK94/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/1.webp" 
    alt="A pair of floating, glowing puzzle pieces coming together in a soft light."
    caption="Solution to LeetCode 1: Two Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}

---

### The Two Sum Problem 🎯

Two Sum is a classical problem where you’re given a `number array` and a `target`, and you need to find two indices from the array where the numbers add up to the `target`. 🔢

{{< dots >}}

### Let's try to solve it 🧩

- You can check all possible pairs, which leads to an algorithm with `quadratic complexity`, or you can use a `hash table` to bring the complexity down to `linear`. 📉

    For example you have `nums = [2, 5, 7, 8]` and `target = 9`, listing all possibilities will be like
    ```
    [[2, 2][2,5][2,7][2,8]]
    [[5, 2][5,5][5,7][5,8]]
    [[7, 2][7,5][7,7][7,8]]
    [[8, 2][8,5][8,7][8,8]]
    It like 4x4 i.e. n x n -> O(n^2)
    ```

- Let’s go with the second method, where you achieve linear complexity by using a hash table. 🗃️  
A hash table is a data structure that allows **inserting** and **retrieving** key-value pairs in constant time. ⚡

- Iterate over the number list and, for each number, record its complement and index if no number in the table can act as a complement for the current number.

- If a complement for the current number exists, retrieve its index and return it along with the current index as the answer. ✅

- For the edge case where no pair is found, return a `-1, -1` pair. ❌

That’s it! Now, let’s break down the code. 🧑‍💻

{{< dots >}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                return { mp[nums[i]], i };
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
{{< /highlight >}}
### The Code Breakdown 📝


#### 1. Hash Map (or Table) Declaration 🗂️
```cpp
map<int, int> mp;
```
- This is the hash table, which has an integer key (the complement) and an integer value (the index).


#### 2. The Loop and Iterator 🔄
```cpp
for(int i = 0; i < nums.size(); i++)
```
- Iterate over each index in the number array; the iterator `i` can fetch any number at index `i` from the array `nums`.

#### 3. Check for Complement 🔍
```cpp
if(mp.count(nums[i]))
```
- This line checks if a previously seen number can act as a complement for the current number.

#### 4. If YES, Return the Solution ✅
```cpp
return { mp[nums[i]], i };
```
- Retrieve the index of the complement and pair it with the current index as the solution. This line returns the pair if it exists.

#### 5. Recording Complement 📝
```cpp
mp[target - nums[i]] = i;
```
- This stores the complement of the current number and records it along with the current index in the map.

#### 6. If Nothing is Found ❌
```cpp
return {-1, -1};
```
- Return the pair `-1, -1`.


{{< dots >}}

### Understanding Time and Space Complexity ⏱️📏

#### Time Complexity:
We iterate over each element in the array once, performing constant-time operations (insertion and retrieval) on each iteration. This results in a linear `O(n)` time complexity. 🚀

#### Space Complexity: 
We use a hash map to store up to `n` pairs of elements, so the space complexity is also linear, `O(n)`, which is a trade-off for faster lookup. 🗄️

[`Link to LeetCode Lab`](https://leetcode.com/problems/two-sum/description/)

---
{{< youtube Yyyi12oaK94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
