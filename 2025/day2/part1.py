def parse() -> list[list[str]]:
	with open("inputs.csv") as f:
		return [line.split('-') for line in f.read().strip().split(',')]

def sum_invalid_in_range(L: int, R: int) -> int:
	if L > R:
		return 0
	
	total = 0
	max_k = len(str(R)) // 2
	
	for k in range(1, max_k + 1):
		multiplier = 10**k + 1
		min_x = 10**(k - 1)
		max_x = 10**k - 1
		
		low_x = max(min_x, (L + multiplier - 1) // multiplier)
		high_x = min(max_x, R // multiplier)
		
		if low_x <= high_x:
			count = high_x - low_x + 1
			sum_x = (low_x + high_x) * count // 2
			total += sum_x * multiplier
	
	return total

def main(data: list[list[str]]) -> int:
	total = 0
	for arr in data:
		a, b = int(arr[0]), int(arr[1])
		if a > b:
			a, b = b, a
		total += sum_invalid_in_range(a, b + 1)
	return total

print(main(parse()))