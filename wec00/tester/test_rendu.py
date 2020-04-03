import os
import sys

if len(sys.argv) < 2:
	print("usage: "+sys.argv[0]+" folder" + " [studentlogin]")
else:
	os.system("gcc -o test.out srcs/unit_test.c "+sys.argv[1]+"/*.c"+ " -Wall -Wextra -Werror")
	if (len(sys.argv) == 3):
		print("-----------------------------\nTesting "+ sys.argv[2] +"'s project")
	os.system("./test.out")
	os.system("rm -f test.out")
