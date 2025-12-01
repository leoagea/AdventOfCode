def parse() -> list[tuple[str, int]]:
	inputs = []
	with open('input.csv', 'r') as f:
		return [(line[0], int(line[1:])) for line in f.read().split()]

def main(inputs) -> int:
	start = 50
	step = []
	for d, n in inputs:
		start = (start + (n if d == 'R' else -n)) % 100
		step.append(start)
	return step.count(0)

print(main(parse()))