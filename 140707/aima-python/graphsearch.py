#!/usr/local/bin/python
#-*- coding: utf-8 -*-
# graphsearch.py
from search import *
import sys, argparse
def change_path_node2state(path):
    return [node.state for node in path]

def main(args):
    ab = GraphProblem('A', 'B', romania)
    print 'Problem: from Arab to Bucharest'

    if args.b:
        print u'Method: 幅優先探索'
        path = breadth_first_graph_search(ab).path()
    elif args.d:
        print u'Method: 深さ優先探索'
        path = depth_first_graph_search(ab).path()
    elif args.l:
        print u'Method: 深さ制限付き探索'
        path = depth_limited_search(ab, args.l).path()
    elif args.i:
        print u'Medhot: 反復深化探索'
        path = iterative_deepening_search(ab).path()

    path = change_path_node2state(path)
    print 'Answer: ',
    for i, node in enumerate(reversed(path)):
        print node,
        if i == len(path)-1:
            print
        else:
            print '->',



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Select method to do graph search')
    parser.add_argument('-b', action='store_true', help='breadth first graph search')
    parser.add_argument('-d', action='store_true', help='depth first graph search')
    parser.add_argument('-i', action='store_true', help='iterative deepening search')
    parser.add_argument('-l', type=int, help='depth limited graph search')
    args = parser.parse_args()
    main(args)
