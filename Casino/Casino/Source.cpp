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

	return name;
}

int main() {

	Player player(generatePlayer());
	Deck deck;
	deck.shuffle();

	int input;

	do {
		cout << "1. Poker" << endl;
		cout << "2. Black Jack" << endl;
		cout << "3. Exit" << endl;

		do
		{
			cin >> input;

		} while (input > 3 || input < 1);

		if (input == 1) {

			int choice;

			do
			{
				for (int i = 0; i < 5; i++) {
					player.handOneCard(deck.deal(),input);
				}

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
		else {

			int choice;

			for (int i = 0; i < 2; i++) {

				player.handOneCard(deck.deal(), input);
			}

			cout << "Hand total: " << player.getHandSum() << endl;

			do
			{

				if (player.getHandSum() == 21) {

					cout << "Hand Sum: " << player.getHandSum() << endl;
					cout << "You win" << endl;
					cout << endl;
					break;
				}
				else if (player.getHandSum() > 21) {

					cout << "Hand Sum: " << player.getHandSum() << endl;
					cout << "Bust!" << endl;
					cout << endl;
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
				}
				else if (choice == 2) {

					if (player.getDealerHandSum(deck) >= player.getHandSum() && player.getDealerHandSum(deck) <= 21) {

						cout << "Dealer hand sum: " << player.getDealerHandSum(deck) << endl;
						cout << "The dealer wins" << endl;
						cout << endl;
						break;
					}
					else {
						
						cout << "Dealer hand sum: " << player.getDealerHandSum(deck) << endl;
						cout << "You win!" << endl;
						cout << endl;
						break;
					}
				}
				else
					break;

		} while (true);

		deck.resetNoOfCards();
		deck.shuffle();
	}
} while (input == 1 || input == 2);

return 0;
}