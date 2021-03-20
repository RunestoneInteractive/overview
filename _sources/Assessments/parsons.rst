Parsons Problems - Mixed Up Blocks
-------------------------------------

Parsons problems provide blocks that are mixed up and the user must drag the blocks to the right and put them in the correct order.  The blocks can be plain text as shown below.

.. parsonsprob:: morning

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


The blocks can contain code. They can
also have numbered labels on the left or right side which can help people working in groups to discuss the problem (:numbered: left or :numbered: right).  The example below shows a problem in Python. Notice that a block can contain more than one line of code.  Be sure to break up the lines of code so that there is only one correct solution.

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
                    for (int i = 15; i > 0; i--) #paired
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
                     for (int i = 15; i > 0; i--) #paired
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
           for (int i = 15; i > 0; i--) #paired
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
                     for (int i = 15; i > 0; i--) #paired
         =====
                         System.out.println(i);
         =====
              }
         =====
         }

