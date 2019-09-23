;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname Exercise-1.8) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;; Varun Belani 7/24/2019 SICP

#| Exercise 1.7
The good-enough? test used in computing
square roots will not be very effective for finding the square
roots of very small numbers. Also, in real computers, arithmetic operations are almost always performed with limited precision. This makes our test inadequate for very large
numbers. Explain these statements, with examples showing
how the test fails for small and large numbers. An alternative strategy for implementing good-enough? is to watch
how guess changes from one iteration to the next and to
stop when the change is a very small fraction of the guess.
Design a square-root procedure that uses this kind of end
test. Does this work better for small and large numbers?
|#

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)))


;; Test Case #1
#|
guess is 1
square root radicand is 0.5 



|#



(sqrt-iter 1 