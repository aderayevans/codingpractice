class Production_rule:
    def __init__(self):
        self.the_cause = ''
        self.the_consequence = ''
    def import_(self):
        self.the_cause = input('The cause: ')
        self.the_consequence = input('The consequence: ')
    def get_the_cause(self):
        return self.the_cause
    def get_the_consequence(self):
        return self.the_consequence
    def get_first_char_in_the_consequence(self):
        return self.the_consequence[0]
    def get_last_char_in_the_consequence(self):
        return self.the_consequence[len(self.the_consequence)-1]
    def display(self):
        print(self.the_cause + ' --> ' + self.the_consequence)
class Regular_grammar:
    def __init__(self):
        self.variables = []
        self.v_amount = 0
        self.terminal_symbols = []
        self.t_amount = 0
        self.start_symbol =''
        self.production_rules = []
        self.p_amount = 0
    def import_(self):
        self.v_amount = int(input('How much variables: '))
        self.variables = ['']*self.v_amount
        for index in range(0, self.v_amount):
            self.variables[index] = input('/<' + str(index+1) + '>: ')
        self.t_amount = int(input('How much terminal_symbols: '))
        self.terminal_symbols = ['']*self.t_amount
        for index in range(0, self.t_amount):
            self.terminal_symbols[index] = input('/<' + str(index + 1) + '>: ')
        while True:
            self.start_symbol = input('which is start symbol: ')
            if self.start_symbol in self.variables:
                break
        
        self.p_amount = int(input('How much production rules: '))
        self.production_rules = ['']*self.p_amount
        for index in range(0, self.p_amount):
            self.production_rules[index] = Production_rule()
            print('Importing production rule (' + str(index+1) + '):')
            self.production_rules[index].import_()
    def get_start_symbol(self):
        return self.start_symbol
    def get_final_symbol(self):
        states = self.get_states()
        states = list(dict.fromkeys(states))
        final_symbols = []
        for index in range(0, len(states)):
            if len(states[index]) == 1 or states[index] == 'Eps':
                if states[index] in self.terminal_symbols or states[index] == 'Eps':
                    final_symbols.append(states[index])
        if len(final_symbols) == 1:
            return final_symbols[0]
        else:
            return final_symbols
    def get_alphabets(self):
        states = self.get_states()
        states = list(dict.fromkeys(states))
        alphabets = []
        for index in range(0, len(states)):
            if len(states[index]) == 1:
                if states[index] in self.terminal_symbols or states[index] == 'Eps':
                    alphabets.append(states[index])
        return alphabets
    def get_states(self):
        states = []
        for index in range (0, self.p_amount):
            states.append(self.production_rules[index].get_the_cause())
            states.append(self.production_rules[index].get_the_consequence())
        return states
    def get_extra_states(self):
        states = self.get_states()
        states = list(dict.fromkeys(states))
        list_extra = []
        temp_states = []
        for index in range (0, len(states)):
            if len(states[index]) > 1 and states[index] != 'Eps':
                temp_states.append(states[index])
        while True:
            length_of_list_mem = 0
            for index in range (0, len(temp_states)):
                if len(temp_states[index]) > 1:
                    length_of_list_mem += 1
            if length_of_list_mem == 0:
                break
            for index in range (0, len(temp_states)):
                if temp_states[index][0] in self.terminal_symbols:
                    temp_str = temp_states[index][1:len(temp_states[index])]
                    temp_list = [temp_states[index], temp_str, temp_states[index][0]]
                    list_extra.append(temp_list)
                    temp_states[index] = temp_str
        return(list_extra)
    def get_cause_consequence(self):
        list_c_c = []
        for index in range(0, self.p_amount):
            c_c = [None]*2
            c_c[0] = self.production_rules[index].get_the_cause()
            c_c[1] = self.production_rules[index].get_the_consequence()
            list_c_c.append(c_c)
        return list_c_c
    def display(self):
        print('>>Regular grammar:')
        print('Variables: ')
        for index in range(0, self.v_amount):
            print('/<' + str(index+1) + '>: ' + self.variables[index])
        print('Terminal symbols: ')
        for index in range(0, self.t_amount):
            print('/<' + str(index+1) + '>: ' + self.terminal_symbols[index])
        print('P:')
        for index in range(0, self.p_amount):
            self.production_rules[index].display()
    def not_Right_rule(self):
        for index in range (0, len(self.production_rules)):
            if (self.production_rules[index].get_first_char_in_the_consequence() in self.variables
                and self.production_rules[index].get_last_char_in_the_consequence() in self.terminal_symbols):
                return True
        return False
    def reverse_(self, the_str):
        temp_str = the_str[len(the_str)::-1]
        return temp_str
    def reverse_to_right(self, the_str):
        if the_str[0] in self.variables and the_str[len(the_str)-1] in self.terminal_symbols and the_str != 'Eps':
            return self.reverse_(the_str)
        else:
            return the_str
    def get_states_leftver(self):
        states = self.get_states()
        states = list(dict.fromkeys(states))
        for index in range (0, len(states)):
            if len(states[index]) > 1:
                states[index] = self.reverse_to_right(states[index])
        return states
    def get_extra_states_leftver(self):
        states = self.get_states_leftver()
        states = list(dict.fromkeys(states))
        list_extra = []
        temp_states = []
        for index in range (0, len(states)):
            if len(states[index]) > 1 and states[index] != 'Eps':
                temp_states.append(states[index])
        while True:
            length_of_list_mem = 0
            for index in range (0, len(temp_states)):
                if len(temp_states[index]) > 1:
                    length_of_list_mem += 1
            if length_of_list_mem == 0:
                break
            for index in range (0, len(temp_states)):
                if temp_states[index][0] in self.terminal_symbols:
                    temp_str = temp_states[index][1:len(temp_states[index])]
                    temp_list = [self.reverse_(temp_states[index]), self.reverse_(temp_str), temp_states[index][0]]
                    list_extra.append(temp_list)
                    temp_states[index] = temp_str
        return(list_extra)
class Transition:
    def __init__(self):
        self.input_state = ''
        self.output_state = ''
        self.alphabet = ''
    def set_input_state(self, state):
        self.input_state = state
    def set_output_state(self, state):
        self.output_state = state
    def set_alphabet(self, alphabet):
        self.alphabet = alphabet
    def set_transition(self, input_state, output_state, alphabet):
        self.set_input_state(input_state)
        self.set_output_state(output_state)
        self.set_alphabet(alphabet)
    def get_input_state(self):
        return self.input_state
    def get_output_state(self):
        return self.output_state
    def get_alphabet(self):
        return self.alphabet
    def display(self):
        print('Tr(' + self.input_state + ', ' + self.alphabet + ') = ' + self.output_state)
class Finite_automata:
    def __init__(self):
        self.states = []
        self.alphabets = []
        self.transitions = []
        self.current_transition_pos = 0
        self.start_state = ''
        self.final_states = []
    def set_states(self, states):
        self.states = states
    def set_state(self, state):
        self.states.append(state)
    def set_alphabets(self, alphabets):
        self.alphabets = alphabets
    def set_final_state(self, final_states):
        self.final_states = final_states
    def set_alphabet(self, alphabet):
        self.alphabets.append(alphabet)
    def set_transition_type1(self, list_c_c):
        for index in range(0, len(list_c_c)):
            self.transitions.append(None)
            self.transitions[self.current_transition_pos] = Transition()
            self.transitions[self.current_transition_pos].set_transition(list_c_c[index][0], list_c_c[index][1], 'Eps')
            self.current_transition_pos += 1
    def set_transition_type2(self, input_state, output_state, alphabet):
        self.transitions.append(None)
        self.transitions[self.current_transition_pos] = Transition()
        self.transitions[self.current_transition_pos].set_transition(input_state, output_state, alphabet)
        self.current_transition_pos += 1
    def set_start_state(self, start_state):
        self.start_state = start_state
    def set_extra_states(self, list_extra):
        for extra in list_extra:
            self.set_transition_type2(extra[0], extra[1], extra[2])
            self.set_alphabet(extra[2])
            self.set_state(extra[1])
    def display(self):
        self.del_same()
        print('>>Finite automata:')
        print('States: ')
        for index in range(0, len(self.states)):
            print('/<' + str(index+1) + '>: ' + self.states[index])
        print('Alphabets: ')
        for index in range(0, len(self.alphabets)):
            print('/<' + str(index+1) + '>: ' + self.alphabets[index])
        print('Start state: ' + self.start_state)
        if len(self.final_states) == 1:
            print('Final state: ' + self.final_states[0])
        else:
            print('Final states: ')
            for index in range(0, len(self.final_states)):
                print('/<' + str(index+1) + '>: ' + self.final_states[index])
        print('Transition:')
        for index in range(0, len(self.transitions)):
            self.transitions[index].display()
    def del_same(self):
        self.states = list(dict.fromkeys(self.states))
        self.alphabets = list(dict.fromkeys(self.alphabets))
        self.final_states = list(dict.fromkeys(self.final_states))
    def convert_back(self):
        temp_transitions = []
        for index in range(0, len(self.transitions)):
            temp_transitions.append(None)
            temp_transitions[index] = Transition()
            temp_transitions[index].set_transition
            temp_transitions[index].set_transition(self.transitions[index].get_output_state(), self.transitions[index].get_input_state(), self.transitions[index].get_alphabet())
        self.transitions = temp_transitions
testRG = Regular_grammar()
testRG.import_()
if testRG.not_Right_rule():
    print("Left regular grammar:")
    testFA = Finite_automata()
    testFA.set_start_state(testRG.get_final_symbol())
    testFA.set_final_state(testRG.get_start_symbol())
    testFA.set_states(testRG.get_states())
    testFA.set_alphabets(testRG.get_alphabets())
    testFA.set_transition_type1(testRG.get_cause_consequence())
    testFA.set_extra_states(testRG.get_extra_states_leftver())
    testFA.convert_back()
    testRG.display()
    testFA.display()
else:
    testFA = Finite_automata()
    testFA.set_start_state(testRG.get_start_symbol())
    testFA.set_final_state(testRG.get_final_symbol())
    testFA.set_states(testRG.get_states())
    testFA.set_alphabets(testRG.get_alphabets())
    testFA.set_transition_type1(testRG.get_cause_consequence())
    testFA.set_extra_states(testRG.get_extra_states())
    testRG.display()
    testFA.display()
pass