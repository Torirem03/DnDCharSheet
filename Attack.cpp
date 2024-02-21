//Liz Hinton
//2-15-24
//eahinton@dmacc.edu
//attack class, has damage type and damage amount in dice (ex 4d6) as well what is being used to attack, and the to hit and damage modifiers

class attack(){
	//variables
	private:
	//weapon or spell 
	string atkMethod;
	//damage type
	string dmgType;
	//damage amount
	string dmgAmount;
	//hit modifier
	int toHitMod;
	//damage modifier
	int dmgMod;
	
	
	//constructors
	public:
	//default
	attack(){
		atkMethod = "dagger";
		dmgType = "piercing";
		dmgAmount = "1d4";
		toHitMod = 0;
		dmgMod = 0;
	}
	
	//all
	attack(string a, string t, string d, int h, int m){
		atkMethod = a;
		dmgType = t;
		dmgAmount = d;
		toHitMod = h;
		dmgMod = m;
	}
	
	// attack method, dmg type and amount
	attack(string a, string t, string d){
		atkMethod = a;
		dmgType = t;
		dmgAmount = d;
		toHitMod = 0;
		dmgMod = 0;
	}
	
	//getters
	string getAtkMethod(){
		return atkMethod;
	}
	
	string getDmgType(){
		return dmgType;
	}
	
	string getDmgAmount(){
		return dmgAmount;
	}
	
	int getToHitMod(){
		return toHitMod;
	}
	
	int getDmgMod(){
		return dmgMod;
	}
	
	
	//setters
	void setAtkMethod(string a){
		atkMethod = a;
	}
	
	void setDmgType(string t){
		dmgType = t;
	}
	
	void setDmgAmount(string d){
		dmgAmount = d;
	}
	
	void setToHitMod(int h){
		toHitMod = h;
	}
	
	void setDmgMod(int m){
		dmgMod = m;
	}
	
	//methods
}
