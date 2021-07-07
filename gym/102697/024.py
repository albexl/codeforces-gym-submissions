import math

def main():

	s = input().split()

	points = [0, 0]

	line = input().split()
	for i in range(2):
		points[i] += 2 * int(line[i])

	line = input().split()
	for i in range(2):
		points[i] += 3 * int(line[i])

	line = input().split()
	for i in range(2):
		points[i] += int(line[i])

	winner = 0 if points[0] > points[1] else 1

	print(s[winner])

main()