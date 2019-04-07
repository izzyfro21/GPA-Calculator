#include <iostream>

class GPA{
	public:
		float decimal;
		void Calculate();
		char weight[7];
		char grade[7];
		float numGrade[7];
		void letterToNum();
		void CombinedGPA();
		void onePointScale(char, int);
		void pointFiveScale(char, int);
		float compGPA;


};


//converts the letter grade to GPA for a 0.5 scale
void GPA::pointFiveScale(char grade, int i){
	switch (grade){
			case 'A':
				numGrade[i] = 4.0;
				break;
			case 'a':
				numGrade[i] = 4.0;
				break;
			case 'B':
				numGrade[i] = 3.5;
				break;
			case 'b':
				numGrade[i] = 3.0;
				break;
			case 'C':
				numGrade[i] = 3.5;
				break;
			case 'c':
				numGrade[i] = 2.0;
				break;
			case 'd':
				numGrade[i] = 1.0;
				break;
			case 'f':
				numGrade[i] = 0.0;
				break;
	}	
	
}

//converts the letter grade to GPA for a 1.0 scale
void GPA::onePointScale(char grade, int i){
	switch (grade){
			case 'A':
				numGrade[i] = 4.0;
				break;
			case 'B':
				numGrade[i] = 3.0;
				break;
			case 'C':
				numGrade[i] = 2.0;
				break;
			case 'D':
				numGrade[i] = 1.0;
				break;
			case 'F':
				numGrade[i] = 0.0;
				break;
			default:
				numGrade[i] = 999;
				break;
	}
}

//Gets the grades from the user and converts their letter grades to a GPA
void GPA::letterToNum(){
	for(int i = 0; i<=5; i++){
		std::cout<< "If your grade has a + as in an A+ use a capital letter if it is a normal A then use a lowercase letter. Example: an A for A+ and an a for A \n";
		std::cout<< "If your school uses the 1 point grading scale use a capital letter for all grades \n";
		std::cout<< "What is your grade in class number " << i+1 << ": ";
		std::cin>> grade[i];
		std::cout<<"is this class honors(h), College/AP/IB/etc(a) or standard(s): ";
		std::cin>>weight[i];

		if(decimal == 1.0){
			onePointScale(grade[i], i);
		}else if(decimal == 0.5){
			pointFiveScale(grade[i], i);
		}

		if(weight[i] == 'a'){
			numGrade[i]++;
		}else if(weight[i] == 'h'){
			numGrade[i] += 0.5;
		}
	}
}

//Averages all the GPA to the combined GPA
void GPA::CombinedGPA(){
	compGPA = ((numGrade[0]+numGrade[1] + numGrade[2] + numGrade[3] + numGrade[4] + numGrade[5])/6.0);
}



int main(int argc, char const *argv[])
{
	GPA yourGrade;

	//Asks the user what GPA scale their School uses
	std::cout<<"Does your GPA scale go by 0.5(B+ is 3.5) or by 1.0(B+ is same as a B, a 3.0), Anser by typing 0.5 or 1.0: ";
	std::cin>> yourGrade.decimal;

	yourGrade.letterToNum();

	yourGrade.CombinedGPA();

	std::cout << "Your GPA is: "<<yourGrade.compGPA<< std::endl;

	return 0;
}