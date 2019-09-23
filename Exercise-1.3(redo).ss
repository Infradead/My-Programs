(define (sum-of-squares x y z)
  (cond (if ((> x y) (> x z)) (* x x))
        (and (> y x) (> y z)) (* y y)
        (and (> z x) (> z y)) (* z z)))



