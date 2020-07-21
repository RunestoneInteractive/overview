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
