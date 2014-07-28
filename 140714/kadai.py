#!/usr/local/bin/python
#-*- coding: utf-8 -*-
# kadai.py
from search import *
def main():
    print "A* search A to B"
    ab = GraphProblem('A', 'B', romania)
    print ' <- '.join([node.state for node in astar_search(ab).path()])

if __name__ == '__main__':
    main()
