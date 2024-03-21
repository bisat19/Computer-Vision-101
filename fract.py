import turtle

# Create a turtle screen and set its background color
screen = turtle.Screen()
screen.bgcolor("white")

# Create a new turtle object
my_turtle = turtle.Turtle()
my_turtle.color("black")

# Draw a square fractal
def draw_square_fractal(turtle, length, depth):
    if depth == 0:
        return
    for _ in range(4):
        turtle.forward(length)
        turtle.right(90)
    turtle.forward(length)
    turtle.right(90)
    turtle.forward(length)
    turtle.right(90)
    turtle.forward(length)
    turtle.right(90)
    turtle.forward(length)
    turtle.right(90)
    turtle.forward(length/3)
    turtle.right(90)
    turtle.forward(length/3)
    turtle.right(90)
    turtle.forward(length/3)
    turtle.right(90)
    draw_square_fractal(turtle, length/3, depth-1)

# Set the length of the square and the depth of the recursion
length = 300
depth = 3

# Draw the fractal
draw_square_fractal(my_turtle, length, depth)

# Hide the turtle and close the turtle graphics window
my_turtle.hideturtle()
turtle.done()