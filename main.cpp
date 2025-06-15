/**
 * Minecraft shop script for managing a scoreboard based shop system.
 * Made by Dylan Beppu
 */


#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>


std::string SCOREBOARD_VALUE = "Money";
std::string ERROR_COLOR = "§c";
std::string SUCCESS_VALUE = "§a";


std::string BuyItem(std::string array[4]);
std::string SellItem(std::string array[4]);


int main(int argc, char* argv[]) {
    // if (argc != 2) {
    //     std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
    //     return 1;
    // }

    // std::string argument = argv[1];
    // std::cout << "Argument received: " << argument << std::endl;
	//TODO: strip file extention and formate it as *_script.txt

	//TODO: remove for deployment
	std::string shopName = "list.csv";


	// Open the file in read mode
    std::ifstream csvFile;

	csvFile.open(shopName);

    if (!csvFile.is_open()) {
        std::cerr << "Error: Could not open file: " << shopName << std::endl;
        return 1;
    }

    std::ofstream scriptFile;
	scriptFile.open("script.txt");

	if (!scriptFile.is_open()) {
		std::cerr << "Error: Could not create file: shop.csv" << std::endl;
		return 1;
	}

	// Read the contents of the CSV file and write to the script file
	std::string line;
	std::getline(csvFile, line); // Read the header line and ignore it
	
	
	while (std::getline(csvFile, line)) {	
		
		// Split the line by commas into a array
		std::string array[4];
		std::string currSub;
		size_t commasFound = 0;

		for(size_t i = 0; i < line.length(); i++) {	
			if (line[i] == ',') {
				array[commasFound] = currSub;
				commasFound++;
				currSub="";

			} else if(line[i] == ' ') {
				//Do nothing, ignore white space
			
			} else {
				currSub += std::tolower(static_cast<unsigned char>(line[i]));
			
			}
		}

		//Should be last, so shove the rest into the last part
		array[commasFound] = currSub;
	


		for(size_t i = 0; i < 4; i++) {
			std::cout << array[i] << std::endl;
		}


		if (array[1] == "buy") {
			scriptFile << BuyItem(array);
		}




	}

	// Close the script file
	scriptFile.close();
    csvFile.close();



    return 0;
}



std::string BuyItem(std::string array[4]) {
	std::stringstream retStream;
	int lowVal = std::stoi(array[2]) - 1;
	retStream << "\t" << array[0] << " - Buy" << std::endl;
	retStream <<  "/tell @initiator[scores={" << SCOREBOARD_VALUE << "=.." << lowVal << "}] " << ERROR_COLOR << "Not enough " << SCOREBOARD_VALUE << "§f" << std::endl;
// 	"/tell @initiator[scores={Money=..99}] §cNot enough money§f
	retStream <<  "/playsound mob.villager.no @initiator[scores={" << SCOREBOARD_VALUE << "=.." << lowVal << "}]"<< std::endl;

// 	/playsound mob.villager.no @initiator[scores={Money=..99}]
	retStream <<  "/give @initiator[scores={" << SCOREBOARD_VALUE << "=" << array[2] << "}] " <<  array[0] <<  " " << array[3] << std::endl;

// /give @initiator[scores={Money=100..}] iron_ingot 10

	retStream <<  "/tell @initiator[scores={" << SCOREBOARD_VALUE << "=" << array[0] << "..}] " << SUCCESS_VALUE << array[3] << " " << array[0] << " recieved§f" << std::endl;

// /tell @initiator[scores={Money=100..}] §a10 iron recieved§f
// /playsound mob.villager.yes @initiator[scores={Money=100..}]
	retStream <<  "/playsound mob.villager.yes @initiator[scores={" << SCOREBOARD_VALUE << "=" << array[2] << "..}]" << std::endl;
// /scoreboard players remove @initiator[scores={Money=100..}] Money 100"
		retStream <<  "/scoreboard players remove @initiator[scores={" << SCOREBOARD_VALUE << "=" << array[2] << "..}] " << SCOREBOARD_VALUE << " " << array[2] << std::endl;

	retStream << std::endl << std::endl;
	return retStream.str();

}


//TODO: do this part
std::string SellItem(std::string array[4]) {
	std::string retStr = "";

	return retStr;
}





