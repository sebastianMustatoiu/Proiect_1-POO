#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include<map>
#include <iomanip>
#include <set>
#include <cmath>

class Student {
private:
	std::string nume; //nume
	std::string prenume; //prenume
	int varsta; //varsta
	int ID; //id
	std::vector<std::pair<std::string, int>> note; //vector de perechi, de materii si note
	std::vector<std::pair<std::string, double>> medieMaterii;
	double medieGenerala;

public:
	//constructori
	Student();
	Student(std::string nume, std::string prenume, int varsta, int ID);
	Student(const Student& other) ;

	//getteri
	std::string getNume() const;
	std::string getPrenume() const;
	int getVarsta() const;
	int getID() const;
	std::vector<std::pair<std::string, int>> getNote() const;
	double getMedieGenerala() const;
	std::vector<std::pair<std::string, double>> getMedieMaterii() const;

	//setteri
	void setNume(const std::string& nume);
	void setPrenume(const std::string& prenume);
	void setVarsta(const int varsta);
	void setID(const int ID);

	//functii
	void calculeazaMedieMaterii();
	void adaugaNota(const std::string& materie, int nota);
	void calculeazaMedieGenerala();
	void afisareMediiMaterii();
	void afisareMedieGenerala();

	//operatori
	friend std::istream& operator>>(std::istream& is, Student& student);
	friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif