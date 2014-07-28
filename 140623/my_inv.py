#!/usr/local/bin/python
#-*- coding: utf-8 -*-
#
# Author:   kentarowada
# Mail:     www.kentaro.wada@gmail.com
# URL:      http://wkentaro.com
# Created:  2014-06-25
# Filename: my_inv.py
#
import numpy as np

def my_det(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n):
            if i < j:
                tmp = arr[j][i] / arr[i][i]
                for k in range(n):
                    arr[j][k] -= arr[i][k]*tmp

    det = 1.0
    for i in range(n):
        det *= arr[i][i];
    return det

def my_inv(arr):
    arr = np.array(arr, dtype=np.float64)
    n = len(arr)
    iarr = np.identity(n)

    # 掃き出し法
    for i in range(n):
        tmp = 1 / arr[i][i]
        for j in range(n):
            arr[i][j] *= tmp
            iarr[i][j] *= tmp
        for j in range(n):
            if i != j:
                tmp = arr[j][i]
                for k in range(n):
                    arr[j][k] -= arr[i][k] * tmp
                    iarr[j][k] -= iarr[i][k] * tmp
    return iarr

def my_output_inv(arr):
    arr = np.array(arr)
    print "A-->"
    print arr

    det = my_det(arr)
    print "determinant -->",
    print det

    if int(det) == 0:
        print "--> No inverse array"
        return

    iarr = my_inv(arr)
    print "A inverse -->"
    print iarr


def main():
    arr = np.array([[1, 2],
                    [3, 4]])
    my_output_inv(arr)

    print "--"

    arr2 = np.array([[3, 2],
                     [6, 4]])
    my_output_inv(arr2)

if __name__ == '__main__':
    main()
