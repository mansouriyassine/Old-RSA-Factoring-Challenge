import sys

def factorize(number):
    factors = []
    divisor = 2
    while number > 1:
        while number % divisor == 0:
            factors.append(divisor)
            number //= divisor
        divisor += 1
    return factors

if len(sys.argv) != 2:
    print("Usage: factors <file>")
    sys.exit(1)

input_file = sys.argv[1]

try:
    with open(input_file, 'r') as file:
        for line in file:
            n = int(line.strip())
            factors_list = factorize(n)
            factors_str = '*'.join(map(str, factors_list))
            print(f"{n}={factors_str}")

except FileNotFoundError:
    print(f"Error: File '{input_file}' not found.")
    sys.exit(1)

except ValueError:
    print(f"Error: Invalid data in '{input_file}'. Make sure all lines contain valid natural numbers greater than 1.")
    sys.exit(1)
