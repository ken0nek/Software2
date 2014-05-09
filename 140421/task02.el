(defun cube (x) (* x x x))

(defun product (term a b)
  (if (> a b)
      1
    (* (funcall term a)
       (product term (+ a 1) b))))

(defun product-cubes (a b)
	(product 'cube a b))