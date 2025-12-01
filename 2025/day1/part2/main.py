import math

def parse() -> list[tuple[str, int]]:
	with open('input.csv', 'r') as f:
		return [(line[0], int(line[1:])) for line in f.read().split()]

def main(inputs) -> int:
	start = 50
	count = 0
	for d, n in inputs:
		side = 1 if d == 'R' else -1
		first = ((-side * start) % 100) or 100
		count += 1 + (n - first) // 100
		start = (start + side * n) % 100
	return count

print(main(parse()))