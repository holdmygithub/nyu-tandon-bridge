#include<iostream>
#include<vector>

using namespace std;

const int critter_DOODLEBUG = 0, critter_ANT = 1;

class Organism{
    protected:
        int critter;
    public:
        Organism(int critter_type) : critter(critter_type){}
        virtual void move() = 0;
        int get_critter() const{
            return critter;
        }
};

class Ant : public Organism{
    public:
        Ant(): Organism(critter_ANT) {}
        void move(){
            cout<<"HAHA";
        }

};

class Doodlebug : public Organism{
    private:
        int starving;
    public:
        Doodlebug(): Organism(critter_DOODLEBUG), starving(0) {}
        void move(){
            cout<<"HAHA";
        }
        
};

class Grid{
    private:
        vector<vector<Organism*>> world;
        int timestep,width,height;
        void initialize_grid(int num_ants, int num_doodlebugs){
            int x,y;
            for(int i=0;i<num_doodlebugs;i++){
                x = rand()%width;
                y = rand()%height;
                world[x][y] = new Doodlebug();
            }

            for(int i=0;i<num_ants;i++){
                x = rand()%width;
                y = rand()%height;
                world[x][y] = new Ant();
            }
        }

    public:
        Grid(int inp_height, int inp_width, int num_ants, int num_doodlebugs, int doodlebug_breed_step, int ant_breed_step, int doodlebug_starving) : timestep(0), height(inp_height),width(inp_width){
            if((num_ants + num_doodlebugs) > height*width){
                cout<<"Input organisms size is higher than the world";
                exit(1);
            }
            else{ 
                world.resize(width,vector<Organism*>(height,nullptr)); initialize_grid(num_ants,num_doodlebugs); }
            }
};

int main(){
    srand(time(NULL));
    const int WIDTH = 3, HEIGHT = 3, ANTS = 3, DOODLEBUGS = 3, DOODLEBUG_BREED_STEP = 3, ANT_BREED_STEP = 3, DOODLEBUG_STARVING = 3;
    Grid World(WIDTH, HEIGHT, ANTS, DOODLEBUGS, DOODLEBUG_BREED_STEP, ANT_BREED_STEP, DOODLEBUG_STARVING);

    return 0;
}