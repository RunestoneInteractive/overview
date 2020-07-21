Tabbed Question
---------------

Any of the existing components can be placed in a tabbed exhibit-style question. This may be used to provide an possible answer or a Disqus discussion box specifically related to a certain question.

.. tabbed:: exercise1

    .. tab:: Question 1

        Write a program that prints "Hello, world".

        .. activecode:: helloworld

            print("Hello, world")

    .. tab:: Discussion

        .. disqus::
            :shortname: interactivepython
            :identifier: helloworlddiscussion


.. reveal:: exercise1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. tabbed:: exercise1

          .. tab:: Question 1

              Write a program that prints "Hello, world".

              .. activecode:: helloworld

                  print("Hello, world")

          .. tab:: Discussion

              .. disqus::
                  :shortname: interactivepython
                  :identifier: helloworlddiscussion

