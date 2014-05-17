(defun make-rat (n d) (cons n d))

(defun numer (x) (car x))

(defun denom (x) (cdr x))

(defun add-rat (x y)
	(make-rat (+ (* (numer x) (denom y))
		(* (numer y) (denom x)))
	(* (denom x) (denom y))))

(defun print-rat (x) (prin1 (numer x))(prin1 '/)(prin1 (denom x))(print nil))