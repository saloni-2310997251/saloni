#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int i=1;
class GuessTheNumber {
private:
    int ComputerGeneratedNumber;
    int userGuessedNumber;
public:
void generateRandomNumber(void){
    srand(time(0));
    ComputerGeneratedNumber=rand()%100+1;
}
void startGame(void){
	cout<<"Guess The Number Game"<<endl;
	cout<<"Try to guess a random number between 1 to 100"<<endl;
	do{
		cout<<"guess the number:";
		cin>>userGuessedNumber;
		cout<<"attempt: "<<i++<<endl;
	if (userGuessedNumber < ComputerGeneratedNumber) {
		cout<<"Guessed number is smaller than computer generated number.please try again"<<endl;
	}
	else if (userGuessedNumber > ComputerGeneratedNumber) {
		cout<<"Guessed number is greater than computer generated number.please try again"<<endl;
	}
	else{
		cout<<"congratulations you won the game in "<<--i<<" attempts"<<endl;
	}		
	}while(userGuessedNumber != ComputerGeneratedNumber);
}
};
int main(){
	GuessTheNumber game;
    game.generateRandomNumber();
	game.startGame();
	return 0;
}
