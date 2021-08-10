Toggle Questions
=================

.. parsonsprob:: exp1_pp1a
   :adaptive:
   :numbered: left

   Put the blocks in order to define the function ``has22`` to return ``True`` if there are at least two items in the list nums that are adjacent and both equal to 2, otherwise return ``False``. For example, return ``True`` for ``has22([1, 2, 2])`` since there are two adjacent items equal to 2 (at index 1 and 2) and ``False`` for ``has22([2, 1, 2])`` since the 2’s are not adjacent.
   -----
   def has22(nums):
   =====
       for i in range(len(nums)-1):
   =====
       for i in range(len(nums)): #paired
   =====
           if nums[i] == 2 and num[i+1] == 2:
   =====
           if nums[i] == 2 and num[i-1] == 2: #paired
   =====
               return True
   =====
               return true #paired
   =====
       return False


.. activecode:: exp1_q1_write
   :autograde: unittest

   Finish the function ``has22`` below to return ``True`` if there are at least two items in the list ``nums`` that are adjacent and both equal to 2, otherwise return ``False``.  For example, return ``True`` for ``has22([1, 2, 2])`` since there are two adjacent items equal to 2 (at index 1 and 2) and ``False`` for ``has22([2, 1, 2])`` since the 2's are not adjacent.

   ~~~~
   def has22(nums):

   ====
   from unittest.gui import TestCaseGui

   class myTests(TestCaseGui):

       def testOne(self):
           self.assertEqual(has22([1, 2, 2]), True, 'has22([1, 2, 2])')
           self.assertEqual(has22([1, 2, 1, 2]), False, 'has22([1, 2, 1, 2])')
           self.assertEqual(has22([2, 1, 2]), False, 'has22([2, 1, 2])')
           self.assertEqual(has22([2, 2, 1]), True, 'has22([2, 2, 1])')
           self.assertEqual(has22([3, 4, 2]), False, 'has22([3, 4, 2])')
           self.assertEqual(has22([2]), False, 'has22([2])')
           self.assertEqual(has22([]), False, 'has22([])')
           self.assertEqual(has22([3, 3, 1]), False, 'has22([3, 3, 1])')
           self.assertEqual(has22([1, 4, 4]), False, 'has22([1, 4, 4])')

   myTests().main()


.. mchoice:: test_question2_3_2
   :practice: T
   :answer_a: Nothing is printed. A runtime error occurs.
   :answer_b: Thursday
   :answer_c: 32.5
   :answer_d: 19
   :correct: d
   :feedback_a: It is legal to change the type of data that a variable holds in Python.
   :feedback_b: This is the first value assigned to the variable day, but the next statements reassign that variable to new values.
   :feedback_c: This is the second value assigned to the variable day, but the next statement reassigns that variable to a new value.
   :feedback_d: The variable day will contain the last value assigned to it when it is printed.

   What is printed when the following statements execute?

   .. code-block:: python

     day = "Thursday"
     day = 32.5
     day = 19
     print(day)


.. mchoice:: test_question2_4_1
   :practice: T
   :answer_a: True
   :answer_b: False
   :correct: b
   :feedback_a: -  The + character is not allowed in variable names.
   :feedback_b: -  The + character is not allowed in variable names (everything else in this name is fine).

   True or False:  the following is a legal variable name in Python:   A_good_grade_is_A+

     
