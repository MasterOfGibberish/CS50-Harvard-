try:
    x = int(input("x: "))
except ValueError:
    print("it is not an int")
    exit()
try:
    y = int(input("y: "))
except ValueError:
    print("it is not an int")
    exit()
print(x + y)