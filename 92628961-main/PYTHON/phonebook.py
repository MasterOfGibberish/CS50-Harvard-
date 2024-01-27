from cs50 import get_string

people = {
    "Carter": "+8989898",
    "David": "+875545"
}

name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")