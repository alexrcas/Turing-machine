#include "transition_t.hpp"

transition_t::transition_t(state& src, state& dest, char read, char write, char mv) :
read_symbol_(read), write_symbol_(write), mv_(mv)
{
	try {
		src_ = new state(src);
		dest_ = new state(dest);
	}
	catch(bad_alloc) {
		cerr<<"Error reservando memoria"<<endl;
		exit(-1);
	}
}

bool transition_t::operator < (const transition_t& trans) const
{
	return ((src_->get_id() < trans.src_->get_id()) || (get_read_symbol() < trans.get_read_symbol()));
}