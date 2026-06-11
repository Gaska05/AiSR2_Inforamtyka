from abc import ABC, abstractmethod


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14159265359 * (self.radius ** 2)

    def perimeter(self):
        return 2 * 3.14159265359 * self.radius


class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)
class Square(Shape):
    def __init__(self, side):
        self.side = side
    def area(self):
        return self.side * self.side
    def perimeter(self):
        return 2 * (self.side * self.side)
class Triangle(Shape):
    def __init__(self, side1, side2, side3):
        self.side1 = side1
        self.side2 = side2
        self.side3 = side3
    def area(self):
        return self.side1 * self.side2 * self.side3
    def perimeter(self):
        return self.side1 + self.side2 + self.side3
class ParallelShape(Shape):
    def __init__(self, side1, side2):
        self.side1 = side1
        self.side2 = side2
    def area(self):
        return self.side1 * self.side2
    def perimeter(self):
        return self.side1 + self.side2




if __name__ == '__main__':
    circle = Circle(5)
    rectangle = Rectangle(4, 6)
    square =Square(2)
    triangle =Triangle(5, 6, 7)
    sarallel = ParallelShape(5, 6)

    print("Circle Area:", circle.area())
    print("Circle Perimeter:", circle.perimeter())

    print("Rectangle Area:", rectangle.area())
    print("Rectangle Perimeter:", rectangle.perimeter())

    print("Sqaere Area:", square.area())
    print("Sqaere Perimeter:", square.perimeter())

    print("Triangle Area:", triangle.area())
    print("Triangle Perimeter:", triangle.perimeter())

    print("Parallel Shape:", sarallel.perimeter())
    print("Parallel Shape:", sarallel.area())
