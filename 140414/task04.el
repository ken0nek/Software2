 (defun mySum(a b c)
   (interactive)
   (- (+ a b c) (min a b c)))
(mySum 3 4 5)