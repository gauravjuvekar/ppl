(print
 (funcall
  (lambda (lfact n) (funcall lfact n lfact))
  (lambda (n lfact) (if (= n 0) 1 (* n (funcall lfact (- n 1) lfact)) ) )
 4)
)
