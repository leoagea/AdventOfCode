def parse() -> list[list[str]]:
	with open("inputs.csv") as f:
		return [line.split('-') for line in f.read().strip().split(',')]

def get_divisors(n: int) -> list[int]:
	divisors = []
	for i in range(1, n):
		if n % i == 0:
			divisors.append(i)
	return divisors

def sum_repeated_pattern(L: int, R: int, k: int, n: int) -> int:
	r = n // k 
	
	p = 10 ** k
	multiplier = (p ** r - 1) // (p - 1)
	
	min_x = 10 ** (k - 1) if k > 1 else 1
	max_x = 10 ** k - 1
	
	low_x = max(min_x, (L + multiplier - 1) // multiplier)
	high_x = min(max_x, R // multiplier)
	
	if low_x > high_x:
		return 0
	
	count = high_x - low_x + 1
	sum_x = (low_x + high_x) * count // 2
	return sum_x * multiplier

def is_primitive_pattern(x: int, k: int) -> bool:
	s = str(x).zfill(k)
	for sub_k in range(1, k):
		if k % sub_k == 0:
			pattern = s[:sub_k]
			if pattern * (k // sub_k) == s:
				return False
	return True

def count_primitive_patterns(k: int) -> list[int]:
	min_x = 10 ** (k - 1) if k > 1 else 1
	max_x = 10 ** k - 1
	return [x for x in range(min_x, max_x + 1) if is_primitive_pattern(x, k)]

def sum_primitive_in_range(L: int, R: int, k: int, n: int) -> int:
	r = n // k
	p = 10 ** k
	multiplier = (p ** r - 1) // (p - 1)
	
	min_x = 10 ** (k - 1) if k > 1 else 1
	max_x = 10 ** k - 1
	
	low_x = max(min_x, (L + multiplier - 1) // multiplier)
	high_x = min(max_x, R // multiplier)
	
	if low_x > high_x:
		return 0
	
	total = 0
	for x in range(low_x, high_x + 1):
		if is_primitive_pattern(x, k):
			total += x * multiplier
	return total

def sum_invalid_in_range(L: int, R: int) -> int:
	if L > R:
		return 0
	
	min_digits = len(str(L))
	max_digits = len(str(R))
	
	total = 0
	
	for n in range(min_digits, max_digits + 1):
		n_min = max(L, 10 ** (n - 1)) if n > 1 else max(L, 1)
		n_max = min(R, 10 ** n - 1)
		
		if n_min > n_max:
			continue
		
		pattern_lengths = [k for k in get_divisors(n) if n // k >= 2]
		
		if not pattern_lengths:
			continue
		
		for k in pattern_lengths:
			total += sum_primitive_in_range(n_min, n_max, k, n)
	
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