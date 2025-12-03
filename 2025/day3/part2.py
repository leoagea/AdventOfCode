def parse() -> list[str]:
	with open("input.csv") as f:
		return f.read().splitlines()
	
def best_k_digits(s: str) -> str:
	n = len(s)
	rem = n - 12
	stack = []

	for ch in s:
		while rem > 0 and stack and stack[-1] < ch:
			stack.pop()
			rem -= 1
		stack.append(ch)

	if len(stack) > 12:
		stack = stack[:12]

	return ''.join(stack)

def main(data: list[str]):
	total = 0
	for line in data:
		total += int(best_k_digits(line))
	return total

print(main(parse()))