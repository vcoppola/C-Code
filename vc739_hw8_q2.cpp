#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include < time.h>

using namespace std;

const int  WORLDSIZE = 20;
const int  INITIALANTS = 100;
const int  INITIALBUGS = 5;
const int  DOODLEBUG = 1;
const int  ANT = 2;
const int  ANTBREED = 3;
const int  DOODLEBREED = 8;
const int  DOODLESTARVE = 3;

//Forward declaration of of Organism classes so we can reference them in the World class
class Organism;
class Dodlebug;
class Ant;

class World {
friend class Organism; //Allow Organism to access grid
friend class Doodlebug; //ALlow Organism to access grid
friend class Ant; //Allow  Organism to access grid
public:
	World();
	~World();
	Organism* getAt(int x, int y);
	void setAt(int x, int y, Organism *org);
	void Display();
	void SimulateOneStep();
private:
	Organism* grid[WORLDSIZE][WORLDSIZE];
};

//Definition for the Organism base class.

class Organism {
	friend class World; //Allow world to affecct organism
public:
	//constructors
	Organism();
	Organism(World *world, int x, int y);
	//destructor
	~Organism();

	virtual void breed() = 0; //Whether or not to breed
	virtual void move() = 0; //Rules to move ant or doodlebug
	virtual int getType() = 0; //Return of ant or doodlebug
	virtual bool starve() = 0; //Determine of organism starves

protected:
	int x, y; //Position on the grid
	bool moved; // Bool to indicate if moved this turn
	int breedTicks; // Number of ticks since breeding last
	World *world;
};

//World constructor, destructor

World::World() {
	//Initialize world to empty space
	int i, j;
	for (i = 0; i < WORLDSIZE; i++) {

		for (j = 0; j < WORLDSIZE; j++) {
			grid[i][j] = NULL;
		}
	}
};

World::~World() {
	//Release any allocated memory
	int i, j;
	for (i = 0; i < WORLDSIZE; i++) {

		for (j = 0; j < WORLDSIZE; j++) {
			if (grid[i][j] != NULL) delete (grid[i][j]);
		}
	}
};

//Member function definitions

Organism* World::getAt(int x, int y) {
	if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
		return grid[x][y];
	return NULL;
}
void World::setAt(int x, int y, Organism *org) {
	if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
		grid[x][y] = org;
	}
}

void World::Display() {
	int i, j;
	cout << endl << endl;
	for (j = 0; j < WORLDSIZE; j++) {
		for (i = 0; i < WORLDSIZE; i++) {
			if (grid[i][j] == NULL)
				cout << ".";
			else if (grid[i][j]->getType() == ANT)
				cout << "o";
			else cout << "X";
		}//end of i
		cout << endl;
	}//end of j
}

void World::SimulateOneStep() {
	int i, j;
	//First - reset all organisms to not moved
	for (i = 0; i < WORLDSIZE; i++) {
		for (j = 0; j < WORLDSIZE; j++) {
			if (grid[i][j] != NULL)
				grid[i][j]->moved = false;
		}
	}
	//Loop through cells in order and move if it's a Doodlebug
	for (i = 0; i < WORLDSIZE; i++) {
		for (j = 0; j < WORLDSIZE; j++) {
			if ((grid[i][j] != NULL) && (grid[i][j]->getType() == DOODLEBUG)) {
				if (grid[i][j]->moved == false) {
					grid[i][j]->moved = true; //Mark as moved
					grid[i][j]->move();
				}
			}
		}
	}
	//Loop through cells in order to move if it's an Ant
	for (i = 0; i < WORLDSIZE; i++)
		for (j = 0; j < WORLDSIZE; j++) {
			if ((grid[i][j] != NULL) && (grid[i][j]->getType() == ANT)){
				if (grid[i][j]->moved == false) {
					grid[i][j]->moved = true; //Mark as moved
					grid[i][j]->move();
				}
			}
		}
		//Loop through cells in order and check if we should breed

	 for (i = 0; i < WORLDSIZE; i++)
		 for (j = 0; j < WORLDSIZE; j++){
				//Kill off any doodlebugs that haven't eaten recently
				if ((grid[i][j] != NULL) && (grid[i][j]->getType() == DOODLEBUG)) {
					if (grid[i][j]->starve()) {
						delete (grid[i][j]);
						grid[i][j] = NULL;
					}
				}
			}
		//Loop through cells in order to check if we should breed
		for (i=0; i < WORLDSIZE; i++){
			for (j = 0; j < WORLDSIZE; j++) {
				if ((grid[i][j] != NULL) && (grid[i][j]->moved == true)) {
					grid[i][j]->breed();
				}
			}
		}
	} // end simulateOne step


//Organism Constructor
Organism::Organism()
{
	world = NULL;
	moved = false;
	breedTicks = 0;
	x = 0;
	y = 0;
}
Organism::Organism(World *wrld, int x, int y){
	this->world = wrld;
	moved = false;
	breedTicks = 0;
	this->x = x;
	this->y = y;
	wrld->setAt(x, y, this);
}
//destructor
Organism::~Organism() {
}

//Start with the Ant class

class Ant : public Organism {
	friend class World;
public:
	Ant();
	Ant(World *world, int x, int y);
	void breed(); // Must define this since virtual
	void move(); // Must definte this since virtual
	int getType(); // Must definte this since virtual
	bool starve() { //return false, ant never starves
		return false;
	}
};

//Ant constructor
Ant::Ant() : Organism() {
}
Ant::Ant(World *world, int x, int y) : Organism(world, x, y) {
}

void Ant::move() {
	//Pick random direction to move
	int dir = rand() % 4;
	//try to move up, if not an edge and empty spot
	if (dir == 0) {
		if ((y > 0) && (world->getAt(x, y - 1) == NULL)) {
			world->setAt(x, y - 1, world->getAt(x, y));
			//Move to new spot
			world->setAt(x, y, NULL);
			y--;
		}
	}
	//Try to move down
	else if (dir == 1) {
		if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)) {
			world->setAt(x, y + 1, world->getAt(x, y)); //Move to new spot
			world->setAt(x, y + 1, world->getAt(x, y)); // Set current spot to empty
			y++;
		}
	}
	//Try to move left
	else if (dir == 2) {
		if ((x > 0) && (world->getAt(x - 1, y) == NULL)) {
			world->setAt(x - 1, y, world->getAt(x, y)); //Move to a new spot
			world->setAt(x, y, NULL); // Set current spot to empty
			x--;
		}
	}
	//Try to move right
	else {
		if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)) {
			world->setAt(x + 1, y, world->getAt(x, y)); //Move to new spot
			world->setAt(x, y, NULL); // Set current spot to empty
			x++;
		}
	}
}
int Ant::getType(){
	return ANT;
}
void Ant::breed() {
	breedTicks;
	if (breedTicks == ANTBREED) {
		breedTicks = 0;
		//Try to make a new ant either above, left, right
		if ((y > 0) && (world->getAt(x, y - 1) == NULL)) {
			Ant *newAnt = new Ant(world, x, y - 1);
		}
		else if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)) {
			Ant *newAnt = new Ant(world, x, y + 1);
		}
		else if ((x > 0) && (world->getAt(x - 1, y) == NULL)) {
			Ant *newAnt = new Ant(world, x - 1, y);
		}
		else if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)) {
			Ant *newAnt = new Ant(world, x + 1, y);
		}
	}
}
class Doodlebug : public Organism {
	friend class World;
public:
	Doodlebug();
	Doodlebug(World *world, int x, int y);
	void breed(); //Must define this since virtual
	void move(); //Must define this since virutal
	int getType(); //Must define this since virtual
	bool starve(); //Check if Doodlebug starves to death
private:
	int starveTicks; //Number of moves before starving
};

//Doodlebug constructor
Doodlebug::Doodlebug(World *world, int x, int y) : Organism(world, x, y) {
	starveTicks = 0;
}
//member functions

void Doodlebug::move(){
	if ((y > 0) && (world->getAt(x, y - 1) != NULL) 
		&& (world->getAt(x, y - 1)->getType() == ANT)) {
		
		delete (world->grid[x][y - 1]); // Kill ant
		world->grid[x][y - 1] = this; // Move to spot
		world->setAt(x, y, NULL);
		starveTicks = 0; // Reset hunger
		y--;
		return;
	}
	else if ((y < WORLDSIZE - 1) 
		&& (world->getAt(x, y + 1) != NULL) 
		&& (world->getAt(x, y + 1)->getType() == ANT)) {

		delete (world->grid[x][y + 1]); // Kill ant
		world->grid[x][y + 1] = this; // Move to spot
		world->setAt(x, y, NULL);
		starveTicks = 0; // Reset hunger
		y++;
		return;
	}
	else if ((x > 0) && (world->getAt(x - 1, y) != NULL) &&
		(world->getAt(x - 1, y)->getType() == ANT)) {

		delete (world->grid[x - 1][y]);// Kill ant
		world->grid[x - 1][y] = this; // Move to spot
		world->setAt(x, y, NULL);
		starveTicks = 0; //Reset hunger
		x++;
		return;
	}

	int dir = rand() % 4;
	//Try to move up if not an edge and  empty spot

	//try to move up, if not an edge and empty spot
	if (dir == 0) {
		if ((y > 0) && (world->getAt(x, y - 1) == NULL)) {
			world->setAt(x, y - 1, world->getAt(x, y));
			//Move to new spot
			world->setAt(x, y, NULL);
			y--;
		}
	}
	//Try to move down
	else if (dir == 1) {
		if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)) {
			world->setAt(x, y + 1, world->getAt(x, y)); //Move to new spot
			world->setAt(x, y + 1, world->getAt(x, y)); // Set current spot to empty
			y++;
		}
	}
	//Try to move left
	else if (dir == 2) {
		if ((x > 0) && (world->getAt(x - 1, y) == NULL)) {
			world->setAt(x - 1, y, world->getAt(x, y)); //Move to a new spot
			world->setAt(x, y, NULL); // Set current spot to empty
			x--;
		}
	}
	//Try to move right
	else {
		if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)) {
			world->setAt(x + 1, y, world->getAt(x, y)); //Move to new spot
			world->setAt(x, y, NULL); // Set current spot to empty
			x++;
		}
	}
	starveTicks++; //increment starve ticks since we didn't eat on this turn
}
int Doodlebug::getType() {
	return DOODLEBUG;
}
void Doodlebug::breed() {
	breedTicks++;
	if (breedTicks == DOODLEBREED) {
		breedTicks = 0;
		//Try to make a new ant either above, left, right or down
		if ((y > 0) && (world->getAt(x, y - 1) == NULL)) {
			Doodlebug *newDoodle = new Doodlebug(world, x, y - 1);
		}
		else if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)) {
			Doodlebug *newDoodle = new Doodlebug(world, x, y + 1);
		}
		else if ((x > 0) && (world->getAt(x - 1, y) == NULL)) {
			Doodlebug *newDoodle = new Doodlebug(world, x - 1, y);
		}
		else if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)) {
			Doodlebug *newDoodle = new Doodlebug(world, x + 1, y);
		}
	}//end if
}//end breed

bool Doodlebug::starve() {
	// Starve if no food eaten in last DOODLESTARVE time ticks
	if (starveTicks > DOODLESTARVE) {
		return true;
	}
	else {
		return false;
	}
} //end starve

//main

int main() {

	string s;
	srand(time(NULL)); //seed random number generator
	World w; // Randomly create 100 ants
	int antcount = 0;

	while (antcount < INITIALANTS) {
		int x = rand() % WORLDSIZE;
		int y = rand() % WORLDSIZE;
		if (w.getAt(x, y) == NULL) { // Only put ant in empty spot
			antcount++;
			Ant *a1 = new Ant(&w, x, y);
		}
	} //end while

	//Randomly create 5 doodlebugs
	int doodlecount = 0;
	while (doodlecount < INITIALBUGS) {
		int x = rand() % WORLDSIZE;
		int y = rand() % WORLDSIZE;
		if (w.getAt(x, y) == NULL) { //Only put doodlebug in empty spot
			doodlecount++;
			Doodlebug *d1 = new Doodlebug(&w, x, y);
		}
	} //end while

	//Run simulation forever until user cancels

	while (true) {
		w.Display();
		w.SimulateOneStep();
		cout << endl << "Press enter for next step" << endl;
		getline(cin, s);
	}

	//pause system
	system("pause");

	return 0;
} //end main

	
	







	
	
	














