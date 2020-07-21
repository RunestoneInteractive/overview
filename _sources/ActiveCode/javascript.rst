JavaScript
----------

We have come to realize that not everyone loves Python as much as we do.
So we have now made it possible to write activecode examples in pure javascript as well
as Python.  Here is a simple example:

.. activecode:: jstest1
   :language: javascript
   :nocodelens:

   var x = 10;
   var y = 11;
   var z = x + y;
   console.log(z);
   function fact(n) {
      if(n <= 1) return 1;
      else {
          return n * fact(n-1);
      }
   }
   console.log(fact(10));
   writeln('hello world');


Adding a javascript example is just as easy as Python, all you need to do is add a ``:language:``
parameter to the activecode directive.

.. reveal:: jstest1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: jstest1
         :language: javascript
         :nocodelens:

         var x = 10;
         var y = 11;
         var z = x + y;
         console.log(z);
         function fact(n) {
            if(n <= 1) return 1;
            else {
                return n * fact(n-1);
            }
         }
         console.log(fact(10));
         writeln('hello world');


      Adding a javascript example is just as easy as Python, all you need to do is add a ``:language:``
      parameter to the activecode directive.
