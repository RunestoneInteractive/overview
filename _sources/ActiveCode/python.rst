ActiveCode Examples in Python
--------------------------------

One of the most important things that you can do when you are learning a programming language is to write programs.  Unfortunately,
typical textbooks allow you to read about programming, but don't allow you to practice.  We have created a unique tool called
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

Click on the "Show Source" button below to see what the reStructuredText (rst) looks like for the activecode above.  You can author ebook content in rst.

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

.. reveal:: codeexample2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

       .. code-block:: rst

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


Image Processing
----------------

We have a special image library that we wrote for skulpt that lets you access images pixel by pixel.  This is a great way to practice nested iteration and to learn about the many different filters provided by services like Instagram, and others.

.. datafile:: golden_gate.png
    :image:
    :fromfile: golden_gate.png


Click on the reveal to see the rst for the datafile directive.

.. reveal:: golden_gate_ex
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. datafile:: golden_gate.png
         :image:
         :fromfile: golden_gate.png

You can use images in many ways.  If you have an image in your page and it has an id tag you can use that.  If you have a full URL to an image you can use that.  But the best thing to do if you are writing a book is to use the ``.. datafile::`` directive, this ensures that the image is available from anywhere in the book.

.. activecode::  act_ip_1
    :nocodelens:

    import image

    img = image.Image("golden_gate.png")
    win = image.ImageWin(img.getWidth(), img.getHeight())
    img.draw(win)
    img.setDelay(1,15)   # setDelay(1, 2000) will speed up a lot                      # img.setDelay(delay, number of pixels between delay)

    for row in range(img.getHeight()):
        for col in range(img.getWidth()):
            p = img.getPixel(col, row)

            newred = p.red * 1.4
            newgreen =  p.green * .75
            newblue =  p.blue * 1.1

            newpixel = image.Pixel(newred, newgreen, newblue)

            img.setPixel(col, row, newpixel)

    img.draw(win)
    win.exitonclick()

Click on the reveal to show the source for the activecode above.

.. reveal:: act_ip_1_rev
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode::  act_ip_1
          :nocodelens:

          import image

          img = image.Image("golden_gate.png")
          win = image.ImageWin(img.getWidth(), img.getHeight())
          img.draw(win)
          img.setDelay(1,15)   # setDelay(1, 2000) will speed up a lot                      # img.setDelay(delay, number of pixels between delay)

          for row in range(img.getHeight()):
              for col in range(img.getWidth()):
                  p = img.getPixel(col, row)

                  newred = p.red * 1.4
                  newgreen =  p.green * .75
                  newblue =  p.blue * 1.1

                  newpixel = image.Pixel(newred, newgreen, newblue)

                  img.setPixel(col, row, newpixel)

          img.draw(win)
          win.exitonclick()


Graphs and Charts
-----------------

Using a simple Altair-like wrapper around the vega library, we can draw some nice charts and graphs.  We only implement a subset of altair but you can do most of the basic plots. bar, scatter, line, point, heatmaps are all possible.  If you see something from the `Altair Gallery <https://altair-viz.github.io/gallery/>`_ that does not work let us know, or have a look at the code `On github <https://github.com/RunesotneInteractive/skulpt>`_ and make PR 😀!

A key difference between our baby Altair and the real Altair is that we do not use DataFrames.  We use a simple Data object.  YOu can create a data object with a bunch of named parameters and lists of values as shown below. Or from a dictionary or even from a JSON object.

.. activecode:: alt_kiva_bar1
    :nocodelens:

    import altair

    data = altair.Data(customer=['Alice', 'Bob', 'Claire'], cakes=[5,9,7], flavor=['chocolate', 'vanilla', 'strawberry'])
    print(data)
    chart = altair.Chart(data)
    mark = chart.mark_bar()
    enc = mark.encode(x='customer:N',y='cakes',color='flavor:N')
    enc.display()

.. reveal:: alt_kiva_bar1_rev
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: alt_kiva_bar1
          :nocodelens:

          import altair

          data = altair.Data(customer=['Alice', 'Bob', 'Claire'], cakes=[5,9,7], flavor=['chocolate', 'vanilla', 'strawberry'])
          print(data)
          chart = altair.Chart(data)
          mark = chart.mark_bar()
          enc = mark.encode(x='customer:N',y='cakes',color='flavor:N')
          enc.display()




Unit Tests for Python Code
---------------------------

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


Click the Show Source button to see the source code for the above example.

.. reveal:: units1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

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

Before you go on, fix the add function in the activecode box.  The full complement of assertXXX functions is available.  You can see the list `Here <http://docs.python.org/2/library/unittest.html#assert-methods>`__.  Now, for an introductory course exposing the inner workings of the unittest class may lead to more confusion that anything.

Hidden Unit Tests with Graphical Status
---------------------------------------

You can get the benefit of the unittest module with activecode by placing it in the hidden code at the end.  You can hide the code by placing it after a line that contains ``====``.


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

Server Side Python
------------------

If the JOBE server has pandas installed we can even use pandas right in the text and have it process data from a file.  Just use the option :language: python3.

Here is the file it will read from.

.. datafile:: country_data.csv
    :fromfile: world_countries.csv

.. activecode:: pandas
   :language: python3
   :datafile: country_data.csv

   import pandas as pd

   df = pd.read_csv('country_data.csv', encoding='latin1')
   print(df.head())

.. reveal:: pandas_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: pandas
         :language: python3
         :datafile: country_data.csv

         import pandas as pd

         df = pd.read_csv('country_data.csv', encoding='latin1')
