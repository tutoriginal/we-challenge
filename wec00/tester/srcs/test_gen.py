import sys
import random

def gen_test(n):
	i = 0
	func = "print_speed"
	#func = "assert"
	while (i < n):
		j = 0
		sys.stdout.write(func+"(\"")
		while (j < random.randrange(1, 1919)):
			c = chr(random.randrange(33, 126))
			if c == '\"' or c == '\\' or c == '?':
				pass
			else:
				sys.stdout.write(c)
			j += 1
		sys.stdout.write("\");\n")
		i += 1
	print("printf(\"Score = %llu\\n\", average_score /= n); // The higher the score the slower is the function on average\n}\n")
if len(sys.argv) < 2:
	print("usage: "+sys.argv[0]+" nbtest")
else:
	gen_test(int(sys.argv[1]))
	
