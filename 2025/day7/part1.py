def parse():
	with open("inputs.csv") as f:
		x, y = 0, 0
		grid = {}
		start = None
		for line in f.read().splitlines():
			x = 0
			for c in line:
				coord = (x, y)
				grid[coord] = c
				if c == 'S':
					start = coord
				x += 1
			y += 1
		return grid, start

def main(grid, start):
	stack = [start]
	seen = set()
	counted = set()

	while stack:
		pos = stack.pop()
		if pos in seen:
			continue
		seen.add(pos)

		cell = grid.get(pos)
		if cell is None:
			continue

		x, y = pos
		down = (x, y + 1)
		down_cell = grid.get(down)

		if down_cell == '^':
			if down not in counted:
				counted.add(down)
			stack.append((x - 1, y + 1))
			stack.append((x + 1, y + 1))
		else:
			stack.append(down)

	return len(counted)



grid, start = parse()
print(main(grid, start))