from random import randint
t = 1
print(t)
for i in range(1, t+1):
	n = randint(950, 1000)
	print(n)
	for j in range(1, n+1):
		print(randint(1, 1000000000), end = ' ')