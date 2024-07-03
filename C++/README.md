# Text File Management

To initialize the program, you should have `makefile` installed. If you don't have it, you should run the following commands from your terminal:

```bash
sudo apt-get update
sudo apt-get install make
```

If you already have make installed, to run the program first type the following command in the terminal:

```bash
make build
```

Then you should type:

```
./a.exe num_threshold input_file.txt
```

where:

- `num_threshold`: is equal to the minimum number of occurrences that a word must have to be replaced.
- `input_file.txt`: name of the file to compress.

## Context

This is a text compression and decompression algorithm based on replacements. The algorithm works as follows:

1. Taking a text file as input, a replacement threshold is established.
2. For each word whose frequency is equal to or greater than the replacement threshold, change its string of characters for another. Add in a separate file a table with each of the replacements, indicating the original word and its new string. Do not modify the input file, create a new one with the same name as the original but with the extension .rep and the table file, in the same way but with the extension .tab.
