#!/usr/bin/env python3

import math


class Shape(object):
    def __init__(self, turtle=None):
        self.turtle = turtle


class Polygon(Shape):
    def __init__(self, points, turtle=None):
        Shape.__init__(self, turtle)
        self.points = points

    def draw(self, turtle=None):
        if turtle is None:
            turtle = self.turtle
        turtle.penup()
        pos = turtle.pos()
        relative = lambda x, y: (pos[0] + x, pos[1] + y)
        turtle.goto(relative(*(self.points[-1])))
        turtle.pendown()
        for point in self.points:
            turtle.goto(relative(*point))
        turtle.penup()
        turtle.goto(pos)
        turtle.pendown()

    def transform(self, matrix):
        if not (len(matrix) == 2 and
                (len(matrix[0]) == len(matrix[1]) == 2)):
            raise ValueError("Transformation matrix must be order 2 square")
        apply = lambda point, matrix: (
            (point[0] * matrix[0][0]) + (point[1] * matrix[0][1]),
            (point[0] * matrix[1][0]) + (point[1] * matrix[1][1]))
        self.points = [apply(point, matrix) for point in self.points]


class RegularPolygon(Polygon):
    def __init__(self, sides, radius, turtle=None):
        step_angle = 360 / sides
        points = []
        angle = 0
        while angle < 360:
            points.append((
                radius * math.cos(math.radians(angle)),
                radius * math.sin(math.radians(angle))))
            angle += step_angle
        Polygon.__init__(self, points, turtle)


class Ellipse(RegularPolygon):
    def __init__(self, rad_x, rad_y, turtle=None):
        sides = max((rad_x, rad_y))
        RegularPolygon.__init__(self, sides, min((rad_x, rad_y)), turtle)
        if rad_x < rad_y:
            self.transform(((1, 0), (0, rad_y / rad_x)))
        else:
            self.transform(((rad_x / rad_y, 0), (0, 1)))
