def right_triangle(n):
    print("\nRight Triangle:")
    for i in range(1, n + 1):
        print("*" * i)

def inverted_triangle(n):
    print("\nInverted Triangle:")
    for i in range(n, 0, -1):
        print("*" * i)

def pyramid(n):
    print("\nPyramid:")
    for i in range(1, n + 1):
        print(" " * (n - i) + "*" * (2 * i - 1))

def diamond(n):
    print("\nDiamond:")
    for i in range(1, n + 1):
        print(" " * (n - i) + "*" * (2 * i - 1))
    for i in range(n - 1, 0, -1):
        print(" " * (n - i) + "*" * (2 * i - 1))

def number_pattern(n):
    print("\nNumber Pattern:")
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            print(j, end=" ")
        print()

def floyd_triangle(n):
    print("\nFloyd’s Triangle:")
    num = 1
    for i in range(1, n + 1):
        for j in range(i):
            print(num, end=" ")
            num += 1
        print()

def main():
    n = 5

    right_triangle(n)
    inverted_triangle(n)
    pyramid(n)
    diamond(n)
    number_pattern(n)
    floyd_triangle(n)

if __name__ == "__main__":
    main()
