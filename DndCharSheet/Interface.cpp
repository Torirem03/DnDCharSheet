//Liz Hinton
//2-12-24
//eahinton@dmacc.edu
//This program will be the interface for interacting with the character sheet class. This will include the ability to create, edit, save, and view character sheets.
//All input will be validated or tell the user that the input is invalid.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctype.h>
#include "charSheet.h"
using namespace std;

class interface{
	//variables
	//active character sheet
	characterSheet activeCharSheet;
	//array that stores character sheets
	vector<characterSheet> savedCharSheets;
	//main menu input string
	int menuInput;
	//other input string
	string otherInput;
	//temp variables
	string tempName;
	string tempPlayer;
	int tempStr;
	int tempCon;
	int tempDex;
	int tempCha;
	int tempInt;
	int tempWis;
	int tempLevel;
	int tempAge;
	string tempGender;
	string tempHeight;
	string tempWeight;
	string tempSkin;
	string tempHair;
	
	//contructors
	//default no args contructor
	interface(){
		activeCharSheet = new characterSheet();
	}
	
	//getters
	
	//setters
	
	//methods
	//create character sheet
    createCharSheet(){
		//name character
		cout << "enter a name for your character" << endl;
		cin >> tempName;
		//valid input loop
        //while (isdigit(tempName){
			//name character until valid input
            //cout << "invalid input detected, please make sure your name has a letter" << endl;
            //cin >> tempName;
        //}
		//pick class: artificer, barbarian, bard
		cout << "pick a class:" << endl;
		cout << "1: artificer " << endl;
		cout << "2: barbarian " << endl;
		cout << "3: bard      " << endl;
		cin >> otherInput; //fix once char sheet is complete
		//valid input loop
        while (stoi(otherInput) > 3 || stoi(otherInput) < 1){
			//pick class until valid input
			cout << "invalid input, pick a class:" << endl;
			cout << "1: artificer " << endl;
			cout << "2: barbarian " << endl;
			cout << "3: bard      " << endl;
			cin >> otherInput; //fix once char sheet is complete
		}
		//pick race
		cout << "pick a race:" << endl;
		cout << "1: elf      " << endl;
		cout << "2: dwarf    " << endl;
		cout << "3: human    " << endl;
		cin >> otherInput; //fix once char sheet is complete
		//valid input loop
        while (stoi(otherInput) > 3 || stoi(otherInput) < 1){
			//pick race until valid input
			cout << "invalid input, pick a race:" << endl;
			cout << "1: elf      " << endl;
			cout << "2: dwarf    " << endl;
			cout << "3: human    " << endl;
			cin >> otherInput; //fix once char sheet is complete
		}
		//pick background
		cout << "pick a background:" << endl;
		cout << "1: noble          " << endl;
		cout << "2: acolyte        " << endl;
		cout << "3: sailor         " << endl; 
		cin >> otherInput; //fix once char sheet is complete
		//valid input loop
        while(stoi(otherInput) > 3 || stoi(otherInput) < 1){
			//pick background until valid input
			cout << "invalid input, pick a background:" << endl;
			cout << "1: noble          " << endl;
			cout << "2: acolyte        " << endl;
			cout << "3: sailor         " << endl;
			cin >> otherInput; //fix once char sheet is complete
		}
		//enter strength
		cout << "enter a number 1-20 for your strength score: " << endl;
        cin >> tempStr;
		//valid input loop
		while (tempStr > 20 || tempStr < 1){
			//enter strength until valid input
			cout << "invalid input, please enter a number 1-20 for your strength:" << endl;
            cin >> tempStr;
		}
		//enter dexterity
		cout << "enter a number 1-20 for your dexterity score: " << endl;
        cin >> tempDex;
		//valid input loop
		while (tempDex > 20 || tempDex < 1){
			//enter dexterity until valid input
			cout << "invalid input, please enter a number 1-20 for your dexterity:" << endl;
            cin >> tempDex;
		}
		//enter charisma
		cout << "enter a number 1-20 for your charisma: " << endl;
        cin >> tempCha;
		//valid input loop
		while (tempCha > 20 || tempCha < 1){
			//enter charisma until valid input
			cout << "invalid input, please enter a number 1-20 for your charisma:" << endl;
            cin >> tempCha;
		}
		//enter intelligence
		cout << "enter a number 1-20 for your intelligence: " << endl;
        cin >> tempInt;
		//valid input loop
		while(tempInt > 20 || tempInt < 1){
			//enter intelligence until valid input
			cout << "invalid input, please enter a number 1-20 for your intelligence:" << endl;
            cin >> tempInt;
		}
		//enter wisdom
		cout << "enter a number 1-20 for your wisdom: " << endl;
        cin >> tempWis;
		//valid input loop
		while(tempWis > 20 || tempWis < 1){
			//enter wisdom until valid input
			cout << "invalid input, please enter a number 1-20 for your wisdom:" << endl;
            cin >> tempWis;
		}
		//enter constitution
		cout << "enter a number 1-20 for your constitution: " << endl;
        cin >> tempCon;
		//valid input loop
		while (tempCon > 20 || tempCon < 1){
			//enter constitution until valid input
			cout << "invalid input, please enter a number 1-20 for your constitution:" << endl;
            cin >> tempCon;
		}
		//enter player name
		cout << "enter player name: " << endl;
		cin >> tempPlayer;
		//valid input loop
        //while (isdigit(tempPlayer)){
			//enter player name until valid input
            //cout << "error, please make sure your name has a letter"
            //cin >> tempPlayer;
        //}
		//enter level 
		cout << "enter your level(1-20): " << endl;
        cin >> tempLevel;
		//valid input loop
		while(tempLevel > 20 || tempLevel < 1){
			//enter level until valid input
            cout << "error, please enter a level 1-20:" << endl;
            cin >> tempLevel;
		}
	}
		
	//edit character sheet
	editCharSheet(){
		//output menu to ask user what they would like to edit
		cout << "what would you like to edit?" << endl;
		cout << "1: character name           " << endl;
		cout << "2: class                    " << endl;
		cout << "3: race                     " << endl;
		cout << "4: background               " << endl;
		cout << "5: strength                 " << endl;
		cout << "6: dexterity                " << endl;
		cout << "7: charisma                 " << endl;
		cout << "8: intelligence             " << endl;
		cout << "9: wisdom                   " << endl;
		cout << "10: constitution            " << endl;
		cout << "11: player name             " << endl;
		cout << "12: level                   " << endl;
		cout << "13: age                     " << endl;
		cout << "14: gender                  " << endl;
		cout << "15: height                  " << endl;
		cout << "16: weight                  " << endl;
		cout << "17: skin color              " << endl;
		cout << "18: hair color              " << endl;
		//input from user
		cin >> otherInput;
		//big if tree to edit various things based on input
		//if edit name
		if(otherInput == "1"){
			//output asking for new name
			cout << "enter a new name for your character" << endl;
			//input from user
			cin >> tempName;
			//valid input loop
            //while (isdigit(tempName)){
				//name character until valid input
            //	cout << "invalid input detected, please make sure your name has a letter" << endl;
            //	cin >> tempName;
            // }
			//set name to new value
			activeCharSheet.setName(tempName);
		//else if edit class
		} else if(otherInput == "2"){
			//pick new class
			cout << "pick a new class:" << endl;
			cout << "1: artificer " << endl;
			cout << "2: barbarian " << endl;
			cout << "3: bard      " << endl;
			cin >> otherInput;
			//valid input loop
            while (stoi(otherInput) > 3 || stoi(otherInput) < 1){
				//pick class until valid input
				cout << "invalid input, pick a class:" << endl;
				cout << "1: artificer " << endl;
				cout << "2: barbarian " << endl;
				cout << "3: bard      " << endl;
				cin >> otherInput;
			}
			//set class to new value
			//add once char sheet is finished
		//else if edit race
		} else if(otherInput == "3"){
			//pick new race
			cout << "pick a new race:" << endl;
			cout << "1: elf      " << endl;
			cout << "2: dwarf    " << endl;
			cout << "3: human    " << endl;
			cin >> otherInput;
			//valid input loop
            while (stoi(otherInput) > 3 || stoi(otherInput) < 1){
				//pick race until valid input
				cout << "invalid input, pick a race:" << endl;
				cout << "1: elf      " << endl;
				cout << "2: dwarf    " << endl;
				cout << "3: human    " << endl;
				cin >> otherInput;
			}
			//set race to new value
			//add once char sheet is finished
		//else if edit background
		} else if(otherInput == "4"){
			//pick new background
			cout << "pick a new background:" << endl;
			cout << "1: noble          " << endl;
			cout << "2: acolyte        " << endl;
			cout << "3: sailor         " << endl; 
			cin >> otherInput;
			//valid input loop
            while(stoi(otherInput) > 3 || stoi(otherInput) < 1){
				//pick background until valid input
				cout << "invalid input, pick a background:" << endl;
				cout << "1: noble          " << endl;
				cout << "2: acolyte        " << endl;
				cout << "3: sailor         " << endl;
				cin >> otherInput;
			}
			//set background to new value
			//add once char sheet is finished
		//else if edit strength
		} else if(otherInput == "5"){
			//enter new strength
			cout << "enter a number 1-20 for your new strength score: " << endl;
            cin >> tempStr;
			//valid input loop
			while (tempStr > 20 || tempStr < 1){
				//enter strength until valid input
				cout << "invalid input, please enter a number 1-20 for your strength:" << endl;
                cin >> tempStr;
			}
			//set strength to new value
            activeCharSheet.setStrength(tempStr);
		//else if edit dex
		} else if (otherInput == "6"){
			//enter new dex
			cout << "enter a number 1-20 for your new dexterity score: " << endl;
            cin >> tempDex;
			//valid input loop
			while (tempDex > 20 || tempDex < 1){
				//enter dexterity until valid input
				cout << "invalid input, please enter a number 1-20 for your dexterity:" << endl;
                cin >> tempDex;
			}
			//set dex to new value
            activeCharSheet.setDexterity(tempDex);
		//else if edit cha
		} else if(otherInput == "7"){
			//enter new cha
			cout << "enter a number 1-20 for your charisma: " << endl;
            cin >> tempCha;
			//valid input loop
			while (tempCha > 20 || tempCha < 1){
				//enter charisma until valid input
				cout << "invalid input, please enter a number 1-20 for your charisma:" << endl;
                cin >> tempCha;
			}
			//set cha to new value
            activeCharSheet.setCharisma(tempCha);
		//else if edit int
		} else if(otherInput == "8"){
			//enter new int
			cout << "enter a number 1-20 for your intelligence: " << endl;
            cin >> tempInt;
			//valid input loop
			while(tempInt > 20 || tempInt < 1){
				//enter intelligence until valid input
				cout << "invalid input, please enter a number 1-20 for your intelligence:" << endl;
                cin >> tempInt;
			}
			//set int to new value
			activeCharSheet.setInt(tempInt);
		//else if wis
		} else if(otherInput == "9"){
			//enter new wis
			cout << "enter a number 1-20 for your wisdom: " << endl;
            cin >> tempWis;
			//valid input loop
			while(tempWis > 20 || tempWis < 1){
				//enter wisdom until valid input
				cout << "invalid input, please enter a number 1-20 for your wisdom:" << endl;
                cin >> tempWis;
			}
			//set wis to new value
            activeCharSheet.setWisdom(tempWis);
		//else if con
		} else if(otherInput == "10"){
			//enter new con
			cout << "enter a number 1-20 for your constitution: " << endl;
            cin >> tempCon;
			//valid input loop
			while (tempCon > 20 || tempCon < 1){
				//enter constitution until valid input
				cout << "invalid input, please enter a number 1-20 for your constitution:" << endl;
                cin >> tempCon;
			}
			//set con to new value
            activeCharSheet.setConstitution(tempCon);
		//else if player name
		} else if(otherInput == "11"){
			//enter player name
			cout << "enter player name: " << endl;
			cin >> tempPlayer;
			//valid input loop
            //while (isDigit(tempPlayer)){
				//enter player name until valid input
                //cout << "error, please make sure your name has a letter"
            //	cin >> tempPlayer;
            //}
			//set player name to new value
            activeCharSheet.setPlayerName(tempPlayer);
		//else if level
		} else if(otherInput == "12"){
			//enter level
			cout << "enter your level(1-20): " << endl;
            cin >> tempLevel;
			//valid input loop
			while(tempLevel > 20 || tempLevel < 1){
				//enter level until valid input
                cout << "error, please enter a level 1-20:" << endl;
                cin >> tempLevel;
			}
			//set level to new value
			activeCharSheet.setLevel(tempLevel);
		//else if age
		} else if(otherInput == "13"){
			//enter age
			cout << "enter your characters age: " << endl;
            cin >> tempAge;
			//set age to new value
			activeCharSheet.setAge(tempAge);
		//else if gender
		} else if(otherInput == "14") {
			//enter gender
			cout << "enter your characters gender: " << endl;
			cin >> tempGender;
			//valid input loop
            //while (isDigit(tempGender)){
				//enter gender until valid input
                //cout << "error, please make sure your gender has a letter"
                //cin >> tempGender;
            //}
			//set gender to new value
			activeCharSheet.setGender(tempGender);
		//else if height
		} else if(otherInput == "15") {
			//enter height
			cout << "enter your characters height: " << endl;
			cin >> tempHeight;
			//valid input loop
            //while (isDigit(tempHeight)){
				//enter height until valid input
                //cout << "error, please make sure your height has a unit (ex. feet, meters)"
                //cin >> tempHeight;
            //}
			//set height to new value
			activeCharSheet.setHeight(tempHeight);
		//else if weight
		} else if(otherInput == "16"){
			//enter weight
			cout << "enter your characters weight: " << endl;
			cin >> tempWeight;
			//valid input loop
            //while (isDigit(tempWeight)){
				//enter weight until valid input
                //cout << "error, please make sure your weight has a unit (ex. pounds, kilograms)"
                //cin >> tempWeight;
            //}
			//set weight to new value
			activeCharSheet.setWeight(tempWeight);
		//else if skin
		} else if(otherInput == "17"){
			//enter skin
			cout << "enter your characters skin color: " << endl;
			cin >> tempSkin;
			//valid input loop
            //while (isDigit(tempSkin)){
				//enter skin until valid input
                //cout << "error, please make sure your skin color has a letter"
                //cin >> tempSkin;
            //}
			//set skin to new value
			activeCharSheet.setSkin(tempSkin);
		//else if hair
		} else if(otherInput == "18"){
			//enter hair
			cout << "enter your characters hair color: " << endl;
			cin >> tempHair;
			//valid input loop
            //while (isDigit(tempHair)){
				//enter gender until valid input
                //cout << "error, please make sure your hair color has a letter"
                //cin >> tempHair;
            //}
			//set hairr to new value
            activeCharSheet.setHairColor(tempHair);
		} else {
            cout << "error, invalid input recieved, redirecting to main menu";
        }
	}
		
		
	//clear character sheet
	clearCharSheet(){
		//overwrites current character sheet with the default
        activeCharSheet = new characterSheet();
	}
		
		
	//save character sheet
	saveCharSheet(){
		//saves active character sheet to vector
		int index;
		//if vector is empty
		if (savedCharSheets.empty()){
			//add character sheet to vector
		} else {
			//for loop to go through vector elements
            for (int i = 0; i < savedCharSheets.size(); i++)
				//if character name, class, and level of active character sheet matches the current vector entry
				if (savedCharSheets[i].name == activeCharSheet.name && savedCharSheets[i].dndClass == activeCharSheet.dndClass && savedCharSheets[i].level == activeCharSheet.level){
					matchingChar = true;
					index = i;
				}
			//if matchingChar is false
			if(matchingChar == false){
				//add character sheet to vector
				savedCharSheets.append(activeCharSheet);
			} else {
				//overwrite matching vector entry with new data
				savedCharSheets[index] = activeCharSheet;
			}
		}
	}
		
		
	//view current character sheet
	viewCurrentCharSheet(){
		//outputs info from the current character sheet using print sheet
		activeCharSheet.printSheet();
	}
		
		
	//view all saved character sheets
	viewAllCharSheets(){
		//outputs all saved character sheets
		//for loop to go through every entry in vector
        for(int i = 0; i < savedCharSheets.size(); i++){
			//output character sheet
			savedCharSheets[i].printSheet();
		}
	}
		
	//load character sheet
	loadCharSheet(){
		//finds a character sheet in the vector based on input and sets it as the active character sheet
		//user input for name class and level
        cout << "enter name of the character you'd like to find";
		cin >> tempName;
        cout << "enter class of the character you'd like to find";
        string tempClass;
		cin >> tempClass;
        cout << "enter level of the character you'd like to find";
		cin >> tempLevel;
		//for loop to go through vector
		for (int i = 0; i < savedCharSheets.size(); i++)
			//if current entry has the same name class race and level as the inputs
            if(savedCharSheets[i].getName() == tempName || savedCharSheets[i].getDndClass() == tempClass || savedCharSheets[i].getLevel() == tempLevel){
				//set current entry to active character sheet
				activeCharSheet == savedCharSheets[i];
			}
	}
	
				
	//start method
	start(){
		//if there is a csv from previously running this program, it will be loaded into the vector
		//if csv exists
		ifstream charSheetCsv;
   		charSheetCsv.open("characterSheets.csv");
		if (charSheetCsv){
			//set vector to parsed csv
			savedCharSheets = characterSheet::parseCSV("characterSheets.csv");
		}
	}
		
	
	//end method
	end(){
		//save the vector to a csv so that it can be loaded later
		//if the vector is not empty and csv exists
		ifstream charSheetCsv;
   		charSheetCsv.open("characterSheets.csv");
        if(!savedCharSheets.empty() && charSheetCsv){
			//save the vector to the csv, overwriting the previous data
			charSheetCsv << savedCharSheets;
		//else if the vector is not empty and csv doesnt exist
        } else if(!savedCharSheets.empty() && !charSheetCsv){
			//create the csv
			ofstream charSheetCsv("characterSheets.csv");
			//save the vector to the csv
			charSheetCsv << savedCharSheets;
		}
	}
	
	
	//run interface
	runInterface(){
		//starter method
		start();
		//output menu of options
		cout << "enter the number of what menu option you would like, or q to quit" << endl;
		cout << "1: create a new character sheet (note: this will overwrite the current character sheet, if you havent saved it the information will be lost)" << endl;
		cout << "2: edit the current character sheet" << endl;
		cout << "3: clear the current character sheet" << endl;
		cout << "4: view current character sheet" << endl;
		cout << "5: view all saved character sheets" << endl;
		cout << "6: load a character sheet (note: this will overwrite the current character sheet)" << endl;
		cout << "7: save current character sheet" << endl;
		//user input
		cin >> menuInput;
		//while input is not q
		while(menuInput != "q"){
			//if create char sheet
			if(menuInput == "1"){
				//create char sheet
				createCharSheet();
			//else if edit
			} else if(menuInput == "2"){
				//edit char sheet
				editCharSheet();
			//else if clear
			} else if(menuInput == "3"){
				//clear char sheet
				clearCharSheet();
			//else if view active
			} else if(menuInput == "4"){
				//view active char sheet
				viewCurrentCharSheet();
			//else if view all
			} else if(menuInput == "5"){
				//view all char sheets
				viewAllCharSheets();
			//else if load
			} else if (menuInput == "6"){
				//load char sheet
				loadCharSheet();
			//else if save	
			} else if(menuInput == "7"){
				//save char sheet
				saveCharSheet();
			//else
			} else {
				//print error
				cout << "error, invalid menu option chosen, please pick again"
			}
			//output menu again
			cout << "enter the number of what menu option you would like, or q to quit" << endl;
			cout << "1: create a new character sheet (note: this will overwrite the current character sheet, if you havent saved it the information will be lost)" << endl;
			cout << "2: edit the current character sheet" << endl;
			cout << "3: clear the current character sheet" << endl;
			cout << "4: view current character sheet" << endl;
			cout << "5: view all saved character sheets" << endl;
			cout << "6: load a character sheet (note: this will overwrite the current character sheet)" << endl;
			cout << "7: save current character sheet" << endl;
			cin >> menuInput;
		}
		//output goodbye message
		cout << "you have quit the program, see you next time!"
		//end method
		end();
	}
		
};

main(){
	//create interface
	interface charSheetInterface();
	//run interface
	charSheetInterface.runInterface();
}
