def parse():
	with open("inputs.csv") as f:
		top = f.read().strip().partition("\n\n")[0]
	return [tuple(sorted(map(int, line.split("-")))) for line in top.splitlines()]

def main(ranges):
	ranges = sorted(ranges)
	merged = []
	for lo, hi in ranges:
		if merged and lo <= merged[-1][1] + 1:
			merged[-1] = (merged[-1][0], max(merged[-1][1], hi))
		else:
			merged.append((lo, hi))
	return sum(hi - lo + 1 for lo, hi in merged)

print(main(parse()))