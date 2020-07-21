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
