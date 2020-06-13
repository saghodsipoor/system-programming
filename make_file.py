#!/usr/bin/python3

x_text = "x" * 100 + "\n"

with open("file.in", "w") as f:
    for i in range(10000):
        f.write(x_text)