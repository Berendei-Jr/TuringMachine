# Turing machine

## Usage:
1) First, you need to create a program structure, using simple template:
```
turing::program Program = {
            "q0 a - q1 b R"
    };
```
This means the following: if machine reads symbol 'a' and it is currently in state 'q0', it should change its state to 'q1', write symbol 'b' and move to rhe right.
'R' - right, 'L' - left, 'ST' - stay

2) Then you need to create the Machine itself:
```
turing::machine Machine("abcdef");
```
Argument "abcdef" is an initial string, that should be writen on the Machine's tape.

3) Attach your Program to the Machine:
```
 Machine.Attach(Program);
```

4) Run your program! Function Run() will return a continuous result string.
```
 std::cout << Machine.Run();
```
