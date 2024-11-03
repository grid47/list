
+++
authors = ["Crafted by Me"]
title = "Leetcode 2019: The Score of Students Solving Math Expression"
date = "2019-04-24"
description = "In-depth solution and explanation for Leetcode 2019: The Score of Students Solving Math Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-score-of-students-solving-math-expression/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public int scoreOfStudents(String s, int[] answers) {

        int n = (int) (s.length() / 2 + 1);
        Set<Integer>[][] dp = new Set[n][n];
        for(int i = 0; i < n; i++) {
            dp[i][i] = new HashSet();
            dp[i][i].add(s.charAt(2 * i) - '0');
        }

        for(int dif = 1; dif < n; dif++) {
        for(int start = 0; start < n - dif; start++) {

                int end = start + dif;
                dp[start][end] = new HashSet<>();

                for(int i = 2 * start + 1; i < 2 * end; i += 2) {
                    if (s.charAt(i) == '+') {
                        for(int a : dp[start][(int) (i / 2)])
                        for(int b : dp[(int) (i / 2) + 1][end])
                            if(a + b <= 1000) dp[start][end].add(a + b);
                    } else {
                        for(int a : dp[start][(int) (i / 2)])
                        for(int b : dp[(int) (i / 2) + 1][end])
                            if(a + b <= 1000) dp[start][end].add(a * b);
                    }
                }
            }
        }

        int crct = parse(s), ans = 0;
        for (int x : answers) {
                 if (x == crct)                ans += 5;
            else if (dp[0][n - 1].contains(x)) ans += 2;
        }
        return ans;
    }
    
    private int parse(String s) {
        List<Integer> stk = new ArrayList();
        int num = 0;
        char op = '+';
        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if(ch >= '0' && ch <= '9') 
            {
                num = ch - '0';
                                    
            }
            if(i == s.length() - 1 || ch == '+' || ch == '*' ) {
                if (op == '+')
                {
                    stk.add(num);
                }
                else
                {                                    
                    int y = stk.get(stk.size() - 1);
                    stk.remove(stk.size() - 1);
                    stk.add(y * num);
                }
                num = 0;
                op = ch;
            }
        }
        int res = 0;
        for(int x : stk) res += x;
        return res;
    }
}
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

