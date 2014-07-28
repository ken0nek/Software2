#-*- coding: utf-8 -*-
from scipy import linalg
import numpy as np

def output_inv(arr):
    print "A-->"
    print arr

    print "determinant -->", linalg.det(arr)

    try:
        iarr = linalg.inv(arr)
    except linalg.LinAlgError:
        print "--> No inverse array"
        return

    iarr = linalg.inv(arr)
    print "A inverse -->"
    print iarr

    print "confirm -->"
    res = np.dot(arr, iarr)
    print np.array(res, dtype=np.float16)

def main():
    arr = np.array([[1, 2],
                    [3, 4]])

    arr2 = np.array([[3, 2],
                     [6, 4]])

    output_inv(arr)
    print "--"
    output_inv(arr2)

if __name__ == '__main__':
    main()
