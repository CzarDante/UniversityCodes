(defun factorial (n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))

(defun fibonacci (n)
  (if (<= n 1)
      n
      (+ (fibonacci (- n 1)) (fibonacci (- n 2)))))

(defun serieG-term (i)
  (let* ((fib (fibonacci i))
         (fact (factorial (fibonacci i))))
    (/ i fact)))

(defun serieG-helper (n i sum)
  (if (> i n)
      sum
      (let ((term (serieG-term i)))
        (if (>(mod i 2) 0)
            (serieG-helper n (+ i 1) (+ sum term))
            (serieG-helper n (+ i 1) (- sum term))))))

(defun serieG (n)
  (if (zerop n)
      nil
      (serieG-helper n 1 0)))

;; Exemplos de uso:
(print (serieG 0))  ; NIL
(print (serieG 1))  ; 1
(print (serieG 2))  ; -1
(print (serieG 3))  ; 1/2
(print (serieG 4))  ; -1/6
(print (serieG 5))  ; -1/8
(print (serieG 6))  ; -841/6720
(print (serieG 7))  ; -779304233/6227020800
(print (serieG 8))  ; -799246316600776801/6386367771463680000