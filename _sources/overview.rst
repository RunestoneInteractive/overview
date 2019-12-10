..  Copyright (C)  Brad Miller, David Ranum, Jeffrey Elkner, Peter Wentworth, Allen B. Downey, Chris
    Meyers, and Dario Mitchell.  Permission is granted to copy, distribute
    and/or modify this document under the terms of the GNU Free Documentation
    License, Version 1.3 or any later version published by the Free Software
    Foundation; with Invariant Sections being Forward, Prefaces, and
    Contributor List, no Front-Cover Texts, and no Back-Cover Texts.  A copy of
    the license is included in the section entitled "GNU Free Documentation
    License".


..  shortname:: Overview
..  description:: This is an overview chapter for the web site.

.. setup for automatic question numbering.

.. qnum::
   :start: 1
   :prefix: sc-1-


An Overview of Runestone Interactive
====================================

.. admonition:: **Runestone Interactive** is a project that provides:

    * Interactive, open source textbooks for computer science and programming content which you can use by creating an account and logging in
    * Tools for writing your own interactive activities (or even your own book!)
    * An application server for hosting your own content on the web.  We also use this server to provide textbooks as a service!

In order to see how the special tools for writing interactive activities work, and examine the type of special content that's used in our interactive textbooks, the following sections will show a few of them in action. For more detailed documentation and information about the Runestone community and project, please see `the main Runestone Interactive website <http://runestoneinteractive.org>`_.

How can I use Runestone?
========================

.. sidebar:: An Overview of the Overview

   .. contents:: Topic Outline

There are several ways that you might want to use Runestone in your own classroom.  The most common way is to choose one of our textbooks, and allow us to serve that book to your students.  We call this building a custom course.  Hundreds of high schools and colleges use our service to provide their students great content for learning computer science. Its free, and you don't have to install any additional software on your school computers to get going.  In the sections below you will see examples of the kinds of interactive components that are embedded in our textbooks, that enhance the learning of your students.

If you decide to use one of our books, you can customize the book in a couple of different ways.

* You can create your own assignments, by combining end of the chapter exercises or review questions that are right in each section of the book.  We have a grading interface that allows you to grade these assignments and provide students feedback all within the textbook.

* You can also customize which chapters you want to use, and the order that you teach them in.  That takes a bit more work, but you can definitely do it.


Once you get going using one of our textbooks, you may decide that you want to create your own tutorials, lab exercises, or even make a short booklet to use as presentation materials.  Using the runestone tools it is pretty easy to make your own materials. We have `Documentation on how to do that <http://runestoneinteractive.org/instructors.html>`_

What is an Interactive Textbook?
================================

One of the key differences between an interactive textbook and a regular textbook is that with an interactive textbook your students do not need to switch back and forth between reading a book and interacting with a development environment.  One of our primary motivations for creating an interactive book was to encourage students to experiment with examples as they are reading.  To do this we developed the idea of an activecode example.  This led to the development of many other interactive components.  In the following sections you can explore each of them from the perspective of a reader.  At the end, we have some information on where to go if you want to write your own materials.


ActiveCode Examples
-------------------

One of the most important things that you can do when you are learning a programming language is to write programs.  Unfortunately,
typical textbooks allow you to read about programming but don't allow you to practice.  We have created a unique tool called
**activecode** that allows you to write, modify, and execute programs right
in the text itself (right from the web browser).  Although this is certainly not the way real programs are written, it provides an excellent
environment for learning a programming language like Python since you can experiment with the language as you are reading.

Take a look at the activecode interpreter in action.  If we take a simple Python program and make it active, you will see that it can be executed directly by pressing the *run* button.   Try pressing the *run* button below.

.. activecode:: over_ac_example1
   :coach:

   print("My first program adds a list of numbers")
   myList = [2, 4, 6, 8, 10]
   total = 0
   for num in myList:
       total = total + num
   print(total)


Now try modifying the activecode program shown above.  First, modify the string in the first print statement
by changing the word *adds* to the word *multiplies*.  Now press *run*.  You can see that the result of the program
has changed.  However, it still prints "30" as the answer.  Modify the total calculation by changing the
addition symbol, the "+", to the multiplication symbol, "*".  Press *run* to see the new results (note that you should also fix the total initialization for a correct claculation).
You can do this as many times as you like.  You can even start completely over by simply deleting all the code from the window.

If you are a registered user and have logged in,
any changes you make are automatically saved, and the history slider allows you to go back to any previous version of your program.
Note that these saved programs can be accessed from anywhere if you have logged in.  However, if you are
working anonymously, then you will lose your work at the end of the session.

.. reveal:: codeexample1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: codeexample1
         :coach:

         print("My first program adds a list of numbers")
         myList = [2, 4, 6, 8, 10]
         total = 0
         for num in myList:
             total = total + num
         print(total)


Activecode is even capable of executing graphical programs that use the built in Python turtle module.
The program shown below is a very interesting graphics program that uses the turtle and the idea of recursion to construct a type of
fractal called a Sierpinski Triangle.  Once you run the program, try experimenting with the number of triangle levels.  You
can find this on line 39 (it is currently set to 3).  Try 4!
Try some other
changes and see what happens (maybe change a few of the colors or make the level 2).  If you ever want to go back to the original example, simply reload the page in the browser.  One of
the great things about activecode is that you can experiment as much as you want.  This can be very helpful as you
are learning to program.



.. activecode:: codeexample2
    :nocodelens:
    :hidecode:
    :autorun:

    import turtle

    def drawTriangle(points,color,myTurtle):
        myTurtle.fillcolor(color)
        myTurtle.up()
        myTurtle.goto(points[0][0],points[0][1])
        myTurtle.down()
        myTurtle.begin_fill()
        myTurtle.goto(points[1][0],points[1][1])
        myTurtle.goto(points[2][0],points[2][1])
        myTurtle.goto(points[0][0],points[0][1])
        myTurtle.end_fill()

    def getMid(p1,p2):
        return ( (p1[0]+p2[0]) / 2, (p1[1] + p2[1]) / 2)

    def sierpinski(points,degree,myTurtle):
        colormap = ['blue','red','green','white','yellow',
                    'violet','orange']
        drawTriangle(points,colormap[degree],myTurtle)
        if degree > 0:
            sierpinski([points[0],
                            getMid(points[0], points[1]),
                            getMid(points[0], points[2])],
                       degree-1, myTurtle)
            sierpinski([points[1],
                            getMid(points[0], points[1]),
                            getMid(points[1], points[2])],
                       degree-1, myTurtle)
            sierpinski([points[2],
                            getMid(points[2], points[1]),
                            getMid(points[0], points[2])],
                       degree-1, myTurtle)

    def main():
       myTurtle = turtle.Turtle()
       myWin = turtle.Screen()
       myPoints = [[-100,-50],[0,100],[100,-50]]
       sierpinski(myPoints,3,myTurtle)
       myWin.exitonclick()

    main()




The CodeLens Tool
-----------------


In addition to activecode, you can also execute Python code with the assistance of a unique visualization tool.  This tool, known as **codelens**, allows you to control the step by step execution of a program.  It also lets you see the values of
all variables as they are created and modified.  The following example shows codelens in action on the same simple program as we saw above.  Remember that in activecode, the source code executes from beginning to end and you can see the final result.  In codelens you can see and control the step by step progress.  Try clicking on the forward button below.

.. codelens:: over_codelens1
    :showoutput:

    print("My first program adds two numbers, 2 and 3:")
    print(2 + 3)


Note that you can control the step by step execution and you can even move forward and backward thru the statements as they execute.  The following example shows a more sophisticated program using Python lists.  The codelens tool draws very useful
pictures as the statements are being executed.  These pictures, called reference diagrams, are very helpful as you learn about the
more complex aspects of Python.

.. reveal:: over_codelens1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. codelens:: firstexample
          :showoutput:

          print("My first program adds two numbers, 2 and 3:")
          print(2 + 3)


.. codelens:: secondexample

    fruit = ["apple","orange","banana","cherry"]
    numlist = [6,7]
    newlist = fruit + numlist
    zeros = [0] * 4

    zeros[1] = fruit
    zeros[1][2] = numlist


Multiple Choice
---------------

It is also possible to embed simple questions into the text.  These
questions provide a way for the students to check themselves as they go along.  The questions also provide feedback so that you can
understand why an answer may or may not be correct.

**Check your understanding**

.. mchoice:: question1_1
   :answer_a: Python
   :answer_b: Java
   :answer_c: C
   :answer_d: ML
   :correct: a
   :feedback_a: Yes, Python is a great language to learn, whether you are a beginner or an experienced programmer.
   :feedback_b: Java is a good object oriented language but it has some details that make it hard for the beginner.
   :feedback_c: C is an imperative programming language that has been around for a long time, but it is not the one that we use.
   :feedback_d: No, ML is a functional programming language.  You can use Python to write functional programs as well.

   What programming language does this site help you to learn?


This next type of question allows more than one correct answer to be required.  The feedback will tell you whether you have the
correct number as well as the feedback for each.

.. reveal:: question1_1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. mchoice:: question1_1
         :answer_a: Python
         :answer_b: Java
         :answer_c: C
         :answer_d: ML
         :correct: a
         :feedback_a: Yes, Python is a great language to learn, whether you are a beginner or an experienced programmer.
         :feedback_b: Java is a good object oriented language but it has some details that make it hard for the beginner.
         :feedback_c: C is an imperative programming language that has been around for a long time, but it is not the one that we use.
         :feedback_d: No, ML is a functional programming language.  You can use Python to write functional programs as well.

         What programming language does this site help you to learn?


.. mchoice:: question1_2
   :multiple_answers:
   :answer_a: red
   :answer_b: yellow
   :answer_c: black
   :answer_d: green
   :correct: a,b,d
   :feedback_a: Red is a definitely on of the colors.
   :feedback_b: Yes, yellow is correct.
   :feedback_c: Remember the acronym...ROY G BIV.  B stands for blue.
   :feedback_d: Yes, green is one of the colors.

   Which colors might be found in a rainbow? (choose all that are correct)


.. reveal:: question1_2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. mchoice:: question1_2
         :multiple_answers:
         :answer_a: red
         :answer_b: yellow
         :answer_c: black
         :answer_d: green
         :correct: a,b,d
         :feedback_a: Red is a definitely on of the colors.
         :feedback_b: Yes, yellow is correct.
         :feedback_c: Remember the acronym...ROY G BIV.  B stands for blue.
         :feedback_d: Yes, green is one of the colors.

         Which colors might be found in a rainbow? (choose all that are correct)


Fill in the Blank
-----------------

Another type of question allows you as the instructor to ask for a value.  You can test for the value using Pythons regular expressions.  For example:

.. fillintheblank:: fill1512

    What is the value of 25 expressed as an octal number (base 8)?

    - :31: Is the correct answer!
      :25: Thats base 10!
      :.*: 25 in octal please

.. reveal:: fill1512_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. fillintheblank:: fill1512

          What is the value of 25 expressed as an octal number (base 8)?

          - :31: Is the correct answer!
            :25: Thats base 10!
            :.*: 25 in octal please

There is also a way of giving your students some simple programming problems where the code is already there for them but not indented or in the correct order.  Think of it like coding with refrigerator magnets! Use drag-and-drop to get everything right.

Parsons Problems
----------------

.. parsonsprob:: bnm_3_1_2018

   Add some text here

   -----
   import turtle
   window = turtle.Screen()
   ella = turtle.Turtle()
   =====
   ella.right(90)
   ella.forward(150)
   =====
   ella.left(90)
   ella.forward(75)



.. parsonsprob:: bnm_3_2_2018

   Construct a block of code that correctly implements the accumulator pattern.
   -----
   x = 0
   =====
   for i in range(10)
      x = x + 1


.. reveal:: question1_100_4_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. parsonsprob:: question1_100_4

         Construct a block of code that correctly implements the accumulator pattern.
         -----
         x = 0
         ======
         for i in range(10)
            x = x + 1

CodeLens Predictions
--------------------

Here is a different sort of CodeLens visualization.  Some CodeLens blocks can have
questions embedded in them that will ask you a question about the value of a
variable, or which line will be the next line to execute.  This example asks you
to keep track of the ``tot`` variable as you step through the loop.

.. codelens:: codelens_question
    :question: What is the value of tot after the line with the red arrow executes?
    :breakline: 4
    :feedback: Use the global variables box to look at the current values of tot and i.
    :correct: globals.tot

    tot = 0
    prod = 1
    for i in range(10):
       tot = tot + i
       prod = prod * i

.. reveal:: codelens_question_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. codelens:: codelens_question
          :question: What is the value of tot after the line with the red arrow executes?
          :breakline: 4
          :feedback: Use the global variables box to look at the current values of tot and i.
          :correct: globals.tot

          tot = 0
          prod = 1
          for i in range(10):
             tot = tot + i
             prod = prod * i

Here's another example that asks the student to predict which line will be the
next line executed.

.. codelens:: codelens_question_line
    :question: After the line with the red arrow is executed, which will be next?
    :breakline: 3
    :feedback: Remember that in an if/else statement only one block is executed.
    :correct: line

    x = 2
    y = 0
    if x % 2 == 1:
        print('x is odd')
        y = y + x
    else:
        print('x is even')
        y = y - x

.. reveal:: codelens_question_line_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. codelens:: codelens_question_line
          :question: After the line with the red arrow is executed, which will be next?
          :breakline: 3
          :feedback: Remember that in an if/else statement only one block is executed.
          :correct: line

          x = 2
          y = 0
          if x % 2 == 1:
              print('x is odd')
              y = y + x
          else:
              print('x is even')
              y = y - x

Drag N Drop
-----------

You can add a Drag n drop matching question to your page simply by defining the pairs of matchable elements within a dragndrop directive.
The order of draggable elements and their respective dropzones will be randomized so the pairs aren't always side-by-side.

.. dragndrop:: dnd1
    :feedback: This is feedback.
    :match_1: Drag me to 1|||I am 1
    :match_2: Drag me to 2|||I am 2
    :match_3: Drag me to 3|||I am 3

    This is a drag n drop question.

.. reveal:: dnd1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. dragndrop:: dnd1
          :feedback: This is feedback.
          :match_1: Drag me to 1|||I am 1
          :match_2: Drag me to 2|||I am 2
          :match_3: Drag me to 3|||I am 3

          This is a drag n drop question.

Clickable Area
--------------

Clickable area is another type of assess question you can use. All you need to do is write the code you wish to be in the question, and wrap the parts that you
would like to be clickable in either a click-correct tag or a click-incorrect tag. The students can click on all elements you defined as being clickable, and
will be evaluated once they click the 'Check Me' button.

.. clickablearea:: click1
    :question: Click on all assignment statements.
    :iscode:
    :feedback: Remember, the operator '=' is used for assignment.

    :click-incorrect:def main()::endclick:
        :click-correct:x = 4:endclick:
        for i in range(5):
            :click-correct:y = i:endclick:
            :click-incorrect:if y > 2::endclick:
                print(y)


.. reveal:: click1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. clickablearea:: click1
          :question: Click on all assignment statements.
          :iscode:
          :feedback: Remember, the operator '=' is used for assignment.

          :click-incorrect:def main()::endclick:
              :click-correct:x = 4:endclick:
              for i in range(5):
                  :click-correct:y = i:endclick:
                  :click-incorrect:if y > 2::endclick:
                      print(y)

Short Answer
------------

.. shortanswer:: shorta1

   You can ask your students to answer reflective questions or short essays in the box provided.


.. reveal:: shorta1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. shortanswer:: shorta1

         You can ask your students to answer reflective questions or short essays in the box provided.

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


    .. activecode:: timedactive
       :language: python

       Write a program that prints "hello world" two times.
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


          .. activecode:: timedactive
             :language: python

             Write a program that prints "hello world" two times.
             ~~~~
             print("hello world")

Embedded Videos
---------------

Our toolset provides a number of different things that will help you to learn to program in the Python programming language.
Aside from reading the text, it is sometimes useful to hear someone tell you about different aspects of the topic being discussed.
In order to accomplish this, we provide a way to integrate simple, short videos into the text.  For example, if you click
on the video shown below, you will hear us talk about the tools that will be described shortly.

.. video:: over_videoinfo
    :controls:
    :thumb: _static/activecodethumb.png

    http://media.interactivepython.org/runestone.mov
    http://media.interactivepython.org/runestone.webm


.. reveal:: videoinfo_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. video:: videoinfo
          :controls:
          :thumb: _static/activecodethumb.png

          http://media.interactivepython.org/runestone.mov
          http://media.interactivepython.org/runestone.webm


YouTube
-------

.. youtube:: X1-UNHUajfk
    :divid: theforloop
    :height: 315
    :width: 560
    :align: left

.. youtube:: anwy2MPT5RE
    :divid: yt_vid_ex1
    :height: 315
    :width: 560
    :align: left

.. reveal:: anwy2MPT5RE
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. youtube:: anwy2MPT5RE
          :height: 315
          :width: 560
          :align: left

Unit Tests for Code
-------------------

Its nice to be able to have students solve a particular problem by writing some code, its even better if you can give them some feedback and provide some tests for them.  Much of the ``unittest`` module from Python is available in the ``unittest`` module for activecode.  Take a look:

.. activecode:: units1
   :nocodelens:

   def add(a,b):
      return 4

   from unittest.gui import TestCaseGui

   class myTests(TestCaseGui):

       def testOne(self):
           self.assertEqual(add(2,2),4,"A feedback string when the test fails")
           self.assertAlmostEqual(add(2.0,3.0), 5.0, 1, "Try adding your parmeters")

   myTests().main()

Before you go on, fix the add function in the activecode box.  The full complement of assertXXX functions is available.  You can see the list `Here <http://docs.python.org/2/library/unittest.html#assert-methods>`_.  Now, for an introductory course exposing the inner workings of the unittest class may lead to more confusion that anything.  But, you can still get the benefit of the unittest module with activecode by placing it in the hidden code at the end.  You can hide the code by placing it after a line that contains ``====``.  The source code for the above example with the unit tests hidden would look like this:

.. sourcecode:: rst

    .. activecode:: units1

       def add(a,b):
          return 4

       ====
       from unittest.gui import TestCaseGui

       class myTests(TestCaseGui):

           def testOne(self):
               self.assertEqual(add(2,2),4,"A feedback string when the test fails")
               self.assertAlmostEqual(add(2.0,3.0), 5.0, 5, "Try adding the parameters")

       myTests().main()

Hidden Unit Tests with Graphical Status
---------------------------------------



.. activecode:: units2
   :nocodelens:

   Fix the following code so that it always correctly adds two numbers.
   ~~~~
   def add(a,b):
      return 4

   ====
   from unittest.gui import TestCaseGui

   class myTests(TestCaseGui):

       def testOne(self):
           self.assertEqual(add(2,2),4,"A feedback string when the test fails")
           self.assertAlmostEqual(add(2.0,3.0), 5.0, 5, "Try adding your parameters")

   myTests().main()


.. reveal:: units2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: units2
         :nocodelens:

         Fix the following code so that it always correctly adds two numbers.
         ~~~~
         def add(a,b):
            return 4

         ====
         from unittest.gui import TestCaseGui

         class myTests(TestCaseGui):

             def testOne(self):
                 self.assertEqual(add(2,2),4,"A feedback string when the test fails")
                 self.assertAlmostEqual(add(2.0,3.0), 5.0, 5, "Try adding your parameters")

         myTests().main()

ShowEval Trace Mode
-------------------

.. showeval:: showEval_0
   :trace_mode: true

   eggs = ['dogs', 'cats', 'moose']
   ~~~~

   ''.join({{eggs}}{{['dogs', 'cats', 'moose']}}).upper().join(eggs)
   {{''.join(['dogs', 'cats', 'moose'])}}{{'dogscatsmoose'}}.upper().join(eggs)
   {{'dogscatsmoose'.upper()}}{{'DOGSCATSMOOSE'}}.join(eggs)
   'DOGSCATSMOOSE'.join({{eggs}}{{['dogs', 'cats', 'moose']}})
   {{'DOGSCATSMOOSE'.join(['dogs', 'cats', 'moose'])}}{{'dogsDOGSCATSMOOSEcatsDOGSCATSMOOSEmoose'}}


.. showeval:: showEval_2
   :trace_mode: true

   eggs = ['dogs', 'cats', 'moose']
   ham = ['elk', 'salmon']
   eggs = eggs + ham
   ~~~~
   eggs = {{eggs}}{{['dogs', 'cats', 'moose']}} + ham
   eggs = ['dogs', 'cats', 'moose'] + {{ham}}{{['elk', 'salmon']}}
   eggs = {{['dogs', 'cats', 'moose'] + ['elk', 'salmon']}}{{['dogs', 'cats', 'moose', 'elk', 'salmon']}}

ShowEval Replace Mode
---------------------

.. showeval:: showEval_1
  :trace_mode: false

  eggs = ['dogs', 'cats', 'moose']
  ~~~~

  ''.join({{eggs}}{{['dogs', 'cats', 'moose']}}).upper().join(eggs)
  {{''.join(['dogs', 'cats', 'moose'])}}{{'dogscatsmoose'}}.upper().join(eggs)
  {{'dogscatsmoose'.upper()}}{{'DOGSCATSMOOSE'}}.join(eggs)
  'DOGSCATSMOOSE'.join({{eggs}}{{['dogs', 'cats', 'moose']}})
  {{'DOGSCATSMOOSE'.join(['dogs', 'cats', 'moose'])}}{{'dogsDOGSCATSMOOSEcatsDOGSCATSMOOSEmoose'}}


Disqus Comment Box
------------------

A comment box allowing users to add comments and start discussions can be added. A comment box can be added at the page level, but also for an individual section or question, allowing discussion of that particular content.

.. disqus::
    :shortname: interactivepython
    :identifier: discussion1

.. reveal:: disqus_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. disqus::
          :shortname: interactivepython
          :identifier: discussion1

Tabbed Question
---------------

Any of the existing components can be placed in a tabbed exhibit-style question. This may be used to provide an possible answer or a Disqus discussion box specifically related to a certain question.

.. tabbed:: exercise1

    .. tab:: Question 1

        Write a program that prints "Hello, world".

        .. activecode:: helloworld

            print("Hello, world")

    .. tab:: Discussion

        .. disqus::
            :shortname: interactivepython
            :identifier: helloworlddiscussion


.. reveal:: exercise1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. tabbed:: exercise1

          .. tab:: Question 1

              Write a program that prints "Hello, world".

              .. activecode:: helloworld

                  print("Hello, world")

          .. tab:: Discussion

              .. disqus::
                  :shortname: interactivepython
                  :identifier: helloworlddiscussion



Polls
-----
.. poll:: pollid1
   :scale: 10
   :allowcomment:

    On a scale from 1 to 10, how important do you think it is to have a polling directive in the Runestone Tools?

.. reveal:: pollid1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. poll:: pollid1
         :scale: 10
         :allowcomment:

          On a scale from 1 to 10, how important do you think it is to have a polling directive in the Runestone Tools?

Reveals
-------
.. reveal:: revealid1
    :showtitle: Reveal Content
    :hidetitle: Hide Content

    This content starts out hidden. It's visibility can be toggled by using the Show/Hide button.

    The reveal block can also contain other directives (ActiveCode, Disqus block, etc):

    .. activecode:: ac11

        print ("Hello, world")


.. reveal:: revealid1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. reveal:: revealid1
          :showtitle: Reveal Content
          :hidetitle: Hide Content

          This content starts out hidden. It's visibility can be toggled by using the Show/Hide button.

          The reveal block can also contain other directives (ActiveCode, Disqus block, etc):

          .. activecode:: ac11

              print ("Hello, world")

DOM Access
----------

Python programs written in activecode windows can now import the ``document`` module. This document module
allows access to basic elements of the web page, including the new text entry box called
**text1** :textfield:`text1:example input:medium` like this one.  Try running the program, then change
the value in the text entry box and run it again.

.. activecode:: tftest1
   :nocodelens:

   import document

   t = document.getElementById('text1')
   print('value = ', t.value)

.. reveal:: tftest1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: tftest1
         :nocodelens:

         import document

         t = document.getElementById('text1')
         print('value = ', t.value)

JavaScript
----------

We have come to realize that not everyone loves Python as much as we do.
So we have now made it possible to write activecode examples in pure javascript as well
as Python.  Here is a simple example:

.. activecode:: jstest1
   :language: javascript
   :nocodelens:

   var x = 10;
   var y = 11;
   var z = x + y;
   console.log(z);
   function fact(n) {
      if(n <= 1) return 1;
      else {
          return n * fact(n-1);
      }
   }
   console.log(fact(10));
   writeln('hello world');


Adding a javascript example is just as easy as Python, all you need to do is add a ``:language:``
parameter to the activecode directive.

.. reveal:: jstest1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: jstest1
         :language: javascript
         :nocodelens:

         var x = 10;
         var y = 11;
         var z = x + y;
         console.log(z);
         function fact(n) {
            if(n <= 1) return 1;
            else {
                return n * fact(n-1);
            }
         }
         console.log(fact(10));
         writeln('hello world');


      Adding a javascript example is just as easy as Python, all you need to do is add a ``:language:``
      parameter to the activecode directive.

HTML
----

Teaching a class on HTML and simple web design?  Why not use activecode for HTML too?
Although you don't run HTML, clicking the run button will cause the HTML to be rendered.

.. activecode:: html1
   :language: html
   :nocodelens:

   <html>
   <body>
   <style>
       h2 { font-size: 48px;
            color: red;
       }
   </style>
   <h2>Hello World</h2>
   <ul>
       <li>one</li>
       <li>two</li>
   </ul>
   </body>
   </html>

.. reveal:: html1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: html1
         :language: html
         :nocodelens:

         <html>
         <body>
         <style>
             h2 { font-size: 48px;
                  color: red;
             }
         </style>
         <h2>Hello World</h2>
         <ul>
             <li>one</li>
             <li>two</li>
         </ul>
         </body>
         </html>


Spreadsheet
-----------

Cells in the spreadsheet that are graded are initially colored light blue.  When the grade button is pressed a test report is printed out, and the cells that were correct are colored with a light green background.  The cells that were not correct have a light redish background

.. spreadsheet:: ss1
    :mindimensions: 6,5
    :colwidths: 200,100,100
    :coltitles: 'name','year','price','foo'

    Google, 1998, 807.80
    Apple, 1976, 116.52
    Yahoo, 1994, 38.66
    ,,=sum(c1:c3)

    ====
    assert A3 == Yahoo
    assert B3 == 1994



Blockly
-------

Support for blockly is very experimental at this stage.  Hopefully we will move beyond proof of concept soon.

.. blockly:: blockly1

   * controls
   controls_if
   controls_repeat_ext
   ====
   * logic
   logic_compare
   ====
   * math
   math_number
   math_arithmetic
   ====
   * text
   text
   text_print
   ====
   variables

   preload::
   <xml>
      <block type="variables_set" id="1" inline="true" x="25" y="9">
         <field name="VAR">X</field>
         <value name="VALUE">
            <block type="math_number" id="2">
               <field name="NUM">10</field>
            </block>
         </value>
      </block>
   </xml>

Add a print statement after the set X to 10.  Click on text and drag out a print block;
connect it to the set block.  Then click on variables and drag out the X block and
connect it to the print block.  Now click the run button and you should see 10 printed
in the gray output area.

Other Languages in ActiveCode
-----------------------------

Activecode now supports Java, C++ and C through a backend server, not in the browser.    You can
use them by specifying the language to be `java`, `cpp` or `c` In addition it supports either Python3 or Python2
outside of the browser using `python3` or `python2` as the language.   You are limited to non-graphical
programs in any of these options.

.. activecode:: lc1
   :language: java
   :stdin: 100

   import java.util.Scanner;

   public class TempConv {
       public static void main(String[] args) {
            Double fahr;
            Double cel;
            Scanner in;

            in = new Scanner(System.in);
            System.out.println("Enter the temperature in F: ");
            fahr = in.nextDouble();

            cel = (fahr - 32) * 5.0/9.0;
            System.out.println(fahr + " degrees F is: " + cel + " C");

            System.exit(0);
       }

   }

.. reveal:: lc1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: lc1
         :language: java
         :stdin: 100

         import java.util.Scanner;

         public class TempConv {
             public static void main(String[] args) {
                  Double fahr;
                  Double cel;
                  Scanner in;

                  in = new Scanner(System.in);
                  System.out.println("Enter the temperature in F: ");
                  fahr = in.nextDouble();

                  cel = (fahr - 32) * 5.0/9.0;
                  System.out.println(fahr + " degrees F is: " + cel + " C");

                  System.exit(0);
             }

         }



.. activecode:: lc2
    :language: cpp
    :stdin: 100
    :compileargs: ['-std=c++11', '-Wall', '-Wpedantic']

    #include <iostream>
    using namespace std;
    void main() {
        cout << "Hello World!" << endl;   cout << "Welcome to C++ Programming" << endl;
    }


SQL
---

.. activecode:: sql1
    :language: sql
    :autograde: unittest
    :dburl: https://runestone.academy/runestone/books/published/overview/_static/bikeshare.db

    select bike_number, max(duration)
    from trip_data
    group by bike_number
    order by max(duration) desc
    limit 4;

    ====
    assert 0,0 == W00379
    assert 0,1 == 86355
    assert 2,1 == 86336



.. datafile:: country_data.csv
    :fromfile: world_countries.csv

Server Side Python
------------------

.. activecode:: pandas
   :language: python3
   :datafile: country_data.csv

   import pandas as pd

   df = pd.read_csv('country_data.csv', encoding='latin1')
   print(df.head())

If the JOBE server has pandas installed we can even use pandas right in the text!

Audio Tours
-----------


.. activecode:: ch03_4
    :nocanvas:
    :tour_1: "Overall Tour"; 1-2: Example04_Tour01_Line01; 2: Example04_Tour01_Line02; 1: Example04_Tour01_Line03;

    for name in ["Joe", "Amy", "Brad", "Angelina", "Zuki", "Thandi", "Paris"]:
        print("Hi", name, "Please come to my party on Saturday!")


.. reveal:: ch03_4_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: ch03_4
          :nocanvas:
          :tour_1: "Overall Tour"; 1-2: Example04_Tour01_Line01; 2: Example04_Tour01_Line02; 1: Example04_Tour01_Line03;

          for name in ["Joe", "Amy", "Brad", "Angelina", "Zuki", "Thandi", "Paris"]:
              print("Hi", name, "Please come to my party on Saturday!")

What To Do Now
--------------

We are working on additional question types as well.  Give us your feedback on our `Github <https://github.com/RunestoneInteractive/RunestoneComponents/issues>`_  or like us or give us feedbak on our `Facebook page <http://www.facebook.com/RunestoneInteractive>`_.

You can find more complete documentation of the directives on our `Runestone docs page <http://runestoneinteractive.org/build/html/index.html>`_

Now that you have seen some of these tools in action, you can do more exploration by going to `Runestone library <http://runestoneinteractive.org/library.html>`_
and browsing through some of our existing books.

We hope you will find these tools and materials useful.  If you want to get more involved, feel free to download the tools and write your own materials.  Everything you need, instructions and help for contributing or writing your own materials, and links to our GitHub repositories, can be found `here <http://runestoneinteractive.org/build/html/index.html>`_


.. toctree::
    :hidden:

    navhelp
