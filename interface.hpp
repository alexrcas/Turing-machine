#pragma once

#include <iostream>
#include <cstdlib>
#include "turing.hpp"

using namespace std;

/**
@class Interface
@brief Ofrece una interfaz para aligerar el código en el programa principal
*/

class Interface {
	public:
		inline Interface() {}	///<@brief Constructor
		inline ~Interface() {}	///<@brief Destructor
		
		void display_menu();	///<@brief Muestra el menú
		void select_option(char, turing_machine&, ifstream*);	///<@brief Ofrece la interacción al usuario @param op Opción elegida @parm turing_machine Referencia a una máquina @param file Puntero al fichero de entrada
};