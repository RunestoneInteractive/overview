Multiple Choice
---------------

It is also possible to embed simple questions into the text.  These
questions provide a way for the students to check themselves as they go along.  The questions also provide feedback so that you can
understand why an answer may or may not be correct.

**Check your understanding**

.. mchoice:: question1_1

    What programming language does this site help you to learn?

    -   Python

        +   Yes, Python is a great language to learn, whether you are a beginner or
            an experienced programmer. The correct answer is designated by using
            a plus sign before the answer.

    -   Java

        -   Java is a good object oriented language but it has some details that make
            it hard for the beginner.

    -   C

        -   C is an imperative programming language that has been around for a long
            time, but it is not the one that we use.

    -   ML

        -   No, ML is a functional programming language.  You can use Python to write
            functional programs as well.

.. reveal:: question1_1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

        .. mchoice:: question1_1

            What programming language does this site help you to learn?

            -   Python

                +   Yes, Python is a great language to learn, whether you are a beginner or
                    an experienced programmer. The correct answer is designated by using
                    a plus sign before the answer.

            -   Java

                -   Java is a good object oriented language but it has some details that make
                    it hard for the beginner.

            -   C

                -   C is an imperative programming language that has been around for a long
                    time, but it is not the one that we use.

            -   ML

                -   No, ML is a functional programming language.  You can use Python to write
                    functional programs as well.

You can also have code blocks in multiple-choice questions, or any other reST construct.

.. mchoice:: qce_1
    :practice: T

    What does the following code print when ``x`` has been set to 187?

    .. code-block:: java

        if (x < 0)
        {
            System.out.println("x is negative");
        }
        else if (x == 0)
        {
            System.out.println("x is zero");
        }
        else
        {
            System.out.println("x is positive");
        }

    -   x is negative

        -   This will only print if x has been set to a number less than zero. Has it?

    -   x is zero

        -   This will only print if x has been set to 0.  Has it?

    -   x is positive

        +   The first condition is false and ``x`` is not equal to zero so the else
            will execute.

.. reveal:: qce_1_src
    :showtitle: Show Source
    :hidetitle: Hide Source
    :modaltitle: Source for the example above

    .. code-block:: rst

        .. mchoice:: qce_1
            :practice: T

            What does the following code print when ``x`` has been set to 187?

            .. code-block:: java

                if (x < 0)
                {
                    System.out.println("x is negative");
                }
                else if (x == 0)
                {
                    System.out.println("x is zero");
                }
                else
                {
                    System.out.println("x is positive");
                }

            -   x is negative

                -   This will only print if x has been set to a number less than zero. Has it?

            -   x is zero

                -   This will only print if x has been set to 0.  Has it?

            -   x is positive

                +   The first condition is false and ``x`` is not equal to zero so the else
                    will execute.

You can have multiple-choice questions with images in them.  You can
upload the images to a service like postimage so that they are on the web.

.. mchoice:: over_turtle_which_draws_pict_mcq

    Which of the following code draws this picture?

    .. image:: https://i.postimg.cc/VNSyPdkL/rect.png

    -   .. image:: https://i.postimg.cc/05L2r1wN/codea.png

        - This code will draw a rectangle in the south west quadrant.

    -   .. image:: https://i.postimg.cc/3xZKLyby/codeb.png

        - This code will draw a rectangle in the north east quadrant.

    -   .. image:: https://i.postimg.cc/4xwg6DmV/codec.png

        + This code will draw a rectangle in the north west quadrant.

    -   .. image:: https://i.postimg.cc/QCLGNsyG/coded.png

        - This code will draw a rectangle in the south east quadrant.

.. reveal:: over_turtle_which_draws_pict_mcq_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. mchoice:: over_turtle_which_draws_pict_mcq

          Which of the following code draws this picture?

          .. image:: https://i.postimg.cc/VNSyPdkL/rect.png

          -   .. image:: https://i.postimg.cc/05L2r1wN/codea.png

              - This code will draw a rectangle in the south west quadrant.

          -   .. image:: https://i.postimg.cc/3xZKLyby/codeb.png

              - This code will draw a rectangle in the north east quadrant.

          -   .. image:: https://i.postimg.cc/4xwg6DmV/codec.png

              + This code will draw a rectangle in the north west quadrant.

          -   .. image:: https://i.postimg.cc/QCLGNsyG/coded.png

              - This code will draw a rectangle in the south east quadrant.


You can also have a multiple choice question with code for each answer.

.. mchoice:: over_class_mcq_correct_person_def_code_block

    Which of the following code is correct?

    -   .. code-block::

           class Person:

               def __init__(self, first, last):
                    self.first = first
                    self.last = last

               def __str__(self):
                   return (first + " " + last)

               def initials(self):
                   return (self.first[0] + self.last[0])


        - This code should use ``self.first`` and ``self.last`` in the ``__str__`` method

    -   .. code-block::

           class Person:

               def __init__(self, first, last):
                    self.first = first
                    self.last = last

               def __str__(self):
                   return (self.first + " " + self.last)

               def initials(self):
                   return (self.first[0] + self.last[0])



        + This code is correct.

    -   .. code-block::

            class Person:

               def __init__(self, first, last):
                    self.first = first
                    self.last = last

               def __str__():
                   return (first + " " + last)

               def initials():
                   return (self.first[0] + self.last[0])

        - This code is missing the ``self`` on the ``__str__`` and ``initials`` methods

    -   None of them

        - One of them is correct


.. reveal:: over_class_mcq_correct_person_def_code_block_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. mchoice:: over_class_mcq_correct_person_def_code_block

          Which of the following code is correct?

          -   .. code-block::

                 class Person:

                     def __init__(self, first, last):
                          self.first = first
                          self.last = last

                     def __str__(self):
                         return (first + " " + last)

                     def initials(self):
                         return (self.first[0] + self.last[0])


              - This code should use ``self.first`` and ``self.last`` in the ``__str__`` method

          -   .. code-block::

                 class Person:

                     def __init__(self, first, last):
                          self.first = first
                          self.last = last

                     def __str__(self):
                         return (self.first + " " + self.last)

                     def initials(self):
                         return (self.first[0] + self.last[0])



              + This code is correct.

          -   .. code-block::

                  class Person:

                     def __init__(self, first, last):
                          self.first = first
                          self.last = last

                     def __str__():
                         return (first + " " + last)

                     def initials():
                         return (self.first[0] + self.last[0])

              - This code is missing the ``self`` on the ``__str__`` and ``initials`` methods

          -   None of them

              - One of them is correct

This next type of question allows more than one correct answer to be required.  Just mark each correct answer with a plus sign (``+``).  The feedback will tell you whether you have the
correct number as well as the feedback for each.

.. mchoice:: question1_2
    :prim_comp: GENERAL

    Which colors might be found in a rainbow? (Choose all that are correct)

    -   red

        +   Red is a definitely on of the colors.

    -   yellow

        +   Yes, yellow is correct.

    -   black

        -   Remember the acronym...ROY G BIV.  B stands for blue.

    -   green

        +   Yes, green is one of the colors.

.. reveal:: question1_2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

        .. mchoice:: question1_2

            Which colors might be found in a rainbow? (Choose all that are correct)

            -   red

                +   Red is a definitely on of the colors.

            -   yellow

                +   Yes, yellow is correct.

            -   black

                -   Remember the acronym...ROY G BIV.  B stands for blue.

            -   green

                +   Yes, green is one of the colors.

The order in which multiple-choice answers are presented can be randomized by adding the ``:random:`` option.

.. reveal:: pxt_show_mchoice
    :showtitle: Show PreTeXt
    :hidetitle: HidePreTeXt

    .. code-block:: xml

        <exercise label="multiple-choice-multiple-answers">
            <title>Multiple-Choice, Not Randomized, Multiple Answers</title>
            <idx>stop signs</idx>
            <statement>
                <p>Which colors might be found in a rainbow?  (Note that the radio buttons now allow multiple buttons to be selected.)</p>
            </statement>
            <choices>
                <choice correct="yes">
                    <statement>
                        <p>Red</p>
                    </statement>
                    <feedback>
                        <p>Red is a definitely one of the colors.</p>
                    </feedback>
                </choice>
                <choice correct="yes">
                    <statement>
                        <p>Yellow</p>
                    </statement>
                    <feedback>
                        <p>Yes, yellow is correct.</p>
                    </feedback>
                </choice>
                <choice>
                    <statement>
                        <p>Black</p>
                    </statement>
                    <feedback>
                        <p>Remember the acronym<ellipsis/><acro>ROY G BIV</acro>.  <q>B</q> stands for blue.</p>
                    </feedback>
                </choice>
                <choice correct="yes">
                    <statement>
                        <p>Green</p>
                    </statement>
                    <feedback>
                        <p>Yes, green is one of the colors.</p>
                    </feedback>
                </choice>
            </choices>
            <hint>
                <p>Do you know the acronym<ellipsis/><acro>ROY G BIV</acro> for the colors of a rainbow, and their order?</p>
            </hint>
        </exercise>

.. mchoice:: mchoice_random
    :random:

    What numbers are less than 3?

    -   0

        +   Correct.

    -   1

        +   Correct.

    -   2

        +   Correct.

    -   3

        -   Incorrect.

    -   4

        -   Incorrect.

.. reveal:: mchoice_random_src
    :showtitle: Show Source
    :hidetitle: Hide Source
    :modaltitle: Source for the example above

    .. code-block:: rst

        .. mchoice:: mchoice_random
            :random:

            What numbers are less than 3?

            -   0

                +   Correct.

            -   1

                +   Correct.

            -   2

                +   Correct.

            -   3

                -   Incorrect.

            -   4

                -   Incorrect.
