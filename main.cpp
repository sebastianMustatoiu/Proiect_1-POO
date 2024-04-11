#include <iostream>
#include "Student.h"
#include "Profesor.h"
#include "Clasa.h"

int main()
{
	Student student("Mustatoiu", "Sebastian", 22, 10000);

	// Adăugarea unor note pentru diverse materii

	student.adaugaNota("Matematica", 8);
	student.adaugaNota("Informatica", 9);
	student.adaugaNota("Fizica", 7);
	student.adaugaNota("Chimie", 10); // Adăugare notă nouă
	student.adaugaNota("Chimie", 8);
	student.adaugaNota("Matematica", 5);

	//student.afisareMediiMaterii();
	//student.afisareMedieGenerala();

	student.adaugaNota("Romana", 10);
	student.adaugaNota("Romana", 6);

	//student.afisareMediiMaterii();
	//student.afisareMedieGenerala();

	//std::cout << student;

	/*Student student1;
	std::cin >> student1;
	std::cout << student1 << std::endl;*/

	//creez Studentul 2

	Student student1("Prioteasa", "Rares", 21, 10001);

	// Adăugarea unor note pentru diverse materii

	student1.adaugaNota("Matematica", 5);
	student1.adaugaNota("Informatica", 5);
	student1.adaugaNota("Fizica", 5);
	student1.adaugaNota("Chimie", 6); // Adăugare notă nouă
	student1.adaugaNota("Chimie", 4);
	student1.adaugaNota("Matematica", 7);
	student1.adaugaNota("Romana", 10);
	student1.adaugaNota("Romana", 8);

	Clasa clasa;
	clasa.adaugaStudent(student);
	clasa.adaugaStudent(student1);

	//clasa.afiseazaStudenti();

	student.calculeazaMedieMaterii();
	student.afisareMedieGenerala();
	student1.calculeazaMedieMaterii();
	student1.afisareMedieGenerala();

	clasa.afiseazaMedieGenerala();

	//clasa.stergeStudent(10001);
	//clasa.afiseazaStudenti();

	std::cout << student;
	Profesor profesor = Profesor("Dumitran", "Adrian", "Romana");
	profesor.noteazaStudent(student, 9);
	//std::cout << student;

	clasa.afiseazaStudenti();
	clasa.stergeStudent(10001);
	clasa.afiseazaStudenti();

	return 0;
}