from cs50 import get_int


def main():
    while True:
        try:
            height = get_int("Height: ")
            if 1 <= height <= 8:
                return pyramid(height)
        except ValueError:
            pass


def pyramid(height):
    for i in range(1, height + 1):
        print(" " * (height - i), end="")
        print("#" * i, end="  ")
        print("#" * i)


main()
