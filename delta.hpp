#pragma once

#include<set>
#include <algorithm>
#include "transition_t.hpp"
#include "state.hpp"

using namespace std;

/**
@class delta
@brief Representa la función de transición
*/
class delta {
	private:
		set<transition_t> E_; ///<@brief Conjunto de transiciones
	public:
		inline delta() {} ///<@brief Constructor
		inline ~delta() {}	///<@brief Destructor
		
		const transition_t* get_transition(const state&, char); ///<@brief Obtiene una transicion @param Q Estado actual @param s Símbolo de entrada @returns Estado siguiente
		void put_transition(transition_t trans) { E_.insert(trans); } ///<@brief Añade una transición @param trans transición
};

