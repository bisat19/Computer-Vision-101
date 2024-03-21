import turtle
screen = turtle.Screen()
screen.bgcolor("white")

my_turtle = turtle.Turtle()
my_turtle.color("black")


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

length = 300
depth = 3
draw_square_fractal(my_turtle, length, depth)

my_turtle.hideturtle()
turtle.done()
