Drag N Drop
-----------

You can add a Drag n drop matching question to your page simply by defining the pairs of matchable elements within a dragndrop directive.
The order of draggable elements and their respective dropzones will be randomized so the pairs aren't always side-by-side.

.. dragndrop:: dnd1
    :prim_comp: ASSIGNMENT
    :feedback: This is feedback.
    :match_1: Monroe Doctrine|||1823
    :match_2: Haymarket Riot|||1886
    :match_3: Louisiana Purchase|||1803
    :match_4: Battle of Gettysburg|||1863


    Match each event in United States history with the year it happened.

.. reveal:: dnd1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. dragndrop:: dnd1
          :prim_comp: ASSIGNMENT
          :feedback: This is feedback.
          :match_1: Monroe Doctrine|||1823
          :match_2: Haymarket Riot|||1886
          :match_3: Louisiana Purchase|||1803
          :match_4: Battle of Gettysburg|||1863

          Match each event in United States history with the year it happened.


.. reveal:: ptx_matching_1
    :showtitle: Show PreTeXt
    :hidetitle: Hide PreTeXt

    .. code-block:: xml

        <exercise label="matching-dates">
            <title>Matching Problem, Dates</title>
            <idx>matching US dates</idx>
            <statement>
                <p>Match each event in United States history with the year it happened.</p>
            </statement>
            <feedback>
                <p>Review <url href="https://www.britannica.com/list/25-decade-defining-events-in-us-history" visual="www.britannica.com/list/25-decade-defining-events-in-us-history">Encyclopedia Brittania, 25 Decade-Defining Events in U.S. History</url>url.</p>
            </feedback>
            <matches>
                <match order="4">
                    <premise>Monroe Doctrine</premise>
                    <response>1823</response>
                </match>
                <match order="3">
                    <premise>Haymarket Riot</premise>
                    <response>1886</response>
                </match>
                <match order="1">
                    <premise>Louisiana Purchase</premise>
                    <response>1803</response>
                </match>
                <match order="2">
                    <premise>Battle of Gettysburg</premise>
                    <response>1863</response>
                </match>
            </matches>
        </exercise>
