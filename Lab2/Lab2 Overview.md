[C on Tutorialspoint](https://www.tutorialspoint.com/cprogramming/c_overview.htm) | [Document Source](./INDEX.md)

SOFE 3200 Tutorials: Part 3
===========================

## Shell Programming & Makefiles

&nbsp;

## Downloading This Tutorial

You may view this document in a browser at `ericdube.com/sofe3200/3`

You can use the following `wget` command to download INDEX.md to your working directory.

```sh
wget http://ericdube.com/sofe3200/3/INDEX.md
```

In Ubuntu, enter `Ctrl+Alt+T`, then enter the above command in the terminal
window that appears.

You will get a plaintext file that is used to generate this page. To see it as
formatted text, you may use any markdown renderer. (ex: http://stackedit.io)

## Download cproject.tar
In this tutorial you will use some C source files to learn about `make`.
To download these files to a subdirectory named `sofe_tut_3`, run the following
commands:
```
wget http://ericdube.com/sofe3200/files/cproject.tar
mkdir sofe_tut_3
tar -x -f cproject.tar ./sofe_tut_3
```

## Today's Plan
1. Any Questions?
2. [Makefiles](#section-makefiles)
3. [Shell Scripts](#section-shellscript)
4. [Perl](#perl)
5. [Bash Activities](#bash-activities)
6. Questions?
7. [Challenge](#section-challenge)

[next](#section-makefile)
# <a name="section-makefile"></a>Makefile Example
A makefile is a very simply way to define tasks for building source code.

Often, compilers will require you to specify each source file that needs to be
compiled. Sometimes you'll need to specify **linker flags** to use specific
libraries as well. A makefile lets you define how your source code is compiled.

The most basic makefile to compile a file called `main.c` would look like this:
```
build:
    gcc main.c
```

This make file contains a **rule** called `build`. When you run the `make`
command in the same directory as this Makefile with no arguments, the first
rule of the Makefile (in this case, the only rule) is executed. Indented after
the rule is a command to execute. For those curious, this uses the `/bin/sh`
shell by default, or the shell defined by the `SHELL` environment variable.

**Note:** The indentation in the Makefile **MUST** be a tab.

We can specify that the `build` rule only executes if `main.c` has changed
simply by appending `main.c` to the same line after `build: `.

```
build: main.c
    main.c
```

This can be useful if you have a large program, where re-compiling the entire
program every time would be unnecessary and require more time.

We can also define variables in Makefiles to make building easier to configure.

```
CC=gcc

build: main.c
    $(CC) main.c -o main
```

Notice we're still writing `main.c` twice, going against the DRY
(don't repeat yourself) principle. Fortunately make gives us two variables;
`$@` represents the left side of the `:` (in this example, `build`), and `$^`
represents the right side of the `:` (in this example, `main.c`).

We can replace the second instance of `main.c` with `$^`.

```
CC=gcc

build: main.c
    $(CC) $^ -o main
```

Now it's much easier to add new source files.

```
CC=cc

build: main.c utils.c
    $(CC) $^ -o main
```

This basic makefile is sufficient for small programs. GCC will find any `.h`
files in the same directory without needing to specify them in the Makefile.

Makefiles are very powerful, and there are many options not demonstrated here.
There are a wide variety fo examples and documentation for Makefiles online.

[next](#section-shellscript)
# <a name="section-shellscript"></a>Shell Scripts

Shell scripts are a powerful tool to automate interaction with the many utilities
available on UNIX-like systems.

The following activities will provide some practice in writing shell scripts.
Many of the features shown here are described in the Week 3 lecture notes, so
be sure to check those if anything is unclear.

## Part 1: Basic Bash script
A shell script typically begins with a declaration of which shell should be
used to interpret the script. This is often called a hashbang because it
begins with the characters `#!`. For example, if the first line is `#!/bin/bash`,
the script should be interpreted using the executable at `/bin/bash`.

Arguments passed when running the script can be accessed by numerated variables
`$1`, `$2`, etc.

For example, create the following file `hello.sh`
```
#!/bin/bash
echo Hello, $1
```

To test the script, first enable execution permissions for all users by
running `sudo chmod +x ./hello.sh`, then run `./hello.sh World`.

## Part 2: Loops in Bash

Create a shell script using one of the following loop structures to iterate
over the interval `[0,20)` (integers).

At the beginning of the file, add the line `#!/bin/bash`. This will ensure
your script runs in a `bash` shell.

### while loop
```
#!/bin/bash
x=0                    # Initialize x to zero
while [ $x -lt 20 ]; do # Keep looping while x < 5
    echo $x
    x=$(($x+1))
done
```

### until loop
```
#!/bin/bash
x=0                   # Initialize x to zero
until [ $x -ge 20]; do # Keep looping until x >= 5
    echo $x
    ((x=$x+1))
done
```

Once you have copied one of the above scripts, you can pipe the output to
`sofe32 send tut3.1` to verify that your solution works.

Don't forget to first run `export SOFEHOST=http://vps.ericdube.com:8080;`
before using the `sofe32` command. (or add this line to the `~/.bashrc` file)

## Functions
### Defining a function

Defining a function in bash is done with the following syntax.
```
function func
{
    echo "Hello, $1"
}
func World
```

This creates a function named `func` which sends hello to standard out.
The function may be passed arguments, which are accessed the same way
as arguments to the shell script. (i.e. the function will have its own
set of variables `$1`, `$2`, etc).

## Arrays
### Defining an array
Arrays are defined by specifying an index while setting a variable.
They can also be explicitly defined using `declare -a`, although
this is not required.

```
declare -a myarray
myarray[0]="First Item"
myarray[1]="Second Item"
```

### Looping over arrays
Arrays and loops are often used together. Specifying a variable as
an index allows iterating over arrays using while or until loops.

The following code, for example, sets five elements from the user's
input.
```
#!/bin/bash
x=0
while [ $x -lt 5 ]; do
    read userinput
    lines[$x]=$userinput
    (( x = $x + 1 ))
done
```

We can then read each element using a loop as well.
```
y=0
while [ $y -lt $x ]; do
    echo "You said ${lines[$y]}"
    (( y = $y + 1 ))
done
```

## Using `&&`, `||`, `;` and `{}`
Placing the `&&` syntax between commands causes the succeeding command
to be executed only of the preceding command succeeds (i.e. program
returns a value of 0).

Placing the `||` syntax between commands causes the succeeding command
to be executed only of the predecing command fails (i.e. program returns
a value other than 0).

Placing `;` in between commands runs them in sequence, as if they
were on separate lines.

```
#!/bin/bash
cat /etc/hosts > /dev/null && echo "It worked!"
cat /etc/fakefile || echo "It failed!"
echo "Part one" ; echo "Part two"
```

**Tip:** You can redirect to `/dev/null` if you don't want to see the
output of a command. `/dev/null` is the location of the void. Every
*nix computer has one. :)

You can use curly braces (`{` and `}`) to group commands together.
For instance, the following code will pipe the output of two commands
run in sequence to `sed`.

```
#/bin/bash
{ echo "Part 1"; echo "Part 2"; } | sed s/Part/Thing/g
```

## Important Notes
### Whitespace
Many features in bash are whitespace sensitive. For instance, writing
`x = 0` instead of `x=0` in the initialization above would result in
an error. Writing `[$y -lt $x]` instead of `[ $y -lt $x ]` would also
result in an error.

### Indexed variables in strings
If you would like to include the value of an array element in a string,
you will need to wrap the variable around the `${}` syntax, otherwise
it will be interpreted literally. For instance, writing `lines[$y]`
instead of `${lines[$y]}` in the above example would result in an
output of the following:
```
    You said lines[0]
    You said lines[1]
     ... etc
```

[next](#perl)
# <a name="perl"></a>Brief Intro to Perl
It's easy to run other programming languages from the shell as well.
For instance, Perl is a popular language for automatic tasks,
writing backend scripts for web services, and more.

A simple "Hello World" script in Perl looks like this:
```
#!/usr/bin/env perl
print "Hello, World\n";
```

Notice the **hashbang** at the top of the file reads `#!/usr/bin/env perl` -
this specifies that the script should be executed using the Perl interpreter.

You can find a good introduction to this language at `perldoc.perl.org/perlintro.html`.

[next](#bash-activities)
# <a name="bash-activities"></a>Activities

## Act I: Verify `cat` can concat file
Write a shell script that can receive a list filenames as separate lines
in standard in.
If `cat FILE` succeeds, the script should print "I can see FILE".
If it fails, the script should print "I can't see FILE".
Note that `FILE` should be replaced with the name of the file.

The output of the file itself should not be printed to standard out.

To test your solution, run your script as follows:
```
chmod +x act1.sh # remember, you only need to do this the first time
sofe32 get tut3.act1 | ./act1.sh | sofe32 send tut3.act1
```

[next](#section-challenge)
# <a name="section-challenge"></a>Challenge Problem
Create a shell script that mimics the functionality of uniq, by taking
lines of text from standard in and removing duplicate lines before
repeating them on standard out. You may discuss with your classmates
about solutions to this problem.

When solving this, pretend that the `uniq` command doesn't exist.
Otherwise, you wouldn't have any reason to write a shell script
that does this.

**Hint:** This can be done with a single array for input values
and nested looping.
