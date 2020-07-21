ShowEval Trace Mode
--------------------

.. showeval:: showEval_2
   :trace_mode: true

   eggs = ['dogs', 'cats', 'moose']
   ham = ['elk', 'salmon']
   eggs = eggs + ham
   ~~~~
   eggs = {{eggs}}{{['dogs', 'cats', 'moose']}} + ham
   eggs = ['dogs', 'cats', 'moose'] + {{ham}}{{['elk', 'salmon']}}
   eggs = {{['dogs', 'cats', 'moose'] + ['elk', 'salmon']}}{{['dogs', 'cats', 'moose', 'elk', 'salmon']}}

.. reveal:: showEval_2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. showeval:: showEval_2
         :trace_mode: true

         eggs = ['dogs', 'cats', 'moose']
         ham = ['elk', 'salmon']
         eggs = eggs + ham
         ~~~~
         eggs = {​{eggs}}{​{['dogs', 'cats', 'moose']}} + ham
         eggs = ['dogs', 'cats', 'moose'] + {​{ham}}{​{['elk', 'salmon']}}
         eggs = {​{['dogs', 'cats', 'moose'] + ['elk', 'salmon']}}{​{['dogs', 'cats', 'moose', 'elk', 'salmon']}}

ShowEval Replace Mode
---------------------

.. showeval:: showEval_1
  :trace_mode: false

  eggs = ['dogs', 'cats', 'moose']
  ~~~~

  ''.join({{eggs}}{{['dogs', 'cats', 'moose']}}).upper().join(eggs)
  {{''.join(['dogs', 'cats', 'moose'])}}{{'dogscatsmoose'}}.upper().join(eggs)
  {{'dogscatsmoose'.upper()}}{​{'DOGSCATSMOOSE'}}.join(eggs)
  'DOGSCATSMOOSE'.join({​{eggs}}{​{['dogs', 'cats', 'moose']}})
  {​{'DOGSCATSMOOSE'.join(['dogs', 'cats', 'moose'])}}{​{'dogsDOGSCATSMOOSEcatsDOGSCATSMOOSEmoose'}}

.. reveal:: showEval_1_src
     :showtitle: Show Source
     :hidetitle: Hide Source
     :modaltitle: Source for the example above

     .. code-block:: rst

        .. showeval:: showEval_1
          :trace_mode: false

          eggs = ['dogs', 'cats', 'moose']
          ~~~~

          ''.join({​{eggs}}{​{['dogs', 'cats', 'moose']}}).upper().join(eggs)
          {​{''.join(['dogs', 'cats', 'moose'])}}{​{'dogscatsmoose'}}.upper().join(eggs)
          {​{'dogscatsmoose'.upper()}}{​{'DOGSCATSMOOSE'}}.join(eggs)
          'DOGSCATSMOOSE'.join({​{eggs}}{​{['dogs', 'cats', 'moose']}})
          {​​{'DOGSCATSMOOSE'.join(['dogs', 'cats', 'moose'])}}{​{'dogsDOGSCATSMOOSEcatsDOGSCATSMOOSEmoose'}}
