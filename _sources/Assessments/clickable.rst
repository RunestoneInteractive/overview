Clickable Area
--------------

Clickable area is another type of assess question you can use. All you need to do is write the code you wish to be in the question, and wrap the parts that you
would like to be clickable in either a click-correct tag or a click-incorrect tag. The students can click on all elements you defined as being clickable, and
will be evaluated once they click the 'Check Me' button.

.. clickablearea:: click1
    :question: Click on all assignment statements.
    :prim_comp: ASSIGNMENT
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
          :prim_comp: ASSIGNMENT
          :iscode:
          :feedback: Remember, the operator '=' is used for assignment.

          :click-incorrect:def main()::endclick:
              :click-correct:x = 4:endclick:
              for i in range(5):
                  :click-correct:y = i:endclick:
                  :click-incorrect:if y > 2::endclick:
                      print(y)


.. reveal:: ptx_click1_src
    :showtitle: Show PreTeXt
    :hidetitle: Hide PreTeXt

    .. code-block:: xml

        <exercise label="clickable-code">
            <title>Clickable Areas, Code</title>

            <statement>
                <p>Identify (by clicking, or by circling) all of the assignment statements in this Python function.</p>
            </statement>

            <areas language="python">
                <cline><area correct="no">def main():</area></cline>
                <cline>    <area correct="yes">x = 4</area></cline>
                <cline>    for i in range(5):</cline>
                <cline>        <area>y = i</area></cline>
                <cline>        <area correct="no">if y > 2:</area></cline>
                <cline>            print(y)</cline>
            </areas>

            <feedback>
                <p>Remember, the operator <c>=</c> is used for assignment.</p>
            </feedback>
        </exercise>
