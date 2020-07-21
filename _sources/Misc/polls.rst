Polls
-----

You can have a poll with a scale from x to y (such as 1 to 10).

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

You can also have a poll with specific answers.

.. poll:: qstudent
   :option_1: student
   :option_2: teacher
   :option_3: other
   :option_4: prefer not to answer

   I am a :

.. reveal:: qstudent_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. poll:: qstudent
         :option_1: student
         :option_2: teacher
         :option_3: other
         :option_4: prefer not to answer

         I am a :
