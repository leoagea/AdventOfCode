def parse() -> list[str]:
	with open("../inputs.csv") as f:
		return [line for line in f.read().splitlines()]

def remove(data: list[str]) -> None:
	print(data)
	leny = len(data)
	lenx = len(data[0])
	count = 0
	copy = []
	for y in range(leny):
		s = ""
		for x in range(lenx):
			if data[y][x] != '@':
				s += data[y][x]
				continue
			all_pos = [(y-1, x-1), (y-1,x), (y-1,x+1), (y, x-1), (y, x+1), (y+1, x-1), (y+1, x), (y+1, x+1)]
			around = [data[pos[0]][pos[1]]for pos in all_pos if pos[0] > -1 and pos[0] < leny and pos[1] > -1 and pos[1] < lenx]
			if around.count('@') < 4:
				s += "."
				count += 1
			else:
				s += data[y][x]
		copy.append("".join(s))
	return (count, copy)

def main(data: list[str]) -> int:
	count, copy = remove(data)
	print(count)
	total = count
	while count > 0:
		count, copy = remove(copy)
		total += count
	return total

print(main(parse()))