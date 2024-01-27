import math

l = 0
s = 0
w = 1

text = input("Text: ")
n = len(text)
for i in range(n):
    if text[i] == '!' or text[i] == '.' or text[i] == '?':
        s += 1
    if text[i] == ' ':
        w += 1
    if text[i].isalpha():
        l += 1

L = 100 * (l / w)
S = 100 * (s / w)
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
