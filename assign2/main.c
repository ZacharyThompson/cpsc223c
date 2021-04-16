#include <stdio.h>
#include <string.h>

#define FILENAME "sample2.txt"

// Checks if the line matches the category the user selected
int check_cat(char category[], char line[]) {
	int i;

	// Check if the category string matches the beginning of the line
	// Return false if it isn't
	for(i = 0; line[i] != ':' && i < strlen(category); i++)
		if (category[i] != line[i])
			return 0;

	// If we got here it means the category matched and we should return true
	return 1;
}

// Display all the items associated with the selected category
void show_items(char category[]) {
	FILE *fpointer = fopen(FILENAME, "r"); // open file
	char line[255]; // line to be read from file
	int i;

	// Get a new line until end of file
	while(fgets(line, 255, fpointer) != NULL) {
		// If current line matches the selected category
		if(check_cat(category, line)) {
			// Start at appropriate position (length of category + ':' + ' ')
			// and display each item neatly
			for(i = strlen(category)+2; line[i] != '\0'; i++) {
				if(line[i] == ' ') // replace space with newline character
					putchar('\n');
				else
					putchar(line[i]);
			}
		}
	}

	fclose(fpointer); // close file
}

int main() {
	puts("Which Token would you like to search the file for?");
	puts("  1. Food");
	puts("  2. Colors");
	puts("  3. People");

	// Based on the number the user inputs, display the associated category.
	switch (getchar()) {
		case '1':
			puts("\nDisplaying Food");
			show_items("Food");
			break;
		case '2':
			puts("\nDisplaying Colors");
			show_items("Colors");
			break;
		case '3':
			puts("\nDisplaying People");
			show_items("People");
			break;
	}

	return 0;
}
