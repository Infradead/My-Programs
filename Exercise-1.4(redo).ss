(define (sum-of-squares x y z)
  (cond
   (+ (and ((> x y) (> x z) (* x x)))
      (and ((> y x) (> y z) (* y y)))
      (and ((> z x) (> z y) (* z z))))))


;; (define (abs x)
;;   (cond 
;;    ((> x 0) x)
;;    (( = x 0) 0)
;;    ((< x 0) (- x))))

