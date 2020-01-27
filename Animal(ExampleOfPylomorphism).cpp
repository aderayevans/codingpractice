#include <iostream>

class Animal {
	private:
		std::string breed;
		std::string color;
		float weight;
	public:
		Animal (){
			breed = std::string("");
			color = std::string("");
			weight = 0;
		}
		Animal (const Animal& thatAnimal){
			breed = thatAnimal.breed;
			color = thatAnimal.color;
			weight = thatAnimal.weight;
		}
		virtual void makeSound () {
			std::cout << "..." << std::endl;
		}
		virtual void setBreed (std::string breed) {
			this->breed = breed;
		}
		virtual void setBreed (){
			std::cout << "What kind of breed is this animal? ";
			std::cin >> breed;
		}
		virtual void setColor (){
			std::cout << "What kind of color is this animal? ";
			std::cin >> breed;
		}
		virtual void setWeight (){
			std::cout << "How much weight is this animal? ";
			std::cin >> breed;
		}
		virtual std::string getBreed (){
			return breed;
		}
		virtual std::string getColor (){
			return color;
		}
		virtual float getWeight (){
			return weight;
		}
};
class Cow : public Animal {
	public:
		virtual void makeSound () {
			std::cout << "moo..moo" << std::endl;
		}
};
class Pig : public Animal {
	public:
		virtual void makeSound () {
			std::cout << "oink..oink" << std::endl;
		}
};
class Goat : public Animal {
	public:
		virtual void makeSound () {
			std::cout << "naa..naa" << std::endl;
		}
};
int checkPig (std::string breed, Animal *thecattle[], int index){
	if (breed == "pig"){
		thecattle[index] = new Pig();
		thecattle[index]->setBreed("Pig");
		return 1;
	}
	else return 0;
}
int checkCow (std::string breed, Animal *thecattle[], int index){
	if (breed == "cow"){
		thecattle[index] = new Cow();
		thecattle[index]->setBreed("Cow");
		return 1;
	}
	else return 0;
}
int checkGoat (std::string breed, Animal *thecattle[], int index){
	if (breed == "goat"){
		thecattle[index] = new Goat();
		thecattle[index]->setBreed("Goat");
		return 1;
	}
	else return 0;
}
int checkAnimal (std::string breed, Animal *thecattle[], int index){
	if ((checkPig(breed, thecattle, index) == 1)
			|| (checkCow(breed, thecattle, index) == 1)
			|| (checkGoat(breed, thecattle, index) == 1)) return 1;
	else return 0;
}
void setCattle(Animal *thecattle[], int index){
	std::string breed = std::string();
	while (true){
		std::cout << "What kind: ";
		std::cin >> breed;
		if (checkAnimal(breed, thecattle, index) == 1) break;
		else std::cout << "Please type again:" << std::endl;
	}
	thecattle[index]->setColor();
	thecattle[index]->setWeight();
}
int main(){
	int cattleamount;
	std::cout << "Old MacDonald Had A Farm, how much cattles will he have?" << std::endl;
	std::cout << "Cattle-amount: ";
	std::cin >> cattleamount;
	std::cin.ignore(100, '\n');
	Animal *hiscattle[cattleamount];
	for (int index = 0; index < cattleamount; index++){
		setCattle(hiscattle, index);
	}
	for (int index = 0; index < cattleamount; index++){
		hiscattle[index]->makeSound();
	}
}

