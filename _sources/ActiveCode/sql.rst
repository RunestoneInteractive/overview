SQL
---

You can even have SQL in an activecode.

.. activecode:: sql1
    :language: sql
    :autograde: unittest
    :dburl: /_static/bikeshare.db

    select bike_number, max(duration)
    from trip_data
    where start_station = 31105
    group by bike_number
    order by max(duration) desc
    limit 4;

    ====
    assert 0,0 == W00554
    assert 0,1 == 51618
    assert 2,1 == 38347

.. reveal:: sql1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block::

      .. activecode:: sql1
         :language: sql
         :autograde: unittest
         :dburl: https://runestone.academy/runestone/books/published/overview/_static/bikeshare.db

         select bike_number, max(duration)
         from trip_data
         group by bike_number
         order by max(duration) desc
         limit 4;

         ====
         assert 0,0 == W00379
         assert 0,1 == 86355
         assert 2,1 == 86336

