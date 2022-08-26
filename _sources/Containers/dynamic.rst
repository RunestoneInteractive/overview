Dynamic Questions
=================

To support a model of writing and assessing using a question bank we have
added new directives that allow you to select a question when the page is loaded.
The simplest is to simply specify the id of a question you want inserted at
any point in a book or an exam.

.. selectquestion:: dynamic_q_1
    :fromid: question1_2

.. reveal:: dynamic_q_1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Foo

   .. code-block::

       .. selectquestion:: dynamic_q_1
          :fromid: question1_2

If you list multiple questions as part of the ``:fromid:`` option a question will be selected at random when it is displayed to the student.

Using Dynamic Questions to secure Exams
---------------------------------------

Using the ``selectquestion`` directive has real benefits for writing a timed exam including:

* Questions are not loaded into the page until the student sees the question for the first time.  This prevents students from viewing the source to see the questions.
* Using ``:fromid: question_1, question_2, ...`` you can provide multiple equivalent questions for each exam question making it more difficult for students to share answers.

There are several other options to the ``selectquestion`` that are designed to support automated exam creation, but they rely on the presence of a well developed and structured question bank.  Something we would love to develop in Runestone, but have not yet completed.

* ``:proficiency:`` - If you have a lot of questions and they are tagged with either ``:prim_comp:`` or ``:supp_comp:``  then the exam will choose a question at random from all questions in the question bank that are aimed at that particular proficiency.

* ``:min_difficulty:`` - We have developed a way to automatically assign a level of difficulty to a question based on past students historical performance on the question.  This allows you to include a question between a minimum and maximum difficulty level.
* ``:max_difficulty:``
* ``:autogradable:`` -- this ensures that Runestone only chooses a question that is automatically gradeable.
* ``:not_seen_ever:`` -- this ensures that Runestone selects a question that the student has not answered sometime in the past.

There is lots of research to do to see if this approach can actually work and produce exams that students will accept as fair.  But it seems that for an online exam, generating a different (but equivalent) exam for every student could go a long way toward reducing cheating as well as saving instructors a lot of work.

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
        :fromid: question1_ma
        :points: 5


    .. selectquestion:: dynamic_q_2
        :fromid: qce_1, question1_1, mchoice_random
        :points: 5

    .. selectquestion:: dynamic_q_3
        :fromid: units2
        :points: 2

    .. selectquestion:: dynamic_q_4
        :fromid: morning, per_person_cost
        :points: 2

In the above timed exam the selectquestion was used to provide multiple options for each of the questions.  This would mean that students would not all get exactly the same questions on their exam but rather randomly selected, yet equivalent problems for each question in the exam.  Here is an example of how you can do that:

.. reveal:: dynamic_q_4_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Foo

   .. code-block::

       .. selectquestion:: dynamic_q_4
           :fromid: morning, per_person_cost
           :points: 2


AB Experiments with Dynamic Questions
-------------------------------------

Using the ``:ab: <experimentid>`` option on selectquestion allows the system to assign a student to either the A or B group and then consistently choose the questions for that group for your student.

.. selectquestion:: ab_example
   :ab: abexperiment1
   :fromid: test_question2_3_2, test_question2_4_1
   :points: 10


.. reveal:: ab_example_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Foo

   .. code-block::

      .. selectquestion:: ab_example
         :ab: abexperiment1
         :fromid: test_question2_3_2, test_question2_4_1
         :points: 10



Toggle Questions
----------------

Sometimes when learners are given a mixed-up code (Parsons) problem to solve they would rather write the code themselves.  Adding the ``:toggle:`` option to a ``selectquestion`` directive allows the learner to preview the other problems and choose which one to solve.  Whichever one is selected will be graded. This can be used with any types of problems.

.. selectquestion:: dynamic_toggle_1
   :fromid: exp1_pp1a, exp1_q1_write
   :toggle:

.. reveal:: dynamic_toggle_1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Foo

   .. code-block::

      .. selectquestion:: dynamic_toggle_1
         :fromid: exp1_pp1a, exp1_q1_write
         :toggle:

You can also lock the toggle question so that it will display the other question in a
pop-up window, but not allow the user to switch to that question.  This is
helpful if you want to use a Parsons problem to scaffold a student who is
struggling to write code.

.. selectquestion:: dynamic_toggle_lock
   :fromid: exp1_q1_write, exp1_pp1a
   :toggle: lock


.. reveal:: dynamic_toggle_lock_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Foo

   .. code-block::

      .. selectquestion:: dynamic_toggle_1
         :fromid: exp1_q1_write, exp1_pp1a
         :toggle: lock
