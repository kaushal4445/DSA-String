🔄 Rotate String (LeetCode)
📌 Problem Statement

Given two strings s and goal, return true if and only if s can become goal after some number of shifts.

A shift means moving the first character of s to the end.

🧠 Examples
Input:  s = "abcde", goal = "cdeab"
Output: true
Input:  s = "abcde", goal = "abced"
Output: false
🚀 Approach 1: Brute Force (Rotation Simulation)
💡 Idea

Generate all possible rotations of string s and compare each with goal.

🔍 Logic

Rotate string at every index i

Use:

rotated = s.substr(i) + s.substr(0, i)

If any rotation matches goal, return true

🧾 Code (C++)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated == goal) {
                return true;
            }
        }
        return false;
    }
};
⏱️ Complexity
Type	Complexity
Time	O(n²)
Space	O(n)
⚡ Approach 2: Optimized (String Doubling Trick)
💡 Idea

If goal is a rotation of s, then it must be a substring of s + s.

🔍 Why it works?

All rotations of s exist inside s + s.

Example:

s = "abcde"
s + s = "abcdeabcde"

Rotations:
abcde
bcdea
cdeab
deabc
eabcd
🧾 Code (C++)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};
🔍 Important Concept
🔸 string::npos

Special value meaning "not found"

If find() does NOT find substring → returns npos

doubledS.find(goal) != string::npos

👉 Means substring exists

⏱️ Complexity
Type	Complexity
Time	O(n)
Space	O(n)
🆚 Comparison
Feature	Brute Force	Optimized
Idea	Try all rotations	Use substring trick
Time	O(n²) ❌	O(n) ✅
Code Simplicity	Medium	Easy
Efficiency	Slow	Fast
