#include "delta.hpp"

const transition_t* delta::get_transition(const state& Q, char read)
{
	const transition_t* aux;
	for(set<transition_t>::iterator i = E_.begin(); i!= E_.end(); i++)
	{
		aux = &(*i);
		if((*aux->get_src() == Q) && (aux->get_read_symbol() == read))
			return  aux;
	}
	return NULL;
}
