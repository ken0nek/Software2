#-*- coding: utf-8 -*-
import sys
import math
import decimal

def main():
    decimal.getcontext().prec = int(sys.argv[1])

    a = decimal.Decimal('1.0')
    b = decimal.Decimal(-100000)
    c = decimal.Decimal('1.0')

    D = math.sqrt(b**2 - 4*a*c)
    D = decimal.Decimal(D)
    x1 = (-b - D)/(2*a)
    x2 = (-b + D)/(2*a)

    print " a = {0:27.20e}".format(a)
    print " b = {0:27.20e}".format(b)
    print " c = {0:27.20e}".format(c)
    print "x1 = {0:27.20e}".format(x1)
    print "x2 = {0:27.20e}".format(x2)
    print "e1 = {0:27.20e}".format(a * x1**2 + b * x1 + c)
    print "e2 = {0:27.20e}".format(a * x2**2 + b * x2 + c)

    x1_ = (-b - b/abs(b) * D)/(2*a)
    x2_ = c / (a * x1_)
    print "x1'= {0:27.20e}".format(x1_)
    print "x2'= {0:27.20e}".format(x2_)

    print "e1'= {0:27.20e}".format(a * x1_**2 + b*x1_ + c)
    print "e2'= {0:27.20e}".format(a * x2_**2 + b*x2_ + c)

if __name__ == '__main__':
    main()
