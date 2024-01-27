from cs50 import get_int


def draw_pyramid(height):
    for i in range(height):
        print(" " * (height - i - 1), end="")  # Drawing
        print("#" * (i + 1), end="")
        print("  ", end="")
        print("#" * (i + 1), end="")
        print()


height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")


draw_pyramid(height)  # Call the function
