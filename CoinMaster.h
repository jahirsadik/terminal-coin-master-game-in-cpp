#include<bits/stdc++.h>
#include"Village.h"
using namespace std;

class CoinMaster{

private:
	string current_player_name;
	Village village;
	double current_coins = 0.00;
	int spins_left = 10;
	vector<string> spin_objects;
	stack<int> coins_for_farm;
	queue<int> coins_for_boat;

	// Enumeration to store the needed coins for each levels
	enum CoinNeeded {  
	LEVEL2 = 20'000,
	LEVEL3 = 75'000,
	LEVEL4 = 150'000,
	LEVEL5 = 250'000
	};

	// Enumeration to store the values 0,1,2.. corresponding to COIN, HAMMER, SHEILD..
	enum SpinObjects{ 
		COIN,
		HAMMER,
		SHEILD,
		BOX,
		MEDICINE,
		PIG
	};

	string attackers[10] = {"ALVEE", "MONON", "RAFID", "AZMOL", "MAHIN", "AKASH", "ASIF", "NAHIAN", "PRINCE", "ASHIK"};
	string defenders[10] = {"SHAKIL", "TASHSIN", "REZAUL", "MIFTAUL", "PARABAR", "SHIHAB", "ZAHIN", "KOWSHIK", "SHADMAN", "NAFIS"};


public:

	CoinMaster(string player_name): village(player_name){
		printStats();
		spin_objects.push_back("COIN");
		spin_objects.push_back("HAMMER");
		spin_objects.push_back("SHEID");
		spin_objects.push_back("BOX");
		spin_objects.push_back("MEDICINE");
		spin_objects.push_back("PIG");

		coins_for_farm.push(255'000); // implemented using a stack, so last one is pushed first
		coins_for_farm.push(155'000);
		coins_for_farm.push(75'500);
		coins_for_farm.push(25'000);

		coins_for_boat.push(22'500); // implemented using a queue, so first one is pushed first
		coins_for_boat.push(79'600);
		coins_for_boat.push(151'000);
		coins_for_boat.push(249'800);
	}

	double getNumOfCoins(){
		return current_coins;
	}

	int getNumOfSpins_left(){
		return spins_left;
	}

	void giveNewSpins(){
		spins_left += 10;
	}

	bool isSheildLeft(){
		return (village.total_number_of_sheilds > 0);
	}

	void printStats(){
		cout << string(15, '-') << "Current Player Statistics" << string(15, '-') << endl;
		cout << "Total coins: " << current_coins << endl;
		cout << "Total Spins left: " << spins_left << endl << endl;
	}

	void getVillageInfo(){
		village.villageInfo();
	}

	void sheildDecrease(){
		village.total_number_of_sheilds--;
	}

	// spin functions

	void spin(){
		if(!spins_left){
			cout << "No spins are left" << endl;
		}
		else{
			spins_left--;
			cin.clear();

			int slot1, slot2, slot3;
			cout << "Press ENTER to spin slot1" << endl;
			std::cin.ignore();
			cout << "SPINNING..." << endl;
			slot1 = rand() % 6;
			cout << "Slot 1: " << spin_objects[slot1] << endl;
			cout << "Press ENTER to spin slot2" << endl;
			std::cin.ignore();
			slot2 = rand() % 6;
			cout << "Slot 2: " << spin_objects[slot2] << endl;
			// Increase probability
			cout << "Press ENTER to spin slot3" << endl;
			std::cin.ignore();

			if(slot1 == 2 and slot2 == 2){
				int temp = rand()%1; // Can increase probability of a combo by changing this
				if(temp == 0){
					slot3 = 2;
				}
				else{
					slot3 = rand() % 6;
				}
			}
			else{
				slot3 = rand() % 6;
			}

			if(slot1 == 1 and slot2 == 1){
				int temp = rand()%2; // Can increase probability of a combo by changing this
				if(temp == 0){
					slot3 = 1;
				}
				else{
					slot3 = rand() % 6;
				}
			}
			else{
				slot3 = rand() % 6;
			}
			if(slot1 == 3 and slot2 == 3){
				int temp = rand()%2; // Can increase probability of a combo by changing this
				if(temp == 0){
					slot3 = 3;
				}
				else{
					slot3 = rand() % 6;
				}
			}
			else{
				slot3 = rand() % 6;
			}
			if(slot1 == 5 and slot2 == 5){
				int temp = rand()%2; // Can increase probability of a combo by changing this
				if(temp == 0){
					slot3 = 5;
				}
				else{
					slot3 = rand() % 6;
				}
			}
			else{
				slot3 = rand() % 6;
			}

			cout << "Slot 3: " << spin_objects[slot3] << endl;
			vector<int> arr(6);
			arr[slot1]++;
			arr[slot2]++;
			arr[slot3]++;
			int max_elem = *max_element(arr.begin(), arr.end()); 
			
			if(max_elem == 3 and slot1 == 0) // COIN
			{
				current_coins += 20'000;
				cout << "20,000 coins gained" << endl;
			}
			else if(max_elem == 3 and slot1 == 1) // HAMMER
			{
				cout << "GOT ONE HAMMER COMBO. ATTACKING " << getAttacker() <<"'s VILLAGE" << endl;
				int gift = rand() % (int)current_coins;
				current_coins += gift;
				cout << "Got " << gift << " coins." << endl;

			}
			else if(max_elem == 3 and slot1 == 2) // SHEILD
			{
				cout << "GOT ONE SHEILD" << endl;
				cout << "-- You can stop attacks on your village using sheilds --" << endl;
				if(village.total_number_of_sheilds < 3){
					village.total_number_of_sheilds++;
				}else{
					cout << "Maximum sheild capacity reached!" << endl;
				}
			}
			else if(max_elem == 3 and slot1 == 3) // BOX
			{
				current_coins += 35'000;
				cout << "35,000 coins gained" << endl;
			}
			else if(max_elem == 3 and slot1 == 4) // MEDICINE
			{
				cout << "GOT ONE MEDICINE" << endl;
				cout << "-- You can heal your village using medicines if it was attacked --" << endl;
			}
			else if(max_elem == 3 and slot1 == 5) // PIG
			{
				cout << "COIN MASTER COMBO" << endl;
				cout << "Attacking the coin masters house" << endl;
				// coin master house attack
				coinMasterHouseAttack();
			}
			else{
				if(max_elem == 1){
					int gain = 2'000 + (rand() % 1'500);
					current_coins += gain;
					cout << gain << " coins gained" << endl;
				}
				else if(max_elem == 2){
					int gain = 10'000 + (rand() % 5'500);
					current_coins += gain;
					cout << gain <<" coins gained" << endl;
				}
			}
		}
	}



	void upgradeVillageHouse(){
		int cur_level = village.house_level;
		if(cur_level == 5){
			cout << "Max House level reached!" << endl;
		}
		else{
			double coinsNeeded = 0;
			switch(cur_level){
				case 1:
					coinsNeeded = LEVEL2;
					break;
				case 2:
					coinsNeeded = LEVEL3;
					break;
				case 3:
					coinsNeeded = LEVEL4;
					break;
				case 4:
					coinsNeeded = LEVEL5;
					break;
				default:
					cout << "Error occured, upgradeVillageHouse()" << endl;
			}
			cout << "Coins needed for the upgrade: " << coinsNeeded << endl;
			if(current_coins < coinsNeeded){
				cout << "Not enough coins for the upgrade" << endl;
			}
			else{
				current_coins -= coinsNeeded;
				village.house_level++;
				cout << "Successfully upgraded the village house to Level " << ++cur_level << endl;
			}
		}
	}


	void upgradeVillageStatue(){
		int cur_level = village.statue_level;
		if(cur_level == 5){
			cout << "Max Statue level reached!" << endl;
		}
		else{
			double coinsNeeded = 0;
			switch(cur_level){
				case 1:
					coinsNeeded = LEVEL2;
					break;
				case 2:
					coinsNeeded = LEVEL3;
					break;
				case 3:
					coinsNeeded = LEVEL4;
					break;
				case 4:
					coinsNeeded = LEVEL5;
					break;
				default:
					cout << "Error occured, upgradeVillageStatue()" << endl;
			}
			cout << "Coins needed for the upgrade: " << coinsNeeded << endl;
			if(current_coins < coinsNeeded){
				cout << "Not enough coins for the upgrade" << endl;
			}
			else{
				current_coins -= coinsNeeded;
				village.statue_level++;
				cout << "Successfully upgraded the village statue to Level " << ++cur_level << endl;
			}
		}
	}

	void upgradeVillageGarden(){
		int cur_level = village.garden_level;
		if(cur_level == 5){
			cout << "Max Garden level reached!" << endl;
		}
		else{
			double coinsNeeded = 0;
			switch(cur_level){
				case 1:
					coinsNeeded = LEVEL2;
					break;
				case 2:
					coinsNeeded = LEVEL3;
					break;
				case 3:
					coinsNeeded = LEVEL4;
					break;
				case 4:
					coinsNeeded = LEVEL5;
					break;
				default:
					cout << "Error occured, upgradeVillageGarden()" << endl;
			}
			cout << "Coins needed for the upgrade: " << coinsNeeded << endl;
			if(current_coins < coinsNeeded){
				cout << "Not enough coins for the upgrade" << endl;
			}
			else{
				current_coins -= coinsNeeded;
				village.garden_level++;
				cout << "Successfully upgraded the village garden to Level " << ++cur_level << endl;
			}
		}
	}


	// These two functions are implemented using stacks
	void upgradeVillageFarm(){
		int cur_level = village.farm_level;
		if(cur_level == 5){
			cout << "Max Farm level reached!" << endl;
		}
		else{
			double coinsNeeded = coins_for_farm.top();
			cout << "Coins needed for the upgrade: " << coinsNeeded << endl;
			if(current_coins < coinsNeeded){
				cout << "Not enough coins for the upgrade" << endl;
			}
			else{
				current_coins -= coinsNeeded;
				village.farm_level++;
				coins_for_farm.pop();
				cout << "Successfully upgraded the village Farm to Level " << ++cur_level << endl;
			}			
		}
	}


	void upgradeVillageBoat(){
		int cur_level = village.boat_level;
		if(cur_level == 5){
			cout << "Max Boat level reached!" << endl;
		}
		else{
			double coinsNeeded = coins_for_boat.front();
			cout << "Coins needed for the upgrade: " << coinsNeeded << endl;
			if(current_coins < coinsNeeded){
				cout << "Not enough coins for the upgrade" << endl;
			}
			else{
				current_coins -= coinsNeeded;
				village.boat_level++;
				coins_for_boat.pop();
				cout << "Successfully upgraded the village Boat to Level " << ++cur_level << endl;
			}	
		}
	}

	bool isVillageAttacked(){
		return ((rand() % 100) < 10); // 10% chance of village being attacked
	}

	string getAttacker(){
		int index = rand() % 10;
		return attackers[index];
	}

	string getDefender(){
		int index = rand() % 10;
		return defenders[index];
	}

	void coinMasterHouseAttack(){
		cout << "What parts do you want to attack. You can attack two parts. First choose one -\n" << 
				"1. House\n2. Farm\n3. Garden\n4. Statue\n5. Boat\n";
		int a, b, temp1, temp2, temp3;
		temp1 = rand()%6;
		temp2 = rand()%6;
		temp3 = rand()%6;
		scanf("%d", &a);
		if(a == temp1 || a == temp2 || a == temp3){
			int gift = (rand() % 20'000) + 20'000;
			current_coins += gift;
			cout << "Got " << gift << " coins." << endl;
		}
		else{
			cout << "No coins found in that part" << endl;
		}
		cout << "Choose another part to attack" << endl;
		scanf("%d", &b);
		while(a == b){
			cout << "Choose another part to attack" << endl;
			scanf("%d", &b);
		}
		if(b == temp1 || b == temp2 || b == temp3){
			int gift = (rand() % 20'000) + 20'000;
			current_coins += gift;
			cout << "Got " << gift << " coins." << endl;
		} 
		else{
			cout << "No coins found in that part" << endl;
		}
		cin.clear();
	}
};

