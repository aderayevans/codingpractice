#include <cstring>
#include <string>
#include <iostream>

int membercount = 0;

std::string* cinArrayMember (int memberamount){
	std::string *arrayof = new std::string[memberamount];
	int i;
	for (i=0;i<memberamount;i++){
		std::cout << "\tstd::string[" << i << "]: ";	getline (std::cin, arrayof[i]);
	}
	return arrayof;
}
int giaiThua (int memberamount){
	if (memberamount == 1) return memberamount;
	else if (memberamount == 0) return 1;
	return memberamount * giaiThua(memberamount - 1);
}
void swapString (std::string *A, std::string *B){
    std::string tmp;
    tmp = *A;
    *A = *B;
    *B = tmp;
}
void swapInt (int *A, int *B){
    int tmp;
    tmp = *A;
    *A = *B;
    *B = tmp;
}
void toSort (std::string *arrayofstring, int memberamount) {
	for (int i = 0; i < memberamount - 1; i++){
		swapString (&arrayofstring[i], &arrayofstring[i+1]);
	}
}
void disp (std::string *arrayofstring, int memberamount){
	for (int i = 0; i < memberamount; i++){
		std::cout << arrayofstring[i] << std::endl;
	}
}
void addString (std::string *arrayofpermuted, std::string *arrayofstring, int arrayofbool[], int memberamount)  {
	arrayofpermuted[membercount] = "";
	for (int i = 0; i < memberamount; i++){
		arrayofpermuted[membercount].append(arrayofstring[arrayofbool[i]]);
	}
//	std::cout << arrayofpermuted[membercount] << std::endl;
	membercount++;
}
void toPermute (std::string *arrayofpermuted, std::string *arrayofstring, int memberamount) {
	for (int i = 0; i < memberamount; i++){
		toSort(arrayofstring, memberamount);
		int arrayofbool[memberamount];
		for (int z = 0; z < memberamount; z++){
			arrayofbool[z] = z;
		}
		int count = 0;
		for (int j = 0; j < giaiThua(memberamount - 1); j++){
			if (count == 0){
				swapInt (&arrayofbool[0], &arrayofbool[1]);
				count = count + 1;
				
				addString(arrayofpermuted, arrayofstring, arrayofbool, memberamount);
			}
			else {
				swapInt (&arrayofbool[0], &arrayofbool[memberamount - 1]);
				count = 0;
				
				addString(arrayofpermuted, arrayofstring, arrayofbool, memberamount);
			}
		}
	}
	membercount = 0;
}
void Example (){
	int truenum = 0;
	int memberamountofA, memberamountofB; 
	std::string *arrayofA, *arrayofB;
	std::string *arrayofpermutedA, *arrayofpermutedB;
	int check = 0;
	
	std::cout << "Nhap so phan tu danh sach thu nhat: ";	std::cin >> memberamountofA;	std::cin.ignore(100, '\n');
	std::cout << "Nhap vao danh sach thu nhat: " << std::endl; 
	arrayofA = new std::string[memberamountofA]; arrayofA = cinArrayMember(memberamountofA);
	arrayofpermutedA =  new std::string[giaiThua(memberamountofA)];
	
	std::cout << "Nhap so phan tu danh sach thu hai: ";	std::cin >> memberamountofB;	std::cin.ignore(100, '\n');
	std::cout << "Nhap vao danh sach thu hai: " << std::endl; 
	arrayofB = new std::string[memberamountofB]; arrayofB = cinArrayMember(memberamountofB);
	arrayofpermutedB =  new std::string[giaiThua(memberamountofB)];	
	
//	disp (arrayofA, memberamountofA);
//	disp (arrayofB, memberamountofB);
	
	toPermute(arrayofpermutedA, arrayofA, memberamountofA);
	toPermute(arrayofpermutedB, arrayofB, memberamountofB);
	
//	disp (arrayofpermutedA, giaiThua(memberamountofA));
//	disp (arrayofpermutedB, giaiThua(memberamountofB));
	
	for (int i = 0; i < giaiThua(memberamountofA); i++){
		for (int j = 0; j < giaiThua(memberamountofB); j++){
			if (arrayofpermutedA[i] == arrayofpermutedB[j]){
				check++;
				std::cout << "Hai hoan vi giong nhau: " << arrayofpermutedA[i] << "=" << arrayofpermutedB[j] << std::endl;
				break;
			}
		}
	}
	if (check != 0){
		std::cout << "Co tao ra hoan vi giong nhau" << std::endl;
	}
	else std::cout << "Not match so well!!!" << std::endl;
	delete[] arrayofA;    delete[] arrayofB;	
    delete[] arrayofpermutedA;    delete[] arrayofpermutedB;
}
int main (){
	int selectnum=0;
	Example();
}
