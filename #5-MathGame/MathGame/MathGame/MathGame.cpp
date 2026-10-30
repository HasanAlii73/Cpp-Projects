#include <iostream>
using namespace std;


int random(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

enum enOperation {addop = 1, subop = 2, mulop = 3, divop = 4, mixop = 5};

enum enLevel {easy = 1, medium = 2, hard = 3, mix = 4};

int Readquiznumberofquestions()
{
	int numberq;
	cout << "How many Questions do you want to answer ? ";
	cin >> numberq;
	return numberq;
}

enLevel Readquizlevel()
{
	int lvl;
	cout << "Enter questions level : [1] Easy, [2] Medium, [3] Hard, [4] Mix : ";
	cin >> lvl;
	return enLevel(lvl);
}

enOperation ReadquizOperation()
{
	int optype;
	cout << "Enter Operation Type : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ";
	cin >> optype;
	return enOperation(optype);
}

struct stQuestion
{
	int Numberofquestion = 0;
	enLevel level = easy;
	enOperation op = addop;
	int num1 = 0;
	int num2 = 0; 
	int rightanswer = 0;
	bool right = 1;
};

struct stQuizz
{
	stQuestion questions[100];
	int numberofqu = 0;
	enLevel levels = easy;
	enOperation ops = addop;
	int numberofRight = 0;
	int numberofWrong = 0;
	bool pass = 1;
};

void GenerateQuestionNums(stQuestion& question)
{
	switch (question.level)
	{ 
	case(enLevel::easy):
	{
		question.num1 = random(1, 10);
		question.num2 = random(1, 10); 
		cout << question.num1 << "\n" << question.num2;
		break;
	}
	case(enLevel::medium):
	{
		question.num1 = random(10, 50);
		question.num2 = random(10, 50);
		cout << question.num1 << "\n" << question.num2;
		break;
	}
	case(enLevel::hard):
	{
		question.num1 = random(50, 100);
		question.num2 = random(50, 100);
		cout << question.num1 << "\n" << question.num2;
		break;
	}
	case(enLevel::mix):
	{
		question.level = enLevel(random(1, 3));
		GenerateQuestionNums(question);
		break;
	}
	}
}

void GenerateQuestionsOPS(stQuestion& question)
{
	switch (question.op)
	{
	case(enOperation::addop): {cout << " +\n"; break; }
	case(enOperation::subop): {cout << " -\n"; break; }
	case(enOperation::mulop): {cout << " *\n"; break; }
	case(enOperation::divop): {cout << " /\n"; break; }
	case(enOperation::mixop):
	{
		question.op = enOperation(random(1, 4));
		GenerateQuestionsOPS(question);
		break;
	}
	}
}

int calculator(stQuestion question)
{
	switch (question.op)
	{
	case(enOperation::addop):return question.num1 + question.num2;
	case(enOperation::subop):return question.num1 - question.num2;
	case(enOperation::mulop):return question.num1 * question.num2;
	case(enOperation::divop):return question.num1 / question.num2;
	default:return 0;
	}
}

void checkAnswer(stQuestion& question, int youranswer)
{
	if (youranswer == question.rightanswer)
	{
		cout << "Right answer :)\n";
		system("color 2f");
		question.right = true;
	}
	else
	{
		cout << "Wrong answer :(\n";
		system("color 4f");
		cout << "The right answer is : " << question.rightanswer;
		question.right = false;
	}
}

void quizzcounter(stQuizz& quizz, int i)
{
	if (quizz.questions[i].right)
		quizz.numberofRight++;
	else
		quizz.numberofWrong++;
}

void GenerateQuestion(stQuestion& question, stQuizz& quizz)
{
	int youranswer;
	question.level = quizz.levels;
	question.op = quizz.ops;
	cout << "Question [" << question.Numberofquestion << "/" << quizz.numberofqu << "]\n\n";
	GenerateQuestionNums(question);
	GenerateQuestionsOPS(question);
	cout << "-----------\n";
	cin >> youranswer;
	question.rightanswer = calculator(question);
	checkAnswer(question, youranswer);

}

string getLEVELstring(enLevel level)
{
	switch (level)
	{
	case(easy):return "EASY";
	case(medium):return "MEDIUM";
	case(hard):return "HARD";
	case(mix):return "MIX";
	default:return"UNknown";
	}
}

char getOPchar(enOperation op)
{
	switch (op)
	{
	case(addop):return '+';
	case(subop):return '-';
	case(mulop):return '*';
	case(divop):return '/';
	case(mixop):return 'M';
	default:return 'E';
	}
}

void didyoupass(stQuizz& quizz)
{
	if (quizz.numberofRight > quizz.numberofWrong)	quizz.pass = true;
	else quizz.pass = false;
}

void Results(stQuizz& quizz)
{
	didyoupass(quizz);
	if (quizz.pass == true)
	{
		cout << "\n\n================================\n";
		cout << "Final results is PASS :)\n";
		cout << "================================\n";
	}
	else
	{
		cout << "\n\n================================\n";
		cout << "Final results is NOT PASS :(\n";
		cout << "================================\n";
	}
	cout << "Number of questions : " << quizz.numberofqu << "\n";
	cout << "Questions Level : " << getLEVELstring(quizz.levels) << "\n";
	cout << "OP type : " << getOPchar(quizz.ops) << "\n";
	cout << "Number of Right answers : " << quizz.numberofRight << "\n";
	cout << "Number of Wrong answers : " << quizz.numberofWrong << "\n";
	cout << "================================\n";

}

void GenerateQuizz(stQuizz& quizz)
{
	for (int i = 0; i < quizz.numberofqu; i++)
	{
		quizz.questions[i].Numberofquestion = i + 1;
		GenerateQuestion(quizz.questions[i], quizz);
		quizzcounter(quizz, i);
		cout << "\n\n";
	}
	Results(quizz);
}

void mathgame()
{
	stQuizz quizz;
	quizz.numberofqu = Readquiznumberofquestions();
	quizz.levels = Readquizlevel();
	quizz.ops = ReadquizOperation();
	GenerateQuizz(quizz);
}

void startgame()
{
	char ans = 'Y';
	do
	{
	system("cls");
	system("color 0f");
		mathgame();
		cout << "Do you want to play again ? (Y/N) : ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	startgame();
	return 0;
}