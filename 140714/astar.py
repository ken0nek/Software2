#!/usr/local/bin/python
#-*- coding: utf-8 -*-
# astar.py
import bisect
import math

infinity = 1.0e400
#-------------------------------------------------------------------------------------------
def Dict(**entries):  
    return entries
def distance((ax, ay), (bx, by)):
    return math.hypot((ax - bx), (ay - by))
def memoize(fn, slot=None):
    if slot:
        def memoized_fn(obj, *args):
            if hasattr(obj, slot):
                return getattr(obj, slot)
            else:
                val = fn(obj, *args)
                setattr(obj, slot, val)
                return val
    else:
        def memoized_fn(*args):
            if not memoized_fn.cache.has_key(args):
                memoized_fn.cache[args] = fn(*args)
            return memoized_fn.cache[args]
        memoized_fn.cache = {}
    return memoized_fn
def update(x, **entries):
    if isinstance(x, dict):
        x.update(entries)   
    else:
        x.__dict__.update(entries) 
    return x 
class Queue:
    def __init__(self): 
        abstract

    def extend(self, items):
        for item in items: self.append(item)
class PriorityQueue(Queue):
    def __init__(self, order=min, f=lambda x: x):
        update(self, A=[], order=order, f=f)
    def append(self, item):
        bisect.insort(self.A, (self.f(item), item))
    def __len__(self):
        return len(self.A)
    def pop(self):
        if self.order == min:
            return self.A.pop(0)[1]
        else:
            return self.A.pop()[1]
#-------------------------------------------------------------------------------------------
class Node:
    def __init__(self, state, parent=None, action=None, path_cost=0):
        update(self, state=state, parent=parent, action=action, 
               path_cost=path_cost, depth=0)
        if parent:
            self.depth = parent.depth + 1
    def __repr__(self):
        return "<Node %s>" % (self.state,)
    def path(self):
        x, result = self, [self]
        while x.parent:
            result.append(x.parent)
            x = x.parent
        return result
    def expand(self, problem):
        return [Node(next, self, act,
                     problem.path_cost(self.path_cost, self.state, act, next))
                for (act, next) in problem.successor(self.state)]
class Problem:
    def __init__(self, initial, goal=None):
        self.initial = initial; self.goal = goal
    def successor(self, state):
        abstract
    def goal_test(self, state):
        return state == self.goal
    def path_cost(self, c, state1, action, state2):
        return c + 1
    def value(self):
        abstract
def graph_search(problem, fringe):
    closed = {}
    fringe.append(Node(problem.initial))
    while fringe:
        node = fringe.pop()
        if problem.goal_test(node.state): 
            return node
        if node.state not in closed:
            closed[node.state] = True
            fringe.extend(node.expand(problem))    
    return None
class Graph:
    def __init__(self, dict=None, directed=True):
        self.dict = dict or {}
        self.directed = directed
        if not directed: self.make_undirected()
    def make_undirected(self):
        for a in self.dict.keys():
            for (b, distance) in self.dict[a].items():
                self.connect1(b, a, distance)
    def connect(self, A, B, distance=1):
        self.connect1(A, B, distance)
        if not self.directed: self.connect1(B, A, distance)
    def connect1(self, A, B, distance):
        self.dict.setdefault(A,{})[B] = distance
    def get(self, a, b=None):
        links = self.dict.setdefault(a, {})
        if b is None: return links
        else: return links.get(b)
    def nodes(self):
        return self.dict.keys()
def UndirectedGraph(dict=None):
    return Graph(dict=dict, directed=False)
def best_first_graph_search(problem, f):
    f = memoize(f, 'f')
    return graph_search(problem, PriorityQueue(min, f))
def astar_search(problem, h=None):
    h = h or problem.h
    def f(n):
        return max(getattr(n, 'f', -infinity), n.path_cost + h(n))
    return best_first_graph_search(problem, f)
romania = UndirectedGraph(Dict(
    A=Dict(Z=75, S=140, T=118),
    B=Dict(U=85, P=101, G=90, F=211),
    C=Dict(D=120, R=146, P=138),
    D=Dict(M=75),
    E=Dict(H=86),
    F=Dict(S=99),
    H=Dict(U=98),
    I=Dict(V=92, N=87),
    L=Dict(T=111, M=70),
    O=Dict(Z=71, S=151),
    P=Dict(R=97),
    R=Dict(S=80),
    U=Dict(V=142)))
romania.locations = Dict(
    A=( 91, 492),    B=(400, 327),    C=(253, 288),   D=(165, 299), 
    E=(562, 293),    F=(305, 449),    G=(375, 270),   H=(534, 350),
    I=(473, 506),    L=(165, 379),    M=(168, 339),   N=(406, 537), 
    O=(131, 571),    P=(320, 368),    R=(233, 410),   S=(207, 457), 
    T=( 94, 410),    U=(456, 350),    V=(509, 444),   Z=(108, 531))
class GraphProblem(Problem):
    def __init__(self, initial, goal, graph):
        Problem.__init__(self, initial, goal)
        self.graph = graph
    def successor(self, A):
        return [(B, B) for B in self.graph.get(A).keys()]
    def path_cost(self, cost_so_far, A, action, B):
        return cost_so_far + (self.graph.get(A,B) or infinity)
    def h(self, node):
        locs = getattr(self.graph, 'locations', None)
        if locs:
            return int(distance(locs[node.state], locs[self.goal]))
        else:
            return infinity
def main():
    print "A* search: B <- A"
    ab = GraphProblem('A', 'B', romania)
    print ' <- '.join([node.state for node in astar_search(ab).path()])
if __name__ == '__main__':
    main()
