(defun make-rat (n d)
	(let ((c (gcd n d)))
		(cons (/ n c) (/ d c))))

(defun numer (x) (car x))

(defun denom (x) (cdr x))

(defun add-rat (x y)
	(make-rat (+ (* (numer x) (denom y))
		(* (numer y) (denom x)))
	(* (denom x) (denom y))))

(defun print-rat (x) (prin1 (numer x))(prin1 '/)(prin1 (denom x))(print nil))

(setq one-third (make-rat 1 3))

(print-rat (add-rat one-third one-third))