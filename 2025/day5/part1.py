def parse():
	with open("inputs.csv") as f:
		top, _, bottom = f.read().strip().partition("\n\n")
	ranges = [tuple(map(int, line.split("-"))) for line in top.splitlines()]
	keys = [int(x) for x in bottom.splitlines() if x.strip()]
	return ranges, keys
	
def main(ranges, keys):
	return sum(1 for k in keys if any(min <= k <= max for min, max in ranges))

ranges, keys = parse()
print(main(ranges, keys))