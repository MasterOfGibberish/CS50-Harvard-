from string import digits #access to all decimal digits
from itertools import product #for instance 10*10* ... zdz veiksmai su skaiciais

for passcode in product (digits, repeat=4):
    print(*passcode)