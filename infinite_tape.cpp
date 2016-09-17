#include "infinite_tape.hpp"

/**
*@brief Constructor de la clase
*/
infinite_tape::infinite_tape()
{
	for (int i=0;i<DEFAULT_TAPE_SIZE;i++)
		track_.push_back('$');
	head_=DEFAULT_TAPE_SIZE / 2;
}

/**
*@brief Mueve la cabeza de E/S a la izquierda
*/
void infinite_tape::move_left()
{
	head_--;
	if (head_ == 0)	//Si tras realizar movimiento la cabeza lectora queda en la primera celda de la cinta. Ya se inserta un nuevo
	{				//símbolo blanco al comienzo. En realidad, el usuario jamás estará en la primera celda de la cinta.
		track_.insert(track_.begin(),'$');
		head_ = 1;	//Al haber insertado al comienzo, la cabeza no está en la posición 0 sino en la 1.
	}
}

/**
*@brief Mueve la cabeza de E/S a la derecha
*/
void infinite_tape::move_right()
{
	head_++;	//Ídem que el método mover a la izquierda pero insertando al final.
	if (head_ == track_.size()-1)
	{
		track_.push_back('$');
	}
}

/**
*@brief Vuelca una cadena en la cinta
*/
void infinite_tape::put_string(char* string)
{
	int aux = head_;	//Se guarda la posición de la cabeza para luego ponerla donde estaba, de forma que apunte al comienzo de la cadena.
	for (int i=0;i<strlen(string);i++)
	{
		track_.at(head_)=string[i];
		move_right();
	}
	head_=aux;
}

/**
*@brief Imprime la cinta por pantalla
*/
void infinite_tape::show_tape()
{
	for (int i=0;i<track_.size();i++)
	{
		if (i==head_)
			cout<<"|"<<track_.at(i)<<"|";
		else
			cout<<track_.at(i);
	}
	cout<<endl;
}