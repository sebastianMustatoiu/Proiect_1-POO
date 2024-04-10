#include "Profesor.h"

Profesor::Profesor() : nume(""), prenume(""), disciplina("") {}
Profesor::Profesor(const std::string& nume, const std::string& prenume, const std::string& discicplina) : nume(nume), prenume(prenume), disciplina(disciplina) {}

std::string Profesor::getNume() {
	return nume;
}

std::string Profesor::getPrenume() {
	return prenume;
}

std::string Profesor::getDisciplina() {
	return disciplina;
}

void Profesor::setNume(const std::string& nume) {
	for (char c : nume) {
		if (!std::isalpha(c)) {
			std::cout << "Numele nu este valid\n";
			return;
		}
	}
	this->nume = nume;
}

void Profesor::setPrenume(const std::string& prenume) {
	for (char c : prenume) {
		if (!std::isalpha(c)) {
			std::cout << "Prenumele nu este valid\n";
			return;
		}
	}
	this->prenume = prenume;
}

void Profesor::setDisciplina(const std::string& disciplina) {
	for (char c : disciplina) {
		if (!std::isalpha(c)) {
			std::cout << "Numele disciplinei nu este valid\n";
			return;
		}
	}
	this->disciplina = disciplina;
}

void Profesor::noteazaStudent(Student& student, int nota) {
	student.adaugaNota(disciplina, nota);
}

std::ostream& operator<<(std::ostream& os, const Profesor& profesor) {
	os << "Profesor: " << profesor.nume << " " << profesor.prenume << ", Disciplina: " << profesor.disciplina;
	return os;
}
