# J-Lang
A esolang made for Japanese speakers.
*Note*: This is a personal work in progress project made in free time. Progress will not be very fast.
In addition this project is in its very early stages of development.

J-Lang will be an esolang fully using Japanese keywords and srcipts. This is an effort to provide tools Japanese learners can use to code that don't require them to learn another language.

## Compiling the Project

I am new to C/++, so to focus on getting a better understanding of the language and compiler I will not be using CMake or Ninja for a while.
So, when there is something that is stable and can be compiled, you will want use the commands below to compile the project.

Windows (CL)
```
cl /EHsc /utf-8 lexer.cpp coreFunctions.cpp runner.cpp -o jlang.exe
```

Linux/Mac (g++)
```
g++ main.cpp lexer.cpp coreFunctions.cpp runner.cpp -o jlang
```

If you change any files make sure to save them using UTF-8 with BOM to ensure Japanese characters are properly rendered.
Windows users may need to run `chcp 65001` before using this program, though.

## Roadmap

1. Simple print statements *done*
2. Variables
3. Math/Numbers
4. If/Else operations

*This roadmap is subject to change.*

## Languge

JLang is an interperated programming language designed for programming soley in Japanese with a typicall Japanese input keyboard.

### Functions

- **示す**
示す is the esolang's "print" function. It displays whatever is intered into it in the terminal.

*Example*:
```jlang
「世界よ、こんにちは！」！示す
```
The Japanese quotes act like any regular quote; they contain strings. The full width exclamation mark is the "function call operator", it is not the same as a regular exclamation mark, which will not be recognized by the interperator. The function call operator is used when calling functions, and marks when to pass arguments into a function.
The ！ tells the interperator "push the value(s) you just saw into the next function."

## Contributions

Any contributions are welcome, but large feature changes need to be discussed in an issue and be approved.

Contribution ideas:
- Bug fixes
- Simplifications
- Cross-platform support
- Suggested improvments
- Documentation support
- Translation help

## License

This project is licensed using Apache 2.0.