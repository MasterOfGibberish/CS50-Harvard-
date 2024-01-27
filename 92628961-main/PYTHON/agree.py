from cs50 import get_string

s = get_string("Do you agree? ").lower

if s.lower in ["Y", "y", "yes", "YES"]:
    print("agreed")
elif s == "N" or s == "n":
    print("disagree")
else:
    print("lopas!")