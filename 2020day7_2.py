colors = {}
number = 0

def counter(color):
    count = 0
    for c in colors[color]:
        if c!= "no other":
            count += counter(c)
    return count + 1

def main():
    f = open("input.txt")

    for line in f:
        line = line.strip("\n. ")
        separate = line.split("contain")


        # isolate
        for i in range(0, len(separate)):
            remove_characters = " "
            separate[i] = separate[i].replace("bags", "").lstrip()
            separate[i] = separate[i].replace("bag", "").lstrip()

        color = separate[0].split("bags")[0].strip()

        contains = separate[1].split(", ")
        length = len(contains)
        for i in range(0, length):
            contains[i] = contains[i].strip()
            if contains[i] != "no other":
                for j in range(0, int(contains[i][0])-1):
                    contains.append(contains[i][2::])
                contains[i]= contains[i][2::]

        colors[color] = contains

    print(counter("shiny gold") -1)



main()
