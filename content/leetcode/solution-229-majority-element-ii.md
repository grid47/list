
+++
authors = ["grid47"]
title = "Leetcode 229: Majority Element II"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 229: Majority Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/229.webp"
youtube = "Eua-UrQ_ANo"
youtube_upload_date="2023-10-05"
youtube_thumbnail="https://i.ytimg.com/vi/Eua-UrQ_ANo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/229.webp" 
    alt="A sequence of numbers with one element glowing brightly, signifying the majority element."
    caption="Solution to LeetCode 229: Majority Element II Problem"
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
    vector<int> majorityElement(vector<int>& nums) {
            std::vector<int> result;
    int n = nums.size();

    if (n == 0) return result;

    int cnt1 = 0, cnt2 = 0;
    int cnd1 = 0, cnd2 = 0;

    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (val == cnd1) cnt1++;
        else if (val == cnd2) cnt2++;
        else if (cnt1 == 0) { cnt1 = 1; cnd1 = val; }
        else if (cnt2 == 0) { cnt2 = 1; cnd2 = val; }
        else { cnt1--; cnt2--; }
    }

    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (val == cnd1) cnt1++;
        else if (val == cnd2) cnt2++;
    }

    n = n / 3;

    if (cnt1 > n) result.push_back(cnd1);
    if (cnt2 > n) result.push_back(cnd2);

    return result;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The task is to find all elements in the given list `nums` that appear more than `n/3` times, where `n` is the size of the list. If there are multiple elements that satisfy this condition, we need to return them in a vector. If no such elements exist, the result should be an empty vector.

---

### 🧠 Approach

To solve this problem efficiently, we’ll leverage the **Boyer-Moore Voting Algorithm**, which is traditionally used to find a majority element in an array. This algorithm can be extended to find elements that appear more than `n/3` times in the list. Here’s how we’ll break it down:

1. **Two Potential Majority Candidates:**
   - Since there can be at most two elements that appear more than `n/3` times, we will maintain two candidate values `cnd1` and `cnd2` along with their respective counts `cnt1` and `cnt2`.

2. **First Pass: Identify Candidates:**
   - In the first pass, we traverse the array and update counts for the two potential candidates. If a number matches one of the candidates, we increase its count. If the count reaches zero, we replace that candidate with the current number.

3. **Second Pass: Verify Candidates:**
   - After identifying two candidates, we make a second pass to verify their actual counts. If a candidate appears more than `n/3` times, we include it in the result.

4. **Edge Case Handling:**
   - If the array is empty, we return an empty result.
   - If no element appears more than `n/3` times, we return an empty result.

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initialization

```cpp
std::vector<int> result;
int n = nums.size();
if (n == 0) return result;
```

- We initialize a vector `result` to store the majority elements.
- The variable `n` stores the size of the list `nums`.
- If `nums` is empty, we return an empty result immediately.

#### Step 2: Variables for Counting

```cpp
int cnt1 = 0, cnt2 = 0;
int cnd1 = 0, cnd2 = 0;
```

- We declare two counters `cnt1` and `cnt2` to track the counts of two potential majority candidates (`cnd1` and `cnd2`).

#### Step 3: First Pass - Identify the Potential Candidates

```cpp
for (int i = 0; i < n; i++) {
    int val = nums[i];

    if (val == cnd1) cnt1++;
    else if (val == cnd2) cnt2++;
    else if (cnt1 == 0) { cnt1 = 1; cnd1 = val; }
    else if (cnt2 == 0) { cnt2 = 1; cnd2 = val; }
    else { cnt1--; cnt2--; }
}
```

- In the first pass, we iterate over the array and update the counts of the candidates:
  - If the current number matches `cnd1`, we increase `cnt1`.
  - If the current number matches `cnd2`, we increase `cnt2`.
  - If `cnt1` is zero, we assign `val` to `cnd1` and reset `cnt1` to 1.
  - If `cnt2` is zero, we assign `val` to `cnd2` and reset `cnt2` to 1.
  - If neither condition is met, we decrement both `cnt1` and `cnt2`.

#### Step 4: Second Pass - Verify the Candidates

```cpp
cnt1 = 0;
cnt2 = 0;

for (int i = 0; i < n; i++) {
    int val = nums[i];
    if (val == cnd1) cnt1++;
    else if (val == cnd2) cnt2++;
}
```

- In the second pass, we reset `cnt1` and `cnt2` to zero, then count the actual occurrences of `cnd1` and `cnd2` in the array.

#### Step 5: Check for Majority Elements

```cpp
n = n / 3;

if (cnt1 > n) result.push_back(cnd1);
if (cnt2 > n) result.push_back(cnd2);
```

- We check if the counts of `cnd1` and `cnd2` are greater than `n/3`. If so, we add them to the result vector.

#### Step 6: Return the Result

```cpp
return result;
```

- Finally, we return the `result` vector, which contains all elements that appear more than `n/3` times.

---

### 📈 Complexity Analysis

#### Time Complexity:

- **First Pass:** The first loop runs in **O(n)** time, as it iterates through all elements in the array.
- **Second Pass:** The second loop also runs in **O(n)** time, as it counts the occurrences of the two candidates.

Thus, the overall time complexity is **O(n)**.

#### Space Complexity:

- We only store two candidates (`cnd1`, `cnd2`) and their counts (`cnt1`, `cnt2`), so the space complexity is **O(1)**, i.e., constant space.
- The result vector will store at most two elements (if there are two majority elements), so it also contributes **O(1)** space.

Therefore, the space complexity is **O(1)**.

---

### 🏁 Conclusion

This solution efficiently finds all elements that appear more than `n/3` times in a list. By using the Boyer-Moore Voting Algorithm, we optimize the process to **O(n)** time complexity with **O(1)** space complexity. The approach leverages a clever way to identify and verify potential majority candidates in two passes, making it both time-efficient and space-efficient.

#### Key Points:
- We identify two potential majority candidates in the first pass.
- The second pass verifies if these candidates appear more than `n/3` times.
- The time complexity is **O(n)**, and the space complexity is **O(1)**, making the solution ideal for large input sizes.
- The edge case of an empty array is handled at the start, ensuring robustness.

Now you're all set to efficiently tackle problems like this with the Boyer-Moore Voting Algorithm! 💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/majority-element-ii/description/)

---
{{< youtube Eua-UrQ_ANo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
