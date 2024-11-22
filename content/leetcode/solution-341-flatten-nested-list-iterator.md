
+++
authors = ["grid47"]
title = "Leetcode 341: Flatten Nested List Iterator"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 341: Flatten Nested List Iterator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Design","Queue","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/341.webp"
youtube = "4ILiBgLokM8"
youtube_upload_date="2023-10-20"
youtube_thumbnail="https://i.ytimg.com/vi/4ILiBgLokM8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/341.webp" 
    alt="A nested list unfolding and flattening into a 1D array, with each item softly glowing as it appears."
    caption="Solution to LeetCode 341: Flatten Nested List Iterator Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we’re asked to design a **NestedIterator** for a nested list of integers. The list can contain both integers and other lists, and our goal is to iterate over all the integers in a **flattened** order.

#### Example:
Given the nested list:
```cpp
[[1,1],2,[1,1]]
```
The iterator should return:
```cpp
1, 1, 2, 1, 1
```
We need to implement an iterator that can:
- Return the next integer using the `next()` method.
- Check if there are more integers with the `hasNext()` method.

---

### 🧠 Approach

We’ll use a **stack-based approach** to manage our position in the nested list. A stack will help us navigate through the nested structure and flatten it as we go.

#### Key Insights:
1. **Stack-Based Iteration**: 
   We use a stack to track the iterators for each level of the nested list. Each element in the stack represents a position in the current list, allowing us to “pop” and “push” as we explore deeper levels.
   
2. **Handling Nested Lists**: 
   When we encounter a list, we push its start and end iterators onto the stack. This allows us to continue flattening from that nested level.

3. **Handling Integer Values**: 
   If the element is an integer, we return it directly.

4. **Efficiency**: 
   By using the stack, we only push and pop iterators when necessary. This allows us to keep our solution efficient, ensuring each call to `next()` and `hasNext()` runs in constant time, regardless of how deep the nesting goes.

---

### 🔨 Step-by-Step Code Breakdown

Let’s break the solution down and understand how each part works.

#### Step 1: Constructor
```cpp
NestedIterator(vector<NestedInteger> &nestedList) {
    begins.push(nestedList.begin());
    ends.push(nestedList.end());
}
```
- In the constructor, we initialize two stacks:
  - `begins`: Tracks the current iterator for each list.
  - `ends`: Tracks the end iterator for each list.

We push the beginning and end of the input `nestedList` into the stacks.

#### Step 2: `next()` Method
```cpp
int next() {
    hasNext();
    return (begins.top()++)->getInteger();
}
```
- The `next()` method first calls `hasNext()` to ensure that we have a next integer to return.
- It then returns the integer at the current position of `begins.top()`, incrementing the iterator (`begins.top()++`) to move to the next position.

#### Step 3: `hasNext()` Method
```cpp
bool hasNext() {
    while (begins.size()) {
        if (begins.top() == ends.top()) {
            begins.pop();
            ends.pop();
        } else {
            auto x = begins.top();
            if (x->isInteger())
                return true;
            begins.top()++;
            begins.push(x->getList().begin());
            ends.push(x->getList().end());
        }
    }
    return false;
}
```
- The `hasNext()` method ensures we’re always pointing to an integer.
- **Step 1**: While `begins` is not empty:
  - If the top iterator of `begins` equals the top iterator of `ends`, we’ve reached the end of the current list, so we pop both stacks and backtrack one level.
  - If the current element is a list, we push its start and end iterators onto the stack to continue flattening.
  - If the current element is an integer, we immediately return `true`.
- **Step 2**: If no integers are left, we return `false`.

#### Step 4: Stack for Nested Traversal
- The stacks `begins` and `ends` store iterators that point to the current element and the end of each list. By managing these iterators, we can easily traverse any depth of nesting and ensure that `next()` always returns the next integer.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **`next()`**: Each call to `next()` operates in **O(1)** time. We’re simply accessing the next integer and incrementing the iterator.
- **`hasNext()`**: In the worst case, `hasNext()` may need to traverse the entire nested structure to find the next integer. However, each element is visited only once, so the time complexity is still **O(1)** per call.

#### Space Complexity:
- **O(d)**, where `d` is the maximum depth of the nested list. The space complexity comes from the stacks, which hold iterators for each level of nesting.

---

### 🏁 Conclusion

The **NestedIterator** class efficiently flattens a nested list using a stack-based approach. We use iterators and stacks to navigate through the nested structure and ensure that both `next()` and `hasNext()` are executed in constant time.

#### Key Benefits:
- **Efficiency**: Both `next()` and `hasNext()` operate in **O(1)** time, making the solution fast, even for deeply nested lists.
- **Simplicity**: The stack-based approach is simple yet powerful, handling arbitrary nesting without the need for complex recursion.
- **Flexibility**: This approach can easily adapt to other nested structures as well.

By mastering this approach, you'll be well-equipped to handle problems involving nested data structures and iteration. Keep practicing these techniques—flattening complex structures has never been so efficient! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/flatten-nested-list-iterator/description/)

---
{{< youtube 4ILiBgLokM8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
