from functools import reduce
from operator import mul, add

def parse():
	with open("inputs.csv") as f:
		cols = list(zip(*[line.split() for line in f.read().strip().split("\n")]))
	return [(tuple(map(int, col[:4])), col[4]) for col in cols]

def main():
	total = 0
	for nums, op in parse():
		func = mul if op == "*" else add
		result = reduce(func, nums)
		total += result
	return total

print(main())