#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include "transition_t.hpp"

using namespace std;

/**
@class state
@brief Representa un estado de la máquina
*/

class transition_t;

class state {
	private:
		int id_; ///<@brief ID del estado
		bool accept_;	///<@brief Indica si el estado es de aceptación
	public:
		inline state(int id, bool accept): id_(id), accept_(accept) {} ///<@brief Constructor @param id ID del estado @param accept Indica si el estado es de aceptación
		inline state(const state& Q): id_(Q.id_), accept_(Q.accept_) {}///<@brief Constructor de copia
		inline ~state() {} ///<@brief Destructor
		
		inline bool is_accept() const { return accept_; }	///<@brief Obtiene si el estado es de aceptación @returns TRUE si el estado es de aceptación
		inline int get_id() const { return id_; }	///<@brief Devuelve la ID del estado @returns ID del estado
		
		inline bool operator==(const state& Q) const { return id_ == Q.id_; }	///<@brief Sobrecarga del operador de comparación @returns Devuelve si los estados son iguales
		inline bool operator < (const state& Q) const { return id_ < Q.id_; }	///<@brief Sobrecarga del operador de comparación @returns Devuelve si el estado es menor
		
		void print();	///@brief Muestra por pantalla la información del estado
};