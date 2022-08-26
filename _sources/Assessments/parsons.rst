Parsons Problems - Mixed Up Blocks
-------------------------------------

Parsons problems provide blocks that are mixed up and the user must drag the blocks to the right and put them in the correct order.  The blocks can be plain text as shown below.

.. parsonsprob:: morning
   :prim_comp: GENERAL

   Put the blocks in order to describe a morning routine.
   -----
   get up
   =====
   eat breakfast
   =====
   brush your teeth

.. reveal:: morning_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. parsonsprob:: morning

         Put the blocks in order to describe a morning routine.
         -----
         get up
         =====
         eat breakfast
         =====
         brush your teeth


.. reveal:: ptx_morning_src
   :showtitle: Show PreTeXt
   :hidetitle: Hide PreTeXt

      .. code-block:: xml

         <exercise label="number-theory-proof" adaptive="yes">
            <title>Early morning exercise</title>
            <statement>
                <p>Put the blocks in order.</p>
            </statement>
            <blocks>
                <block order="2">
                    <p>Get Up</p>
                </block>
                <block order="3">
                    <choice><p>Drink a shot of rum</p></choice>
                    <choice correct="yes"><p>Eat Breakfast</p></choice>
                </block>
                <block order="1">
                    <p>Brush your teeth</p>
                </block>
            </blocks>
            <hint>Drinking before noon is not recommended.</hint>
         </exercise>

The blocks can contain code. They can
also have numbered labels on the left or right side which can help people working in groups to discuss the problem (:numbered: left or :numbered: right).  The example below shows a problem in Python. Notice that a block can contain more than one line of code.  Be sure to break up the lines of code so that there is only one correct solution.

.. parsonsprob:: per_person_cost
   :numbered: left
   :prim_comp: GENERAL

   The following program should figure out the cost per person for a dinner including the tip. But the blocks have been mixed up.  Drag the blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
   -----
   bill = 89.23
   =====
   tip = bill * 0.20
   =====
   total = bill + tip
   =====
   numPeople = 3
   perPersonCost = total / numPeople
   =====
   print(perPersonCost)

.. reveal:: per_person_cost_src
      :showtitle: Show Source
      :hidetitle: Hide Source
      :modaltitle: Source for the example above

      .. code-block:: rst

         .. parsonsprob:: per_person_cost
            :numbered: left

            The following program should figure out the cost per person for a dinner including the tip. But the blocks have been mixed up.  Drag the blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
            -----
            bill = 89.23
            =====
            tip = bill * 0.20
            =====
            total = bill + tip
            =====
            numPeople = 3
            perPersonCost = total / numPeople
            =====
            print(perPersonCost)

Here is an example in Java.  Parsons problems can have distractor (incorrect) code blocks that are not needed in a correct solution. Indicate that a block is a distractor by adding (#distractor) at the end of the line of code.  This will randomly mix in the distractor block with the correct code blocks.  The problems can also be adaptive (:adaptive:), which means that if learner is struggling to answer the problem correctly it can dynamically be made easier by removing distractors or combining blocks.  You can tell if a problem is adaptive because it will have a "Help Me" button.  The learner must submit at least three incorrect solutions before they can use the help button.  Also, notice that the indentation has been provided in the problem below.  This is because of the ( :noindent:).

.. parsonsprob:: java_countdown
   :numbered: left
   :adaptive:
   :noindent:

   The following program segment should print a countdown from 15 to 0 (15, 14, 13, ... 0).  But the blocks have been mixed up and include <b>one extra block</b> that is not needed in a correct solution.  Drag the needed blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
   -----
   public class Test1
   {
   =====
       public static void main(String[] args)
       {
   =====
           for (int i = 15; i >=0; i--)
   =====
           for (int i = 15; i > 0; i--) #distractor
   =====
               System.out.println(i);
   =====
       }
   =====
   }

.. reveal:: java_countdown_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. parsonsprob:: java_countdown
         :numbered: left
         :adaptive:
         :noindent:

         The following program segment should print a countdown from 15 to 0 (15, 14, 13, ... 0).  But the blocks have been mixed up and include <b>one extra block</b> that is not needed in a correct solution.  Drag the needed blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
         -----
         public class Test1
         {
         =====
             public static void main(String[] args)
             {
         =====
                 for (int i = 15; i >=0; i--)
         =====
                 for (int i = 15; i > 0; i--) #distractor
         =====
                     System.out.println(i);
         =====
             }
         =====
         }

Here is the same example, but with a paired distractor (#paired vs #distractor).  The distractor block be shown either above or below the correct block.  There will also be purple edges on the sides and the word "or" to show that the blocks are paired.
You can optionally add an explanation of the distractor by adding a colon and including text after the colon.  This will be
shown if the user hovers over the block after the block is disabled.

.. parsonsprob:: java_countdown_paired
            :numbered: left
            :noindent:

            The following program segment should print a countdown from 15 to 0 (15, 14, 13, ... 0).  But the blocks have been mixed up and include <b>one extra block</b> that is not needed in a correct solution.  Drag the needed blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
            -----
            public class Test1
            {
            =====
                public static void main(String[] args)
                {
            =====
                    for (int i = 15; i >=0; i--)
            =====
                    for (int i = 15; i > 0; i--) #paired: This will stop when i is 0 so the countdown won't include 0
            =====
                        System.out.println(i);
            =====
                }
            =====
            }

.. reveal:: java_countdown_paired_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. parsonsprob:: java_countdown_paired
         :numbered: left
         :noindent:

         The following program segment should print a countdown from 15 to 0 (15, 14, 13, ... 0).  But the blocks have been mixed up and include <b>one extra block</b> that is not needed in a correct solution.  Drag the needed blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
         -----
         public class Test1
         {
         =====
             public static void main(String[] args)
             {
         =====
                 for (int i = 15; i >=0; i--)
         =====
                     for (int i = 15; i > 0; i--) #paired: This will stop when i is 0 so the countdown won't include 0
         =====
                         System.out.println(i);
         =====
              }
         =====
         }

Here is the same problem, but now the user has to indent the code as well since this does not have (:noindent:).  That means the user must provide the indentation.  Notice the lines in the solution area to the right, they that indicate that indentation is possible.

.. parsonsprob:: java_countdown_paired2
   :numbered: left

   The following program segment should print a countdown from 15 to 0 (15, 14, 13, ... 0).  But the blocks have been mixed up and include <b>one extra block</b> that is not needed in a correct solution.  Drag the needed blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
   -----
   public class Test1
   {
   =====
       public static void main(String[] args)
       {
   =====
           for (int i = 15; i >=0; i--)
   =====
           for (int i = 15; i > 0; i--) #paired: This will never reach 0
   =====
               System.out.println(i);
   =====
       }
   =====
   }

.. reveal:: java_countdown_paired2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. parsonsprob:: java_countdown_paired
         :numbered: left

         The following program segment should print a countdown from 15 to 0 (15, 14, 13, ... 0).  But the blocks have been mixed up and include <b>one extra block</b> that is not needed in a correct solution.  Drag the needed blocks from the left and put them in the correct order on the right.  Click the *Check Me* button to check your solution.</p>
         -----
         public class Test1
         {
         =====
             public static void main(String[] args)
             {
         =====
                 for (int i = 15; i >=0; i--)
         =====
                     for (int i = 15; i > 0; i--) #paired: This will never reach 0
         =====
                         System.out.println(i);
         =====
              }
         =====
         }


Graph Based Grading
~~~~~~~~~~~~~~~~~~~

Sometimes there is not one correct ordering for a problem.  For example if you need to initialize a couple of variables and then use them later, but the order you initialize the variables doesn't matter.  If you can specify the order of the blocks as a Directed Acyclic Graph then you can do create a Parsons problem with dependencies.  
Here is a simple example.  The variables a and b can be initialized in either order as long as they are initialized before they are used in the multiplication.

.. parsonsprob:: simple_dag
    :grader: dag

    -----
    a = 5 #tag:0; depends:;
    =====
    b = 10 #tag:1; depends:;
    =====
    result = a * b #tag:2; depends: 0,1;
    =====
    print(f"result = {result}") #tag:3; depends: 2;

.. reveal:: proof_blocks_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

        .. parsonsprob:: simple_dag_src
            :grader: dag

            -----
            a = 5 #tag:0; depends:;
            =====
            b = 10 #tag:1; depends:;
            =====
            result = a * b #tag:2; depends: 0,1;
            =====
            print(f"result = {result}") #tag:3; depends: 2;

Here is a more complicated example from :math:`Mathematics` :

Proof Blocks
~~~~~~~~~~~~

.. parsonsprob:: test_proof_blocks_1
  :language: natural
  :grader: dag

  .. raw:: html

    <embed>
          <p>Drag and drop <font color="red"><strong>ALL</strong></font> of the blocks below to create a proof of the following statement.</p>
        <center><font color="red">If graphs \(G\) and \(H\) are isomorphic and \(G\) is 2-colorable, then \(H\) is 2-colorable.</font></center>
    </embed>

  -----
  Assume \(G\) and \(H\) are isomorphic graphs and \(G\) is 2-colorable. #tag:0; depends:;
  =====
  Let \(c:V(G) \to \{red, blue\}\) be a 2-coloring of \(G\). #tag: 1; depends:0;
  =====
  Let \(f\) be an isomorphism \(V(H) \to V(G)\) #tag: 2; depends: 0;
  =====
  Define \(c':V(H) \to \{red, blue\}\) as \(c'(v)=c(f(v))\) #tag:3;depends:1,2;
  =====
  Let \(\langle u - v \rangle\) be an edge in \(H\). (If instead there are no edges in \(H\), then \(H\) is trivially 2-colorable and we are done.) #tag:4;depends:0;
  =====
  \(\langle f(u) - f(v) \rangle\) is an edge in \(G\) #tag:5;depends:4,2;
  =====
  \(c(f(u)) \ne c(f(v))\) #tag:6;depends:5,1;
  =====
  \(c'(u) \ne c'(v)\) #tag:7;depends:6,3;
  =====
  \(c'\) is a 2-coloring of \(H\), so \(H\) is 2-colorable. (end of proof) #tag:8;depends:7;


.. reveal:: proof_blocks_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. parsonsprob:: test_proof_blocks_1
        :language: math
        :grader: dag

        .. raw:: html

            <embed>
                <p>Drag and drop <font color="red"><strong>ALL</strong></font> of the blocks below to create a proof of the following statement.</p>
                <center><font color="red">If graphs \(G\) and \(H\) are isomorphic and \(G\) is 2-colorable, then \(H\) is 2-colorable.</font></center>
            </embed>

        -----
        Assume \(G\) and \(H\) are isomorphic graphs and \(G\) is 2-colorable. #tag:0; depends:;
        =====
        Let \(c:V(G) \to \{red, blue\}\) be a 2-coloring of \(G\). #tag: 1; depends:0;
        =====
        Let \(f\) be an isomorphism \(V(H) \to V(G)\) #tag: 2; depends: 0;
        =====
        Define \(c':V(H) \to \{red, blue\}\) as \(c'(v)=c(f(v))\) #tag:3;depends:1,2;
        =====
        Let \(\langle u - v \rangle\) be an edge in \(H\). (If instead there are no edges in \(H\), then \(H\) is trivially 2-colorable and we are done.) #tag:4;depends:0;
        =====
        \(\langle f(u) - f(v) \rangle\) is an edge in \(G\) #tag:5;depends:4,2;
        =====
        \(c(f(u)) \ne c(f(v))\) #tag:6;depends:5,1;
        =====
        \(c'(u) \ne c'(v)\) #tag:7;depends:6,3;
        =====
        \(c'\) is a 2-coloring of \(H\), so \(H\) is 2-colorable. (end of proof) #tag:8;depends:7;


Horizontal Parsons Problems
~~~~~~~~~~~~~~~~~~~~~~~~~~~

This parsons problem demonstrates randomized blocks with block based feedback.

.. hparsons:: test_hparsons_block_1
    :language: sql
    :dburl: /_static/test.db
    :randomize:
    :blockanswer: 0 1 2 3

    This is a horizontal Parsons problem! Feedback is based on block for this problem.
    The blocks are randomized, but cannot be reused ;)
    ~~~~
    --blocks--
    SELECT 
    *
    FROM
    test


Randomized block with execution based feedback.

.. hparsons:: test_hparsons_regex_1 
    :language: regex
    :randomize:
    :reuse:
    :blockanswer: 0 1 2 3

    This is a horizontal Parsons problem! Feedback is based on code execution.
    The blocks are randomized, but cannot be reused ;) write a regular expression 
    that matches a string that starts with ab followed by zero or more c
    ~~~~
    --blocks--
    a
    b
    c
    *

Randomized block with execution based feedback

.. hparsons:: test_hparsons_sql_1 
    :language: sql
    :dburl: /_static/test.db
    :randomize:

    This is a horizontal Parsons problem! Feedback is based on code execution.
    The blocks are randomized, but cannot be reused ;)
    ~~~~
    --blocks--
    SELECT 
    *
    FROM
    test
    --unittest--
    assert 1,1 == world
    assert 0,1 == hello
    assert 2,1 == 42

(2x-3)^2
4x^2 -6x -6x + 9
