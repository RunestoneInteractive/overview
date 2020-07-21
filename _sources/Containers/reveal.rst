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
