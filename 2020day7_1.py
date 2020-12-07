colors = {}
counted = []


def check_gold(color):
    for c in colors[color]:
        if c == "shiny gold":
            return True
        elif c in counted:
            return True
        elif c!= "no other":
            if check_gold(c):
                return True
    return False

def main():
    f = open("input.txt")

    for line in f:
        line = line.strip("\n. ")
        separate = line.split("contain")

        # isolate
        for i in range(0, len(separate)):
            remove_characters = "1234567890";
            for c in remove_characters:
                separate[i] = separate[i].replace(c, "").strip()
            separate[i] = separate[i].replace("bags", "").lstrip()
            separate[i] = separate[i].replace("bag", "").lstrip()

        color = separate[0].split("bags")[0].strip()
        contains = separate[1].split(", ")
        for i in range(0, len(contains)):
            contains[i] = contains[i].strip()

        colors[color] = contains
    for c in colors:
        if (check_gold(c)):
            counted.append(c)


main()
print(len(counted))
