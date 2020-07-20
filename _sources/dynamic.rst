Dynamic Questions
=================

To support a model of writing and assessing using a question bank we have
added new directives that allow you to select a question when the page is loaded.
The simplest is to simply specify the id of a question you want inserted at
any point in a book or an exam.

.. selectquestion:: dynamic_q_1
    :fromid: question1_2

.. reveal:: selectreveal_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Foo

   .. code-block::

       .. selectquestion:: question1_2



.. timed:: timed2
    :timelimit: 10

    .. fillintheblank:: fill1412_ex

        Fill in the blanks to make the following sentence: "The red car drove away" The |blank| car drove |blank|.

        - :red: Correct
          :.*: Try red

        - :away: Corect
          :.*: where did we say the red car was going?

    .. selectquestion:: dynamic_q_2
        :fromid: qce_1, question1_1, mchoice_random

    .. selectquestion:: dynamic_q_3
        :fromid: units2

    .. selectquestion:: dynamic_q_4
        :fromid: morning



