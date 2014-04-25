(defun fib (n) (fib-iter 1 1 1 n))
(defun fib-iter (pSum ppSum counter max-count) ;p = pre
  (cond ((<= max-count 1) 1)
        ((>= counter max-count) pSum)
        (t (fib-iter (+ pSum ppSum) pSum (+ counter 1) max-count))))