.. _fill in the blank docs:

Fill in the Blank
-----------------
Another type of question allows you as the instructor to ask for a value.  You can test for the value using regular expressions.  Leading and trailing whitespace in an answer will automatically be ignored. For example:

.. fillintheblank:: fill1512
    :prim_comp: GENERAL
    
    How many bowling pins are used when bowling?
    You can put spaces before or after the number without affecting
    the correctness of the answer.
    You can provide the answer in decimal (10), hexadecimal (0xA),
    binary (0b1010), or using scientific notation (1e1).

    -   :10:    Correct.
        :0x10:  Incorrect. (Note that solutions can be provided in any base
                as well).
        :.*:    Incorrect. Note that the last option given, regardless of
                its content, matches any response not already matched by
                the previous feedback options. For example, ``:x:`` would
                work in the same way.


.. reveal:: fill1512_src
    :showtitle: Show Source
    :hidetitle: Hide Source
    :modaltitle: Source for the example above

    .. literalinclude:: fitb.rst
        :language: rest
        :start-at: fill1512
        :end-before: fill1512_src


You can have multiple blank areas to fill in.

.. fillintheblank:: fillDecVar1

   Fill in the following: |blank| ``age =`` |blank| ``;`` to declare ``age``
   to be an integer and set its value to 5.

   -    :int:   Correct. You typically use whole numbers for ages after age 1.
        :.*:    Remember that Java uses just the first three letters of the
                word integer to define an integral type.
   -    :5:     Correct. You can initialize to a value.
        :.*:    Use ``5`` in the second blank.


.. reveal:: fillDecVar1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

    .. literalinclude:: fitb.rst
        :language: rest
        :start-at: fillDecVar1
        :end-before: fillDecVar1_src


Case-insensitive answers are supported:

.. fillintheblank:: fitb_casei
    :casei:

    What is the opposite of yes?

    -   :no:    Correct.
        :.*:    The correct answer is no, No, nO, or NO.


.. reveal:: fitb_casei_src
    :showtitle: Show Source
    :hidetitle: Hide Source
    :modaltitle: Source for the example above

    .. literalinclude:: fitb.rst
        :language: rest
        :start-at: fitb_casei
        :end-before: fitb_casei_src


Numeric answers may provide a tolerance, to accept a range of correct answers.

.. fillintheblank:: fitb_tolerance

    What is 1/3 as a decimal value? Provide at least three `significant
    figures <https://en.wikipedia.org/wiki/Significant_figures>`_.

    -   :0.333 0.0005:  Correct. Any value in the range of 0.333±0.0005 is
                        correct.
        :.*:            Incorrect. Did you provide three `significant
                        figures`_?

.. reveal:: fitb_tolerance_src
    :showtitle: Show Source
    :hidetitle: Hide Source
    :modaltitle: Source for the example above

    .. literalinclude:: fitb.rst
        :language: rest
        :start-at: fitb_tolerance
        :end-before: fitb_tolerance_src
