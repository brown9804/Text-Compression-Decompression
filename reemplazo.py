import re
import numpy
import os
import sys

replacements = {"mi":"~,~,^^-", "no":"-^^,~,~", "la":"~^^:~~"}

file_a_leer = raw_input("Digite nombre del archivo (sin el .txt): ")
file_a_leer+=".rep"

fname = raw_input("Digite nombre del archivo (con su .txt): ")

name = open(fname, 'r')

with name as infile, open(file_a_leer,"w") as outfile:
    for line in infile:
        for src, target in replacements.items():
            line = line.replace(src, target)
        outfile.write(line)
