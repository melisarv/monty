## Monty Bytecode Interpreter

----
Monty is a scripting language that is compiled into bytecodes and the purpose of this interpreter is to execute the files containing the bytecode.

----
### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

----
## Usage

All the files are compiled in the following form:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
Run the program:
```
 ./monty bytecode_file
```

----
## List of implemented opcodes:
Opcode |  Description
--------------------- | ------------------------------
push  | pushes an element to the stack
pall  | prints all the values on the stack
pint  | prints the value at the top of the stack
pop   | removes the top element of the stack
swap  | swaps the top 2 elements of the stack
add   |  adds the top 2 elements of the stack, stores it in the second element of the stack, and pops the stack
nop  |  doesn't do anything

----
## Author
* [Melisa Rojas](https://github.com/melisarv)
