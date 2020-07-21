Spreadsheet
-----------

Cells in the spreadsheet that are graded are initially colored light blue.  When the grade button is pressed a test report is printed out, and the cells that were correct are colored with a light green background.  The cells that were not correct have a light redish background

.. spreadsheet:: ss1
    :mindimensions: 6,5
    :colwidths: 200,100,100
    :coltitles: 'name','year','price','foo'

    Google, 1998, 807.80
    Apple, 1976, 116.52
    Yahoo, 1994, 38.66
    ,,=sum(c1:c3)

    ====
    assert A3 == Yahoo
    assert B3 == 1994

.. reveal:: ss1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. spreadsheet:: ss1
          :mindimensions: 6,5
          :colwidths: 200,100,100
          :coltitles: 'name','year','price','foo'

          Google, 1998, 807.80
          Apple, 1976, 116.52
          Yahoo, 1994, 38.66
          ,,=sum(c1:c3)

          ====
          assert A3 == Yahoo
          assert B3 == 1994

