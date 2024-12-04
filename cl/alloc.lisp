(defun get-ms ()
  (/ (get-internal-real-time) internal-time-units-per-second 1/1000)
)

(defun test (r s)
  (let (
      (st (get-ms))
    )
    (loop for i from 0 to r do
      (aref (make-array s) 0)
    )
    (- (get-ms) st)
  )
)

(defun stats (ts)
  (format nil "Min : ~A, max : ~A, average : ~,2f~%"
    (floor (reduce #'min ts))
    (floor (reduce #'max ts))
    (/ (reduce #'+ ts) (length ts))
  )
)

(defun alloc-test (r s)
  (stats (loop for i from 0 to 10 collect
    (test r s)
  ))
)

(defclass person () ((age :initarg :age :accessor get-age)))

(defun person-test (r s)
  (let ((st (get-ms)))
    (loop for i from 0 to r do
      (get-age (make-instance 'person :age s))
    )
    (- (get-ms) st)
  )
)

(defun person-alloc-test (r s)
  (stats (loop for i from 0 to 10 collect
    (person-test r s)
  ))
)
