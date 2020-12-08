
def terminates(lines):
    a = 0
    visited = []
    i=0

    while i not in visited and i != len(lines):
        visited.append(i)
        if lines[i][0:3] == "acc":
            a += int(lines[i][4::])
        elif lines[i][0:3] == "jmp":
            i += int(lines[i][4::]) - 1
        i += 1

    if i == len(lines):
        return a
    else:
        return -.5

def switch(lines, i):
    if lines[i][0:3] == "nop":
        lines[i] = "jmp" + lines[i][3::]
    elif lines[i][0:3] == "jmp":
        lines[i] = "nop" + lines[i][3::]

def main():
    lines = []
    f = open("input.txt", "r")
    for line in f:
        lines.append(line.strip())

    for i in range(len(lines)-1, -1, -1):
        switch(lines, i)
        if terminates(lines) != -.5:
            break
        else:
            switch(lines, i) # switch back


    print(terminates(lines))

main()