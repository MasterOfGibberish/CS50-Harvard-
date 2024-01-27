from cs50 import get_int

number = get_int("type your credit card number: ")
g = 0
cc = number

while cc > 0:
    cc = cc // 10
    g += 1

if g < 13 or g > 16:
    print("INVALID")
    exit(0)

sum, sum1, sum2, index, index2, index3 = 0, 0, 0, 0, 0, 0
skaidymas = 10
skaidymas2 = 1

for i in range(g, 0, -1):
    index = number // skaidymas2 % skaidymas
    skaidymas2 = skaidymas2 * 10

    if g % 2 == 0:
        if i % 2 == 0:
            sum1 += index
        else:
            if index * 2 > 9:
                index = index * 2
                index2 = index % 10
                index3 = index // 10 % 10
                index = index2 + index3
                sum2 += index
            else:
                sum2 += index * 2
    else:
        if i % 2 == 0:
            if index * 2 > 9:
                index = index * 2
                index2 = index % 10
                index3 = index // 10 % 10
                index = index2 + index3
                sum2 += index
            else:
                sum2 += index * 2
        else:
            sum1 += index

sum = sum1 + sum2

if sum % 10 != 0:
    print("INVALID")
    exit(0)

n = number

while n > 100:
    n = n // 10

n1 = n % 10
n2 = n // 10 % 10

if g >= 13 and g <= 16 and index == 4:
    print("VISA")
    exit(0)
elif g == 15 and n2 == 3 and (n1 == 4 or n1 == 7):
    print("AMEX")
    exit(0)
elif g == 16 and n2 == 5 and (0 < n1 < 6):
    print("MASTERCARD")
    exit(0)
else:
    print("INVALID")
    exit(0)
