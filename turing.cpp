#include "turing.hpp"

using namespace std;

/**
*@brief Constructor
*@param file Fichero de entrada
*/
turing_machine::turing_machine(ifstream* file)
{	vector<int> acceptlist;
	vector<state> states;
	file_ = file;
	char read, write, movement;
	int next, id;
	bool accept;
	state* aux;
	char accept_states[256];
	int dmy;
	
	*file_ >> n_states_ >> S_;
	file_->seekg(6, ios::beg);
	file_->getline(accept_states, 256);
	char* pch = strtok(accept_states, " ");
	while(pch)
	{
		acceptlist.push_back(atoi(pch));
		pch = strtok(NULL, " ");
	}
	*file_ >> n_t_;
	
	for (int i=0;i<n_states_;i++)
	{
		accept = false;
		for(int j=0;j<acceptlist.size(); j++)
		{
			if (i == acceptlist[j])
				accept = true;
		}
		states.push_back(*new state(i, accept));
		Q_.insert(*new state(i, accept));
	}
	for(int i=0; i<n_t_; i++)
	{
		*file_>>id >> read >> write >> movement >> next;
		D_.put_transition(*new transition_t(*new state(states[id]), *new state(states[next]), read, write, movement));
	}
	
	try {
		T_ = new infinite_tape();
	}
	catch(bad_alloc) {
		cerr<<"ERROR RESERVANDO MEMORIA"<<endl;
		exit(-1);
	}
	
}

turing_machine::~turing_machine()
{
	if (T_ != NULL)
		delete T_;
}

/**
 * @brief Escribe en la cinta
 * @param str Cadena a escribir en la cinta
 * */
void turing_machine::put_string(char* str)
{
	T_->put_string(str);
}

bool turing_machine::run()
{
	state* dummy = new state(*Q_.begin());
	const transition_t* aux;
	bool first = true;
	int op;
	do
	{
		if (first)
		{
			T_->show_tape();
			cout<<"Estado: "<<dummy->get_id()<<endl;
			cout<<endl;
		}
		aux = D_.get_transition(*dummy, T_->read());
		if (aux!=NULL)
		{
			T_->write(aux->get_write_symbol());
			if (aux->get_movement()=='L')
				T_->move_left();
			else
			{
				if (aux->get_movement()=='R')
					T_->move_right();
			}
			dummy = aux->get_dest();
			T_->show_tape();
			cout<<"Estado: "<< dummy->get_id() <<endl;
			cout<<endl;
			loop_counter_++;
			first=false;
		}
		
		if (loop_counter_ % LOOP_TOLERANCE == 0)
		{
			cout<<"\nAVISO. Posible bucle infinito detectado."<<endl;
			cout<<"1.Realizar otras 100 iteraciones\t2.Parar y dar la cadena por rechazada: \n";
			cin>>op;
			if (op==2)
			{
				aux=NULL;
				return false;
			}
		}
		
	} while(aux!=NULL);
	return (dummy->is_accept());
}


void turing_machine::show_tape()
{
	T_->show_tape();
}

void turing_machine::clear_tape()
{
	delete T_;
	T_=new infinite_tape();
	cout<<"Cinta borrada!"<<endl;
}

void turing_machine::print_file()
{
	cout<<"\nFICHERO .TM:"<<endl;
	file_->seekg(0, ios::beg);
	char aux[256];
	while(!file_->eof())
	{
		file_->getline(aux, 256);
		cout<<aux<<endl;
	}
}

void turing_machine::print()
{
	const state* aux;
	for(set<state>::iterator i = Q_.begin(); i!= Q_.end(); i++)
	{
		aux = &(*i);
		cout<<"Estado: "<<"q"<<aux->get_id()<<endl;
		cout<<"Aceptacion: ";
		aux->is_accept() ? cout<<"SI"<<endl : cout<<"NO"<<endl;
		cout<<endl;
	}
}