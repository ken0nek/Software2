#-*- coding: utf-8 -*-
# sort_alg.py
import sys
import collections
from time import time

def read_array(fname):
    fp = open(fname, "r")
    ret = []
    for row in fp.readlines():
        ret.append(int(row))
    return ret

# ------------------- selection -----------------------

def selection_sort(num):
    for i in range(len(num)):
        min_pos, min_n = i, num[i]
        for n in range(i+1, len(num)):
            if (num[n] < min_n):
                min_pos, min_n = n, num[n]
        num[i], num[min_pos] = min_n, num[i]
    return num

# ------------------- bubble -----------------------

def bubble_sort(num):
    length = len(num)
    for i in range(length):
        for n in range(length-1,i,-1):
            if num[n] < num[n-1]:
                num[n], num[n-1] = num[n-1], num[n]
    return num

# ------------------- heap -----------------------

def heap_add(num, c):
    while True:
        p = (c-1) / 2
        if c <= 0:
            break
        if num[p] <= num[c]:
            break
        num[p], num[c] = num[c], num[p]
        c = p
    return num

def heap_del(num, length, p):
    while True:
        c = p*2 + 1
        if c >= length:
            break
        if c+1 < length and num[c+1] <= num[c]:
            c += 1
        if num[p] <= num[c]:
            break
        num[p], num[c] = num[c], num[p]
        p = c
    return num

def heap_sort(num):
    length = len(num)
    for i in range(1,length):
        num = heap_add(num, i)
    for i in range(length):
        num[length-1-i], num[0] = num[0], num[length-1-i]
        num = heap_del(num, length-1-i, 0)
    num.reverse()
    return num

# ------------------- merge -----------------------

def merge(num, left, right, size):
    i, j, k, l = left, right, left, left+size
    tmp = [0 for _ in range(l)]
    while i<right and j<l:
        if num[i] < num[j]:
            tmp[k] = num[i]
            i+=1
        else:
            tmp[k] = num[j]
            j+=1
        k+=1
    if i<right:
        for h in range(i, right):
            tmp[k] = num[h]
            k+=1
    if j<l:
        for h in range(j, l):
            tmp[k] = num[h]
            k+=1
    for h in range(left, l):
        num[h] = tmp[h]
    return num

def merge_sort(num, left, right):
    if (left < right):
        middle = (right+left) / 2;
        num = merge_sort(num, left, middle)
        num = merge_sort(num, middle+1, right)
        num = merge(num, left, middle+1, right-left+1);
    return num

# ------------------- quick -----------------------

def quick_sort(num, first, last):
    x = (num[first]+num[last]) / 2
    i, j = first, last
    while True:
        while num[i] < x: i+=1
        while x < num[j]: j-=1
        if i >= j: break
        num[i], num[j] = num[j], num[i]
        i+=1
        j-=1
    if first < i-1:
        num = quick_sort(num, first, i-1)
    if j+1 < last:
        num = quick_sort(num, j+1, last)
    return num

def main():
    fname = "rand.txt"

    print "reading from {0}".format(fname)
    data = read_array(fname)

    print "using SELECTION SORT"
    num = data[:]
    print num
    t0 = time()
    num = selection_sort(num)
    print num
    print "duration:{0}[sec]".format(time()-t0)
    
    print "using BUBBLE SORT"
    num = data[:]
    print num
    t0 = time()
    num = bubble_sort(num)
    print num
    print "duration:{0}[sec]".format(time()-t0)

    print "using HEAP SORT"
    num = data[:]
    print num
    t0 = time()
    num = heap_sort(num)
    print num
    print "duration:{0}[sec]".format(time()-t0)

    print "using MERGE SORT"
    num = data[:]
    print num
    t0 = time()
    num = merge_sort(num, 0, len(num)-1)
    print num
    print "duration:{0}[sec]".format(time()-t0)

    print "using QUICK SORT"
    num = data[:]
    print num
    t0 = time()
    num = quick_sort(num, 0, len(num)-1)
    print num
    print "duration:{0}[sec]".format(time()-t0)

if __name__ == '__main__':
    main()
