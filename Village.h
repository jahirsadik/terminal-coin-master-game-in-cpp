#include<bits/stdc++.h>
using namespace std;

class Village{

private:
	string village_owner;
	

public:
	int house_level, statue_level, garden_level, farm_level, boat_level; // upto five levels
	int total_number_of_sheilds;
	
	Village(string player_name){
		village_owner = player_name;
		cout << "New Village Created." << endl;
		
		// Setting up initial village levels
		house_level = 1;
		statue_level = 1;
		garden_level = 1;
		farm_level = 1;
		boat_level = 1;
		total_number_of_sheilds = 0;
		villageInfo();
	}

	void villageInfo(){
	   	cout << string((100 - strlen("Village Info"))/2, '-') << "Village Info" << string((100 - strlen("Village Info"))/2, '-') << endl;
	   	cout << "Owner Name: " << village_owner << endl;
		cout << string(10, ' ') << "House Level: " << house_level << endl;
		cout << string(10, ' ') << "Statue Level: " << statue_level << endl;
		cout << string(10, ' ') << "Garden Level: " << garden_level << endl;
		cout << string(10, ' ') << "Farm Level: " << farm_level << endl;
		cout << string(10, ' ') << "Boat Level: " << boat_level << endl;
		cout << string(10, ' ') << "Total Number of sheilds: " << total_number_of_sheilds << endl;
	}

};


