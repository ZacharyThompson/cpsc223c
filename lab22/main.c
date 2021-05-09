#include <stdio.h>

typedef struct student {
	char name[50];
	int CWID;
	float gpa;
	int age;

	char* (*getName)(struct student *);
	int (*getCWID)(struct student *);
	float (*getGpa)(struct student *);
	int (*getAge)(struct student *);
	void (*print)(struct student *);
} student;

// Getters
char* get_name(student *s) {
	return s->name;
}

int get_CWID(student *s) {
	return s->CWID;
}

float get_gpa(student *s) {
	return s->gpa;
}

int get_age(student *s) {
	return s->age;
}


// Print
void print_student(student *s) {
	printf("Name: %s\n", s->name);
	printf("CWID: %d\n", s->CWID);
	printf("GPA: %f\n", s->gpa);
	printf("Age: %d\n", s->age);
}

int main() {
	student stdnt_1 = { 
		"John", 
		1234, 
		3.2, 
		18 , 
		get_name, 
		get_CWID,
		get_gpa,
		get_age,
		print_student
	};

	stdnt_1.print(&stdnt_1);
	putchar('\n');

	printf("enter a name: ");
	scanf("%s", stdnt_1.name);
	while((getchar())!='\n'); // clear any newlines

	printf("enter a CWID: ");
	scanf("%d", &stdnt_1.CWID);

	printf("enter the gpa: ");
	scanf("%f", &stdnt_1.gpa);

	printf("enter a Age: ");
	scanf("%d", &stdnt_1.age);

	putchar('\n');
	stdnt_1.print(&stdnt_1);
}
