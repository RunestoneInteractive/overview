# You can also use Runestone Components and write in Markdown!

Lets try an activecode directive!

```{activecode} mdactive

print("Hello World")
```


Writing directives in Markdown is a little different  The above example was written as:


    ```{activecode} mdactive

    print("Hello World")
    ```

Whereas in RST you would write:

```
.. activecode:: mdactive

    print("hello world")
```


Lets Try a Parsons

Parsons Problems
----------------

```{parsonsprob} bnm_3_1_2018_md

Add some text here

-----
import turtle
window = turtle.Screen()
ella = turtle.Turtle()
=====
ella.right(90)
ella.forward(150)
=====
ella.left(90)
ella.forward(75)
```

