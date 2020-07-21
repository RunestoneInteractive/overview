
HTML
----

Teaching a class on HTML and simple web design?  Why not use activecode for HTML too?
Although you don't run HTML, clicking the run button will cause the HTML to be rendered.

.. activecode:: html1
   :language: html
   :nocodelens:

   <html>
   <body>
   <style>
       h2 { font-size: 48px;
            color: red;
       }
   </style>
   <h2>Hello World</h2>
   <ul>
       <li>one</li>
       <li>two</li>
   </ul>
   </body>
   </html>

.. reveal:: html1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: html1
         :language: html
         :nocodelens:

         <html>
         <body>
         <style>
             h2 { font-size: 48px;
                  color: red;
             }
         </style>
         <h2>Hello World</h2>
         <ul>
             <li>one</li>
             <li>two</li>
         </ul>
         </body>
         </html>
