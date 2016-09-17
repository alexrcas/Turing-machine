/*Clase que representa una cinta usada por la máquina.
Este diseño utiliza una lista enlazada para ir insertando símbolos en blanco en los extremos de la cinta según la cabeza de lectura
vaya llegando a los mismos, de forma que nunca es relativamente posible alcanzar el final. */
#pragma once

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define DEFAULT_TAPE_SIZE 10


/**
*@class infinite_tape
*@brief Cinta infinita sobre la que escribe la máquina
*/
class infinite_tape
{
	private:
		vector<char> track_;	///<@brief Cinta de caracteres
		int head_;				///<@brief Posicion de la cabeza de E/S
		
	public:
		infinite_tape();
		inline ~infinite_tape() {};	///<@brief Destructor de la clase

		inline char read() { return track_.at(head_); }	
		void write(char symbol) { track_.at(head_)=symbol; }	

		void move_left();	
		void move_right();	

		void put_string(char*);	

		void show_tape();
};

	
	
	