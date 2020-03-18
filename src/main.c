/* Data de submissao: 16/03/2020
 * Nome: Jose Lucas SantAnna Barretto
 * RA: 200059
 */

#include <stdio.h>
const int tam_buffer=100;

/* this function clears an entire string */
void clear_string(char* string){
	int i;

	i = 0;
	while(string[i]!='\0'){
		string[i] = '\0';
		i++;
	}
}

/* this function writes the next word in a text, starting from a defined point, to a separate string. Also returns the size of the word. */
int get_next_word(char string[tam_buffer], char* next_word, int start_index){
	int i,word_size;

	clear_string(next_word); // clear next_word string
	
	// copies the characters from the text to the new string until the string is empty or until it finds a space
	i=0;
	while(string[start_index+i]!=' ' && string[start_index+i]!='\0' && string[start_index+i]!='\n'){
		next_word[i] = string[start_index+i];
		i++;
	}

	word_size = i; // the size of the word is the number of characters copied
	return word_size; // returns the size of the word
}

/* this function reverses a single word of known size */
void get_reverse_word(char word[tam_buffer], char* reverse_word, int word_size){
	int i;

	clear_string(reverse_word); // clears reverse_word string

	for(i=0;i<word_size;i++){
		reverse_word[i] = word[word_size-i-1]; // uses reverse indexes for the regular and reverse words
	}
}

/* this function concatenates a word to an already existing string */
void cat_word2string(char* string, char word[tam_buffer], int string_size){
	int i;
	
	// concatenates the word to the end of the string
	i=0;
	while(word[i]!='\0'){
		string[string_size + i] = word[i];
		i++;
	}
}

/* main code function */
int main() {
	char buffer[tam_buffer]; // user input string
	char next_word[tam_buffer]; // next word from the text
	char reverse_word[tam_buffer]; // reversed word string
	char reverse_text[tam_buffer]; // reversed text string
	int word_size; // size of each word
	int index; // input string index
	int i;

	fgets(buffer, tam_buffer, stdin); // inputs the string

	// iterates over the input string until it reaches the end
	index = 0;
	while(buffer[index] != '\n'){

		// if there is a space in the text
		if(buffer[index] == ' '){
			cat_word2string(reverse_text, " ", index); // concatenates the space to the reverse text string
			index++; // continues to iterate forward in the text
		}

		// finds next word
		word_size = get_next_word(buffer, next_word, index);

		// reverses the next word
		get_reverse_word(next_word, reverse_word, word_size);


		// concatenates the word into the reversed string
		cat_word2string(reverse_text, reverse_word, index);

		// updates the index
		index = index + word_size;
	}

	// clears the unused part of the string to remove unwanted characters
	for(i=index;i<tam_buffer;i++){
		reverse_text[i] = '\0';
	}

	// prints the reverse text string
	printf("%s\n", reverse_text);
	return 0;
}
