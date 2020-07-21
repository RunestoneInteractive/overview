Java
----

Activecode now supports Java, C++ and C through a backend server, not in the browser.    You can
use them by specifying the language to be `java`, `cpp` or `c` In addition it supports either Python3 or Python2
outside of the browser using `python3` or `python2` as the language.   You are limited to non-graphical
programs in any of these options.

.. activecode:: lc1
   :language: java
   :stdin: 100

   import java.util.Scanner;

   public class TempConv {
       public static void main(String[] args) {
            Double fahr;
            Double cel;
            Scanner in;

            in = new Scanner(System.in);
            System.out.println("Enter the temperature in F: ");
            fahr = in.nextDouble();

            cel = (fahr - 32) * 5.0/9.0;
            System.out.println(fahr + " degrees F is: " + cel + " C");

            System.exit(0);
       }

   }

.. reveal:: lc1_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: lc1
         :language: java
         :stdin: 100

         import java.util.Scanner;

         public class TempConv {
             public static void main(String[] args) {
                  Double fahr;
                  Double cel;
                  Scanner in;

                  in = new Scanner(System.in);
                  System.out.println("Enter the temperature in F: ");
                  fahr = in.nextDouble();

                  cel = (fahr - 32) * 5.0/9.0;
                  System.out.println(fahr + " degrees F is: " + cel + " C");

                  System.exit(0);
             }

         }

Unit Tests in Java
---------------------

You can also have hidden unit tests in Java using JUnit tests.  Place the unit tests after '===='.

.. activecode:: jUnitTesting2
    :language: java
    :autograde: unittest

    Here is a for loop that counts from 1 to 5.
    Can you change it to count from 2 to 10?
    ~~~~
    public class StudentCode
    {
        public static void main(String[] args)
        {
            for(int count = 2; count <= 10; count++)
            {
                System.out.println(count);
            }

        }

        public int adder(int a, int b) {

            return a+b;
        }
    }

    ====
    import static org.junit.Assert.*;

    import org.junit.After;
    import org.junit.Before;
    import org.junit.Test;

    import java.io.*;
    import java.nio.file.Files;
    import java.nio.file.Paths;

    public class ForLoopTestTester extends CodeTestHelper
    {
        /* Example test for main method - should pass */
        @Test
        public void testMain() throws IOException
        {
            // I wrote a method to run a method and send back the output - only works with String[] args for now
            String output = getMethodOutput("main");
            String expect = "2\n3\n4\n5\n6\n7\n8\n9\n10\n";

            assertEquals("Output doesn't match", cleanString(expect), cleanString(output));

        }

        @Test
        public void testAdder() throws IOException {
            StudentCode s = new StudentCode();
            String msg = "Adding 2+2" + ""+4 + ""+s.adder(2,2);
            System.out.println("testing s.adder(2,2)");
            assertEquals(msg, 4, s.adder(2,2));
            assertEquals("adding 3+3", 6, s.adder(3,3));
        }

        @Test
        public void testContent() throws IOException {
            String content = new String ( Files.readAllBytes( Paths.get("StudentCode.java")));

        }
    }

.. reveal:: junit_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block::

      .. activecode:: jUnitTesting2
          :language: java
          :autograde: unittest

          Here is a for loop that counts from 1 to 5.
          Can you change it to count from 2 to 10?
          ~~~~
          public class StudentCode
          {
              public static void main(String[] args)
              {
                  for(int count = 2; count <= 10; count++)
                  {
                      System.out.println(count);
                  }

              }

              public int adder(int a, int b) {

                  return a+b;
              }
          }

          ====
          import static org.junit.Assert.*;

          import org.junit.After;
          import org.junit.Before;
          import org.junit.Test;

          import java.io.*;
          import java.nio.file.Files;
          import java.nio.file.Paths;

          public class ForLoopTestTester extends CodeTestHelper
          {
              /* Example test for main method - should pass */
              @Test
              public void testMain() throws IOException
              {
            // I wrote a method to run a method and send back the output - only works       with String[] args for now
                  String output = getMethodOutput("main");
                  String expect = "2\n3\n4\n5\n6\n7\n8\n9\n10\n";

            assertEquals("Output doesn't match", cleanString(expect), cleanString      (output));

              }

              @Test
              public void testAdder() throws IOException {
                  StudentCode s = new StudentCode();
                  String msg = createMessage("Adding 2+2", ""+4, ""+s.adder(2,2));
                  System.out.println("testing s.adder(2,2)");
                  assertEquals(msg, 4, s.adder(2,2));
                  assertEquals("adding 3+3", 6, s.adder(3,3));
              }

              @Test
              public void testContent() throws IOException {
            String content = new String ( Files.readAllBytes( Paths.get("StudentCode.      java")));

              }
          }

.. activecode:: jUnitTesting3
    :language: java
    :autograde: unittest

    In this project, you will create a class that can tell riddles like the following:

    Riddle Question: Why did the chicken cross the playground?
    Riddle Answer: To get to the other slide!
    ~~~~
    public class Riddle
    {
        // 2 instance variables for Riddle's question and answer: private type variableName;
        private String quest;
        private String ans;

        // constructor
        public Riddle(String initQuestion, String initAnswer)
        {
            // set the instance variables to the init parameter variables
            quest = initQuestion;
            ans = initAnswer;
        }

        // Print riddle question
        public void printQuestion()
        {
            // print out the riddle question with System.out.println
            System.out.println(quest);
        }

        // Print riddle answer
        public void printAnswer()
        {
            // print out the riddle answer with System.out.println
            System.out.println(ans);
        }

        // main method for testing
        public static void main(String[] args)
        {
            // call the constructor to create 3 new Riddle objects

            // call their printQuestion() and printAnswer methods

        }
    }
    ====
    //import codetesthelper.*;

    // Test Code for Lesson 5.1.5 - Riddle
    import static org.junit.Assert.*;
    import org.junit.After;
    import org.junit.Before;
    import org.junit.Test;

    import java.io.*;

    public class RunestoneTests extends CodeTestHelper
    {
        public RunestoneTests()
        {
            super("Riddle"); // class name / location of main

            Object[] values = new Object[]{"Question", "Answer"};
            setDefaultValues(values);
        }

        @Test
        public void testPrintQuestion()
        {
            String output = getMethodOutput("printQuestion");
            String expect = "Question";

            boolean passed = getResults(expect, output, "Checking method printQuestion()");
            assertTrue(passed);
        }

        @Test
        public void testPrintAnswer()
        {
            String output = getMethodOutput("printAnswer");
            String expect = "Answer";

            boolean passed = getResults(expect, output, "Checking method printAnswer()");
            assertTrue(passed);
        }

        @Test
        public void testDefaultConstructor()
        {
            String[] args = {"Question 1", "Answer 1"};
            String output = checkDefaultConstructor();
            String expect = "fail";

            boolean passed = getResults(expect, output, "Checking default constructor");
            assertTrue(passed);
        }

        @Test
        public void testConstructor()
        {
            String[] args = {"Question 1", "Answer 1"};
            String output = checkConstructor(args);
            String expect = "pass";

            boolean passed = getResults(expect, output, "Checking constructor with parameters");
            assertTrue(passed);
        }

        @Test
        public void testVariableTypes()
        {
            String varTypes = "String String";
            String output = testInstanceVariableTypes(varTypes.split(" "));

            boolean passed = getResults(varTypes, output, "Checking Instance Variable Type(s)");
            assertTrue(passed);
        }

        @Test
        public void testPrivateVariables()
        {
            String expect = "2 Private";
            String output = testPrivateInstanceVariables();

            boolean passed = getResults(expect, output, "Checking Private Instance Variable(s)");
            assertTrue(passed);
        }


        @Test
        public void testMain()
        {
            String output = getMethodOutput("main");

            String expect = "6 line(s) of text";
            String actual = " line(s) of text";

            if (output.length() > 0) {
                actual = output.split("\n").length + actual;
            } else {
                actual = output.length() + actual;
            }
            boolean passed = getResults(expect, actual, "Checking main method");
            assertTrue(passed);
        }
    }

.. reveal:: jUnitTesting3_src
       :showtitle: Show Source
       :hidetitle: Hide Source
       :modaltitle: Source for the example above

       .. code-block::

          .. activecode:: jUnitTesting3
              :language: java
              :autograde: unittest

              In this project, you will create a class that can tell riddles like the following:

              Riddle Question: Why did the chicken cross the playground?
              Riddle Answer: To get to the other slide!
              ~~~~
              public class Riddle
              {
                  // 2 instance variables for Riddle's question and answer: private type variableName;
                  private String quest;
                  private String ans;

                  // constructor
                  public Riddle(String initQuestion, String initAnswer)
                  {
                      // set the instance variables to the init parameter variables
                      quest = initQuestion;
                      ans = initAnswer;
                  }

                  // Print riddle question
                  public void printQuestion()
                  {
                      // print out the riddle question with System.out.println
                      System.out.println(quest);
                  }

                  // Print riddle answer
                  public void printAnswer()
                  {
                      // print out the riddle answer with System.out.println
                      System.out.println(ans);
                  }

                  // main method for testing
                  public static void main(String[] args)
                  {
                      // call the constructor to create 3 new Riddle objects

                      // call their printQuestion() and printAnswer methods

                  }
              }
              ====
              //import codetesthelper.*;

              // Test Code for Lesson 5.1.5 - Riddle
              import static org.junit.Assert.*;
              import org.junit.After;
              import org.junit.Before;
              import org.junit.Test;

              import java.io.*;

              public class RunestoneTests extends CodeTestHelper
              {
                  public RunestoneTests()
                  {
                      super("Riddle"); // class name / location of main

                      Object[] values = new Object[]{"Question", "Answer"};
                      setDefaultValues(values);
                  }

                  @Test
                  public void testPrintQuestion()
                  {
                      String output = getMethodOutput("printQuestion");
                      String expect = "Question";

                      boolean passed = getResults(expect, output, "Checking method printQuestion()");
                      assertTrue(passed);
                  }

                  @Test
                  public void testPrintAnswer()
                  {
                      String output = getMethodOutput("printAnswer");
                      String expect = "Answer";

                      boolean passed = getResults(expect, output, "Checking method printAnswer()");
                      assertTrue(passed);
                  }

                  @Test
                  public void testDefaultConstructor()
                  {
                      String[] args = {"Question 1", "Answer 1"};
                      String output = checkDefaultConstructor();
                      String expect = "fail";

                      boolean passed = getResults(expect, output, "Checking default constructor");
                      assertTrue(passed);
                  }

                  @Test
                  public void testConstructor()
                  {
                      String[] args = {"Question 1", "Answer 1"};
                      String output = checkConstructor(args);
                      String expect = "pass";

                      boolean passed = getResults(expect, output, "Checking constructor with parameters");
                      assertTrue(passed);
                  }

                  @Test
                  public void testVariableTypes()
                  {
                      String varTypes = "String String";
                      String output = testInstanceVariableTypes(varTypes.split(" "));

                      boolean passed = getResults(varTypes, output, "Checking Instance Variable Type(s)");
                      assertTrue(passed);
                  }

                  @Test
                  public void testPrivateVariables()
                  {
                      String expect = "2 Private";
                      String output = testPrivateInstanceVariables();

                      boolean passed = getResults(expect, output, "Checking Private Instance Variable(s)");
                      assertTrue(passed);
                  }


                  @Test
                  public void testMain()
                  {
                      String output = getMethodOutput("main");

                      String expect = "6 line(s) of text";
                      String actual = " line(s) of text";

                      if (output.length() > 0) {
                          actual = output.split("\n").length + actual;
                      } else {
                          actual = output.length() + actual;
                      }
                      boolean passed = getResults(expect, actual, "Checking main method");
                      assertTrue(passed);
                  }
              }
