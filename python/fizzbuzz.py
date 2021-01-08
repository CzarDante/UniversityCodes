import time
import colorama
from colorama import Fore,Back,Style,init
init()
red = "\03[1;31m"
end = "\033[0;0m"
for i in range(100000):
    num = i
    time.sleep(0.1)
    if num%3==0:
        if num%5==0:
            print(Fore.RED + "fizz buzz")
        else:
            print(Fore.YELLOW +"fizz")
    elif num%5==0:
            print(Fore.GREEN + "buzz")
    else:
        print(Fore.WHITE + f"{num} ")