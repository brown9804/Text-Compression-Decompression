# Text Compression and Decompression Algorithm in C++ and Python 

Costa Rica 

[![GitHub](https://img.shields.io/badge/--181717?logo=github&logoColor=ffffff)](https://github.com/)
[brown9804](https://github.com/brown9804)

Last updated: 2020-04-14

------------------------------------------

<div align="center">
  <h3 style="color: #4CAF50;">Total Visitors</h3>
  <img src="https://profile-counter.glitch.me/brown9804/count.svg" alt="Visitor Count" style="border: 2px solid #4CAF50; border-radius: 5px; padding: 5px;"/>
</div>

> This repository contains a text compression and decompression algorithm based on replacements. The algorithm works as follows:

1. It takes a text file as input and sets a replacement threshold.
2. For each word whose frequency is equal to or greater than the replacement threshold, it changes its string of characters to another.
3. It adds a table with each of the replacements in a separate file, indicating the original word and its new string.

The algorithm does not modify the input file. Instead, it creates a new file with the same name as the original but with a `.rep` extension for the compressed text and a `.tab` extension for the table of replacements.


