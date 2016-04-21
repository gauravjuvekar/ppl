#!/usr/bin/env python3

import turtle, shapes

t = turtle.Turtle()
t.speed('fastest')
s = shapes.Ellipse(50, 100, t)
t.pu()
t.goto(100, 100)
t.pd()
s.draw()

input()
