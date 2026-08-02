# 🔤 Valid Anagram (LeetCode 242)

## 📌 Problem Statement

Given two strings `s` and `t`, return **true** if `t` is an **anagram** of `s`, otherwise return **false**.

### What is an Anagram?

An **anagram** is a word or phrase formed by rearranging the letters of another word, using **all the original letters exactly once**.

---

# 📝 Example 1

### Input

```text
s = "anagram"
t = "nagaram"
```

### Output

```text
true
```

### Explanation

Both strings contain the same characters.

```
anagram

↓

Rearrange

↓

nagaram
```

So the answer is **true**.

---

# 📝 Example 2

### Input

```text
s = "rat"
t = "car"
```

### Output

```text
false
```

### Explanation

The characters are different.

```
rat

↓

Sort

art

car

↓

Sort

acr
```

Since

```
art ≠ acr
```

Return **false**.

---

# 💡 Intuition

Two strings are anagrams if they contain exactly the same characters with the same frequency.

Instead of counting every character manually, we can simply:

1. Check if both strings have the same length.
2. Sort both strings.
3. Compare them character by character.

If every character matches after sorting, the strings are anagrams.

---

# ✅ C++ Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < s.length(); i++){

            if(s[i] != t[i]){
                return false;
            }
        }

        return true;
    }
};
```

---

# 🔍 Step-by-Step Explanation

---

# Step 1 : Check Length

```cpp
if(s.length() != t.length()){
    return false;
}
```

### Why?

If two strings have different lengths, they cannot be anagrams.

### Example

```
s = "abc"

t = "ab"
```

Lengths

```
3

2
```

Different lengths

↓

Return

```
false
```

---

# Step 2 : Sort Both Strings

```cpp
sort(s.begin(), s.end());
sort(t.begin(), t.end());
```

Sorting arranges characters in alphabetical order.

### Example

Before Sorting

```
s = anagram

t = nagaram
```

After Sorting

```
aaagmnr

aaagmnr
```

Diagram

```
Before

anagram

nagaram

      │
      ▼

After Sorting

aaagmnr

aaagmnr
```

Now both strings become identical.

---

# Step 3 : Compare Characters

```cpp
for(int i = 0; i < s.length(); i++)
```

Compare every character.

---

## First Character

```
aaagmnr

^

aaagmnr

^
```

Compare

```
a == a
```

✔ Match

---

## Second Character

```
aaagmnr

 ^

aaagmnr

 ^
```

Compare

```
a == a
```

✔ Match

---

## Third Character

```
aaagmnr

  ^

aaagmnr

  ^
```

Compare

```
a == a
```

✔ Match

Continue...

Every character matches.

Return

```
true
```

---

# 📊 Dry Run

## Input

```text
s = "anagram"

t = "nagaram"
```

---

## Step 1

Check Length

```
8 == 8
```

Continue.

---

## Step 2

Sort

```
anagram

↓

aaagmnr
```

```
nagaram

↓

aaagmnr
```

---

## Step 3

Compare

| Index | s | t | Match |
|------:|:-:|:-:|:-----:|
|0|a|a|✅|
|1|a|a|✅|
|2|a|a|✅|
|3|g|g|✅|
|4|m|m|✅|
|5|n|n|✅|
|6|r|r|✅|

All characters match.

Return

```
true
```

---

# 🎯 Example 2

### Input

```text
s = "rat"

t = "car"
```

---

## Step 1

Lengths

```
3

3
```

Equal.

---

## Step 2

Sort

```
rat

↓

art
```

```
car

↓

acr
```

Diagram

```
art

acr
```

---

## Step 3

Compare

| Index | s | t | Match |
|------:|:-:|:-:|:-----:|
|0|a|a|✅|
|1|r|c|❌|

Characters are different.

Return

```
false
```

---

# 🌟 Visual Explanation

Input

```
anagram

nagaram
```

↓

Check Length

```
Equal
```

↓

Sort Both Strings

```
aaagmnr

aaagmnr
```

↓

Compare

```
a ✔

↓

a ✔

↓

a ✔

↓

g ✔

↓

m ✔

↓

n ✔

↓

r ✔
```

↓

Return

```
true
```

---

# ❌ Example Where It Fails

Input

```
hello

world
```

Sort

```
ehllo

dlorw
```

Compare

```
e

d
```

Not equal

↓

Return

```
false
```

---

# 🎨 Complete Flow Diagram

```
Input

s

t

      │
      ▼

Are lengths equal?

├── No
│
▼
Return false

└── Yes
      │
      ▼

Sort s

Sort t

      │
      ▼

Compare every character

      │
      ▼

All characters same?

├── No
│
▼
Return false

└── Yes
      │
      ▼

Return true
```

---

# ⚖️ Why Sorting Works?

Suppose

```
listen

silent
```

Sort both strings.

```
eilnst

eilnst
```

Both become exactly the same.

Therefore,

```
listen

silent
```

are anagrams.

Another example

```
triangle

integral
```

Sort

```
aegilnrt

aegilnrt
```

Again, both are identical.

---

# ⏱ Time Complexity

Sorting first string

```
O(n log n)
```

Sorting second string

```
O(n log n)
```

Comparing characters

```
O(n)
```

### Total

```
O(n log n)
```

---

# 💾 Space Complexity

No extra data structure is used (ignoring the sorting algorithm).

```
O(1)
```

---

# ✅ Key Points

- First check if the lengths are equal.
- Sort both strings alphabetically.
- Compare each character one by one.
- If any character differs, return `false`.
- If every character matches, return `true`.

---

# 📌 Summary

✔ Check string lengths.

✔ Sort both strings.

✔ Compare character by character.

✔ If all characters match, return `true`.

✔ Otherwise, return `false`.

### Complexity

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`
