#include<bits/stdc++.h>
#include"CoinMaster.h"
using namespace std;

string current_player_name;

enum Choice { 
	STATS = 1, 
	SPIN, 
	SHOP,
	INFO,
	EXIT
};



int main(){
	bool isTimerRunning = false;
	time_t timer_started_at = 0;

	// Start a new game
   	cout << string((100 - strlen("COIN MASTER"))/2, '+') << "COIN MASTER" << string((100 - strlen("COIN MASTER"))/2, '+') << endl;
	cout << "Enter your name:" << endl;
	getline(cin, current_player_name);

	CoinMaster coinMaster(current_player_name);

	bool onGoing = true;
	while(onGoing){
		cout << "Select what you want to do -\n" <<
				"1. Print Stats\n" <<
				"2. Spin\n" << 
				"3. Village shop\n" <<
				"4. Village Info\n" <<
				"5. Exit" <<
				endl;
		int choice = -1;
		string temp;
		getline(cin, temp);
	    string::size_type sz;   // alias of size_t
		int choice2 = -1;
		string temp2;
	    string::size_type sz2;   // alias of size_t

	    try{
  			choice = stoi(temp, &sz);
	    }  catch (const std::invalid_argument& ia) {
	  		std::cerr << "Invalid argument in selection: " << ia.what() << '\n';
  		}	

		switch(choice){
			case STATS: 
				printf("Chose to print player stats\n");
				coinMaster.printStats();
				break;
			case SPIN: 
				printf("Chose to spin.\n");
				coinMaster.spin();
				cin.clear();
				break;
			case SHOP:
				printf("Chose to shop.\n");
				cout << "Which one do you want to upgrade:\n" <<
					"1. House\n" <<
					"2. Statue\n" <<
					"3. Garden\n" << 
					"4. Farm\n" <<
					"5. Boat\n";
				getline(cin, temp2);
			    try{
		  			choice2 = stoi(temp2, &sz2);
			    }  catch (const std::invalid_argument& ia) {
			  		std::cerr << "Invalid argument: " << ia.what() << '\n';
		  		}	
				if(choice2 == 1) coinMaster.upgradeVillageHouse();
				else if(choice2 == 2) coinMaster.upgradeVillageStatue();
				else if(choice2 == 3) coinMaster.upgradeVillageGarden();
				else if(choice2 == 4) coinMaster.upgradeVillageFarm();
				else if(choice2 == 5) coinMaster.upgradeVillageBoat();
				else{
					cout << "No Option Choosen" << endl;
				}
				break;
			case INFO: 
				printf("Chose to see info.\n");
				coinMaster.getVillageInfo();
				break;
			case EXIT:
				printf("Chose to quit.\n");
				onGoing = false;
				break;
			default:
				printf("Not chosen anything\n");
		}

		if(coinMaster.isVillageAttacked() && coinMaster.getNumOfCoins() > 10000){ // village was attacked
			string attacker = coinMaster.getAttacker();
			cout << string(15, '*') << "Your village was attacked by " << attacker << string(15, '-') <<  endl;
			if(coinMaster.isSheildLeft()){
				coinMaster.sheildDecrease();
				cout << "One sheild was used to defend" << endl;
			}
			else{
				int raided = (rand() % (int)(coinMaster.getNumOfCoins()/3));
				cout << raided << " amount of coins were stolen" << endl;
				cout << "Find sheilds to defend yourself" << endl;
			}
		}

		if(coinMaster.getNumOfSpins_left() == 0 and !isTimerRunning){ // run timer if already not running and coins are zero
			isTimerRunning = true;
			time_t current_time;
			current_time = time(NULL);
			cout << "You will get new coins in 60 seconds" << endl;
			timer_started_at = current_time;
		}
		else if(isTimerRunning){
			time_t current_time;
			current_time = time(NULL);
			time_t interval = 60 - (current_time - timer_started_at);		
			if(interval < 0){
				coinMaster.giveNewSpins();
				cout << "New spins are given";
				isTimerRunning = false;
			}else{
				cout << string(15, '-') << interval << " seconds remaining till player gets new spins" << string(15, '-') << endl;
			}
 		}
	}

	return 0;
}

