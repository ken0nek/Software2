(defun Fib (n) (if (= n 1) 1
                 (if (= n 2) 1
                   (+ (Fib (- n 1)) (Fib (- n 2))))))