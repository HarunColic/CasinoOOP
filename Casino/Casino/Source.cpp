#include<iostream>
#include<algorithm>
#include"Card.h"
#include"Deck.h"
#include"Player.h"
using namespace std;

//function called when program starts
char * generatePlayer() {

	char name[50];
	cout << "Please insert your name" << endl;
	cin.getline(name, 50);

	char *_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
	
	return _name;
}

int main() {

	Player player(generatePlayer());
	Deck deck;
	deck.shuffle();

	int input;

	do {

		system("cls");

		cout << "1. Poker" << endl;
		cout << "2. Black Jack" << endl;
		cout << "3. Shuffle cards" << endl;
		cout << "4. Exit" << endl;

		do
		{
			cin >> input;

		} while (input > 4 || input < 1);

		if (input == 1) {

			int choice;

			player.resetNoOfCards();

			for (int i = 0; i < 5; i++) {

				player.handOneCard(deck.deal(), input);
			}

			do
			{
				cout << "1. Check Hand" << endl;
				cout << "2. Exit" << endl;

				do
				{
					cin >> choice;

				} while (choice > 2 || choice < 1);

				if (choice == 1) {

					player.checkhand(input);
				}

			} while (choice == 1);
		}
		else if(input == 2) {

			int choice;

			for (int i = 0; i < 2; i++) {

				player.handOneCard(deck.deal(), input);
			}

			cout << player.getName() << "'s Hand Sum: " << player.getHandSum() << endl;

			do
			{

				if (player.getHandSum() == 21) {

					cout <<player.getName()<< "'s Hand Sum: " << player.getHandSum() << endl;
					cout << "You win" << endl;
					cout << endl;
					player.resetHandSum();
					player.resetNoOfCards();
					system("pause");
					break;
				}
				else if (player.getHandSum() > 21) {

					cout << player.getName() << "'s Hand Sum: " << player.getHandSum() << endl;
					cout << "Bust!" << endl;
					cout << endl;
					player.resetHandSum();
					player.resetNoOfCards();
					system("pause");
					break;
				}

				cout << "1. Hit" << endl;
				cout << "2. Stand" << endl;
				cout << "3. Exit" << endl;

				do
				{
					cin >> choice;

				} while (choice > 3 || choice < 1);

				if (choice == 1) {

					player.handOneCard(deck.deal(), input);
					cout << player.getName() << "'s Hand Sum: " << player.getHandSum() << endl;
				}
				else if (choice == 2) {

					int dealerHand = player.getDealerHandSum(deck);

					if (dealerHand < 21 && dealerHand >= player.getHandSum()) {

						cout << "Dealer hand sum: " << dealerHand << endl;
						cout << "The dealer wins" << endl;
						cout << endl;
						player.resetHandSum();
						player.resetNoOfCards();
						system("pause");
						break;
					}
					else {
						
						cout << "Dealer hand sum: " << dealerHand << endl;
						cout << "You win!" << endl;
						cout << endl;
						player.resetHandSum();
						player.resetNoOfCards();
						system("pause");
						break;
					}
				}
				else if(choice == 3){
					
					player.resetHandSum();
					player.resetNoOfCards();
					break;
				}

		} while (true);

		player.resetHandSum();
		player.resetNoOfCards();
		deck.resetNoOfCards();
		deck.shuffle();

	}
		else if (input == 3) {

			for (int i = 0; i < strlen(player.getName()); i++) {
				deck.shuffle();
			}
			player.resetNoOfCards();
		}

} while (input != 4);

return 0;
}