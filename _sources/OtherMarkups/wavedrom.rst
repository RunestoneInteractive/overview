********
WaveDrom
********
`WaveDrom <https://wavedrom.com/>`_ provides digital timing diagrams based on a JSON-formatted description of the waveform. See the home page for extensive documentation on how to create these diagrams.

The Runestone extension allows authors to easily include these diagrams in a Runestone book. The code to embed a diagram closely follows the code used to embed `GraphViz diagrams <https://www.sphinx-doc.org/en/master/usage/extensions/graphviz.html>`_, and therefore supports the same options:

.. rst:directive:: wavedrom

    Directive to embed wavedrom code.  The input WaveJSON code for ``wavedrom`` is given as the content; omit the outermost curly braces (``{}``).  For example::

        .. wavedrom::

            signal: [{ name: "clk", wave: "010101" }]

    produces:

    .. wavedrom::

        signal: [{ name: "clk", wave: "010101" }]

    .. rubric:: options

    .. rst:directive:option:: align: alignment of the graph
        :type: left, center or right

        The horizontal alignment of the graph.

    .. rst:directive:option:: caption: caption of the graph
        :type: text

        The caption of the graph.

    .. rst:directive:option:: name: label
        :type: text

        The label of the graph.

    .. rst:directive:option:: class: class names
        :type: a list of class names separeted by spaces

        The class name of the graph.

As another example:

.. wavedrom::
    :caption: A basic clock waveform.
    :align: right

    signal: [{ name: "Alfa", wave: "01.zx=ud.23.456789" }]

.. reveal:: wavedrom_src
    :showtitle: Show Source
    :hidetitle: Hide Source
    :modaltitle: Source for the example above

    .. literalinclude:: wavedrom.rst
        :language: rest
        :start-after: As another example:
        :end-before: wavedrom_src
