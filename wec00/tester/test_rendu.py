import os
import sys

if len(sys.argv) < 2:
	print("usage: "+sys.argv[0]+" folder")
else:
 os.system("gcc -o test.out unit_test.c "+sys.argv[1]+"/*.c"+ " -Wall -Wextra -Werror")
