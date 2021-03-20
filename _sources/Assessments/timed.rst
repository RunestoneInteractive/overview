Timed Exam Questions
--------------------

You can add a timed exam of any of the assessments described so far. You can specify the maximum duration of the exam in minutes and it will display the time remaining.  If you don't include a duration it will keep track of the amount of time used and give the user unlimited time to finish the exam.   To start the exam click on the "Start" button.  You can pause the time by clicking on the "Pause" button and start it again by clicking on the "Resume" button.  When you pause the exam the questions will be hidden.  There is also a clock icon that will display the time remaining if it is a timed exam and the time used otherwise when the reader hovers over it.

Please note that you can currently only have one timed exam per html page.  By default the feedback will be shown after the user clicks the "Submit Answer" button or also after the time runs out for an exam with a specified duration.



.. timed:: timed1
    :timelimit: 10

    .. mchoice:: questiontimed1_1
        :answer_a: The value you are searching for is the first element in the array.
        :answer_b: The value you are searching for is the last element in the array
        :answer_c: The value you are searching for is in the middle of the array.
        :answer_d: The value you are searching for is not in the array
        :answer_e: Sequential Search can never be faster than Binary Search.
        :correct: a
        :feedback_a: Only when the search value is the first item in the array, and thus the first value encountered in sequential search, will sequential be faster than binary.
        :feedback_b: In this case a sequential search will have to check every element before finding the correct one, whereas a binary search will not.
        :feedback_c: Results will differ depending on the exact location of the element, but Binary Search will still find the element faster while Sequential will have to check more elements.
        :feedback_d: If the search value is not in the array, a sequential search will have to check every item in the array before failing, a binary search will be faster.
        :feedback_e: When the search value is the first element, Sequential will always be faster, as it will only need to check one element.

        Under which of these conditions will a sequential search be faster than a binary search?

    .. clickablearea:: clicktimed1
        :question: Click on the correct cells.
        :feedback: Remember, the operator '=' is used for assignment.
        :table:
        :correct: 1,1;1,4;2,3;2,4
        :incorrect: 2,1;2,2;3,0

        +------------------------+------------+----------+----------+
        |        correct         |    N-A     |    N-A   | correct  |
        +========================+============+==========+==========+
        | Incorrect              | incorrect  | correct  | correct  |
        +------------------------+------------+----------+----------+
        | This row is incorrect  |   ...      |   ...    |   ...    |
        +------------------------+------------+----------+----------+

    .. dragndrop:: dnd2
        :feedback: This is feedback.
        :match_1: Drag to Answer A|||Answer A
        :match_2: Drag me Answer B|||Answer B
        :match_3: Drag to Answer C|||Answer C

        This is a drag n drop question.

    .. fillintheblank:: fill1412

        Fill in the blanks to make the following sentence: "The red car drove away" The |blank| car drove |blank|.

        - :red: Correct
          :.*: Try red

        - :away: Corect
          :.*: where did we say the red car was going?

    .. parsonsprob:: morning_exam

        Put the blocks in order to describe a morning routine.
        -----
        get up
        =====
        eat breakfast
        =====
        brush your teeth               

    .. activecode:: timedactive
       :nocodelens:
       
       Fix this code so it passes all of the unit tests.
       ~~~~

       def add(a,b):
          return 4

       ====
       from unittest.gui import TestCaseGui

       class myTests(TestCaseGui):

           def testOne(self):
               self.assertEqual(add(2,2),4,"A feedback string when the test fails")
               self.assertAlmostEqual(add(2.0,3.0), 5.0, 1, "Try adding your parmeters")

       myTests().main()


    .. actex:: timedactex
       :language: python
   
       Write a program that prints "hello world" two times.
       Note that although this is an ``actex`` the code should
       show.
       ~~~~
       print("hello world")


.. reveal:: timed1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. timed:: timed1
          :timelimit: 10

          .. mchoice:: questiontimed1_1
              :answer_a: The value you are searching for is the first element in the array.
              :answer_b: The value you are searching for is the last element in the array
              :answer_c: The value you are searching for is in the middle of the array.
              :answer_d: The value you are searching for is not in the array
              :answer_e: Sequential Search can never be faster than Binary Search.
              :correct: a
              :feedback_a: Only when the search value is the first item in the array, and thus the first value encountered in sequential search, will sequential be faster than binary.
              :feedback_b: In this case a sequential search will have to check every element before finding the correct one, whereas a binary search will not.
              :feedback_c: Results will differ depending on the exact location of the element, but Binary Search will still find the element faster while Sequential will have to check more elements.
              :feedback_d: If the search value is not in the array, a sequential search will have to check every item in the array before failing, a binary search will be faster.
              :feedback_e: When the search value is the first element, Sequential will always be faster, as it will only need to check one element.

              Under which of these conditions will a sequential search be faster than a binary search?

          .. clickablearea:: clicktimed1
              :question: Click on the correct cells.
              :feedback: Remember, the operator '=' is used for assignment.
              :table:
              :correct: 1,1;1,4;2,3;2,4
              :incorrect: 2,1;2,2;3,0

              +------------------------+------------+----------+----------+
              |        correct         |    N-A     |    N-A   | correct  |
              +========================+============+==========+==========+
              | Incorrect              | incorrect  | correct  | correct  |
              +------------------------+------------+----------+----------+
              | This row is incorrect  |   ...      |   ...    |   ...    |
              +------------------------+------------+----------+----------+

          .. dragndrop:: dnd2
              :feedback: This is feedback.
              :match_1: Drag to Answer A|||Answer A
              :match_2: Drag me Answer B|||Answer B
              :match_3: Drag to Answer C|||Answer C

              This is a drag n drop question.

          .. fillintheblank:: fill1412

              Fill in the blanks to make the following sentence: "The red car drove away" The |blank| car drove |blank|.

              - :red: Correct
                :.*: Try red

              - :away: Corect
                :.*: where did we say the red car was going?

          .. parsonsprob:: parsonstest
          
              Get Out of Bed
              Eat Breakfast
              Brush Your Teeth

          .. parsonsprob:: morning_exam

              Put the blocks in order to describe a morning routine.
              -----
              get up
              =====
              eat breakfast
              =====
              brush your teeth

              
          .. activecode:: timedactive
             :language: python

             Write a program that prints "hello world" two times.
             ~~~~
             print("hello world")

