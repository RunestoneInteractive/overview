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

    .. activecode:: units7
        :nocodelens:

        This is some question text.

        And this is more question text

        ~~~~
        def add(a,b):
            return 4

        from unittest.gui import TestCaseGui

        class myTests(TestCaseGui):

            def testOne(self):
                self.assertEqual(add(2,2),4,"A feedback string when the test fails")
                self.assertAlmostEqual(add(2.0,3.0), 5.0, 1, "Try adding your parmeters")

        myTests().main()

    .. selectquestion:: dynamic_q_0
        :proficiency: FUNC01
        :points: 5


    .. selectquestion:: dynamic_q_2
        :fromid: qce_1, question1_1, mchoice_random
        :points: 5

    .. selectquestion:: dynamic_q_3
        :fromid: units2
        :points: 2

    .. selectquestion:: dynamic_q_4
        :fromid: morning, pp_2_hours2seconds_jcomes, per_person_cost
        :points: 2




