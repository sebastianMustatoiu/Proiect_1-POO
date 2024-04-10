#include "Clasa.h"

Clasa::Clasa() {};

void Clasa::adaugaStudent(const Student& student) {
	studenti.push_back(student);
}

void Clasa::stergeStudent(int ID) {
	bool gasit = false;
	for (auto i = studenti.begin(); i != studenti.end(); i++) {
		if (i->getID() == ID) {
			i = studenti.erase(i);
			std::cout << "Studentul cu ID-ul " << ID << " a fost sters din clasa. \n";
			gasit = true;
			break;
		}
	}

	if (!gasit) {
		std::cout << "Nu exista student cu ID-ul " << ID << " in clasa.\n";
	}
}

void Clasa::afiseazaStudenti() const {
	if (studenti.empty()) {
		std::cout << "Clasa nu are studenti.\n";
		return;
	}

	std::cout << "Studentii clasei sunt: \n";
	for (const auto& student : studenti) {
		std::cout << student << "\n";
	}
}

const std::vector<Student>& Clasa::getStudenti() const {
	return studenti;
}

void Clasa::afiseazaMedieGenerala(){
	double sumaMedii = 0;
	int numarStudenti = 0;
	for (auto& student : studenti) {
		student.calculeazaMedieMaterii();
		student.calculeazaMedieGenerala();
	}

	for (const auto& student : studenti) {
		sumaMedii += student.getMedieGenerala();
		numarStudenti++;
	}

	if (numarStudenti > 0) {
		double mediaGeneralaClasa = sumaMedii / numarStudenti;
		std::cout << "Media generala a clasei: " << std::fixed << std::setprecision(2) << mediaGeneralaClasa << std::endl;
	}
	else {
		std::cout << "Nu exista studenti in clasa pentru a calcula media generala.\n";
	}
}
