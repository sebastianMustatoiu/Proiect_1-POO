#include "Student.h"


//constructor implicit
Student::Student() : nume(""), prenume(""), varsta(0), ID(0) {}
	
//constructor cu parametri
Student::Student(std::string nume, std::string prenume, int varsta, int ID) {
	this->nume = nume;
	this->prenume = prenume;
	this->varsta = varsta;
	this->ID = ID;
}
	
//constructor de copiere
Student:: Student(const Student& other) {
	this->nume = other.nume;
	this->prenume = other.prenume;
	this->varsta = other.varsta;
	this->ID = other.ID;
	this->note = other.note;
	this->medieMaterii = other.medieMaterii;
	this->medieGenerala = other.medieGenerala;
}

//getteri

std::string Student::getNume() const {
	return this->nume;
}

std::string Student::getPrenume() const {
	return this->prenume;
}

int Student::getVarsta() const {
	return this->varsta;
}

int Student::getID() const {
	return this->ID;
}

std::map<std::string, std::vector<int>> Student::getNote() const {
	return this->note;
}

double Student::getMedieGenerala() const {
	std::cout << std::fixed << std::setprecision(2);
	return this->medieGenerala;
}

std::vector<std::pair<std::string, double>> Student::getMedieMaterii() const {
	return this->medieMaterii;
}

//setteri

void Student::setNume(const std::string& nume) {
	for (char c : nume) {
		if (!std::isalpha(c)) {
			std::cout << "Numele nu este valid\n";
			return;
		}
	}
	this->nume = nume;
}

void Student::setPrenume(const std::string& prenume) {
	for (char c : prenume) {
		if (!std::isalpha(c)) {
			std::cout << "Prenumele nu este valid\n";
			return;
		}
	}
	this->prenume = prenume;
}

void Student::setVarsta(const int varsta) {
	if (varsta < 0) {
		std::cout << "Varsta introdusa nu este valida\n";
		return;
	}
	this->varsta = varsta;
}

void Student::setID(const int ID) {
	this->ID = ID;
}	


//functii

void Student::calculeazaMedieMaterii() {
	if (note.empty()) {
		std::cout << "Nu exista note disponibile pentru acest student\n";
		return;
	}

	std::map<std::string, double>sumaNoteMaterii;
	std::map<std::string, int>numarNoteMaterii;

	for (const auto& pair : note) {
		const std::string& materie = pair.first;
		const std::vector<int>& noteMaterie = pair.second;
		double sumaNote = 0;

		for (int nota : noteMaterie) {
			sumaNote += nota;
		}

		sumaNoteMaterii[materie] = sumaNote;
		numarNoteMaterii[materie] = noteMaterie.size();

	}

	medieMaterii.clear();

	for (const auto& materie : sumaNoteMaterii) {
		double media = materie.second / numarNoteMaterii[materie.first];
		media = std::round(media);
		medieMaterii.push_back(std::make_pair(materie.first, media));
	}
}

void Student::adaugaNota(const std::string& materie, int nota) {
	note[materie].push_back(nota);
}

void Student::calculeazaMedieGenerala() {
	Student::calculeazaMedieMaterii();
	if (medieMaterii.empty()) {
		std::cout << "Nu exista medii disponibile pentru a calcula media generala";
		return;
	}

	double sumaMedii = 0;
	int numarMaterii = 0;

	for (const auto& medie : medieMaterii) {
		sumaMedii += medie.second;
		numarMaterii++;
	}

	medieGenerala = sumaMedii / numarMaterii;

}

void Student::afisareMediiMaterii() {
	Student::calculeazaMedieMaterii();
	std::cout << "Mediile pe materii pentru studentul " << nume << " " << prenume << " sunt:\n";
	for (const auto& materie : medieMaterii) {
		int mediaRotunjita = std::round(materie.second);
		std::cout << materie.first << ": " << mediaRotunjita << std::endl;
	}
	std::cout << std::endl;
}


void Student::afisareMedieGenerala() {
	Student::calculeazaMedieMaterii();
	Student::calculeazaMedieGenerala();
	std::cout << "Media generala a studentului: " << nume << " " << prenume << " este: ";
	std::cout << std::fixed << std::setprecision(2) << medieGenerala << std::endl << std::endl;
}

//operatori
std::istream& operator>>(std::istream& is, Student& student) {
	std::cout << "Introduceti numele: ";
	is >> student.nume;
	std::cout << "Introduceti prenumele: ";
	is >> student.prenume;
	std::cout << "Introduceti varsta: ";
	is >> student.varsta;
	std::cout << "Introduceti ID-ul: ";
	is >> student.ID;
	std::cout << "Introduceti numarul de note: ";
	int numarNote;
	is >> numarNote;
	std::cout << "Introduceti notele: ";
	for (int i = 0; i < numarNote; i++) {
		std::string materie;
		int nota;
		is >> materie >> nota;
		student.adaugaNota(materie, nota);
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
	os << "Nume: " << student.nume << ", Prenume: " << student.prenume
	   << ", Varsta: " << student.varsta << ", ID: " << student.ID << "\n";

	os << "Notele studentului: \n";
	for (const auto& materie : student.note) {
		os << materie.first << ": ";
		for (const auto& nota : materie.second) {
			os << nota << "; ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	return os;
}

