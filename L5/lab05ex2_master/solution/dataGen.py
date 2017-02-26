import fileinput
import random

filename = "reorderlist"

for i in range(10):
	outf = file(filename+str(i+1)+".in","wb")
	n = random.randint(5,5000)
	outf.write(str(n)+"\n");
	for j in range(n):
		outf.write(str(random.randint(0,100000))+" ")

