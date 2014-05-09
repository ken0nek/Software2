(defun square (x) (* x x))

(defun sum (term a b)
  (if (> a b)
      0
    (+ (funcall term a)
       (sum term (+ a 1) b))))

(defun sum-squares (a b)
  (sum 'square a b))


(defun sum-squares (a b)
  (if (> a b)
      0
    (+ (square a) (sum-squares (+ a 1) b))))