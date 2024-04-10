#ifndef CLASA_H
#define CLASA_H

#include <iostream>
#include <vector>
#include "Student.h"
#include <iomanip>

class Clasa {
private:
	std::vector<Student> studenti;
public:
	Clasa();

	void adaugaStudent(const Student& student);
	void stergeStudent(int ID);
	void afiseazaStudenti() const;
	const std::vector<Student>& getStudenti() const;
	void afiseazaMedieGenerala();

	friend std::ostream& operator<<(std::ostream& os, const Clasa& clasa);
};




#endif
