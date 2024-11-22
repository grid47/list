
+++
authors = ["grid47"]
title = "Leetcode 347: Top K Frequent Elements"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 347: Top K Frequent Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Sorting","Heap (Priority Queue)","Bucket Sort","Counting","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/347.webp"
youtube = "jFZx4Q7UL5c"
youtube_upload_date="2023-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/jFZx4Q7UL5c/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/347.webp" 
    alt="A sequence of elements where the most frequent ones glow brightly, showing the top K frequencies."
    caption="Solution to LeetCode 347: Top K Frequent Elements Problem"
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> ma;
        for(int x: nums)
            ma[x]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto [key, val]: ma)
            pq.push(make_pair(val, key));
        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, you're asked to return the **k most frequent elements** from a list of integers. Given an array of integers, your task is to identify and return the elements that appear most frequently. The order of the elements doesn't matter — just make sure to return the top **k** elements with the highest frequency!

Can you think of an efficient way to find the **top k frequent elements** without running into performance issues? Let’s break it down!

---

### 🧠 Approach

To solve this problem efficiently, we can use a combination of a **frequency map** and a **priority queue** (or **max heap**) to help us retrieve the top k frequent elements. Here’s a step-by-step breakdown:

1. **Count the Frequencies**: Start by counting how many times each element appears in the array.
2. **Use a Priority Queue**: Push the frequency-element pairs into a priority queue. This will allow us to quickly access the elements with the highest frequencies.
3. **Extract the Top k Elements**: Once the elements are sorted by frequency, we can pop the top k elements from the queue.

This approach ensures that we can efficiently retrieve the most frequent elements with minimal complexity. 💪

---

### 🔨 Step-by-Step Code Breakdown

Let’s go over the code to see how each part works!

#### Step 1: Count the Frequency of Elements
```cpp
map<int, int> ma;
for(int x: nums)
    ma[x]++;
```
- We start by using a `map<int, int>` to count the frequency of each element in the array `nums`. The key is the element, and the value is its frequency.
- The loop iterates through `nums` and increments the count of each element in the map.

#### Step 2: Push the Frequency-Pair into a Priority Queue
```cpp
priority_queue<pair<int, int>> pq;

for(auto [key, val]: ma)
    pq.push(make_pair(val, key));
```
- Next, we create a **priority queue** called `pq` to store the pairs of (frequency, element). 
- The priority queue sorts the pairs in descending order based on frequency, meaning that the element with the highest frequency will always be at the top.
- We iterate through the `map` and push each `(frequency, element)` pair into the queue.

#### Step 3: Extract the Top k Frequent Elements
```cpp
vector<int> ans;
while(k--) {
    ans.push_back(pq.top().second);
    pq.pop();
}
```
- Now, we initialize a `vector<int>` called `ans` to store the final result.
- The `while` loop runs `k` times, each time extracting the top element from the priority queue. We push the **element** (not the frequency) from the pair into `ans`.
- After each extraction, we remove the top element from the queue using `pq.pop()`.

#### Step 4: Return the Result
```cpp
return ans;
```
- Finally, we return the `ans` vector, which contains the top k frequent elements.

---

### 📈 Complexity Analysis

Let’s analyze the time and space complexity to ensure our solution is optimal.

#### Time Complexity:
- **O(n log n)**: Here’s the breakdown:
  1. **Counting the frequencies**: We iterate over the array once, so this step takes **O(n)**.
  2. **Inserting into the priority queue**: We insert each element into the queue. Each insertion takes **O(log m)**, where `m` is the number of unique elements in the map. In the worst case, `m` is equal to `n`, so the complexity for this step is **O(n log n)**.
  3. **Extracting the top k elements**: Extracting `k` elements from the queue takes **O(k log n)** time. Since `k` is often much smaller than `n`, this step is dominated by the previous steps.

Thus, the overall time complexity is **O(n log n)**.

#### Space Complexity:
- **O(n)**: We use a map to store the frequencies of the elements, and the priority queue holds up to `n` pairs in the worst case. So, the space complexity is proportional to the size of the input array.

---

### 🏁 Conclusion

We’ve successfully solved the problem of finding the **k most frequent elements** in an array with an optimal approach using a frequency map and a priority queue. 🎉

#### Recap:
- **Time Complexity**: **O(n log n)**, where `n` is the number of elements in the array.
- **Space Complexity**: **O(n)**, where `n` is the number of elements.
- The solution efficiently handles large arrays and varying frequencies of elements.
- By using a priority queue, we can quickly retrieve the **top k frequent elements**.

This approach is easy to understand, efficient, and works well for this type of problem. Keep practicing to sharpen your skills in working with heaps and frequency counting — they are powerful tools in algorithm design! 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/top-k-frequent-elements/description/)

---
{{< youtube jFZx4Q7UL5c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
