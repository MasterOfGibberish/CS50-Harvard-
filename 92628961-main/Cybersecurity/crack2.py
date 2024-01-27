from string import ascii_letters #access to all decimal digits
from itertools import product #for instance 10*10* ... zdz veiksmai su skaiciais

for passcode in product (ascii_letters, repeat=4):
    print(*passcode)