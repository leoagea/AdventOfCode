def parse() -> list[str]:
	with open("../inputs.csv") as f:
		return [line for line in f.read().splitlines()]

def main(data: list[str]) -> None:
	leny = len(data)
	lenx = len(data[0])
	count = 0
	for y in range(leny):
		for x in range(lenx):
			if data[y][x] != '@':
				continue
			all_pos = [(y-1, x-1), (y-1,x), (y-1,x+1), (y, x-1), (y, x+1), (y+1, x-1), (y+1, x), (y+1, x+1)]
			around = [data[pos[0]][pos[1]]for pos in all_pos if pos[0] > -1 and pos[0] < leny and pos[1] > -1 and pos[1] < lenx]
			count += around.count('@') < 4
	return count

print(main(parse()))
