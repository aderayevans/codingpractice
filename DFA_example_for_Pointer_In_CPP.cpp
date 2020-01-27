#include <iostream>
#include <string>

using namespace std;

//#define sizeOF(ar) (sizeof(ar)/sizeof(ar[0]))

class Transition {
	private:
		string	input_state;
		char	alphabet;
		string	output_state;
	public:
		Transition () {
			input_state = string();
			alphabet = '0';
			output_state = string();
		}
		Transition (string input_state, char alphabet, string output_state) {
			this->input_state = string();	this->input_state = input_state;
			this->alphabet = alphabet;
			output_state = string();	this->output_state = output_state;
		}
		string getInState () { return input_state; }
		char getAlphabet () { return alphabet; }
		string getOutState () { return output_state; }
		void importTransition () {
			cout << "\t\t>>Import input_state: ";	cin >> input_state;
			cout << "\t\t>>Import alpabet go along with this state: ";	cin >> alphabet;
			cout << "\t\t>>Import output_state: ";	cin >> output_state;
		}
		void dispTransition(){
			cout << "St( " << input_state << ", '" 
								<< alphabet << "')= " << output_state << endl;
		}
};
class DFA {
	private:
		int stateamount, alphabetamount, transitionamount, accept_stateamount;
		string	*states;
		char	*alphabet;
		Transition	*transition_function;
		string	start_state;
		string	*accept_states;
		string	current_state;
	public:
		DFA () {
		    stateamount = alphabetamount = transitionamount = accept_stateamount = 0;
			states = new string[stateamount];
			alphabet = new char[alphabetamount];
			transition_function = new Transition[transitionamount];
//			for (int i = 0; i < 50*50; i++)
//				transition_function[i] = Transition ();
			start_state = string();
			accept_states = new string[accept_stateamount];
			current_state = string();
		}
		DFA (string *states, int stateamount, char *alphabet, int alphabetamount, Transition *transition_function, 
		                        int transitionamount, string start_state, string *accept_states, int accept_stateamount) {
			this->states = new string[stateamount];
			for (int i = 0; i < stateamount; i++)
				*((this->states)+i) = *(states+i);
			for (int i = 0; i < alphabetamount; i++)
				*((this->alphabet)+i) = *(alphabet+i);
			transition_function = new Transition[transitionamount];
			this->start_state = string();	this->start_state = start_state;
			this->accept_states = new string[accept_stateamount];
			for (int i = 0; i < accept_stateamount; i++)
				*((this->accept_states)+i) = *(accept_states+i);
			this->current_state = string();	this->current_state = current_state;
		}
		void importDFA () {
		    cout << "Begin to import DFA: " << endl;
			cout << "* Import states: " << endl;
			cout << "How many states are there in your DFA: "; cin >> stateamount;
			states = new string[stateamount];
			for (int i = 0; i < stateamount; i++){
				cout << "\tImport states [" << i+1 << "]: ";
				cin >> *((this->states)+i);
			}
			cout << "* Import alphabets: " << endl;
			cout << "How many alphabets are there in your DFA: "; cin >> alphabetamount;
			alphabet = new char[alphabetamount];
			for (int i = 0; i < alphabetamount; i++){
				cout << "\tImport alphabet [" << i+1 << "]: ";
				cin >> *((this->alphabet)+i);
			}
			cout << "* Import transitions: " << endl;
			cout << "How many transitions are there in your DFA: "; cin >> transitionamount;
			transition_function = new Transition[transitionamount];
			for (int i = 0; i < transitionamount; i++){
				cout << "\tImport transition [" << i+1 << "]: " << endl;
				(transition_function+i)->importTransition();
			}
			cout << "* Which state is the start state? ";
			cin >> start_state;
			cout << "* Which states are accept states? " << endl;
			cout << "How many accept states are there in your DFA: "; cin >> accept_stateamount;
			accept_states = new string[accept_stateamount];
			for (int i = 0; i < accept_stateamount; i++){
				cout << "\tImport accept state [" << i+1 << "]: ";
				cin >> *((this->accept_states)+i);
			}
			cout << endl;
			current_state = start_state;
		}
		void disp () {
			cout << "Cac trang thai: ";
			for (int i = 0; i < stateamount; i++)
				cout << *(states+i) << " ,";
			cout << endl << "Cac ki tu: ";
			for (int i = 0; i < alphabetamount; i++)
				cout << *(alphabet+i) << " ,";
			cout << endl;
			for (int i = 0; i < transitionamount; i++)
				(transition_function+i)->dispTransition ();		
			cout << "Trang thai bat dau la " << start_state << endl;
			cout << "Cac trang thai ket thuc: ";
			for (int i = 0; i < accept_stateamount; i++)
				cout << *(accept_states+i) << " ,";
			cout << endl;
			cout << "Trang thai hien tai la " << current_state << endl;
		}
		string getCurrentState() { return current_state; }
		void setCurrentState() {
		    string input_state = current_state;
		    char alphabet;
		    checkCurrentState();
		    int checknum = 0;
		    while (checknum == 0){
		        cout << "Nhap alphabet: ";  cin >> alphabet;
		        for (int i = 0; i < alphabetamount; i++) {
		            if (*((this->alphabet)+i) == alphabet) {
		            	checknum = 1;
		            	break;
					}
		        }
		        if (checknum == 0) cout << "Nhap lai!!!" << endl;
		    }
		    for (int i = 0; i < transitionamount; i++){
		        if (input_state == (transition_function+i)->getInState() && alphabet == (transition_function+i)->getAlphabet()) {
				    current_state = (transition_function+i)->getOutState();
				    checkCurrentState();
		        }
		    }
		}
		void setCurrentState(char alphabet) {
		    string input_state = current_state;
//		    checkCurrentState();
		    int checknum = 0;
		    for (int i = 0; i < alphabetamount; i++) {
	        	if (*((this->alphabet)+i) == alphabet) {
	        		for (int i = 0; i < transitionamount; i++){
		        		if (input_state == (transition_function+i)->getInState() && alphabet == (transition_function+i)->getAlphabet()) {
				    		current_state = (transition_function+i)->getOutState();
//				    		checkCurrentState();
		        		}
		    		}
            		checknum = 1;
            		break;
				}
		    }
		    if (checknum == 0) cout << "Khong thuoc automatic." << endl;
		    
		    
		}
		void checkCurrentState () { cout << "Kiem tra current_state: " << current_state << endl; }
		void goInitialState (){ current_state = start_state; }
		int checkAccept (){
			int checknum = 0;
			for (int i = 0; i < accept_stateamount; i++){
				if (current_state == *(accept_states+i)){
					cout << "Dang o trang thai ket thuc" << endl;
					checknum = 0;
					break;
				}
				else {
					cout << "Dang khong o trang thai ket thuc" << endl;
					checkCurrentState();
					checknum++;
				}
			}
			return checknum;
		}
		void checkDFA(){
			int listamount;
			cout << "Ngon ngu cua ban co bao nhieu tu: "; cin >> listamount; cin.ignore(100, '\n');
			char *inputlist = new char[listamount];
			cout << "Nhap ngon ngu cua ban: "; cin >> inputlist;
			
			const char *start_statechar;
			start_statechar = start_state.c_str();
			if (*(inputlist) != *start_statechar) cout << "Khong thuoc automatic." << endl;
			
			goInitialState();
			for (int i = 0; i < listamount; i++){
				setCurrentState(*(inputlist+i));
			}
			if (checkAccept() != 0) cout << "Khong thuoc automatic." << endl;
			else cout << "******Thuoc automatic. yay." << endl;
		}
};
int main () {
	DFA a = DFA ();
	a.importDFA();
	a.disp();
	a.setCurrentState();
	a.checkDFA();
}
