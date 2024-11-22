
+++
authors = ["grid47"]
title = "Leetcode 385: Mini Parser"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 385: Mini Parser in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/385.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/385.webp" 
    alt="A series of nested lists being parsed, with each level gently unfolding and being highlighted."
    caption="Solution to LeetCode 385: Mini Parser Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        
        function<bool(char)> isnumber = [](char c) { return (c == '-') || isdigit(c); };
        
        stack<NestedInteger> stk;
        stk.push(NestedInteger());

        for(auto it = s.begin(); it != s.end();) {
            const char &c = *it;
            if(isnumber(c)) {
                auto it2 = find_if_not(it, s.end(), isnumber);
                int val = stoi(string(it, it2));
                stk.top().add(NestedInteger(val));
                it = it2;
            }
            else {
                if(c == '[') {
                    stk.push(NestedInteger());
                } else if (c == ']') {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
                it++;
            }
        }
        NestedInteger res = stk.top().getList().front();
        return res;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

We’re given a string that represents a nested list of integers. This string can include numbers and lists of numbers, and those lists can be nested to any depth. Your task is to **deserialize** the string into a `NestedInteger` object.

A `NestedInteger` can either hold:
- A single integer.
- A list of other `NestedInteger` objects.

The goal is to parse the string and construct a `NestedInteger` object that reflects the structure of the input string. The string can contain nested lists, and your challenge is to ensure that the parsing handles these lists correctly and maintains the proper hierarchy.

---

### 🧠 Approach

To solve this problem, we’ll use a **stack-based parsing algorithm** that processes the string character by character. Here’s the step-by-step breakdown of the approach:

1. **Identify Nested Integer Types**:
   - A `NestedInteger` can either hold a single integer or a list of `NestedInteger` objects. We’ll recursively build this structure while parsing the string.

2. **Use a Stack**:
   - We’ll use a stack (`stack<NestedInteger>`) to keep track of the current state of the list as we parse the string.
   - When we encounter an opening bracket `[` it means we are starting a new list, so we push a new `NestedInteger` onto the stack.
   - When we encounter a closing bracket `]`, we pop the current `NestedInteger` from the stack (representing the completed list) and add it to the `NestedInteger` on top of the stack.

3. **Handle Integers**:
   - When we encounter a number, we parse it, create a new `NestedInteger` holding that number, and add it to the current `NestedInteger` on the stack.

---

### 🔨 Step-by-Step Code Breakdown

Let's dive into the code to see how we implement this approach:

#### 1. **Helper Function to Check for Numbers**
```cpp
function<bool(char)> isnumber = [](char c) { return (c == '-') || isdigit(c); };
```
- This helper function checks if a character is part of a number (either a minus sign or a digit).
- It helps us identify and parse integer values as we read through the string.

#### 2. **Initialize the Stack**
```cpp
stack<NestedInteger> stk;
stk.push(NestedInteger());
```
- We initialize a stack of `NestedInteger` objects.
- Initially, we push an empty `NestedInteger` onto the stack, which represents the root of the nested list.

#### 3. **Iterate Through the String**
```cpp
for(auto it = s.begin(); it != s.end();) {
    const char &c = *it;
```
- We use an iterator to traverse through the string `s`. The loop continues until we reach the end of the string.
- `c` represents the current character being processed.

#### 4. **Parsing Numbers**
```cpp
if(isnumber(c)) {
    auto it2 = find_if_not(it, s.end(), isnumber);
    int val = stoi(string(it, it2));
    stk.top().add(NestedInteger(val));
    it = it2;
}
```
- When we encounter a number, we use `find_if_not` to find the point where the number ends.
- We convert the substring representing the number into an integer using `stoi` and create a new `NestedInteger` holding that value.
- We then add this `NestedInteger` to the current list represented by the `NestedInteger` on top of the stack.

#### 5. **Handling Opening Bracket (`[`)**
```cpp
else {
    if(c == '[') {
        stk.push(NestedInteger());
    }
```
- If we encounter an opening bracket `[`, it indicates that we are starting a new list.
- We push a new empty `NestedInteger` onto the stack, representing the start of the new list.

#### 6. **Handling Closing Bracket (`]`)**
```cpp
else if (c == ']') {
    NestedInteger ni = stk.top();
    stk.pop();
    stk.top().add(ni);
}
```
- When we encounter a closing bracket `]`, it means we’ve completed a list.
- We pop the `NestedInteger` from the stack, which represents the completed list, and add it to the `NestedInteger` on top of the stack (which is its parent).

#### 7. **Increment the Iterator**
```cpp
it++;
```
- After processing the current character, we move the iterator to the next character in the string.

#### 8. **Return the Final Result**
```cpp
NestedInteger res = stk.top().getList().front();
return res;
```
- After the loop finishes, the stack will contain a single `NestedInteger` object, which represents the entire deserialized structure.
- We return the first element of the list from the top `NestedInteger` object on the stack as the result.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **Time Complexity**: The time complexity of this algorithm is **O(n)**, where `n` is the length of the input string `s`. 
  - Each character in the string is processed exactly once.
  - For each character, we either push or pop elements from the stack, which takes constant time.
  - The `stoi` operation and other string manipulations inside the loop also run in constant time.

#### Space Complexity:
- **Space Complexity**: The space complexity is **O(n)**, where `n` is the length of the string.
  - In the worst case, all elements in the string could form separate nested lists, requiring space proportional to the input string size.
  - The stack stores the nested integer objects, and the space required for these objects is proportional to the number of elements being stored.

---

### 🏁 Conclusion

This algorithm efficiently deserializes a string into a nested list structure using a stack-based approach. By iterating through the string once and managing the parsing with a stack, we can handle both numbers and nested lists in a way that maintains the correct hierarchy.

**Key Points**:
- **Time Complexity**: **O(n)** – Linear in the size of the input string.
- **Space Complexity**: **O(n)** – Linear space required for storing the nested structure.
- **Efficient Parsing**: We use a stack to track the current state of the list and ensure that each element is correctly nested.

With this approach, you can efficiently deserialize any valid string representation of a nested list! Happy coding! 🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/mini-parser/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
