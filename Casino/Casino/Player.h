#pragma once
#include<iostream>
#include"Card.h"
using namespace std;


class Player
{
	char *_name;
	Card _cards[10];
	int _noOfCards;
	int _handSum; //only used in Black Jack

public:

	Player()
	{
		_name = nullptr;
		_noOfCards = 0;
		_handSum = 0;
	}

	Player(char *name) {

		_name = new char[strlen(name) + 1];
		strcpy_s(_name, strlen(name) + 1, name);

		_noOfCards = 0;

		_handSum = 0;

		delete[] name;
		name = nullptr;

	}

	Player(Player &P) {

		if (_name != nullptr) {

			delete[] _name;
			_name = nullptr;
		}

		_name = new char[strlen(P._name) + 1];
		strcpy_s(_name, strlen(P._name) + 1, P._name);

		_noOfCards = P._noOfCards;

		for (int i = 0; i < _noOfCards; i++) {

			_cards[i] = P._cards[i];
		}

		_handSum = P._handSum;
	}

	~Player()
	{

		delete[] _name;
		_name = nullptr;
	}

	void handOneCard(Card _card, int choice) {

		if (choice == 1) {
			
			_cards[_noOfCards] = _card;
			cout << "Card handed" << endl;
			_noOfCards++;
		}
		else if(choice == 2){
			
			_cards[_noOfCards] = _card;
			cout << "Card handed" << endl;
			_noOfCards++;

			if ((int)_card.getRank() <= 10)
				_handSum += (int)_card.getRank();
			else
				_handSum += 10;
		}
	}

	void checkhand(int choice) {

		for (int i = 0; i < _noOfCards; i++) {

			cout << "-------------" << endl;
			cout << _cards[i] << endl;
			cout << "-------------" << endl;
		}

		if (choice == 1) {

			for (int i = 0; i < _noOfCards - 1; i++) {
				int counter = 0;

				for (int j = i+1; j < _noOfCards; j++) {

					if (_cards[i].getRank() == _cards[j].getRank())
						counter++;
				}

				counter++;

				if (counter == 2) {

					cout<<this->_name << " has a pair of " << RankChar[_cards[i].getRank()] << endl;
				}
				else if (counter == 3) {

					cout << this->_name << " has trip " << RankChar[_cards[i].getRank()] << endl;
				}
				else if (counter == 4) {

					cout << this->_name << " has quad " << RankChar[_cards[i].getRank()] << endl;
				}
			}
		}
		else if (choice == 2){

			cout << "Total: " << _handSum << endl;
		}
	}

	int getHandSum() {

		return _handSum;
	}

	int getDealerHandSum(Deck &D) {

		int sum = 0;

		do
		{

			sum += (int)D.deal().getRank();

			if (sum == 21)
				return sum;

		} while (sum<17);

		return sum;
	}

	void resetHandSum() {

		_handSum = 0;
	}

	void resetNoOfCards() {

		_noOfCards = 0;
	}

	char *getName() {

		return _name;
	}
};