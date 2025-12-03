def parse() -> list[str]:
	with open("input.csv") as f:
		return f.read().splitlines()

def main(data: list[str]):
	total = 0
	for line in data:
		idx_max = line.index(max(line))
		if idx_max == len(line) - 1:
			idx_max = line.index(max(line[:-1]))
		total += int(line[idx_max] + max(line[idx_max + 1:]))
	return total

print(main(parse()))