(defun make-rat (n d) (cons n d))

(defun numer (x) (car x))

(defun denom (x) (cdr x))

(defun sub-rat (x y)
	(make-rat (- (* (numer x) (denom y))
		(* (numer y) (denom x)))
	(* (denom x) (denom y))))

(defun div-rat (x y)
	(make-rat (* (numer x) (denom y))
		(* (denom x) (numer y))))

(defun sub (x y)
	(cond ((consp x) (sub-rat x y))
		(t (- x y))))

(defun div (x y)
	(cond ((consp x) (div-rat x y))
		(t (/ x y))))

(defun linear-combination2 (a b x y)
	(sub (div a x) (div b y)))

(defun print-rat (x) (prin1 (numer x))(prin1 '/)(prin1 (denom x))(print nil))

(setq one-half (make-rat 1 2))

(setq one-third (make-rat 1 3))

(print-rat (linear-combination2 one-third one-half one-half one-third))