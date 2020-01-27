#include <iostream>
#include <string>
#include <vector>

class Transition {
	private:
		std::string	input_state;
		char	alphabet;
		std::string	output_state;
	public:
		Transition () {
			input_state = std::string();
			alphabet = '0';
			output_state = std::string();
		}
		Transition (std::string input_state, char alphabet, std::string output_state) {
			this->input_state =std::string();	this->input_state = input_state;
			this->alphabet = alphabet;
			output_state = std::string();	this->output_state = output_state;
		}
		std::string getInState () { return input_state; }
		char getAlphabet () { return alphabet; }
		std::string getOutState () { return output_state; }
		void importTransition () {
			std::cout << "\t\t>>Import input_state: ";	std::cin >> input_state;
			std::cout << "\t\t>>Import alpabet go along with this state: ";	std::cin >> alphabet;
			std::cout << "\t\t>>Import output_state: ";	std::cin >> output_state;
		}
		void dispTransition(){
			std::cout << "St( " << input_state << ", '" 
								<< alphabet << "')= " << output_state << std::endl;
		}
};
class Automata {
	public:
		std::vector<std::string> states;
		std::vector<char>	alphabet;
		std::vector<Transition>	transition_function;
		std::string	start_state;
		std::vector<std::string>	accept_states;
		std::string	current_state;
	public:
		Automata () {
			states = std::vector<std::string>(0);
			alphabet = std::vector<char>(0);
			transition_function = std::vector<Transition>(0);
			start_state = std::string();
			accept_states = std::vector<std::string>(0);
			current_state = std::string();
		}
		virtual void import () {
			int stateamount, alphabetamount, transitionamount, accept_stateamount;
		    std::cout << "Begin to import Automatic: " << std::endl;
			std::cout << "* Import states: " << std::endl;
			std::cout << "How many states are there in your Automatic: "; std::cin >> stateamount;
			states = std::vector<std::string>(stateamount);
			for (int i = 0; i < stateamount; i++){
				std::cout << "\tImport states [" << i+1 << "]: ";
				std::cin >> this->states[i];
			}
			std::cout << "* Import alphabets: " << std::endl;
			std::cout << "How many alphabets are there in your Automatic: "; std::cin >> alphabetamount;
			alphabet = std::vector<char>(alphabetamount);
			for (int i = 0; i < alphabetamount; i++){
				std::cout << "\tImport alphabet [" << i+1 << "]: ";
				std::cin >> this->alphabet[i];
			}
			std::cout << "* Import transitions: " << std::endl;
			std::cout << "How many transitions are there in your Automatic: "; std::cin >> transitionamount;
			transition_function = std::vector<Transition>(transitionamount);
			for (int i = 0; i < transitionamount; i++){
				std::cout << "\tImport transition [" << i+1 << "]: " << std::endl;
				transition_function[i].importTransition();
			}
			std::cout << "* Which state is the start state? ";
			std::cin >> start_state;
			std::cout << "* Which states are accept states? " << std::endl;
			std::cout << "How many accept states are there in your Automatic: "; std::cin >> accept_stateamount;
			accept_states = std::vector<std::string>(accept_stateamount);
			for (int i = 0; i < accept_stateamount; i++){
				std::cout << "\tImport accept state [" << i+1 << "]: ";
				std::cin >> this->accept_states[i];
			}
			goInitialState();
			std::cout << "IN Super now" << std::endl;
		}
		virtual void disp () {
			std::cout << "Cac trang thai: ";
			for (int i = 0; i < states.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << states[i];
			}
			std::cout << std::endl << "Cac ki tu: ";
			for (int i = 0; i < alphabet.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << alphabet[i];
			}
			std::cout << std::endl;
			for (int i = 0; i < transition_function.size(); i++)
				transition_function[i].dispTransition ();		
			std::cout << "Trang thai bat dau la " << start_state << std::endl;
			std::cout << "Cac trang thai ket thuc: ";
			for (int i = 0; i < accept_states.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << accept_states[i];
			}
			std::cout << std::endl;
			std::cout << "Trang thai hien tai la " << current_state << std::endl;
		}
		virtual std::string getStrCurrentState () { return current_state; }
		virtual void setCurrentState () {
		    std::string input_state = current_state;
		    char alphabet;
		    checkCurrentState();
		    int checknum = 0;
		    while (checknum == 0){
		        std::cout << "Nhap alphabet: ";  std::cin >> alphabet;
		        for (int i = 0; i < this->alphabet.size(); i++) {
		            if (this->alphabet[i] == alphabet) {
		            	checknum = 1;
		            	break;
					}
		        }
		        if (checknum == 0) std::cout << "Nhap lai!!!" << std::endl;
		    }
		    for (int i = 0; i < transition_function.size(); i++){
		        if (input_state == transition_function[i].getInState() && alphabet == transition_function[i].getAlphabet()) {
				    current_state = transition_function[i].getOutState();
				    checkCurrentState();
		        }
		    }
		}
		virtual void setCurrentState (char alphabet) {
		    std::string input_state = current_state;
		    int checknum = 0;
		    for (int i = 0; i < this->alphabet.size(); i++) {
	        	if (this->alphabet[i] == alphabet) {
	        		for (int j = 0; j < transition_function.size(); j++){
		        		if (input_state == transition_function[j].getInState() && alphabet == transition_function[j].getAlphabet()) {
				    		current_state = transition_function[j].getOutState();
		        		}
		    		}
            		checknum = 1;
            		break;
				}
		    }
		    if (checknum == 0) std::cout << "Khong thuoc automatic." << std::endl;
		}
		virtual void checkCurrentState () { std::cout << "Kiem tra current_state: " << current_state << std::endl; }
		virtual void goInitialState (){ current_state = start_state; }
		virtual int checkAccept () {
			int checknum = 0;
			for (int i = 0; i < accept_states.size(); i++){
				if (current_state == accept_states[i]){
					checknum++;
					break;
				}
			}
			return checknum;
		}
		virtual void check() {
			std::string str = std::string();
			std::cout << "Nhap ngon ngu cua ban: "; std::cin >> str;
			std::vector<char> inputlist(str.begin(),str.end());
			
			goInitialState();
			for (int i = 0; i < inputlist.size(); i++){
				setCurrentState(inputlist[i]);
			}
			if (checkAccept() == 0) std::cout << "Khong thuoc automatic." << std::endl;
			else std::cout << "******Thuoc automatic. yay." << std::endl;
		}
};
class DFA : public Automata {
	private:
	public:
		DFA () {
			Automata ();
		}
		virtual void import () {
			int stateamount, alphabetamount, transitionamount, accept_stateamount;
		    std::cout << "Begin to import DFA: " << std::endl;
			std::cout << "* Import states: " << std::endl;
			std::cout << "How many states are there in your DFA: "; std::cin >> stateamount;
			states = std::vector<std::string>(stateamount);
			for (int i = 0; i < stateamount; i++){
				std::cout << "\tImport states [" << i+1 << "]: ";
				std::cin >> this->states[i];
			}
			std::cout << "* Import alphabets: " << std::endl;
			std::cout << "How many alphabets are there in your DFA: "; std::cin >> alphabetamount;
			alphabet = std::vector<char>(alphabetamount);
			for (int i = 0; i < alphabetamount; i++){
				std::cout << "\tImport alphabet [" << i+1 << "]: ";
				std::cin >> this->alphabet[i];
			}
			std::cout << "* Import transitions: " << std::endl;
			std::cout << "How many transitions are there in your DFA: "; std::cin >> transitionamount;
			transition_function = std::vector<Transition>(transitionamount);
			for (int i = 0; i < transitionamount; i++){
				std::cout << "\tImport transition [" << i+1 << "]: " << std::endl;
				transition_function[i].importTransition();
			}
			std::cout << "* Which state is the start state? ";
			std::cin >> start_state;
			std::cout << "* Which states are accept states? " << std::endl;
			std::cout << "How many accept states are there in your DFA: "; std::cin >> accept_stateamount;
			accept_states = std::vector<std::string>(accept_stateamount);
			for (int i = 0; i < accept_stateamount; i++){
				std::cout << "\tImport accept state [" << i+1 << "]: ";
				std::cin >> this->accept_states[i];
			}
			current_state = start_state;
		}
};
class NFA : public Automata {
	private:
		std::vector<std::string>	current_states;
	public:
		NFA () {
			Automata ();
			current_states = std::vector<std::string>(0);
		}
		virtual void import () {
			int stateamount, alphabetamount, transitionamount, accept_stateamount;
		    std::cout << "Begin to import NFA: " << std::endl;
			std::cout << "* Import states: " << std::endl;
			std::cout << "How many states are there in your NFA: "; std::cin >> stateamount;
			states = std::vector<std::string>(stateamount);
			for (int i = 0; i < stateamount; i++){
				std::cout << "\tImport states [" << i+1 << "]: ";
				std::cin >> this->states[i];
			}
			std::cout << "* Import alphabets: " << std::endl;
			std::cout << "How many alphabets are there in your NFA: "; std::cin >> alphabetamount;
			alphabet = std::vector<char>(alphabetamount);
			for (int i = 0; i < alphabetamount; i++){
				std::cout << "\tImport alphabet [" << i+1 << "]: ";
				std::cin >> this->alphabet[i];
			}
			std::cout << "* Import transitions: " << std::endl;
			std::cout << "How many transitions are there in your NFA: "; std::cin >> transitionamount;
			transition_function = std::vector<Transition>(transitionamount);
			for (int i = 0; i < transitionamount; i++){
				std::cout << "\tImport transition [" << i+1 << "]: " << std::endl;
				transition_function[i].importTransition();
			}
			std::cout << "* Which state is the start state? ";
			std::cin >> start_state;
			std::cout << "* Which states are accept states? " << std::endl;
			std::cout << "How many accept states are there in your NFA: "; std::cin >> accept_stateamount;
			accept_states = std::vector<std::string>(accept_stateamount);
			for (int i = 0; i < accept_stateamount; i++){
				std::cout << "\tImport accept state [" << i+1 << "]: ";
				std::cin >> this->accept_states[i];
			}
			goInitialState();
		}
		virtual void disp () {
			std::cout << "Cac trang thai: ";
			for (int i = 0; i < states.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << states[i];
			}
			std::cout << std::endl << "Cac ki tu: ";
			for (int i = 0; i < alphabet.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << alphabet[i];
			}
			std::cout << std::endl;
			for (int i = 0; i < transition_function.size(); i++)
				transition_function[i].dispTransition ();		
			std::cout << "Trang thai bat dau la " << start_state << std::endl;
			std::cout << "Cac trang thai ket thuc: ";
			for (int i = 0; i < accept_states.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << accept_states[i];
			}
			std::cout << std::endl;
			std::cout << "Trang thai hien tai la ";
			for (int i = 0; i < current_states.size(); i++){
				if (i != 0) std::cout << ", ";
				std::cout << current_states[i];
			} 
			std::cout << std::endl;
		}
		virtual void goInitialState () {
			current_states.assign(1,start_state);
		}
		virtual std::vector<std::string> getVectorCurrentState () {
			return current_states; 
		}
		virtual void setCurrentState () {
		    std::vector<std::string> temp_current(current_states);
		    char alphabet;
		    int checknum = 0;
		    while (checknum == 0){
		        std::cout << "Nhap alphabet: ";  std::cin >> alphabet;
		        for (int i = 0; i < this->alphabet.size(); i++) {
		            if (this->alphabet[i] == alphabet) {
		            	checknum = 1;
		            	break;
					}
		        }
		        if (checknum == 0) std::cout << "Nhap lai!!!" << std::endl;
		    }
		    for (int index_current = 0; index_current < this->current_states.size(); index_current++){
		    	int currentmultipleways = 0;
		    	for (int index_transition = 0; index_transition < transition_function.size(); index_transition++){
		    		if (current_states[index_current] == transition_function[index_transition].getInState() 
					&& alphabet == transition_function[index_transition].getAlphabet()) {
						if (currentmultipleways != 0) {
				  			temp_current.insert(temp_current.end(),transition_function[index_transition].getOutState());
						}
				  		else {
				  			temp_current[index_current] = transition_function[index_transition].getOutState();
							currentmultipleways++;
						}
		      		}
				}
		    }
           	current_states = temp_current;
		}
		virtual void setCurrentState (char alphabet) {
			std::vector<std::string> temp_current(current_states);
		    for (int index_alphabet = 0; index_alphabet < this->alphabet.size(); index_alphabet++)
	        	if (this->alphabet[index_alphabet] != alphabet);	
		    	else {
		    		for (int index_current = 0; index_current < this->current_states.size(); index_current++){
		    			int currentmultipleways = 0;
		    			for (int index_transition = 0; index_transition < transition_function.size(); index_transition++){
		    				if (current_states[index_current] == transition_function[index_transition].getInState() 
							&& alphabet == transition_function[index_transition].getAlphabet()) {
								if (currentmultipleways != 0) {
				  					temp_current.insert(temp_current.end(),transition_function[index_transition].getOutState());
								}
				  				else {
				  					temp_current[index_current] = transition_function[index_transition].getOutState();
									currentmultipleways++;
								}
		      				}
						}
		      		}
		   		}
           	current_states = temp_current;
		}
		virtual void checkCurrentState () {
			std::cout << "**Kiem tra, trang thai hien tai la ";
			for (int i = 0; i < current_states.size(); i++){
				if (i != 0) std::cout << " ,";
				std::cout << current_states[i];
			} 
			std::cout << std::endl; 
		}
		virtual int  checkAccept (){
			int checknum = 0;
			for (int i = 0; i < accept_states.size(); i++){
				for (int j = 0; j < current_states.size(); j++){
					if (current_states[j] == accept_states[i]){
						checknum++;
						break;
					}
				}
			}
			return checknum;
		}
};
void OneMoreTime(Automata *a) {
	int doitagain = 0;
	while (doitagain == 0) {
		if (doitagain == 0)
			a->check();
		std::cout << "One More Time? (Yes = 0 / No = 1) ";
		std::cin >> doitagain;
	}
}
int main () {
//	DFA a = DFA ();
//	a.importDFA();
//	a.disp();
//	a.setCurrentState();
//	a.checkDFA();
	Automata *b = new NFA ();
	b->import();
	b->disp();
//	b.setCurrentStates();
//	b.checkNFA();
	OneMoreTime(b);
}
