#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class Profesor {
private:
	std::string nume;
	std::string prenume;
	std::string disciplina;

public:
	Profesor();
	Profesor(const std::string& nume, const std::string& prenume, const std::string& disciplina);

	std::string getNume();
	std::string getPrenume();
	std::string getDisciplina();

	void setNume(const std::string& nume);
	void setPrenume(const std::string& nume);
	void setDisciplina(const std::string& disciplina);
	void noteazaStudent(Student& student, int nota);

	friend std::ostream& operator<<(std::ostream& os, const Profesor& profesor);
};


#endif