; bandwidth to q algorithm from http://www.rane.com/note167.html#qformula

(define (bw-to-q q)
  (let ((q2 (* q q)))
    (* (/ 2. (log 2)) (log (* 0.5 (+ (/ 1. q) (sqrt (+ (/ 1. q2) 4.))))))
    ))
