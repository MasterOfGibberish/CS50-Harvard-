from string import ascii_letters, digits, punctuation #access to all decimal digits
from itertools import product #for instance 10*10* ... zdz veiksmai su skaiciais

for passcode in product (ascii_letters, repeat=8):
    print(*passcode)

#sitas kodas uztruktu apie 10,000 metu, tad patarciau nelaukti :DD