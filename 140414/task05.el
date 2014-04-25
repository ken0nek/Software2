(defun fib (n) (if (or (zerop n) (= n 1))
                   1
                   (+ (fib (- n 1)) (fib (- n 2)))))