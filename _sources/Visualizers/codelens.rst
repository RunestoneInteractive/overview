The CodeLens Tool
-----------------


In addition to activecode, you can also execute Python code with the assistance of a unique visualization tool.  This tool, known as **codelens**, allows you to control the step by step execution of a program.  It also lets you see the values of
all variables as they are created and modified.  The following example shows codelens in action on the same simple program as we saw above.  Remember that in activecode, the source code executes from beginning to end and you can see the final result.  In codelens you can see and control the step by step progress.  Try clicking on the forward button below.

.. codelens:: over_codelens1
    :showoutput:

    print("My first program adds two numbers, 2 and 3:")
    print(2 + 3)

Note that you can control the step by step execution and you can even move forward and backward thru the statements as they execute.

.. reveal:: over_codelens1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. codelens:: firstexample
          :showoutput:

          print("My first program adds two numbers, 2 and 3:")
          print(2 + 3)


The following example shows a more sophisticated program using Python lists.  The codelens tool draws very useful  pictures as the statements are being executed.  These pictures, called reference diagrams, are very helpful as you learn about the more complex aspects of Python.

.. codelens:: secondexample

    fruit = ["apple","orange","banana","cherry"]
    numlist = [6,7]
    newlist = fruit + numlist
    zeros = [0] * 4

    zeros[1] = fruit
    zeros[1][2] = numlist

.. reveal:: secondexample_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. codelens:: secondexample

         fruit = ["apple","orange","banana","cherry"]
         numlist = [6,7]
         newlist = fruit + numlist
         zeros = [0] * 4

         zeros[1] = fruit
         zeros[1][2] = numlist

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

