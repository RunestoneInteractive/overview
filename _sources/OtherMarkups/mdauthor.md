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

## Parsons Problems

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

## Multiple Choice

```{mchoice} question1_ma
:multiple_answers:
:correct: a, c
:answer_a: red
:answer_b: brown
:answer_c: blue
:answer_d: gray
:feedback_a: Red it is.
:feedback_b: Not brown.
:feedback_c: Blue it is.
:feedback_d: Not gray.

Which colors might be found in a rainbow (check all)?
```

