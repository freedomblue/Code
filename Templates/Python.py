try:
	while True:
		divisor = int(input())
		count = 0
		if divisor % 2 != 0:
			count = int(1999999/divisor)
		if count % 2 == 0:
			count = count / 2
		else:
			count = count / 2 + 1
		print (int(count))
except EOFError:
	pass