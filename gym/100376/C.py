

def P( a,  b, c):

	if b == 0:
		return 1;
	if(b % 2 == 1):
		return (a*P(a, b - 1, c)) % c;
	else:
		tmp = P(a, b / 2, c);
		return (tmp*tmp)% c;

tc = input()

while tc:
	
	cad = raw_input().split()
	
	x = int(cad[0])
	y = int(cad[1])
	c = int(cad[2])

	print P(y, x, c)
	
	tc -= 1