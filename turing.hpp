#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include "infinite_tape.hpp"
#include "state.hpp"
#include "transition_t.hpp"
#include "delta.hpp"

using namespace std;

#define LOOP_TOLERANCE 100 ///<@brief Margen a partir del cual se sospecha la posibilidad de un bucle

/**
*@brief Representa una máquina de Turing
*/
class turing_machine {
	private:
		ifstream* file_;	///<@brief Fichero de entrada
		
		int S_;	///<@brief Estado de arranque
		int n_states_;	///<@brief Número de estados
		int accept_;	///<@brief Límite de estado de aceptación
		int n_t_;	///<@brief Número de transiciones
		int loop_counter_;	///<@brief Contador para controlar bucles
		
		infinite_tape* T_;	///<@brief Cinta
		delta D_;	///<@brief Función de transición
		set<state> Q_;	///<@brief Conjunto de estados
	
	public:
		turing_machine(ifstream*);
		~turing_machine();	///<@brief Destructor
		
		void put_string();	///<@brief Escribe en la cinta
		void put_string(char*);
		bool run();	///<@brief Inicia la simulación
		void show_tape();	///<@brief Muestra la cinta
		void clear_tape();	///<@brief Limpia la cinta
		void print_file();	///<@brief Muestra el fichero
		void print();	///<@brief Muestra la máquina de forma legible
};