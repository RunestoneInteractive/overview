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


This next type of question allows more than one correct answer to be required.  Just mark each correct answer with a plus sign (``+``).  The feedback will tell you whether you have the
correct number as well as the feedback for each.

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
