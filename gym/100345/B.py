f = []
p = []

def binom(n, k):
	if k > n:
		return 0

	num = f[n]
	den = f[k] * f[n - k]

	return num // den

def main():

	F = open("derangements.in", "r")

	n = F.read()
	n = int(n)

	f.append(1)
	for i in range(n + 5):
		f.append(f[i] * (i + 1))

	p.append(1)
	for i in range(n + 5):
		p.append(2 * p[i]);

	ans = 0

	for i in range(n + 1):

		cur = binom(n, i) * f[n - i] * p[n - i]

		if i % 2 == 1:
			ans -= cur
		else:
			ans += cur

		
	o = open("derangements.out", "w")
	o.write(str(ans) + "\n")


main()