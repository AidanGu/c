#!/usr/bin/env python3

import sys
import re
from collections import namedtuple

Instruction = namedtuple("Instruction", ["code", "args", "output"])

EPSILON = 1e-5

variable_pat = re.compile(r"^[A-Za-z_][A-Za-z_0-9]*$")
def valid_variable(s):
    return (re.match(variable_pat, s) is not None)

class Function:
    def __init__(self, name, instructions):
        self.name = name
        self.instructions = instructions

def load_functions(filename):
    functions = {}
    with open(filename, "r") as infile:
        cur_function = None
        instructions = []

        for line in infile:
            line = line.strip().upper()
            if not line: continue

            if line.startswith("#"):
                continue

            tokens = line.split()

            if tokens[0] == "FUNCTION":
                assert len(tokens) == 2, "syntax error: FUNCTION funcname"

                ## might be in a new function
                if instructions and cur_function:
                    func = Function(cur_function, instructions)
                    functions[cur_function] = func

                cur_function = tokens[1]
                instructions = []
                continue
            else:
                assert cur_function, "need to be inside a function"

            if tokens[0] == "SET":
                assert len(tokens) == 3, "SET takes 2 arguments"
                args = [tokens[1]]
                assert valid_variable(tokens[2])
                output = tokens[2]
                instruction = Instruction(code="SET", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "LABEL":
                assert len(tokens) == 2, "LABEL takes 1 argument"
                args = []
                assert valid_variable(tokens[1])
                output = tokens[1]
                instruction = Instruction(code="LABEL", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "ADD":
                assert len(tokens) == 4, "ADD takes 3 arguments"
                args = tokens[1:3]
                assert valid_variable(tokens[3])
                output = tokens[3]
                instruction = Instruction(code="ADD", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "SUB":
                assert len(tokens) == 4, "SUB takes 3 arguments"
                args = tokens[1:3]
                assert valid_variable(tokens[3])
                output = tokens[3]
                instruction = Instruction(code="SUB", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "MUL":
                assert len(tokens) == 4, "MUL takes 3 arguments"
                args = tokens[1:3]
                assert valid_variable(tokens[3])
                output = tokens[3]
                instruction = Instruction(code="MUL", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "DIV":
                assert len(tokens) == 4, "DIV takes 3 arguments"
                args = tokens[1:3]
                assert valid_variable(tokens[3])
                output = tokens[3]
                instruction = Instruction(code="DIV", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "MOD":
                assert len(tokens) == 4, "MOD takes 3 arguments"
                args = tokens[1:3]
                assert valid_variable(tokens[3])
                output = tokens[3]
                instruction = Instruction(code="MOD", args=args, output=output)
                instructions.append(instruction)
            elif tokens[0] == "RETURN":
                assert(len(tokens) == 2)
                args = [tokens[1]]
                instruction = Instruction(code="RETURN", args=args, output=None)
                instructions.append(instruction)
            elif tokens[0] == "ALMOSTEQUAL":
                assert len(tokens) == 4, "ALMOSTEQUAL takes 3 arguments"
                args = tokens[1:3]
                assert valid_variable(tokens[3])
                output = tokens[3]
                instruction = Instruction(code="ALMOSTEQUAL", args=args,
                        output=output)
                instructions.append(instruction)
            elif tokens[0] == "IF":
                assert len(tokens) == 4, "IF takes 3 arguments"
                args = tokens[1:4]
                assert valid_variable(tokens[2])
                assert valid_variable(tokens[3])
                instruction = Instruction(code="IF", args=args,
                        output=None)
                instructions.append(instruction)
            elif tokens[0] == "CALL":
                assert len(tokens) >= 2, \
                        "CALL takes a function name and optional arguments"
                args = tokens[1:-1]
                output = tokens[-1]
                assert valid_variable(tokens[1])
                instruction = Instruction(code="CALL", args=args,
                        output=output)
                instructions.append(instruction)
            else:
                assert False, f"unknown command {tokens[0]}"

        if instructions and cur_function:
            func = Function(cur_function, instructions)
            functions[cur_function] = func
    return functions

def getvalue(text, environment):
    if valid_variable(text):
        if text in environment:
            return environment[text]
        else:
            assert False, (f"variable not found {text}")
    else:
        return float(text)

def interpret(function, environment, functions):
    ## this is going to need to have a call stack
    print("running function", function.name)

    program_counter = 0
    while (program_counter < len(function.instructions)):
        increment = True
        inst = function.instructions[program_counter]
        print(environment)
        code, args, output = inst
        if code == "SET":
            assert(len(args) == 1), "somehow set got the wrong number of args"
            environment[output] = getvalue(args[0], environment)
        elif code == "ADD":
            assert(len(args) == 2), "somehow set got the wrong number of args"
            left = getvalue(args[0], environment)
            right = getvalue(args[1], environment)
            environment[output] = left + right
        elif code == "SUB":
            assert(len(args) == 2), "somehow set got the wrong number of args"
            left = getvalue(args[0], environment)
            right = getvalue(args[1], environment)
            environment[output] = left - right
        elif code == "MUL":
            assert(len(args) == 2), "somehow set got the wrong number of args"
            left = getvalue(args[0], environment)
            right = getvalue(args[1], environment)
            environment[output] = left * right
        elif code == "DIV":
            assert(len(args) == 2), "somehow set got the wrong number of args"
            num = getvalue(args[0], environment)
            denom = getvalue(args[1], environment)
            environment[output] = num / denom
        elif code == "MOD":
            assert(len(args) == 2), "somehow set got the wrong number of args"
            num = getvalue(args[0], environment)
            denom = getvalue(args[1], environment)
            environment[output] = num % denom
        elif code == "RETURN":
            return getvalue(args[0], environment)
        elif code == "LABEL":
            pass
        elif code == "ALMOSTEQUAL":
            print("ALMOSTEQUAL")
            assert(len(args) == 2), "somehow set got the wrong number of args"
            left = getvalue(args[0], environment)
            right = getvalue(args[1], environment)
            if abs(left - right) < EPSILON:
                environment[output] = 1
            else:
                environment[output] = 0
        elif code == "IF":
            assert(len(args) == 3), "somehow set got the wrong number of args"
            test = environment[args[0]]
            increment = False
            if not test:
                target = args[2]
            else:
                target = args[1]
            found_label = False
            for newpc, inst in enumerate(function.instructions):
                if inst.code == "LABEL" and inst.output == target:
                    print("did a GOTO to", target)
                    program_counter = newpc
                    found_label = True
                    break
            assert found_label, "IF referenced a nonexistent label"
        elif code == "CALL":
            assert(len(args) >= 1), "somehow set got the wrong number of args"
            # evaluate the arguments...
            funcname = args[0]
            assert funcname in functions, f"unknown function {funcname}"
            values = [getvalue(arg, environment) for arg in args[1:]]
            subenvironment = {"ARG{}".format(i): values[i]
                              for i in range(len(values))}
            subanswer = interpret(functions[funcname], subenvironment,
                                  functions)
            environment[output] = subanswer
        else:
            print(inst)
            assert False, "unknown instruction"

        if increment:
            program_counter += 1
    assert False, "oh no, got to the end of the function without returning"

def main():
    if len(sys.argv) != 3:
        print("USAGE: python3 interpreter.py program.bad startfunc")
        return

    badfile = sys.argv[1]
    startfunc = sys.argv[2].upper()

    functions = load_functions(badfile)
    print(functions)

    if startfunc not in functions:
        print(f"function {startfunc} not in file {badfile}")
        return

    environment = {}
    answer = interpret(functions[startfunc], environment, functions)
    print("answer is", answer)


if __name__ == "__main__": main()
