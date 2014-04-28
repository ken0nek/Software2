(defun square (x) (* x x))
(defun sqrt-iter (guess x)
  (if (good-enough? guess x)
      guess
    (sqrt-iter (improve guess x) x)))
(defun good-enough? (guess x) (< (abs (- (square guess) x)) 0.001))
(defun good-enough? (guess x) (< (abs (- guess (improve guess x))) 0.00001))
(defun improve (guess x) (/ (+ guess (/ x guess)) 2))
(defun my-sqrt (x) (sqrt-iter 1.0 x))