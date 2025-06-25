# AutoComplete Trie in C++

This is a simple C++ project that implements an autocomplete feature using the Trie data structure. The program takes a list of words and provides suggestions based on a prefix entered by the user.

## Files

- `AutoCompleteTrie.cpp`: Main source code
- `input_sample.txt`: Sample input
- `output_sample.txt`: Sample output
- `README.md`: Project description

## How to Run

1. Compile the program:
g++ AutoCompleteTrie.cpp -o trie

markdown
Copy
Edit

2. Run the executable:
./trie

css
Copy
Edit

3. Follow the prompts to enter the number of words, the words themselves, and the prefix.

## Sample Input

5
hello
hell
heat
heal
help
he

shell
Copy
Edit

## Sample Output

Suggestions:
heal
heat
hell
hello
help

markdown
Copy
Edit

## Notes

- Input should be in lowercase.
- The program prints all words in the Trie that begin with the given prefix.

## Author

Sree Yagna Veena
