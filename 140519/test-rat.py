#-*- coding:utf-8 -*-
""" test-rat.py """
import operator

class Rat:
    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator

    def __add__(self, a):
        if isinstance(a, Rat):
            numer = self.numerator*a.denominator + self.denominator*a.numerator
            denom = self.denominator * a.denominator
            return Rat(numer, denom)
        else:
            raise TypeError, "Rat is required."

    def __mul__(self, a):
        if isinstance(a, Rat):
            numer = self.numerator * a.numerator
            denom = self.denominator * a.denominator
            return Rat(numer, denom)
        else:
            raise TypeError, "Rat is required."

    def __str__(self):
        return "{0} / {1}".format(self.numerator, self.denominator)

def linear_combination (a, b, x, y):
    return a*x + b*y

def main():
    one_half = Rat(1, 2)
    one_third = Rat(1, 3)
    
    print one_half
    print one_third

    print one_half + one_third
    print one_half * one_third

    print linear_combination(1, 2, 3, 4)
    print linear_combination(one_half, one_half, one_third, one_third)

main()
