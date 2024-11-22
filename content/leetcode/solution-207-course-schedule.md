
+++
authors = ["grid47"]
title = "Leetcode 207: Course Schedule"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 207: Course Schedule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/207.webp"
youtube = "IWLpZbu1wco"
youtube_upload_date="2020-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/IWLpZbu1wco/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/207.webp" 
    alt="A calming flowchart with courses linking together, showing dependencies in a gentle, glowing path."
    caption="Solution to LeetCode 207: Course Schedule Problem"
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
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> cnt(n, 0);

        // Created graph and dependecy counter
        for(int i = 0; i < pre.size(); i++) {
            graph[pre[i][1]].push_back(pre[i][0]);
            cnt[pre[i][0]]++;
        }

         queue<int> q;

        // Triaged course which does not have any dependency.
        for(int i = 0; i < n; i++)
            if(cnt[i] == 0)
                q.push(i);
       

        while(!q.empty()) {
            int size = q.size();
            while(size-- > 0) {
                int course = q.front();
                q.pop();
                for(int dep: graph[course]) {

                    cnt[dep]--;

                    if(cnt[dep] == 0) {
                        q.push(dep);
                    }
                }                
            }
        }

        for(int i = 0; i < n; i++)
            if(cnt[i] != 0)
                return false;   

        return true;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Imagine you're trying to figure out if you can finish all your courses in a university system. 🎓📚 Each course has prerequisites, and these prerequisites form a directed graph. Each course is a node, and a directed edge from course A to course B means you must take course A before course B.

Given `n` courses and a list of prerequisite pairs, we need to determine if it’s possible to finish all the courses. If there's a cycle (i.e., one course depends on another, which depends on the first), it’s impossible to complete all the courses. Your task is to return `true` if you can finish all courses, and `false` if a cycle exists or if some courses cannot be completed due to unmet prerequisites. 🚫

#### Example:
- **Input:** `n = 2`, `pre = [[1, 0]]`
- **Output:** `true`

In this example, course 0 must be taken before course 1, and there’s no cycle, so it’s possible to finish all courses! ✅

---

### 🧠 Approach

To solve this, we’ll use **topological sorting**. The idea is:
1. **Build the graph:** Treat the courses as nodes and the prerequisites as directed edges.
2. **Use Kahn’s Algorithm:** This algorithm helps by removing nodes (courses) with no incoming edges (i.e., no prerequisites). If we can process all courses, there’s no cycle. If some courses remain unprocessed, we have a cycle!

Let’s break it down step by step. ⬇️

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initialize Data Structures
```cpp
vector<vector<int>> graph(n);
vector<int> cnt(n, 0);
```
- **`graph[n]`**: A vector of vectors to represent the directed graph. Each `graph[i]` holds the list of courses that depend on course `i`.
- **`cnt[n]`**: A vector to store the number of prerequisites (in-degree) for each course.

#### Step 2: Build the Graph and Count Dependencies
```cpp
for(int i = 0; i < pre.size(); i++) {
    graph[pre[i][1]].push_back(pre[i][0]);
    cnt[pre[i][0]]++;
}
```
- For each prerequisite pair `[a, b]`, course `b` must be taken before course `a`. So, we add an edge from `b` to `a`.
- Also, we increase the dependency count (`cnt[a]`) for each course `a` because it depends on another course (`b`).

#### Step 3: Queue Initialization (Courses with No Prerequisites)
```cpp
queue<int> q;
for(int i = 0; i < n; i++)
    if(cnt[i] == 0)
        q.push(i);
```
- We initialize a queue with courses that have no prerequisites (i.e., `cnt[i] == 0`). These courses can be taken first! 🎓

#### Step 4: Process Courses and Reduce Dependencies
```cpp
while(!q.empty()) {
    int size = q.size();
    while(size-- > 0) {
        int course = q.front();
        q.pop();
        for(int dep: graph[course]) {
            cnt[dep]--;
            if(cnt[dep] == 0) {
                q.push(dep);
            }
        }                
    }
}
```
- We process each course in the queue. For each course, we reduce the dependency count for its dependent courses.
- If the dependency count for a dependent course becomes 0, it means all its prerequisites are now completed, so we add it to the queue to process next.

#### Step 5: Check for Cycles (Unprocessed Courses)
```cpp
for(int i = 0; i < n; i++)
    if(cnt[i] != 0)
        return false;
```
- If any course still has a non-zero dependency count, it means we couldn’t process it (due to unmet prerequisites), which indicates a cycle. 🚫 In this case, we return `false`.

#### Step 6: Return True (All Courses Can Be Finished)
```cpp
return true;
```
- If we processed all the courses without encountering a cycle, we return `true`, meaning it's possible to finish all the courses! 🎉

---

### 📈 Complexity Analysis

Let’s analyze the time and space complexity of this solution. ⏱️💾

#### Time Complexity:
- **O(V + E):** 
  - **V (vertices)**: We process each course once, so that’s `n` courses.
  - **E (edges)**: For each prerequisite pair, we add an edge, resulting in `E` edges. We process each edge once when adjusting the in-degrees and when iterating over the course’s dependencies.
  - So, the overall time complexity is **O(V + E)**, which is efficient for this problem!

#### Space Complexity:
- **O(V + E):**
  - **Graph Storage:** We store the graph with `V` vertices and `E` edges.
  - **Dependency Count:** We store the in-degrees for each course, which requires an array of size `V`.
  - **Queue:** The queue stores at most `V` courses at any time, in the worst case.
  - Therefore, the space complexity is **O(V + E)**.

---

### 🏁 Conclusion

We’ve successfully solved the problem of determining if all courses can be completed using **Kahn’s Algorithm** for **topological sorting**. 🔄🎓 Here’s the recap:

1. **Time Efficiency:** The algorithm runs in **O(V + E)**, where `V` is the number of courses and `E` is the number of prerequisite pairs.
2. **Space Efficiency:** The space complexity is also **O(V + E)**, which is required to store the graph and auxiliary structures.
3. **Simplicity:** Using Kahn’s algorithm ensures that the solution is both simple and effective, avoiding recursion and handling large inputs easily.

This approach is perfect for resolving dependency-related problems like course scheduling or task ordering in a directed acyclic graph (DAG). Keep up the great work, and you’ll be mastering graph algorithms in no time! 🚀💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/course-schedule/description/)

---
{{< youtube IWLpZbu1wco >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
