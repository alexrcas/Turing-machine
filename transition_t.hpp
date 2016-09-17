#pragma once

#include "state.hpp"

class state;

using namespace std;

/**
@class transition_t
@brief Representa una transición de la máquina
*/
class transition_t {
	private:
		state* src_;	///<@brief Estado inicial
		state* dest_;	///<@brief Estado al que se transita
		char read_symbol_;	///<@brief Símbolo leído
		char write_symbol_;	///<@brief Símbolo a escribir
		char mv_;	///<@brief Movimiento a realizar
	public:
		transition_t(state& src, state& dest, char read, char write, char mv); ///<@brief Constructor
		~transition_t() {}; ///<@brief Destructor
		
		inline state* get_src() const { return src_; } ///<@brief Devuelve el estado inicial @returns Puntero al estado inicial
		inline state* get_dest() const { return dest_; }	///<@brief Devuelve el estado final @returns Puntero al estado final
		inline char get_read_symbol() const { return read_symbol_; }	///<@brief Devuelve el símbolo necesario para la transición @returns Símbolo para realizar la transición
		inline char get_write_symbol() const { return write_symbol_; }	///<@brief Devuelve el símbolo a escribir @returns Símbolo a escribir
		inline char get_movement() const { return mv_; }	///<@brief Devuelve el movimiento @returns Movimiento a realizar
		
		bool operator < (const transition_t&) const;
};